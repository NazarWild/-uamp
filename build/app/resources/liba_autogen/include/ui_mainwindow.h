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
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
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
    QAction *actionRecently_opened;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *trackName;
    QLabel *authorName;
    QLabel *albumImage;
    QSlider *horizontalSlider;
    QLabel *music_start_timer;
    QLabel *trackLength;
    QPushButton *nextButton;
    QPushButton *playButton;
    QPushButton *previousButton;
    QComboBox *comboBox;
    QPushButton *playlists;
    QDial *dial;
    QTableView *tableView;
    QListWidget *listWidget;
    QTreeView *treeView;
    QLabel *label;
    QLabel *label_2;
    QFrame *line_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOpen;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1145, 610);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        MainWindow->setAcceptDrops(true);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionOpen_Folder = new QAction(MainWindow);
        actionOpen_Folder->setObjectName(QString::fromUtf8("actionOpen_Folder"));
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QString::fromUtf8("actionOpen_File"));
        actionRecently_opened = new QAction(MainWindow);
        actionRecently_opened->setObjectName(QString::fromUtf8("actionRecently_opened"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        QPalette palette;
        QBrush brush(QColor(204, 204, 204, 255));
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
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(250, 0, 900, 591));
        trackName = new QLabel(groupBox);
        trackName->setObjectName(QString::fromUtf8("trackName"));
        trackName->setGeometry(QRect(210, 10, 350, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Andale Mono"));
        font1.setPointSize(13);
        trackName->setFont(font1);
        trackName->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        authorName = new QLabel(groupBox);
        authorName->setObjectName(QString::fromUtf8("authorName"));
        authorName->setGeometry(QRect(210, 30, 350, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Apple Braille"));
        font2.setPointSize(8);
        authorName->setFont(font2);
        authorName->setAlignment(Qt::AlignCenter);
        albumImage = new QLabel(groupBox);
        albumImage->setObjectName(QString::fromUtf8("albumImage"));
        albumImage->setGeometry(QRect(150, 10, 50, 50));
        albumImage->setText(QString::fromUtf8(""));
        albumImage->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(140, 80, 621, 20));
        QPalette palette1;
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(230, 230, 230, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        horizontalSlider->setPalette(palette1);
        horizontalSlider->setMaximum(99);
        horizontalSlider->setSliderPosition(0);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        music_start_timer = new QLabel(groupBox);
        music_start_timer->setObjectName(QString::fromUtf8("music_start_timer"));
        music_start_timer->setGeometry(QRect(120, 110, 59, 16));
        music_start_timer->setAlignment(Qt::AlignCenter);
        trackLength = new QLabel(groupBox);
        trackLength->setObjectName(QString::fromUtf8("trackLength"));
        trackLength->setGeometry(QRect(730, 110, 59, 16));
        trackLength->setAlignment(Qt::AlignCenter);
        nextButton = new QPushButton(groupBox);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(700, 20, 50, 40));
        playButton = new QPushButton(groupBox);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(640, 20, 50, 40));
        previousButton = new QPushButton(groupBox);
        previousButton->setObjectName(QString::fromUtf8("previousButton"));
        previousButton->setGeometry(QRect(580, 20, 50, 40));
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 70, 100, 40));
        playlists = new QPushButton(groupBox);
        playlists->setObjectName(QString::fromUtf8("playlists"));
        playlists->setGeometry(QRect(30, 10, 60, 50));
        dial = new QDial(groupBox);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(810, 20, 60, 60));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 145, 900, 441));
        tableView->setGridStyle(Qt::DotLine);
        tableView->setSortingEnabled(true);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 19, 250, 280));
        listWidget->setDragDropMode(QAbstractItemView::DragDrop);
        listWidget->setDefaultDropAction(Qt::MoveAction);
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(0, 320, 250, 265));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 300, 250, 20));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 250, 20));
        label_2->setAlignment(Qt::AlignCenter);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(240, 0, 20, 591));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1145, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOpen = new QMenu(menuFile);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionRecently_opened);
        menuOpen->addAction(actionOpen_Folder);
        menuOpen->addSeparator();
        menuOpen->addAction(actionOpen_File);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "uamp", nullptr));
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
        actionRecently_opened->setText(QCoreApplication::translate("MainWindow", "Recently opened", nullptr));
#if QT_CONFIG(shortcut)
        actionRecently_opened->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox->setTitle(QString());
        trackName->setText(QCoreApplication::translate("MainWindow", "Track", nullptr));
        authorName->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        music_start_timer->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        trackLength->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        nextButton->setText(QString());
        playButton->setText(QString());
        previousButton->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Loop all", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Loop one", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Shuffle all", nullptr));

        playlists->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Library", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Queue", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
