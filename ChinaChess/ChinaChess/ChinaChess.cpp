#include "ChinaChess.h"
#include <QDesktopWidget>
#include <QMouseEvent>

ChinaChess::ChinaChess(QWidget* parent)
    : QMainWindow(parent), m_ptrMainView(new QGraphicsView), m_ptrMainScene(new QGraphicsScene)
{
    ui.setupUi(this);

    //设置窗口为对话框的形式，不可改变大小
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle(tr("中国象棋"));

    //获取可用桌面大小
    QRect clientRect = QApplication::desktop()->availableGeometry();

    //设置View的大小
    m_ptrMainView->setFixedSize(clientRect.height() - 200, clientRect.height() - 200);

    g_game_width = clientRect.height() - 200;
    g_cell_width = (g_game_width) / 10;
    g_top = (g_game_width - 8 * g_cell_width) / 2;
    g_left = (g_game_width - 9 * g_cell_width) / 2;
    g_chess_man_width = g_game_width / 13;

    //画棋盘背景
    nk = new ChessBackground(clientRect.height() - 200);
    //添加到Scene中
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

    //用View显示Scene
    m_ptrMainView->setScene(m_ptrMainScene);
    setCentralWidget(m_ptrMainView);
}

ChinaChess::~ChinaChess() {}

//通过坐标使相应棋子置为选择状态
void ChinaChess::selectChess(int x, int y) {
    clearSelectChess();     //清除所有的棋子选中状态
    for (auto item : m_lstChess) {
        //找到对应棋子判断是否存活，如果存活才能被选中
        if (x == item->getX() && y == item->getY()) {
            //需要判断其选择的棋子颜色是否和出子的方颜色相同
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
    //根据鼠标选中的位置获取棋盘坐标
    QPoint Coordinates = getChessboardCoordinates(event->x(), event->y());
    x = Coordinates.x();
    y = Coordinates.y();

    //已选中棋子的情况
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
