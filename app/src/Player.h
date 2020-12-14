//
// Created by Artem Shemidko on 12.12.2020.
//

#ifndef UAMP_PLAYER_H
#define UAMP_PLAYER_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QLabel>
#include <QSlider>
#include "Controls.h"

#define defaultCoverImage "./app/resources/music_anonim.svg"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Player : public QWidget {
Q_OBJECT
public:
    explicit Player(QWidget *parent = nullptr, Ui::MainWindow *ui = nullptr);

    void updateDurationInfo(qint64 currentInfo);
    void addToPlaylist(const QList<QUrl> &urls);
    void deleteFromPlaylist(int pos);

private:
    void handleCursor(QMediaPlayer::MediaStatus status);

private slots:
    void durationAboutToChanged(qint64 duration);
    void positionAboutToChanged(qint64 progress);
    void metaDataAboutToChanged();

    void previousClicked();

    void seek(int seconds);
    void playlistPositionChanged(int);

    void statusChanged(QMediaPlayer::MediaStatus status);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *m_player{Q_NULLPTR};
    QMediaPlaylist *m_playlist{Q_NULLPTR};
    Controls *controls{Q_NULLPTR};
    qint64 m_duration;
};


#endif //UAMP_PLAYER_H
