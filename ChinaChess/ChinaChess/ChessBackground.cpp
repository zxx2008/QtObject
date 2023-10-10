#include "ChessBackground.h"
#include <QPainter>

ChessBackground::ChessBackground(int width, QObject* parent) : QObject(parent), m_width(width) {
	m_h_width = width / 10;
	m_v_width = width / 10;
}

QRectF ChessBackground::boundingRect() const {
	return QRectF(0, 0, m_width, m_width);
}

void ChessBackground::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
	//画背景
	QPixmap pixmap;
	pixmap.load(":/bamboo.jpg");
	painter->drawPixmap(0, 0, pixmap);
	//画棋盘线条
	painter->setPen(QPen(QBrush(Qt::black), 1, Qt::SolidLine));
	int limit_i = 8;
	int limit_j = 9;
	int left = (m_width - limit_i * m_v_width) / 2; // 棋盘左侧离边界的距离
	int top = (m_width - limit_j * m_h_width) / 2;	//棋盘上侧离边界的距离
	//棋盘网格
	for (int i = 0; i <= limit_i; ++i) {
		if ((i == 0) | (i == limit_i)) {
			painter->drawLine(left + m_v_width * i, top + m_h_width * 0, left + m_v_width * i, top + m_h_width * 9);
		}
		else {
			painter->drawLine(left + m_v_width * i, top + m_h_width * 0, left + m_v_width * i, top + m_h_width * 4);
			painter->drawLine(left + m_v_width * i, top + m_h_width * 5, left + m_v_width * i, top + m_h_width * 9);
		}
	}
	for (int j = 0; j <= limit_j; ++j) {
		painter->drawLine(left + m_v_width * 0, top + m_h_width * j, left + m_v_width * 8, top + m_h_width * j);
	}
	
	//绘制士的移动路径
	painter->drawLine(left + m_v_width * 3, top + m_h_width * 0, left + m_v_width * 5, top + m_h_width * 2);
	painter->drawLine(left + m_v_width * 3, top + m_h_width * 2, left + m_v_width * 5, top + m_h_width * 0);
	painter->drawLine(left + m_v_width * 3, top + m_h_width * 7, left + m_v_width * 5, top + m_h_width * 9);
	painter->drawLine(left + m_v_width * 3, top + m_h_width * 9, left + m_v_width * 5, top + m_h_width * 7);

	//绘制棋盘外围粗边框
	int margin = 7;
	painter->setPen(QPen(QBrush(Qt::black), 4, Qt::SolidLine));
	painter->drawRect(left - margin, top - margin, m_v_width * 8 + margin * 2, m_h_width * 9 + margin * 2);
}
