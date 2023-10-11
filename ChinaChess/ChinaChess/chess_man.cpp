#include "chess_man.h"
#include <QPainter>

ChessMan::ChessMan(int width, ChessType type, QObject* parent)
    : QObject(parent), m_type(type), m_width(width / 13), m_isLive(true), m_Selectedstatus(false) {}

bool ChessMan::getLive() { return m_isLive; }

void ChessMan::setLive(bool live) {
    m_isLive = live;
}

void ChessMan::setSelectedStatus(bool status) {
    m_Selectedstatus = status;
    update();
}

bool ChessMan::getSelectedStatus() {
    return m_Selectedstatus;
}

ChessType ChessMan::getChessType() {
    return m_type;
}

void ChessMan::Move(int x, int y) {
    m_x = x;
    m_y = y;
    this->setPos(g_top - g_chess_man_width / 2 + x * g_cell_width,
        g_left - g_chess_man_width / 2 + y * g_cell_width);
}

int ChessMan::getX() {
    return m_x;
}

int ChessMan::getY() {
    return m_y;
}

QRectF ChessMan::boundingRect() const {
    return QRectF(0, 0, m_width, m_width);
}

void ChessMan::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    if (!m_isLive) {
        return;
    }
    switch (m_type) {
    case Che_R:
        paintCheR(painter);
        break;
    case Ma_R:
        paintMaR(painter);
        break;
    case Xiang_R:
        paintXiangR(painter);
        break;
    case Shi_R:
        paintShiR(painter);
        break;
    case Jiang_R:
        paintJiangR(painter);
        break;
    case Pao_R:
        paintPaoR(painter);
        break;
    case Bing_R:
        paintBingR(painter);
        break;
    case Che_B:
        paintCheB(painter);
        break;
    case Ma_B:
        paintMaB(painter);
        break;
    case Xiang_B:
        paintXiangB(painter);
        break;
    case Shi_B:
        paintShiB(painter);
        break;
    case Jiang_B:
        paintJiangB(painter);
        break;
    case Pao_B:
        paintPaoB(painter);
        break;
    case Bing_B:
        paintBingB(painter);
        break;
    default:
        break;
    }
}

void ChessMan::paintBlackChess(QPainter* painter, QString str) {
    // �ȱ���ԭʼ��Brush���ڻ�ԭ
    QBrush b = painter->brush();
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::Qt4CompatiblePainting);
    painter->setBrush(QBrush(Qt::darkGreen, Qt::SolidPattern));
    painter->drawEllipse(0, 0, m_width, m_width);
    //��ԭbrush
    painter->setBrush(b);

    if (m_Selectedstatus) {
        //ѡ��״̬
        painter->setPen(QPen(Qt::blue, 3, Qt::SolidLine));
    }
    else {
        //δѡ��״̬
        painter->setPen(QPen(Qt::black, 3, Qt::SolidLine));
    }
    painter->drawEllipse(0, 0, m_width, m_width);
    painter->setPen(QPen(Qt::black, 3, Qt::SolidLine));
    painter->drawEllipse(6, 6, m_width - 12, m_width - 12);

    //�����ӿ���
    QFont font;     //���������������������
    font.setFamily("CESI����-GB13000"); //������ʽ
    font.setPixelSize(m_width * 0.35); // �����С
    painter->setFont(font);
    painter->setPen(QPen(Qt::black, 3, Qt::SolidLine));
    painter->drawText(0, 0, m_width, m_width, Qt::AlignCenter, str);
}

void ChessMan::paintRedChess(QPainter* painter, QString str) {
    QBrush b = painter->brush();
    painter->setRenderHints(QPainter::Antialiasing |
        QPainter::SmoothPixmapTransform |
        QPainter::Qt4CompatiblePainting);
    painter->setBrush(QBrush(Qt::darkGreen, Qt::SolidPattern));
    painter->drawEllipse(0, 0, m_width, m_width);
    painter->setBrush(b);
    if (m_Selectedstatus) {
        painter->setPen(QPen(Qt::blue, 3, Qt::SolidLine));
    }
    else {
        painter->setPen(QPen(QColor(163, 0, 0), 3, Qt::SolidLine));
    }
    painter->drawEllipse(0, 0, m_width, m_width);
    painter->setPen(QPen(QColor(163, 0, 0), 3, Qt::SolidLine));
    painter->drawEllipse(6, 6, m_width - 12, m_width - 12);

    QFont font;  //�������壬����������������
    font.setFamily("CESI����-GB13000");  //������ʽ
    font.setPointSize(m_width * 0.35);   //������С
    painter->setFont(font);
    painter->setPen(QPen(QColor(163, 0, 0), 3, Qt::SolidLine));
    painter->drawText(0, 0, m_width, m_width, Qt::AlignCenter, str);
}

void ChessMan::paintCheB(QPainter* painter) {
    paintBlackChess(painter, "��");
}

void ChessMan::paintMaB(QPainter* painter) {
    paintBlackChess(painter, "��");
}

void ChessMan::paintXiangB(QPainter* painter) {
    paintBlackChess(painter, "��");
}

void ChessMan::paintShiB(QPainter* painter) {
    paintBlackChess(painter, "ʿ");
}

void ChessMan::paintJiangB(QPainter* painter) {
    paintBlackChess(painter, "˧");
}

void ChessMan::paintPaoB(QPainter* painter) {
    paintBlackChess(painter, "��");
}

void ChessMan::paintBingB(QPainter* painter) {
    paintBlackChess(painter, "��");
}

void ChessMan::paintCheR(QPainter* painter) {
    paintRedChess(painter, "��");
}

void ChessMan::paintMaR(QPainter* painter) {
    paintRedChess(painter, "��");
}

void ChessMan::paintXiangR(QPainter* painter) {
    paintRedChess(painter, "��");
}

void ChessMan::paintShiR(QPainter* painter) {
    paintRedChess(painter, "ʿ");
}

void ChessMan::paintJiangR(QPainter* painter) {
    paintRedChess(painter, "˧");
}

void ChessMan::paintPaoR(QPainter* painter) {
    paintRedChess(painter, "��");
}

void ChessMan::paintBingR(QPainter* painter) {
    paintRedChess(painter, "��");
}