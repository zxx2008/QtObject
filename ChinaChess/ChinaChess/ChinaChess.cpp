#include "ChinaChess.h"
#include <QDesktopWidget>

ChinaChess::ChinaChess(QWidget *parent)
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

    //g_game_width = 

    //画棋盘背景
    nk = new ChessBackground(clientRect.height() - 200);
    //添加到Scene中
    m_ptrMainScene->addItem(nk);

    //用View显示Scene
    m_ptrMainView->setScene(m_ptrMainScene);
    setCentralWidget(m_ptrMainView);
}

ChinaChess::~ChinaChess() {}
