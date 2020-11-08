#pragma once

#include <QMainWindow>
#include <QMenuBar>
#include <QFileDialog>
#include <QTextStream>
#include <QDir>
#include <QFileSystemModel>
#include <QApplication>
#include <QMessageBox>
#include <QWidget>
#include <QTreeWidget>
#include <QPushButton>
#include <QStringList>
#include <QModelIndex>
#include <QResizeEvent>
#include <QDebug>
#include <QFileInfo>
#include <QPlainTextEdit>
#include <QPalette>
#include <QLabel>
#include <QMediaPlayer>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include <tag.h>
#include <tagutils.h>
#include <tagunion.h>
#include <fileref.h>
#include <taglib_export.h>
#include <audioproperties.h>

#include "main_lib.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString rightTimeChange(int sec);

private slots: // all actions 
    void on_actionOpen_Folder_triggered(); 

    void on_actionOpen_File_triggered();

    void on_horizontalSlider_valueChanged(int value);

    // void on_actionSave_triggered();

    // void on_actionSave_as_triggered();

    void playMusic();

    void elementClicked(const QModelIndex& current);

private:
    Ui::MainWindow *ui;
    QString m_path_file;
    QString m_path_dir;
    QFileSystemModel *m_model;
    QMediaPlayer *m_player;
};
