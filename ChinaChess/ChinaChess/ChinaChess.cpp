#include "ChinaChess.h"
#include <QDesktopWidget>
#include <QMouseEvent>

ChinaChess::ChinaChess(QWidget* parent)
    : QMainWindow(parent), m_ptrMainView(new QGraphicsView), m_ptrMainScene(new QGraphicsScene)
{
    ui.setupUi(this);

    //���ô���Ϊ�Ի������ʽ�����ɸı��С
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle(tr("�й�����"));

    //��ȡ���������С
    QRect clientRect = QApplication::desktop()->availableGeometry();

    //����View�Ĵ�С
    m_ptrMainView->setFixedSize(clientRect.height() - 200, clientRect.height() - 200);

    g_game_width = clientRect.height() - 200;
    g_cell_width = (g_game_width) / 10;
    g_top = (g_game_width - 8 * g_cell_width) / 2;
    g_left = (g_game_width - 9 * g_cell_width) / 2;
    g_chess_man_width = g_game_width / 13;

    //�����̱���
    nk = new ChessBackground(clientRect.height() - 200);
    //��ӵ�Scene��
    m_ptrMainScene->addItem(nk);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (maps[i][j] == NullChess) {
                continue;
            }
            ChessMan* chessman3 = new ChessMan(
                clientRect.height() - 200, static_cast<ChessType>(maps[i][j]));
            chessman3->Move(j, i);
            m_lstChess.push_back(chessman3);
            m_ptrMainScene->addItem(chessman3);
        }
    }

    //��View��ʾScene
    m_ptrMainView->setScene(m_ptrMainScene);
    setCentralWidget(m_ptrMainView);
}

ChinaChess::~ChinaChess() {}

//ͨ������ʹ��Ӧ������Ϊѡ��״̬
void ChinaChess::selectChess(int x, int y) {
    clearSelectChess();     //������е�����ѡ��״̬
    for (auto item : m_lstChess) {
        //�ҵ���Ӧ�����ж��Ƿ����������ܱ�ѡ��
        if (x == item->getX() && y == item->getY()) {
            //��Ҫ�ж���ѡ���������ɫ�Ƿ�ͳ��ӵķ���ɫ��ͬ
            if (m_Role == Red && item->getChessType() <= Bing_R) {
                item->setSelectedStatus(true);
            }
            else if (m_Role == Black && item->getChessType > Bing_R) {
                item->setSelectedStatus(true);
            }
        }
    }
}

void ChinaChess::clearSelectChess() {
    for (auto item : m_lstChess) {
        item->setSelectedStatus(false);
    }
}

void ChinaChess::mousePressEvent(QMouseEvent* event) {
    int x = -1, y = -1;
    //�������ѡ�е�λ�û�ȡ��������
    QPoint Coordinates = getChessboardCoordinates(event->x(), event->y());
    x = Coordinates.x();
    y = Coordinates.y();

    //��ѡ�����ӵ����
    if (this->getSelectedChess() != QPoint(-1, -1)) {
        if (m_Role == Red) {
            for (auto& item : m_lstChess) {
                if (x != -1 && y != -1 && item->getX() == x && item->getY() == y && item->getChessType() <= Bing_R) {
                    selectChess(x, y);
                    return;
                }
            }
        }
        else if (m_Role == Black) {
            
        }
    }
}
