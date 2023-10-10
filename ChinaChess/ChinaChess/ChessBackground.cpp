#include "ChessBackground.h"
#include <QPainter>

ChessBackground::ChessBackground(int width, QObject* parent) : QObject(parent), m_width(width) {
	m_h_width = width / 10;
	m_v_width = width / 10;
	m_v_width = width / 10;
}
