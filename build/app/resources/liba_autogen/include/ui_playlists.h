/********************************************************************************
** Form generated from reading UI file 'playlists.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTS_H
#define UI_PLAYLISTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Playlists
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QTextEdit *textEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Playlists)
    {
        if (Playlists->objectName().isEmpty())
            Playlists->setObjectName(QString::fromUtf8("Playlists"));
        Playlists->resize(400, 610);
        Playlists->setFocusPolicy(Qt::ClickFocus);
        centralwidget = new QWidget(Playlists);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 401, 32));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 70, 400, 515));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 30, 381, 31));
        textEdit->setOverwriteMode(false);
        Playlists->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Playlists);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Playlists->setStatusBar(statusbar);

        retranslateUi(Playlists);

        QMetaObject::connectSlotsByName(Playlists);
    } // setupUi

    void retranslateUi(QMainWindow *Playlists)
    {
        Playlists->setWindowTitle(QCoreApplication::translate("Playlists", "Playlists", nullptr));
        pushButton->setText(QCoreApplication::translate("Playlists", "Add new", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Playlists", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("Playlists", "Write here", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Playlists: public Ui_Playlists {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTS_H
