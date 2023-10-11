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
    void initGameData();    //初始化游戏数据，将游戏回退到初始状态
    QPoint getSelectedChess();  //是否已经有棋子被选中，如果有返回QPoint
    RoleType getRole();     //获取当前角色
    QPoint getChessboardCoordinates(int mouse_x, int mouse_y);  //通过鼠标获取棋盘的坐标点

    //选中指定坐标的棋子
    void clearSelectChess();
    void selectChess(int x, int y);
    ChessMan* getChess(int x, int y);   // 通过坐标获得棋子
    void MoveChess(ChessMan* chess, int x, int y);
    void MoveData(ChessMan* chess, int x, int y);

    bool MoveBindR(ChessMan* chess, int x, int y);
    bool MoveBindB(ChessMan* chess, int x, int y);
    bool MoveXiangR(ChessMan* chess, int x, int y);
    bool MoveXiangB(ChessMan* chess, int x, int y);
    bool MoveShiR(ChessMan* chess, int x, int y);
    bool MoveShiB(ChessMan* chess, int x, int y);
    bool MoveChe(ChessMan* chess, int x, int y);
    bool MoveMa(ChessMan* chess, int x, int y);
    bool MovePao(ChessMan* chess, int x, int y);
    bool MoveJiangR(ChessMan* chess, int x, int y);
    bool MoveJiangB(ChessMan* chess, int x, int y);

    GameType gameover();
private:
    Ui::ChinaChessClass ui;
    QGraphicsView* m_ptrMainView;
    QGraphicsScene* m_ptrMainScene;
    ChessBackground* nk;
    QList<ChessMan*> m_lstChess;
    RoleType m_Role;
    GameType m_gameType;

protected:
    void resizeEvent(QResizeEvent* event);
    void mousePressEvent(QMouseEvent* event);
};
