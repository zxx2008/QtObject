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
    //newһ��output����
    //QAudioOutput* audioOutput = new QAudioOutput(QAudioFormat(), this);
    //newһ��ý�岥�Ŷ���
    mediaPlayer = new QMediaPlayer(this);
    //mediaPlayer->setMedia(QUrl::fromLocalFile("D:/workspace/MyNote/QtObject/MusicPlayer/Numb-Linkin Park.128.mp3"));
    //mediaPlayer->setVolume(30);
    //mediaPlayer->play();
}

void MusicPlayer::on_pushButton_clicked() {
    //qInfo() << "Hello";
    //���ļ��Ի������û�ѡ���������ڵ�Ŀ¼
    QString path = QFileDialog::getExistingDirectory(this, "��ѡ���������ڵ�Ŀ¼", "C:/");
    //qInfo() << path;
    //����·������ȡ�ļ���������mp3,wav�ļ�
    QDir dir(path);
    auto musicList = dir.entryList(QStringList() << "*.mp3" << "*.wav");
    mediaPlayer->stop();
    //����ȡ�����ļ���ʾ��QListWidget��
    ui.listWidget->clear();
    ui.listWidget->addItems(musicList);
    
    for each (auto &item in playList)
    {
        playList.removeOne(item);
    }
    //����������·�����浽playList��
    for (auto& file : musicList) {
        playList.append(QUrl::fromLocalFile(path + "/" + file));
    }

    
    ui.listWidget->setCurrentRow(0); 
    //qInfo() << playList;
    
}

//���ŵ�ǰѡ�е�����,����������ڲ�������ֹͣ
void MusicPlayer::on_pushButton_3_clicked() {
    switch (mediaPlayer->state()) {
    case QMediaPlayer::StoppedState:
        //��ȡѡ�е��к�
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

//������һ��
void MusicPlayer::on_pushButton_4_clicked() {
    curPlayIndex = (curPlayIndex + 1) % playList.size();
    ui.listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setMedia(playList[curPlayIndex]);
    mediaPlayer->play();
}

//������һ��
void MusicPlayer::on_pushButton_5_clicked() {
    curPlayIndex = (curPlayIndex - 1) % playList.size();
    ui.listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setMedia(playList[curPlayIndex]);
    mediaPlayer->play();
}

//�Ӳ����б�ѡ�񲥷�
void MusicPlayer::on_listWidget_doubleClicked(const QModelIndex& index) {
    curPlayIndex = index.row();
    ui.listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setMedia(playList[curPlayIndex]);
    mediaPlayer->play();
}