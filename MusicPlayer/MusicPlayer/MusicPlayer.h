#pragma once

#include <QtWidgets/QMainWindow>
#include <QUrl>
#include "ui_MusicPlayer.h"
#include <QMediaPlayer>

class QMediaplayer;

class MusicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    MusicPlayer(QWidget *parent = Q_NULLPTR);
    void openLrc(); //导入歌词

public slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::MusicPlayerClass ui;
    QList<QUrl> playList;
    QMediaPlayer* mediaPlayer;
    int curPlayIndex = 0;
    QList<QString> musicPath;
};

QString getFileName(QUrl url);  //从URL中获取文件名