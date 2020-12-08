#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>
#include <iostream>
#include <set>

namespace Ui {
  class Playlists;
}

class Playlists : public QMainWindow
{
  Q_OBJECT

public:
  explicit Playlists(QWidget *parent = nullptr);
  ~Playlists();
  void dataRecovery();
  void insertNameOfPlaylist();

  void clearAll();


private slots:
  	void on_pushButton_clicked();
  	void elementClicked(const QModelIndex& current);
signals:
	void changePlaylistSig(QString); 

private:
  	Ui::Playlists *ui;

private:
	QString m_playlist_name;

    std::set<std::string> m_set_playlist;
};
