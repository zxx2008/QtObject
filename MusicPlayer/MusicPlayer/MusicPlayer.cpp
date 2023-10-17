#include "MusicPlayer.h"
#include <QMediaPlayer>
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QListView>
#include <QStringListModel>

MusicPlayer::MusicPlayer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.pushButton_2->setIcon(QIcon(":/C:/Users/26659/Downloads/option.svg"));
    ui.pushButton_5->setIcon(QIcon(":/C:/Users/26659/Downloads/last.svg"));
    ui.pushButton_3->setIcon(QIcon(":/C:/Users/26659/Downloads/play.svg"));
    ui.pushButton_4->setIcon(QIcon(":/C:/Users/26659/Downloads/next.svg"));
    ui.pushButton_6->setIcon(QIcon(":/C:/Users/26659/Downloads/volume.svg"));
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
    QStringList musicList = dir.entryList(QStringList() << "*mp3" << "*wav");
    //qInfo() << musicList;
    //将获取到的文件显示到QListWidget中
    ui.listWidget->addItems(musicList);
    //默认选中第一个音乐
    ui.listWidget->setCurrentRow(0); 
    //将音乐完整路径保存到playList中
    for (auto& file : musicList) {
        playList.append(QUrl::fromLocalFile(path + "/" + file));
    }
    //qInfo() << playList;
    
}

//播放当前选中的音乐
void MusicPlayer::on_pushButton_3_clicked() {
    //获取选中的行号
    int index = ui.listWidget->currentRow();

}
