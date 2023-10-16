#include "MusicPlayer.h"
#include <QMediaPlayer>
#include <QAudioOutput>

MusicPlayer::MusicPlayer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QAudioOutput* audioOutput = new QAudioOutput(this);
    QMediaPlayer* mediaPlayer = new QMediaPlayer(this);
}
