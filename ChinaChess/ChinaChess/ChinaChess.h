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
    void initGameData();    //��ʼ����Ϸ���ݣ�����Ϸ���˵���ʼ״̬
    QPoint getSelectedChess();  //�Ƿ��Ѿ������ӱ�ѡ�У�����з���QPoint
    RoleType getRole();     //��ȡ��ǰ��ɫ
    QPoint getChessboardCoordinates(int mouse_x, int mouse_y);  //ͨ������ȡ���̵������

    //ѡ��ָ�����������
    void clearSelectChess();
    void selectChess(int x, int y);
    ChessMan* getChess(int x, int y);   // ͨ������������
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
