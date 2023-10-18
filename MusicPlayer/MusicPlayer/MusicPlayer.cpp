#include "MusicPlayer.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QString>

MusicPlayer::MusicPlayer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.pushButton_2->setIcon(QIcon(":/option.svg"));
    ui.pushButton_5->setIcon(QIcon(":/last.svg"));
    ui.pushButton_3->setIcon(QIcon(":/play.svg"));
    ui.pushButton_4->setIcon(QIcon(":/next.svg"));
    ui.pushButton_6->setIcon(QIcon(":/volume.svg"));

    //new一个媒体播放对象
    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setVolume(30);
    ui.verticalSlider->setRange(0, 100);
    ui.verticalSlider->setValue(30);
    
    //获取当前媒体的时长
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, [this](qint64 duration) {
        ui.totalLabel->setText(QString("%1:%2").arg(duration / 1000 / 60, 2, 10, QChar('0')).arg(duration / 1000 % 60, 2, 10, QChar('0')));
        ui.horizontalSlider->setRange(0, duration);
        });

    //获取当前播放的时长
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, [this](qint64 pos) {
        ui.curLabel->setText(QString("%1:%2").arg(pos / 1000 / 60, 2, 10, QChar('0')).arg(pos / 1000 % 60, 2, 10, QChar('0')));
        ui.horizontalSlider->setValue(pos);
        });

    //拖动滑块，让音乐播放的进度改变
    connect(ui.horizontalSlider, &QSlider::sliderMoved, mediaPlayer, &QMediaPlayer::setPosition);

    connect(ui.verticalSlider, &QSlider::sliderMoved, mediaPlayer, &QMediaPlayer::setVolume);
}

void MusicPlayer::on_pushButton_clicked() {
    //qInfo() << "Hello";
    //打开文件对话框，让用户选择音乐所在的目录
    QString path = QFileDialog::getExistingDirectory(this, "请选择音乐所在的目录", "D:/");
    //qInfo() << path;
    //根据路径，获取文件夹下所有mp3,wav文件
    QDir dir(path);
    auto musicList = dir.entryList(QStringList() << "*.mp3" << "*.wav");
    mediaPlayer->stop();
    //将获取到的文件显示到QListWidget中
    ui.listWidget->clear();
    ui.listWidget->addItems(musicList);
    
    for each (auto &item in playList)
    {
        playList.removeOne(item);
    }
    //将音乐完整路径保存到playList中
    for (auto& file : musicList) {
        playList.append(QUrl::fromLocalFile(path + "/" + file));
    }

    
    ui.listWidget->setCurrentRow(0); 
    //qInfo() << playList;
    
}

//播放当前选中的音乐,如果现在正在播放音乐停止
void MusicPlayer::on_pushButton_3_clicked() {
    //作一个错误处理
    if (playList.empty()) {
        return;
    }
    switch (mediaPlayer->state()) {
    case QMediaPlayer::StoppedState:
        //获取选中的行号
        curPlayIndex = ui.listWidget->currentRow();
        mediaPlayer->setMedia(playList[curPlayIndex]);
        mediaPlayer->play();
        break;
    case QMediaPlayer::PlayingState:
        mediaPlayer->pause();
        break;
    case QMediaPlayer::PausedState:
        mediaPlayer->play();
        break;
    }
}

//播放下一首
void MusicPlayer::on_pushButton_4_clicked() {
    curPlayIndex = (curPlayIndex + 1) % playList.size();
    ui.listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setMedia(playList[curPlayIndex]);
    mediaPlayer->play();
}

//播放上一首
void MusicPlayer::on_pushButton_5_clicked() {
    curPlayIndex = (curPlayIndex - 1) % playList.size();
    ui.listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setMedia(playList[curPlayIndex]);
    mediaPlayer->play();
}

//从播放列表选择播放
void MusicPlayer::on_listWidget_doubleClicked(const QModelIndex& index) {
    curPlayIndex = index.row();
    ui.listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setMedia(playList[curPlayIndex]);
    mediaPlayer->play();
}