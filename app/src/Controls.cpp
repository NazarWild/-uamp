//
// Created by Artem Shemidko on 12.12.2020.
//

#include "ui_mainwindow.h"
#include "Controls.h"

#include <QBoxLayout>
#include <QStyle>
#include <QToolButton>
#include <QComboBox>
#include <QAudio>
#include <QDial>


Controls::Controls(QWidget *parent, Ui::MainWindow *ui)
        : QWidget(parent)
        , ui(ui) {
    ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    connect(ui->playButton, &QAbstractButton::clicked, this, &Controls::playClicked);

    ui->nextButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    connect(ui->nextButton, &QAbstractButton::clicked, this, &Controls::next);

    ui->previousButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));
    connect(ui->previousButton, &QAbstractButton::clicked, this, &Controls::previous);

    ui->dial->setRange(0, 100);
    connect(ui->dial, &QDial::valueChanged, this, &Controls::onVolumeDialValueChanged);

    ui->comboBox->setCurrentIndex(1);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::activated), this, &Controls::updateMode);

}

QMediaPlayer::State Controls::state() const {
    return m_playerState;
}

void Controls::setState(QMediaPlayer::State state) {
    if (state != m_playerState) {
        m_playerState = state;

        switch (state) {
            case QMediaPlayer::StoppedState:
                ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
                break;
            case QMediaPlayer::PlayingState:
                ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
                break;
            case QMediaPlayer::PausedState:
                ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
                break;
        }
    }
}

int Controls::volume() const {
    qreal linearVolume =  QAudio::convertVolume(ui->dial->value() / qreal(100),
                                                QAudio::LogarithmicVolumeScale,
                                                QAudio::LinearVolumeScale);

    return qRound(linearVolume * 100);
}

void Controls::setVolume(int volume) {
    qreal logarithmicVolume = QAudio::convertVolume(volume / qreal(100),
                                                    QAudio::LinearVolumeScale,
                                                    QAudio::LogarithmicVolumeScale);

    ui->dial->setValue(qRound(logarithmicVolume * 100));
}

void Controls::playClicked() {
    switch (m_playerState) {
        case QMediaPlayer::StoppedState:
        case QMediaPlayer::PausedState:
            emit play();
            break;
        case QMediaPlayer::PlayingState:
            emit pause();
            break;
    }
}

QMediaPlaylist::PlaybackMode Controls::playbackMode() const {
    switch(ui->comboBox->currentIndex()) {
        case 0:
            return QMediaPlaylist::Loop;
        case 1:
            return QMediaPlaylist::CurrentItemInLoop;
        case 2:
            return QMediaPlaylist::Random;
    }
    return m_mode;
}

void Controls::setPlaybackMode(QMediaPlaylist::PlaybackMode mode) {
    m_mode = mode;
}

void Controls::onVolumeDialValueChanged() {
    emit changeVolume(volume());
}

void Controls::updateMode() {
    emit changeMode(playbackMode());
}


