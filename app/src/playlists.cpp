#include "playlists.h"
#include "ui_playlists.h"

Playlists::Playlists(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Playlists)
{
    ui->setupUi(this);

    m_playlist_name = "General";
    m_set_playlist.insert("General");
    
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(const QPoint &)), this,
            SLOT(onPlaylistsContextMenu(const QPoint &)));

    QObject::connect(ui->listWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(elementClicked(QModelIndex)));
}

Playlists::~Playlists()
{
    delete ui;
}

void Playlists::dataRecovery() {
    QSqlQueryModel model;
    model.setQuery("SELECT Name FROM Playlists");

    for (int i = 0; i < model.rowCount(); i++) {
        m_set_playlist.insert(model.record(i).value("Name").toString().toStdString());
        ui->listWidget->addItem(model.record(i).value("Name").toString());
    }
}

void Playlists::insertNameOfPlaylist() {
    QSqlQuery query;
    query.prepare("INSERT INTO Playlists (Name) "
                  "VALUES (?)");
    query.bindValue(0, m_playlist_name);
    query.exec();
}

void Playlists::clearAll() {
    ui->listWidget->clear();
}

void Playlists::on_pushButton_clicked()
{
    QMessageBox msgBox;
    msgBox.move(pos().x() + 70, pos().y() - 120);

    m_playlist_name = ui->textEdit->toPlainText();
    if (!m_playlist_name.isEmpty() && m_set_playlist.count(m_playlist_name.toStdString()) == 0) {
        ui->listWidget->addItem(m_playlist_name);
        m_set_playlist.insert(m_playlist_name.toStdString());
        insertNameOfPlaylist();
        ui->textEdit->setPlainText("");
    }
    else if (m_set_playlist.count(m_playlist_name.toStdString()) > 0) {
        msgBox.setText("Playlist with this name already exist!");
        msgBox.exec();
    }
    else {
        msgBox.setText("Enter the name of new playlist!");
        msgBox.exec();
    }
}

void Playlists::elementClicked(const QModelIndex& current) {
    QModelIndex p = current;
    QSqlQueryModel model;
    QString zapros = "SELECT pid FROM Playlists WHERE Name LIKE '";
    zapros += p.data().toString();
    zapros += "'";
    model.setQuery(zapros);

    emit changePlaylistSig(model.record(model.rowCount() - 1).value("pid").toInt());
}

void Playlists::onPlaylistsContextMenu(const QPoint &point)
{
    QModelIndex p = ui->listWidget->currentIndex();

    m_cur_pname = p.data().toString();

    QMenu contextMenu(tr("SideBar context menu"), this);

    QAction action_new("New playlist", this);
    connect(&action_new, &QAction::triggered, this, &Playlists::on_pushButton_clicked);
    contextMenu.addAction(&action_new);

    QAction action_delete("Delete playlist", this);
    connect(&action_delete, &QAction::triggered, this, &Playlists::func_for_delete);
    contextMenu.addAction(&action_delete);

    contextMenu.exec(ui->listWidget->viewport()->mapToGlobal(point));
}

void Playlists::func_for_delete() {
    if (m_cur_pname != "General") {
        QSqlQuery query;
        QString str = "DELETE FROM Playlists WHERE Name LIKE '";
        str += m_cur_pname;
        str += "'";
        query.exec(str);
        m_set_playlist.clear();
        clearAll();
        dataRecovery();

        QSqlQueryModel model;
        QString zapros = "SELECT pid FROM Playlists WHERE Name LIKE '";
        zapros += m_cur_pname;
        zapros += "'";
        model.setQuery(zapros);

        QSqlQuery query1;
        QString str1 = "DELETE FROM List_sid_pid WHERE pid = ";
        str1 += QString::number(model.record(model.rowCount() - 1).value("pid").toInt());
        query1.exec(str1);

        emit changePlaylistSig(1);
    }
}
