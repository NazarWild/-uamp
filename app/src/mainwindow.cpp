#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    m_model(new QFileSystemModel(this)),
    m_player(new QMediaPlayer),
    m_playlist(new QMediaPlaylist(m_player)),
    m_db(QSqlDatabase::addDatabase("QSQLITE")),
    m_sqlModel(new QSqlTableModel),
    m_recently_used_win(new RecentlyUsed),
    m_playlists_win(new Playlists)
{
    ui->setupUi(this);

    m_cur_pid = 0;
    m_player->setPlaylist(m_playlist);

    m_db.setHostName("localhost");
    m_db.setDatabaseName("databaseUamp");
    bool ok = m_db.open();
    
    if (ok) {
        creationOfTables();
        dataRecovery();
        show_table();
    }
    if(!m_path_dir.isEmpty()) {
        m_model->setRootPath(m_path_dir);
        m_model->setNameFilters(m_allowedTypes);
    }
    ui->treeView->setModel(m_model);
    ui->treeView->setRootIndex(m_model->index(m_path_dir));
    ui->treeView->setHeaderHidden(true);
    ui->treeView->setSelectionBehavior (QAbstractItemView::SelectRows);

    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeView, SIGNAL(customContextMenuRequested(const QPoint &)), this,
            SLOT(onLibraryContextMenu(const QPoint &)));

    QPixmap pix("./app/resources/music_anonim.svg");
    int w = ui->albumImage->width();
    int h = ui->albumImage->height();

    ui->albumImage->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->playButton->setIcon(QIcon("./app/resources/playButton.svg"));
    ui->previousButton->setIcon(QIcon("./app/resources/previousButton.svg"));
    ui->nextButton->setIcon(QIcon("./app/resources/nextButton.svg"));
    ui->playlists->setIcon(QIcon("./app/resources/headphones.svg"));

    for (int i = 1; i < m_model->columnCount(); i++)
        ui->treeView->hideColumn(i);

    QObject::connect(ui->treeView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(elementClicked(QModelIndex)));
    QObject::connect(ui->playButton, SIGNAL(clicked()), this, SLOT(playMusic())); // кнопка запуска трека
    QObject::connect(m_player, &QMediaPlayer::positionChanged, this, &MainWindow::changing_run);
    connect(ui->tableView, &QAbstractItemView::clicked, this, &MainWindow::currentMusicTableIndex);
    connect(m_sqlModel, &QSqlTableModel::beforeUpdate, this, &MainWindow::on_editTableModel_clicked);
    connect(m_playlists_win, SIGNAL(changePlaylistSig(QString)), this, SLOT(changePlaylist(QString)));
    connect(m_recently_used_win, SIGNAL(selectDir(QString)), this, SLOT(setDir(QString)));
}

MainWindow::~MainWindow()
{
    m_db.close();
    delete m_model;
    delete m_playlist;
    delete m_player;
    delete m_sqlModel;
    delete m_playlists_win;
    delete m_recently_used_win;
    delete ui;
}

QString MainWindow::rightTimeChange(int sec) {
    QString first = QString::number(sec / 60);
    QString second = QString::number(sec % 60);

    if (second.length() == 1)
        second = "0" + second;
    return first + ":" + second;
}

void MainWindow::openMusicFile() {
    if(!m_path_file.isEmpty()) {
        TagLib::FileRef f(m_path_file.toStdString().c_str());

        if(f.file()->isValid()) {
            int sec = f.audioProperties()->lengthInSeconds();

            //ui->listWidget->addItem(TStringToQString(f.tag()->title()));

            ui->trackName->setText(TStringToQString(f.tag()->title()));
            ui->authorName->setText(TStringToQString(f.tag()->artist()));
            ui->trackLength->setText(rightTimeChange(sec));
            m_cur_title = TStringToQString(f.tag()->title());
            m_cur_duration = rightTimeChange(sec);
            m_cur_artist = TStringToQString(f.tag()->artist());
            m_cur_album = TStringToQString(f.tag()->album());
            m_cur_genre = TStringToQString(f.tag()->genre());
            insertIntoMusicInfo();
        }
    }
}

