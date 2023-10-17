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
    QStringList musicList = dir.entryList(QStringList() << "*mp3" << "*wav");
    //qInfo() << musicList;
    //����ȡ�����ļ���ʾ��QListWidget��
    ui.listWidget->addItems(musicList);
    //Ĭ��ѡ�е�һ������
    ui.listWidget->setCurrentRow(0); 
    //����������·�����浽playList��
    for (auto& file : musicList) {
        playList.append(QUrl::fromLocalFile(path + "/" + file));
    }
    //qInfo() << playList;
    
}

//���ŵ�ǰѡ�е�����
void MusicPlayer::on_pushButton_3_clicked() {
    //��ȡѡ�е��к�
    int index = ui.listWidget->currentRow();

}
