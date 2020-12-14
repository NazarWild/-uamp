//
// Created by Artem Shemidko on 12.12.2020.
//

#ifndef UAMP_CONTROLS_H
#define UAMP_CONTROLS_H

#include <QMediaPlayer>
#include <QWidget>
#include <QMediaPlaylist>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class Controls : public QWidget
{
    Q_OBJECT

public:
    explicit Controls(QWidget *parent = nullptr, Ui::MainWindow *ui = nullptr);

    [[nodiscard]] QMediaPlayer::State state() const;
    [[nodiscard]] int volume() const;
    [[nodiscard]] QMediaPlaylist::PlaybackMode playbackMode() const;


public slots:
    void setState(QMediaPlayer::State state);
    void setVolume(int volume);
    void setPlaybackMode(QMediaPlaylist::PlaybackMode mode);

signals:
    void play();
    void pause();
    void stop();
    void next();
    void previous();

    void changeVolume(int volume);
    void changeMode(QMediaPlaylist::PlaybackMode mode);

private slots:
    void playClicked();
    void updateMode();
    void onVolumeDialValueChanged();

private:
    Ui::MainWindow *ui;
    QMediaPlayer::State m_playerState = QMediaPlayer::StoppedState;
    QMediaPlaylist::PlaybackMode m_mode = QMediaPlaylist::Sequential;
};


#endif //UAMP_CONTROLS_H