void MainWindow::creationOfTables() {
    QSqlQuery query;
    query.exec("CREATE TABLE music_info (sid INTEGER PRIMARY KEY AUTOINCREMENT,Title TEXT, Duration TEXT, Artist TEXT, Album TEXT, Genre TEXT, Rating INTEGER, Played INTEGER, Playlist_id INTEGER, Path TEXT NOT NULL UNIQUE);");
    query.exec("CREATE TABLE setting_info (curSong TEXT, recentlyUsed TEXT);");
    query.exec("CREATE TABLE recentlyUsed (Path TEXT NOT NULL UNIQUE);");
    query.exec("CREATE TABLE Playlists (pid INTEGER PRIMARY KEY  AUTOINCREMENT, Name TEXT NOT NULL UNIQUE);");
    query.exec("PRAGMA foreign_keys = ON;");
    QString str = "CREATE TABLE List_sid_pid ("  \
      "ID            INTEGER  PRIMARY KEY  AUTOINCREMENT," \
      "PLAYLIST_R    INTEGER  NOT NULL," \
      "SONG_R        INTEGER  NOT NULL," \
      "FOREIGN KEY (PLAYLIST_R) REFERENCES Playlists (pid)" \
      "FOREIGN KEY (SONG_R) REFERENCES music_info (sid) ON DELETE CASCADE" \
      ");";
    query.exec(str);
}

void MainWindow::insertIntoMusicInfo() {
    QSqlQuery query;
    query.prepare("INSERT INTO music_info (Title, Duration, Artist, Album, Genre, Rating, Played, Playlist_id, Path) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, m_cur_title);
    query.bindValue(1, m_cur_duration);
    query.bindValue(2, m_cur_artist);
    query.bindValue(3, m_cur_album);
    query.bindValue(4, m_cur_genre);
    query.bindValue(5, 0);
    query.bindValue(6, 0);
    query.bindValue(7, 1);
    query.bindValue(8, m_path_file);
    query.exec();
    show_table();
}

void MainWindow::show_table() {
    // QString filter = "Playlists";

    // filter +=  " LIKE '";
    // filter +=  m_cur_pid;
    // filter +=  "'";
     
    m_sqlModel->setTable("music_info");
    m_sqlModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    // m_sqlModel->setFilter(filter);
    m_sqlModel->select();

    ui->tableView->setModel(m_sqlModel);
    ui->tableView->setColumnWidth(1, 200);
    ui->tableView->setColumnWidth(2, 70);
    ui->tableView->setColumnWidth(3, 150);
    ui->tableView->setColumnWidth(4, 177);
    ui->tableView->setColumnWidth(5, 80);
    ui->tableView->setColumnWidth(6, 50);
    ui->tableView->setColumnWidth(7, 50);
    ui->tableView->hideColumn(0); // don't show ID's
    ui->tableView->hideColumn(8); // don't show the playlists
    ui->tableView->show();
}

void MainWindow::insertSettInfo() {
    QSqlQuery query;
    query.prepare("INSERT INTO music_info (curSong, recentlyUsed) "
                  "VALUES (?, ?)");
    query.bindValue(0, m_path_file);
    query.bindValue(1, m_path_dir);
    query.exec();
}

void MainWindow::insertRecentlyUsed() {
    QSqlQuery query;
    query.prepare("INSERT INTO recentlyUsed (Path) "
                  "VALUES (?)");
    query.bindValue(0, m_path_dir);
    query.exec();
}

void MainWindow::dataRecovery() {
    QSqlQueryModel model;
    model.setQuery("SELECT curSong, recentlyUsed FROM setting_info");
    m_path_file = model.record(model.rowCount() - 1).value("curSong").toString();
    m_path_dir = model.record(model.rowCount() - 1).value("recentlyUsed").toString();

    if(!m_path_dir.isEmpty()) {
        m_model->setRootPath(m_path_dir);
        ui->treeView->setRootIndex(m_model->index(m_path_dir));
    }

    model.setQuery("SELECT Name FROM Playlists");
    openMusicFile();
}

//private slots

void MainWindow::on_actionOpen_Folder_triggered()
{
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath()); 
    dialog.setFileMode(QFileDialog::Directory);
    QString dirname = dialog.getExistingDirectory();

    if (dirname.isEmpty())
        return ;
    m_path_dir = dirname;
    m_path_file.clear();

    insertRecentlyUsed();
    m_model->setRootPath(m_path_dir);
    ui->treeView->setRootIndex(m_model->index(m_path_dir));
}

