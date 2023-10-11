#pragma once
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif
#include <QObject>
#include <QGraphicsItem>
#include "common.h"

class ChessMan : public QObject, public QGraphicsItem {
	Q_OBJECT;
public:
	explicit ChessMan(int width, ChessType type, QObject* parent = 0);
	bool getLive();		//判断棋子是否存活
	void setLive(bool live);   //设置棋子的存活状态
	void setSelectedStatus(bool status);	//设置棋子的被选择状态
	bool getSelectedStatus();		//获得棋子是否被选择
	ChessType getChessType();		//获得棋子的类型
	void initPos();					//棋子回到原位
	void Move(int x, int y);		//移动棋子
	int getX();       //获得棋子的X
	int getY();       //获得棋子的Y
	virtual QRectF boundingRect() const; //虚函数重载
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	
	//以下是画各类棋子的函数 B表示黑色棋子 R表示红色棋子
	void paintCheB(QPainter* painter);
	void paintMaB(QPainter* painter);
	void paintXiangB(QPainter* painter);
	void paintShiB(QPainter* painter);
	void paintJiangB(QPainter* painter);
	void paintPaoB(QPainter* painter);
	void paintBingB(QPainter* painter);

	void paintCheR(QPainter* painter);
	void paintMaR(QPainter* painter);
	void paintXiangR(QPainter* painter);
	void paintShiR(QPainter* painter);
	void paintJiangR(QPainter* painter);
	void paintPaoR(QPainter* painter);
	void paintBingR(QPainter* painter);

	//画黑色棋子
	void paintBlackChess(QPainter* painter, QString str);
	//画红色棋子
	void paintRedChess(QPainter* painter, QString str);
private:
	int m_x;	
	int m_y;	//棋子在棋盘上的坐标
	ChessType m_type; //棋子的类型
	int m_width;
	bool m_Selectedstatus;   //棋子是否为选中状态
	bool m_isLive;			//棋子是否存活
signals:
	void sigClick();
};
