/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionOpen_Folder;
    QAction *actionOpen_File;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *trackName;
    QLabel *authorName;
    QLabel *albumImage;
    QSlider *horizontalSlider;
    QLabel *music_start_timer;
    QLabel *trackLength;
    QPushButton *nextButton;
    QPushButton *forwardButton;
    QPushButton *playButton;
    QPushButton *rewindButton;
    QPushButton *previousButton;
    QComboBox *comboBox;
    QToolButton *toolButton;
    QTreeView *treeView;
    QTreeView *treeView_2;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOpen;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1149, 594);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(650, 300));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setAcceptDrops(true);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionOpen_Folder = new QAction(MainWindow);
        actionOpen_Folder->setObjectName(QString::fromUtf8("actionOpen_Folder"));
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QString::fromUtf8("actionOpen_File"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(153, 153, 153, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(37, 37, 37, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        centralWidget->setPalette(palette);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        centralWidget->setFont(font);
        centralWidget->setAutoFillBackground(true);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(250, 0, 900, 571));
        trackName = new QLabel(groupBox);
        trackName->setObjectName(QString::fromUtf8("trackName"));
        trackName->setGeometry(QRect(310, 10, 271, 20));
        trackName->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        authorName = new QLabel(groupBox);
        authorName->setObjectName(QString::fromUtf8("authorName"));
        authorName->setGeometry(QRect(280, 30, 331, 31));
        authorName->setAlignment(Qt::AlignCenter);
        albumImage = new QLabel(groupBox);
        albumImage->setObjectName(QString::fromUtf8("albumImage"));
        albumImage->setGeometry(QRect(245, 70, 401, 311));
        albumImage->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(110, 400, 650, 20));
        horizontalSlider->setMaximum(99);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        music_start_timer = new QLabel(groupBox);
        music_start_timer->setObjectName(QString::fromUtf8("music_start_timer"));
        music_start_timer->setGeometry(QRect(90, 430, 59, 16));
        music_start_timer->setAlignment(Qt::AlignCenter);
        trackLength = new QLabel(groupBox);
        trackLength->setObjectName(QString::fromUtf8("trackLength"));
        trackLength->setGeometry(QRect(730, 430, 59, 16));
        trackLength->setAlignment(Qt::AlignCenter);
        nextButton = new QPushButton(groupBox);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(620, 500, 60, 50));
        forwardButton = new QPushButton(groupBox);
        forwardButton->setObjectName(QString::fromUtf8("forwardButton"));
        forwardButton->setGeometry(QRect(520, 500, 60, 50));
        playButton = new QPushButton(groupBox);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(420, 500, 60, 50));
        rewindButton = new QPushButton(groupBox);
        rewindButton->setObjectName(QString::fromUtf8("rewindButton"));
        rewindButton->setGeometry(QRect(320, 500, 60, 50));
        previousButton = new QPushButton(groupBox);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));
        previousButton->setGeometry(QRect(220, 500, 60, 50));
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 505, 100, 40));
        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(750, 510, 40, 30));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(0, 0, 250, 350));
        treeView_2 = new QTreeView(centralWidget);
        treeView_2->setObjectName(QString::fromUtf8("treeView_2"));
        treeView_2->setGeometry(QRect(0, 350, 250, 220));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 350, 250, 20));
        label->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1149, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOpen = new QMenu(menuFile);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuOpen->addAction(actionOpen_Folder);
        menuOpen->addSeparator();
        menuOpen->addAction(actionOpen_File);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "utext", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_Folder->setText(QCoreApplication::translate("MainWindow", "Open Folder", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_Folder->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_File->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen_File->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox->setTitle(QString());
        trackName->setText(QCoreApplication::translate("MainWindow", "Track", nullptr));
        authorName->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        albumImage->setText(QString());
        music_start_timer->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        trackLength->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        nextButton->setText(QString());
        forwardButton->setText(QString());
        playButton->setText(QString());
        rewindButton->setText(QString());
        previousButton->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Loop all", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Loop one", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Shuffle all", nullptr));

        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Recently used", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