void MainWindow::on_actionOpen_File_triggered() {
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath()); 
    dialog.setFileMode(QFileDialog::Directory);
    QString filename = dialog.getOpenFileName();

    QFile file(filename);

    if (file.open(QFile::ReadOnly | QFile::Text)) {

        m_path_file = filename;
        QFileInfo fileInfo(filename);
        m_path_dir = fileInfo.dir().absolutePath();

        insertRecentlyUsed();
        m_model->setRootPath(m_path_dir); 
        ui->treeView->setRootIndex(m_model->index(m_path_dir));
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value) {
    m_player->setPosition(value * 1000);
}

void MainWindow::on_horizontalSlider_sliderPressed()
{
    m_player->blockSignals(true);
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    m_player->blockSignals(false);
}

void MainWindow::currentMusicTableIndex(const QModelIndex &index) {
    m_table_index = index;
}

void MainWindow::changing_run() {
    ui->horizontalSlider->blockSignals(true);
    ui->horizontalSlider->setSliderPosition(m_player->position()/1000);
    ui->horizontalSlider->blockSignals(false);
}

void MainWindow::elementClicked(const QModelIndex& current) {
    QModelIndex p = current;
    std::vector<QString> vec;
    QString tmp_path;

    while(p.isValid()) {
        vec.push_back(p.data().toString());
        p = p.parent();
    }
    std::reverse(vec.begin(), vec.end());
    for (const auto& i : vec) {
        if (i.toStdString() != "/")
            tmp_path += "/" + i;
    }
    m_path_file = tmp_path;

    addToPlaylist();
    insertSettInfo();
    openMusicFile();
    if (m_player->state() != QMediaPlayer::StoppedState)
        m_player->stop();
    playMusic(); // отыгрывает трек
}

void MainWindow::playMusic() {
    if (m_player->state() == QMediaPlayer::PlayingState) {
        m_player->pause();
        ui->playButton->setIcon(QIcon("./app/resources/playButton.svg"));
    }
    else if (m_player->state() == QMediaPlayer::PausedState) {
        m_player->play();
        ui->playButton->setIcon(QIcon("./app/resources/pause.svg"));
    }
    else if (m_player->state() == QMediaPlayer::StoppedState) {
        m_player->setMedia(QUrl::fromLocalFile(m_path_file));
        ui->horizontalSlider->setSliderPosition(0);
        ui->horizontalSlider->setRange(0, m_player->duration()/1000);
        ui->playButton->setIcon(QIcon("./app/resources/pause.svg"));
        m_player->setVolume(0);
        m_player->play();
    }
}

void MainWindow::on_editTableModel_clicked(int, QSqlRecord &) {
    QString path = m_sqlModel->record(m_table_index.row()).value("Path").toString();
    // std::cout << path.toStdString() << std::endl;
    TagLib::FileRef f(path.toStdString().c_str());

    if(f.file()->isValid()) {
        QString buffer = m_sqlModel->record(m_table_index.row()).value("Title").toString();
        f.tag()->setTitle(buffer.toStdString());
        buffer = m_sqlModel->record(m_table_index.row()).value("Artist").toString();
        f.tag()->setArtist(buffer.toStdString());
        buffer = m_sqlModel->record(m_table_index.row()).value("Album").toString();
        f.tag()->setAlbum(buffer.toStdString());
        buffer = m_sqlModel->record(m_table_index.row()).value("Genre").toString();
        f.tag()->setGenre(buffer.toStdString());
        f.save();
    }
}

void MainWindow::on_actionRecently_opened_triggered() {
    QSqlTableModel *sqlModel = new QSqlTableModel;

    sqlModel->setTable("recentlyUsed");
    sqlModel->select();

    m_recently_used_win->setModel(sqlModel);
    m_recently_used_win->move(pos().x() - 400, pos().y());
    m_recently_used_win->show();
}

