//
// Created by Artem Shemidko on 12.12.2020.
//
#include "ui_mainwindow.h"
#include "Player.h"
#include <QTime>
#include <QCursor>
#include <QApplication>
#include <QFileInfo>
#include <QtMultimedia>
#include "Controls.h"

#include <fileref.h>
#include <attachedpictureframe.h>
#include <mpegfile.h>
#include <id3v2tag.h>
#include <QString>
#include <QPixmap>


Player::Player(QWidget *parent, Ui::MainWindow *ui)
        : QWidget(parent)
        , ui(ui) {
    m_player = new QMediaPlayer(this);
    m_player->setAudioRole(QAudio::MusicRole);
    m_playlist = new QMediaPlaylist(m_player);
    m_player->setPlaylist(m_playlist);
    controls = new Controls(dynamic_cast<QWidget *>(parent), ui);

    controls->setState(m_player->state());
    controls->setVolume(m_player->volume());

    connect(m_player, &QMediaPlayer::durationChanged, this, &Player::durationAboutToChanged);
    connect(m_player, &QMediaPlayer::positionChanged, this, &Player::positionAboutToChanged);
    connect(m_player, QOverload<>::of(&QMediaPlayer::metaDataChanged), this, &Player::metaDataAboutToChanged);
    connect(m_playlist, &QMediaPlaylist::currentIndexChanged, this, &Player::playlistPositionChanged);
    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, &Player::statusChanged);
    connect(ui->horizontalSlider, &QSlider::sliderMoved, this, &Player::seek);

    connect(controls, &Controls::play, m_player, &QMediaPlayer::play);
    connect(controls, &Controls::pause, m_player, &QMediaPlayer::pause);
    connect(controls, &Controls::next, m_playlist, &QMediaPlaylist::next);
    connect(controls, &Controls::previous, this, &Player::previousClicked);
    connect(controls, &Controls::changeVolume, m_player, &QMediaPlayer::setVolume);
    connect(controls, &Controls::changeMode, m_playlist, &QMediaPlaylist::setPlaybackMode);

    connect(m_player, &QMediaPlayer::stateChanged, controls, &Controls::setState);
    connect(m_player, &QMediaPlayer::volumeChanged, controls, &Controls::setVolume);
}

void Player::durationAboutToChanged(qint64 duration) {
    m_duration = duration / 1000;
    ui->horizontalSlider->setMaximum(m_duration);
}

void Player::positionAboutToChanged(qint64 progress) {
    if (!ui->horizontalSlider->isSliderDown())
        ui->horizontalSlider->setValue(progress / 1000);
    updateDurationInfo(progress / 1000);
}

void Player::updateDurationInfo(qint64 currentInfo) {
    QString currStr;
    QString totalStr;
    if (currentInfo || m_duration) {
        QTime currentTime((currentInfo / 3600) % 60, (currentInfo / 60) % 60,
                          currentInfo % 60, (currentInfo * 1000) % 1000);
        QTime totalTime((m_duration / 3600) % 60, (m_duration / 60) % 60,
                        m_duration % 60, (m_duration * 1000) % 1000);
        QString format = "mm:ss";
        if (m_duration > 3600)
            format = "hh:mm:ss";
        currStr = currentTime.toString(format);
        totalStr = totalTime.toString(format);
    }
    ui->music_start_timer->setText(currStr);
    ui->trackLength->setText(totalStr);
}

void Player::statusChanged(QMediaPlayer::MediaStatus status) {
    handleCursor(status);

    // handle status message
    switch (status) {
        case QMediaPlayer::UnknownMediaStatus:
        case QMediaPlayer::NoMedia:
        case QMediaPlayer::LoadedMedia:
            qDebug() << "Audio has loaded";
            break;
        case QMediaPlayer::LoadingMedia:
            qDebug() << "Audio loading";
            break;
        case QMediaPlayer::BufferingMedia:
        case QMediaPlayer::BufferedMedia:
            qDebug() << tr("Audio Buffering %1%").arg(m_player->bufferStatus());
            break;
        case QMediaPlayer::StalledMedia:
            qDebug() << tr("Audio Stalled %1%").arg(m_player->bufferStatus());
            break;
        case QMediaPlayer::EndOfMedia:
            QApplication::alert(this);
            break;
        case QMediaPlayer::InvalidMedia:
            qDebug() << "Invalid Audio";
            break;
    }
}

void Player::handleCursor(QMediaPlayer::MediaStatus status) {
#ifndef QT_NO_CURSOR
    if (status == QMediaPlayer::LoadingMedia ||
        status == QMediaPlayer::BufferingMedia ||
        status == QMediaPlayer::StalledMedia)
        setCursor(QCursor(Qt::BusyCursor));
    else
        unsetCursor();
#endif
}

void Player::seek(int seconds) {
    m_player->setPosition(seconds * 1000);
}

void Player::previousClicked() {
    // Go to previous track if we are within the first 5 seconds of playback
    // Otherwise, seek to the beginning.
    if (m_player->position() <= 5000)
        m_playlist->previous();
    else
        m_player->setPosition(0);
}

static bool isPlaylist(const QUrl &url) { // Check for ".m3u" playlists.
    if (!url.isLocalFile())
        return false;
    const QFileInfo fileInfo(url.toLocalFile());
    return fileInfo.exists() && !fileInfo.suffix().compare(QLatin1String("m3u"), Qt::CaseInsensitive);
}

void Player::addToPlaylist(const QList<QUrl> &urls) {
    for (auto &url: urls) {
        if (isPlaylist(url))
            m_playlist->load(url);
        else {
            m_playlist->addMedia(QMediaContent(url));
        }
    }
}
void Player::metaDataAboutToChanged() {
    if (m_player->isMetaDataAvailable()) {
        ui->trackName->setText(m_player->metaData(QMediaMetaData::Title).toString());
        ui->authorName->setText(m_player->metaData(QMediaMetaData::AlbumArtist).toString());

        auto filePath = m_player->currentMedia().request().url().path();
        TagLib::MPEG::File audioFile(filePath.toStdString().c_str());
        TagLib::ID3v2::Tag *tag = audioFile.ID3v2Tag();
        TagLib::ID3v2::FrameList frames = tag->frameList("APIC");

        QPixmap pix;
        if (frames.isEmpty()) {
            pix = QPixmap(defaultCoverImage);
        }
        else {
            auto *coverImage =
                    dynamic_cast<TagLib::ID3v2::AttachedPictureFrame *>(frames.front());
            QImage cover;
            cover.loadFromData((const uchar *)coverImage->picture().data(), coverImage->picture().size());
            pix = QPixmap::fromImage(cover);
        }
        pix = pix.scaled(ui->albumImage->width(),
                         ui->albumImage->height(),
                         Qt::KeepAspectRatio,
                         Qt::SmoothTransformation);
        ui->albumImage->setPixmap(pix);
    }
}

void Player::playlistPositionChanged(int currentItem) {
    ui->listWidget->setCurrentRow(currentItem);
}