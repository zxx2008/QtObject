#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChinaChess.h"

class ChinaChess : public QMainWindow
{
    Q_OBJECT

public:
    ChinaChess(QWidget *parent = Q_NULLPTR);

private:
    Ui::ChinaChessClass ui;
};
