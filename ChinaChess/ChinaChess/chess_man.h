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
	bool getLive();		//�ж������Ƿ���
	void setLive(bool live);   //�������ӵĴ��״̬
	void setSelectedStatus(bool status);	//�������ӵı�ѡ��״̬
	bool getSelectedStatus();		//��������Ƿ�ѡ��
	ChessType getChessType();		//������ӵ�����
	void initPos();					//���ӻص�ԭλ
	void Move(int x, int y);		//�ƶ�����
	int getX();       //������ӵ�X
	int getY();       //������ӵ�Y
	virtual QRectF boundingRect() const; //�麯������
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	
	//�����ǻ��������ӵĺ��� B��ʾ��ɫ���� R��ʾ��ɫ����
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

	//����ɫ����
	void paintBlackChess(QPainter* painter, QString str);
	//����ɫ����
	void paintRedChess(QPainter* painter, QString str);
private:
	int m_x;	
	int m_y;	//�����������ϵ�����
	ChessType m_type; //���ӵ�����
	int m_width;
	bool m_Selectedstatus;   //�����Ƿ�Ϊѡ��״̬
	bool m_isLive;			//�����Ƿ���
signals:
	void sigClick();
};
