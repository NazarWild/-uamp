#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    m_model(new QFileSystemModel(this)),
    m_player(new QMediaPlayer),
    m_db(QSqlDatabase::addDatabase("QSQLITE"))
{
    ui->setupUi(this);
    
    m_db.setHostName("localhost");
    m_db.setDatabaseName("DATABASE_uamp");
    bool ok = m_db.open();
    
    if (ok) {
        QSqlQuery query;
        query.exec("CREATE TABLE music_info (Name TEXT, Duration INTEGER, Artist TEXT, Album TEXT, Genre TEXT, Rating INTEGER, Num_of_playing INTEGER);");
        query.exec("INSERT INTO music_info (Name, Duration, Artist, Album, Genre, Rating, Num_of_playing) VALUES ('hui', 10, 'hui', 'hui', '2', 5, 6);");
    }
    
    ui->treeView->setModel(m_model);
    ui->treeView->setHeaderHidden(true);
    ui->treeView->setSelectionBehavior (QAbstractItemView::SelectRows);
    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);

    QPixmap pix("./app/resources/music_anonim.svg");
    int w = ui->albumImage->width();
    int h = ui->albumImage->height();

    ui->albumImage->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->playButton->setIcon(QIcon("./app/resources/playButton.svg"));
    ui->rewindButton->setIcon(QIcon("./app/resources/rewind.svg"));
    ui->previousButton->setIcon(QIcon("./app/resources/previousButton.svg"));
    ui->forwardButton->setIcon(QIcon("./app/resources/forward.svg"));
    ui->nextButton->setIcon(QIcon("./app/resources/nextButton.svg"));
    ui->favorite->setIcon(QIcon("./app/resources/heart.svg"));
    ui->playlists->setIcon(QIcon("./app/resources/headphones.svg"));
    ui->info->setIcon(QIcon("./app/resources/information.svg"));

    for (int i = 1; i < m_model->columnCount(); i++)
        ui->treeView->hideColumn(i);
    QObject::connect(ui->treeView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(elementClicked(QModelIndex)));
    QObject::connect(ui->playButton, SIGNAL(clicked()), this, SLOT(playMusic())); // кнопка запуска трека
    QObject::connect(m_player, &QMediaPlayer::positionChanged, this, &MainWindow::changing_run);
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
    TagLib::FileRef f(tmp_path.toStdString().c_str());

    if(f.file()->isValid()) {
        int sec = f.audioProperties()->lengthInSeconds();

        ui->trackName->setText(current.data().toString());
        ui->authorName->setText(TStringToQString(f.tag()->artist()));
        ui->trackLength->setText(rightTimeChange(sec));
        if (m_player->state() != QMediaPlayer::StoppedState)
            m_player->stop();
        playMusic(); // отыгрывает трек


        //ui->textEdit_1->setText(TStringToQString(f.tag()->title()));
        //ui->textEdit_2->setText(TStringToQString(f.tag()->album()));
        //ui->textEdit_3->setText(TStringToQString(f.tag()->genre()));
    }
}

MainWindow::~MainWindow()
{
    m_db.close();
    delete m_model;
    delete ui;
}

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

    m_model->setRootPath(dirname); 
    ui->treeView->setRootIndex(m_model->index(dirname));
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

        m_model->setRootPath(m_path_dir); 
        ui->treeView->setRootIndex(m_model->index(m_path_dir));
    }
}

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

QString MainWindow::rightTimeChange(int sec) {
    QString first = QString::number(sec / 60);
    QString second = QString::number(sec % 60);

    if (second.length() == 1)
        second = "0" + second;
    return first + ":" + second;
}

void MainWindow::playMusic() {
    if (m_player->state() == QMediaPlayer::StoppedState) {
        m_player->setMedia(QUrl::fromLocalFile(m_path_file));
        ui->horizontalSlider->setRange(0, m_player->duration()/1000);
        ui->horizontalSlider->setSliderPosition(0);
        m_player->setVolume(50); // надо добавить исправление звука
        m_player->play(); 
        ui->playButton->setIcon(QIcon("./app/resources/pause.svg"));
    }
    else if (m_player->state() == QMediaPlayer::PlayingState) {
        m_player->pause();
        ui->playButton->setIcon(QIcon("./app/resources/playButton.svg"));
    }
    else if (m_player->state() == QMediaPlayer::PausedState) {
        m_player->play();
        ui->playButton->setIcon(QIcon("./app/resources/pause.svg"));
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