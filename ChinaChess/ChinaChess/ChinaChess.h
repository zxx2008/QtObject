#pragma once
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif
#include <QtWidgets/QMainWindow>
#include "ui_ChinaChess.h"
#include "ChessBackground.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "chess_man.h"

class ChinaChess : public QMainWindow
{
    Q_OBJECT

public:
    ChinaChess(QWidget *parent = Q_NULLPTR);
    ~ChinaChess();
private:
    Ui::ChinaChessClass ui;
    QGraphicsView* m_ptrMainView;
    QGraphicsScene* m_ptrMainScene;
    ChessBackground* nk;
    QList<ChessMan*> m_lstChess;
};
