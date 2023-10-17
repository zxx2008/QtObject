#include "MusicPlayer.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>

MusicPlayer::MusicPlayer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.pushButton_2->setIcon(QIcon(":/C:/Users/Zu XiXin/Downloads/option.svg"));
    ui.pushButton_5->setIcon(QIcon(":/C:/Users/Zu XiXin/Downloads/last.svg"));
    ui.pushButton_3->setIcon(QIcon(":/C:/Users/Zu XiXin/Downloads/play.svg"));
    ui.pushButton_4->setIcon(QIcon(":/C:/Users/Zu XiXin/Downloads/next.svg"));
    ui.pushButton_6->setIcon(QIcon(":/C:/Users/Zu XiXin/Downloads/volume.svg"));
    //new一个output对象
    //QAudioOutput* audioOutput = new QAudioOutput(QAudioFormat(), this);
    //new一个媒体播放对象
    mediaPlayer = new QMediaPlayer(this);
    //mediaPlayer->setMedia(QUrl::fromLocalFile("D:/workspace/MyNote/QtObject/MusicPlayer/Numb-Linkin Park.128.mp3"));
    //mediaPlayer->setVolume(30);
    //mediaPlayer->play();
}

void MusicPlayer::on_pushButton_clicked() {
    //qInfo() << "Hello";
    //打开文件对话框，让用户选择音乐所在的目录
    QString path = QFileDialog::getExistingDirectory(this, "请选择音乐所在的目录", "C:/");
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