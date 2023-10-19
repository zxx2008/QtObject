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

    //newһ��ý�岥�Ŷ���
    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setVolume(30);
    ui.verticalSlider->setRange(0, 100);
    ui.verticalSlider->setValue(30);
    
    //��ȡ��ǰý���ʱ��
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, [this](qint64 duration) {
        ui.totalLabel->setText(QString("%1:%2").arg(duration / 1000 / 60, 2, 10, QChar('0')).arg(duration / 1000 % 60, 2, 10, QChar('0')));
        ui.horizontalSlider->setRange(0, duration);
        });

    //��ȡ��ǰ���ŵ�ʱ��
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, [this](qint64 pos) {
        ui.curLabel->setText(QString("%1:%2").arg(pos / 1000 / 60, 2, 10, QChar('0')).arg(pos / 1000 % 60, 2, 10, QChar('0')));
        ui.horizontalSlider->setValue(pos);
        });

    //�϶����飬�����ֲ��ŵĽ��ȸı�
    connect(ui.horizontalSlider, &QSlider::sliderMoved, mediaPlayer, &QMediaPlayer::setPosition);

    connect(ui.verticalSlider, &QSlider::sliderMoved, mediaPlayer, &QMediaPlayer::setVolume);
}

void MusicPlayer::on_pushButton_clicked() {
    //qInfo() << "Hello";
    //���ļ��Ի������û�ѡ���������ڵ�Ŀ¼
    QString path = QFileDialog::getExistingDirectory(this, "��ѡ���������ڵ�Ŀ¼", "D:/");
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
    for (auto& str : musicList) {
        musicPath.append(str);
    }
    qInfo() << musicPath;
    
    ui.listWidget->setCurrentRow(0); 
    //qInfo() << playList;
    
}

//���ŵ�ǰѡ�е�����,����������ڲ�������ֹͣ
void MusicPlayer::on_pushButton_3_clicked() {
    //��һ��������
    if (playList.empty()) {
        return;
    }
    switch (mediaPlayer->state()) {
    case QMediaPlayer::StoppedState:
        //��ȡѡ�е��к�
        curPlayIndex = ui.listWidget->currentRow();
        mediaPlayer->setMedia(playList[curPlayIndex]);
        mediaPlayer->play();
        openLrc();
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
    openLrc();
}

//������һ��
void MusicPlayer::on_pushButton_5_clicked() {
    curPlayIndex = (curPlayIndex - 1) % playList.size();
    ui.listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setMedia(playList[curPlayIndex]);
    mediaPlayer->play();
    openLrc();
}

//�Ӳ����б�ѡ�񲥷�
void MusicPlayer::on_listWidget_doubleClicked(const QModelIndex& index) {
    curPlayIndex = index.row();
    ui.listWidget->setCurrentRow(curPlayIndex);
    mediaPlayer->setMedia(playList[curPlayIndex]);
    mediaPlayer->play();
    openLrc();
}

void MusicPlayer::openLrc() {
    //ѡ����·��
    qInfo() << playList[curPlayIndex].toString();
    qInfo() << QFileInfo(musicPath[curPlayIndex]).absolutePath();
    QString path = QFileInfo(musicPath[curPlayIndex]).absolutePath() + "/lrc/" + getFileName(playList[curPlayIndex]) + ".txt";
    qInfo() << path;
    QFile lrcFile(path);
    ui.listWidget_2->clear();
    if (lrcFile.open(QIODevice::ReadOnly)) {
        //����ļ��򿪳ɹ�
        qInfo() << "lrc File Open Success";
    }
    else {
        //����ļ���ʧ��
        qInfo() << "lrc File Open Fail";
    }
    QList<QString> musicLrc;
    
}

QString getFileName(QUrl url) {
    qInfo() << QFileInfo(url.toString()).baseName();
    return QFileInfo(url.toString()).baseName();
}