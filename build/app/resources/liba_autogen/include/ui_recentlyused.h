/********************************************************************************
** Form generated from reading UI file 'recentlyused.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECENTLYUSED_H
#define UI_RECENTLYUSED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecentlyUsed
{
public:
    QWidget *centralwidget;
    QTreeView *treeView;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RecentlyUsed)
    {
        if (RecentlyUsed->objectName().isEmpty())
            RecentlyUsed->setObjectName(QString::fromUtf8("RecentlyUsed"));
        RecentlyUsed->setWindowModality(Qt::ApplicationModal);
        RecentlyUsed->setEnabled(true);
        RecentlyUsed->resize(400, 610);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RecentlyUsed->sizePolicy().hasHeightForWidth());
        RecentlyUsed->setSizePolicy(sizePolicy);
        RecentlyUsed->setFocusPolicy(Qt::ClickFocus);
        centralwidget = new QWidget(RecentlyUsed);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(0, 0, 400, 610));
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        RecentlyUsed->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(RecentlyUsed);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RecentlyUsed->setStatusBar(statusBar);

        retranslateUi(RecentlyUsed);

        QMetaObject::connectSlotsByName(RecentlyUsed);
    } // setupUi

    void retranslateUi(QMainWindow *RecentlyUsed)
    {
        RecentlyUsed->setWindowTitle(QCoreApplication::translate("RecentlyUsed", "Recently Opened", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecentlyUsed: public Ui_RecentlyUsed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECENTLYUSED_H