void MainWindow::onLibraryContextMenu(const QPoint &point)
{
    QModelIndex p = ui->treeView->currentIndex();
    std::vector<QString> vec;
    QString tmp_path;

    while(p.isValid()) {
        vec.push_back(p.data().toString());
        p = p.parent();
    }
    std::reverse(vec.begin(), vec.end());
    for (const auto& i : vec) {
        if (i.toStdString() != "/")
            tmp_path += "/" + i;
    }
    m_path_file = tmp_path;

    QMenu contextMenu(tr("SideBar context menu"), this);

    QAction action_new("Add to playlist", this);
    connect(&action_new, &QAction::triggered, this, &MainWindow::addToPlaylist);
    contextMenu.addAction(&action_new);

    contextMenu.exec(ui->treeView->viewport()->mapToGlobal(point));
}

///////////////////////////////////////////////////////////////////////////
void MainWindow::addToPlaylist() {
    m_playlist->addMedia(QMediaContent(QUrl::fromLocalFile(m_path_file)));
    std::cout << m_path_file.toStdString() << std::endl;
}
///////////////////////////////////////////////////////////////////////////

void MainWindow::on_playlists_clicked() {
    m_playlists_win->clearAll();
    m_playlists_win->dataRecovery();
    m_playlists_win->insertNameOfPlaylist();
    m_playlists_win->move(1852, pos().y());
    m_playlists_win->show();
}

void MainWindow::changePlaylist(QString playlist) {
    std::cout << playlist.toStdString() << std::endl;
    //m_cur_pid = pid;
    show_table();
}

void MainWindow::setDir(QString dir) {
    m_path_dir = dir;
    m_model->setRootPath(m_path_dir);
    ui->treeView->setRootIndex(m_model->index(m_path_dir));
}

void MainWindow::on_dial_sliderMoved(int position)
{
    m_player->setVolume(position);
}

void MainWindow::on_nextButton_clicked()
{
    m_playlist->next();
}

void MainWindow::on_previousButton_clicked()
{
    m_playlist->previous();
}

// bool TagFunctions::set_image_mpeg(char *file_path, char *image_path)
// {
//     QFileInfo file(file_path);
//     if (!file.isWritable()) {
//         return false;
//     }
//     TagLib::MPEG::File mpegFile(file_path);
//     TagLib::ID3v2::Tag *tag = mpegFile.ID3v2Tag();
//     TagLib::ID3v2::FrameList frames = tag->frameList("APIC");
//     TagLib::ID3v2::AttachedPictureFrame *frame = 0;
//     if(frames.isEmpty())
//     {
//         frame = new TagLib::ID3v2::AttachedPictureFrame;
//         tag->addFrame(frame);
//     }
//     else
//     {
//         frame = static_cast<TagLib::ID3v2::AttachedPictureFrame *>(frames.front());
//     }
//     ImageFile imageFile(image_path);
//     TagLib::ByteVector imageData = imageFile.data();
//     frame->setMimeType("image/jpeg");
//     frame->setPicture(imageData);
//     mpegFile.save();
//     return true;
// }

// void MainWindow::on_actionSave_triggered()
// {
//     TagLib::FileRef f(m_path_file.toStdString().c_str());

//     if(f.file()->isValid()) {
//         QString buffer = ui->textEdit->toPlainText();
//         f.tag()->setArtist(QStringToTString(buffer));
//         buffer = ui->textEdit_1->toPlainText();
//         f.tag()->setTitle(QStringToTString(buffer));
//         buffer = ui->textEdit_2->toPlainText();
//         f.tag()->setAlbum(QStringToTString(buffer));
//         buffer = ui->textEdit_3->toPlainText();
//         f.tag()->setGenre(QStringToTString(buffer));
//         f.save();
//     }
// }

// void MainWindow::on_actionSave_as_triggered()
// {
//     QFileDialog dialog(0);
//     dialog.setWindowModality(Qt::WindowModal);
//     dialog.setAcceptMode(QFileDialog::AcceptSave);
//     if (dialog.exec() == QDialog::Accepted) {
//         QFile file(dialog.selectedFiles().first());
//         QFileInfo fileInfo(dialog.selectedFiles().first());

//         m_path_dir = fileInfo.dir().absolutePath();
//         m_model->setRootPath(m_path_dir);
//         ui->treeView->setRootIndex(m_model->index(m_path_dir));
//     }
// }
