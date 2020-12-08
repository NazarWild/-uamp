#include "playlists.h"
#include "ui_playlists.h"

Playlists::Playlists(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::Playlists)
{
    ui->setupUi(this);

    m_playlist_name = "General";
    ui->listWidget->addItem("General");
    m_set_playlist.insert("General");
    insertNameOfPlaylist();
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

    emit changePlaylistSig(p.data().toString());
}
