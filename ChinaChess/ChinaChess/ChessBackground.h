#pragma once
#include <QObject>
#include <QGraphicsItem>

class ChessBackground : public QObject, public QGraphicsItem {
	Q_OBJECT;
public:
	explicit ChessBackground(int width, QObject* parent);

	//QGraphicsItem interface
	virtual QRectF boundingRect() const; //虚函数重载继承自QGraphicsItem
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget); //虚函数重载自QGraphicsItem
	int m_width;
	int m_h_width;
	int m_v_width;
signals:

public slots:

};