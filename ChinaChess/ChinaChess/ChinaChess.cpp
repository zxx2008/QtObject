#include "ChinaChess.h"
#include <QDesktopWidget>

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
