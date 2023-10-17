#pragma once

#include <QtWidgets/QMainWindow>
#include <QUrl>
#include "ui_MusicPlayer.h"

class QMediaplayer;

class MusicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    MusicPlayer(QWidget *parent = Q_NULLPTR);

public slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::MusicPlayerClass ui;
    QList<QUrl> playList;
    QMediaPlayer* mediaPlayer;
};
