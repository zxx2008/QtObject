#include "ChinaChess.h"
#include <QDesktopWidget>

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

    //g_game_width = 

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
