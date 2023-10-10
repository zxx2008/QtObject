#include "ChinaChess.h"
#include <QDesktopWidget>

ChinaChess::ChinaChess(QWidget *parent)
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

    //��View��ʾScene
    m_ptrMainView->setScene(m_ptrMainScene);
    setCentralWidget(m_ptrMainView);
}

ChinaChess::~ChinaChess() {}
