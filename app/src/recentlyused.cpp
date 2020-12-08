#include "recentlyused.h"
#include "ui_recentlyused.h"

RecentlyUsed::RecentlyUsed(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::RecentlyUsed)
{
  ui->setupUi(this);
  QObject::connect(ui->treeView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(elementClicked(QModelIndex)));
}

RecentlyUsed::~RecentlyUsed()
{
  delete ui;
}

void RecentlyUsed::setModel(QSqlTableModel *sqlModel) {
    ui->treeView->setModel(sqlModel);
    ui->treeView->setColumnWidth(0, 380);
    ui->treeView->show();
}

void RecentlyUsed::elementClicked(const QModelIndex& current) {
    QModelIndex p = current;

    emit selectDir(p.data().toString());
}