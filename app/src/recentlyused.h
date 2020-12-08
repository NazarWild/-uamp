#pragma once

#include <QMainWindow>
#include <QSqlTableModel>

#include <iostream>

namespace Ui {
  class RecentlyUsed;
}

class RecentlyUsed : public QMainWindow
{
  Q_OBJECT

public:
  	explicit RecentlyUsed(QWidget *parent = nullptr);
  	~RecentlyUsed();
  	void setModel(QSqlTableModel *sqlModel);

private slots: // all actions 
    void elementClicked(const QModelIndex& current);

signals:
	void selectDir(QString); 

private:
  	Ui::RecentlyUsed *ui;
};
