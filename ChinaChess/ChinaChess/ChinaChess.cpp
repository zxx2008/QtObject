#include "ChinaChess.h"
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>

ChinaChess::ChinaChess(QWidget* parent)
    : QMainWindow(parent), m_ptrMainView(new QGraphicsView), m_ptrMainScene(new QGraphicsScene), m_Role(Red), m_gameType(running)
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
    this->setMouseTracking(true);
}

ChinaChess::~ChinaChess() {}

//通过坐标使相应棋子置为选择状态
void ChinaChess::selectChess(int x, int y) {
    clearSelectChess();     //清除所有的棋子选中状态
    for (auto item : m_lstChess) {
        //找到对应棋子判断是否存活，如果存活才能被选中(为了防止被吃掉的棋子影响选择)
        if (x == item->getX() && y == item->getY() && item->getLive()) {
            //需要判断其选择的棋子颜色是否和出子的方颜色相同
            if (m_Role == Red && item->getChessType() <= Bing_R) {
                item->setSelectedStatus(true);
            }
            else if (m_Role == Black && item->getChessType() > Bing_R) {
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
        //for (auto item : m_lstChess) {
        //    if (m_Role == Red) {
        //        if (x != -1 && y != -1 && x == item->getX() && y == item->getY() && item->getChessType() <= Bing_R) {
        //            //如果红色方出子，选中棋子为红色则选中
        //            selectChess(x, y);
        //            return;
        //        }
        //    }
        //    else if (m_Role == Black) {
        //        if (x != -1 && y != -1 && x == item->getX() && y == item->getY() && item->getChessType() > Bing_R) {
        //            //如果黑色方出子，选中棋子为黑色则选中
        //            selectChess(x, y);
        //            return;
        //        }
        //    }
        //}
        ChessMan* tempchess = getChess(x, y);
        if (tempchess != nullptr) {
            if (m_Role == Red) {
                if (tempchess->getChessType() <= Bing_R) {
                    selectChess(x, y);
                    return;
                }
            }
            else if (m_Role == Black) {
                if (tempchess->getChessType() > Bing_R) {
                    selectChess(x, y);
                    return;
                }
            }
        }
        //如果上述的if没有触发说明，选择的是没有棋子的或有敌方棋子的地方，这样就可以进行移动了
        for (auto& item : m_lstChess) {
            if (item->getSelectedStatus() && x != -1 && y != -1) {
                if (x != item->getX() || y != item->getY()) {
                    MoveChess(item, x, y);
                }
            }
        }
        
    }
    else {
        //没有选中任何棋子的情况下，选择鼠标位置的棋子，这里没有进行红方和黑方行棋的判断，
        //那是因为selectChess函数内部做了红方和黑方的判断
        selectChess(x, y);
    }

    qInfo() << "x:" << x << ",y:" << y;
}

//获得当前选中的棋子返回QPoint 如果没有选中任何棋子返回 QPoint(-1, -1)
QPoint ChinaChess::getSelectedChess() {
    int x = -1, y = -1;
    for (auto& item : m_lstChess) {
        if (item->getSelectedStatus()) {
            x = item->getX();
            y = item->getY();
        }
    }
    return QPoint(x, y);
}

RoleType ChinaChess::getRole() {
    return m_Role;
}

//通过鼠标的位置返回棋盘坐标
QPoint ChinaChess::getChessboardCoordinates(int mouse_x, int mouse_y) {
    int x = -1, y = -1;
    int half_chess_man_width = g_chess_man_width / 2;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 10; ++j) {
            int x1 = g_top + i * g_cell_width - half_chess_man_width;
            int y1 = g_left + j * g_cell_width - half_chess_man_width;

            int x2 = g_top + i * g_cell_width + half_chess_man_width;
            int y2 = g_left + j * g_cell_width + half_chess_man_width;

            if (mouse_x >= x1 && mouse_x <= x2 && mouse_y >= y1 && mouse_y <= y2) {
                x = i;
                y = j;
                break;
            }
        }
    }
    return QPoint(x, y);
}

ChessMan* ChinaChess::getChess(int x, int y) {
    for (auto item : m_lstChess) {
        if (item->getX() == x && item->getY() == y) {
            return item;
        }
    }
    return nullptr;
}

void ChinaChess::MoveChess(ChessMan* chess, int x, int y) {
    bool res = false;
    switch (chess->getChessType()) {
    case Bing_R:
        res = MoveBingR(chess, x, y);
        break;
    case Bing_B:
        res = MoveBingB(chess, x, y);
        break;
    case Ma_R:
    case Ma_B:
        res = MoveMa(chess, x, y);
        break;
    case Xiang_R:
        res = MoveXiangR(chess, x, y);
        break;
    case Xiang_B:
        res = MoveXiangB(chess, x, y);
        break;
    case Shi_R:
        res = MoveShiR(chess, x, y);
        break;
    case Shi_B:
        res = MoveShiB(chess, x, y);
        break;
    case Che_R:
    case Che_B:
        res = MoveChe(chess, x, y);
        break;
    case Pao_R:
    case Pao_B:
        res = MovePao(chess, x, y);
        break;
    case Jiang_R:
        res = MoveJiangR(chess, x, y);
        break;
    case Jiang_B:
        res = MoveJiangB(chess, x, y);
        break;
    }
    
    //打印移动信息
    if (res) {
        MoveData(chess, x, y);
        //轮到对手走棋
        if (m_Role == Red) {
            m_Role = Black;
        }
        else {
            m_Role = Red;
        }
        //取消棋子选择
        chess->setSelectedStatus(false);
    }
    GameType gameType = gameover();
    if (gameType != running) {
        if (gameType == Red_win)
        {
            QMessageBox::information(nullptr, "提示", "游戏结束，红方获胜！");
        }
        else {
            QMessageBox::information(nullptr, "提示", "游戏结束，红方获胜！");
        }
    }
}

//实现吃子
void ChinaChess::MoveData(ChessMan* chess, int x, int y) {
    ChessMan* tempChess = getChess(x, y);
    if (tempChess != nullptr) {
        tempChess->setLive(false);
    }
    chess->Move(x, y);
}

//用于判断移动是否成立
bool ChinaChess::MoveBingR(ChessMan* chess, int x, int y) {
    bool res = false;
    if (y > 4) {
        if (chess->getY() == y + 1 && chess->getX() == x) {
            res = true;
        }
    }
    else {
        if (chess->getX() == x && chess->getY() == y + 1) {
            res = true;
        }
        else if ((chess->getX() == x + 1 || chess->getX() == x - 1) && chess->getY() == y) {
            res = true;
        }
    }

    return res;
}

bool ChinaChess::MoveBingB(ChessMan* chess, int x, int y) {
    bool res = false;
    if (y <= 4) {
        if (chess->getY() == y - 1 && chess->getX() == x) {
            res = true;
        }
    }
    else {
        if (chess->getY() == y - 1 && chess->getX() == x) {
            res = true;
        }
        else if ((chess->getX() == x + 1 || chess->getX() == x - 1) && chess->getY() == y) {
            res = true;
        }
    }
    return res;
}

bool ChinaChess::MoveChe(ChessMan* chess, int x, int y) {
    //bool res = false;
    int min = 0, max = 0;
    //判断走竖线的情况
    if (chess->getX() == x, chess->getY() != y) {
        if (chess->getY() < y) {
            min = chess->getY();
            max = y;
        }
        else {
            min = y;
            max = chess->getY();
        }
        //如果中间有棋子则移动不成功
        for (int i = min + 1; i < max; ++i) {
            ChessMan* tempchess = getChess(x, i);
            if (tempchess != nullptr) {
                return false;
            }
        }
        return true;
    }
    //判断走横线的情况
    else if (chess->getY() == y && chess->getX() != x) {
        if (chess->getX() < x) {
            min = chess->getX();
            max = x;
        }
        else {
            min = x;
            max = chess->getX();
        }
        for (int i = min + 1; i < max; ++i) {
            ChessMan* tempchess = getChess(i, y);
            if (tempchess != nullptr) {
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
    //return res;
}

bool ChinaChess::MoveMa(ChessMan* chess, int x, int y) {
    bool res = false;
    if (abs(chess->getX() - x) + abs(chess->getY() - y) == 3 && abs(abs(chess->getX() - x) - abs(chess->getY() - y)) == 1) {
        res = true;
    }
    else {
        return false;
    }
    //蹩马腿判断
    if (abs(chess->getX() - x) == 2) {
        if (x > chess->getX()) {
            ChessMan* tempchess = getChess(chess->getX() + 1, chess->getY());
            if (tempchess != nullptr) {
                res = false;
            }
        }
        else {
            ChessMan* tempchess = getChess(chess->getX() - 1, chess->getY());
            if (tempchess != nullptr) {
                res = false;
            }
        }
    }
    else if (abs(chess->getY() - y) == 2) {
        if (y > chess->getY()) {
            ChessMan* tempchess = getChess(chess->getX(), chess->getY() + 1);
            if (tempchess != nullptr) {
                res = false;
            }
        }
        else {
            ChessMan* tempchess = getChess(chess->getX(), chess->getY() - 1);
            if (tempchess != nullptr) {
                res = false;
            }
        }
    }
    return res;
}

bool ChinaChess::MoveXiangR(ChessMan* chess, int x, int y) {
    bool res = false;
    if (abs(chess->getX() - x) == 2 && abs(chess->getY() - y) == 2 && y >= 5) {
        res = true;
        int tempx = (chess->getX() + x) / 2;
        int tempy = (chess->getY() + y) / 2;
        ChessMan* tempchess = getChess(tempx, tempy);
        if (tempchess != nullptr) {
            res = false;
        }
    }
    return res;
}

bool ChinaChess::MoveXiangB(ChessMan* chess, int x, int y) {
    bool res = false;
    if (abs(chess->getX() - x) == 2 && abs(chess->getY() - y) == 2 && y <= 4) {
        res = true;
        //塞象眼判断
        int tempx = (chess->getX() + x) / 2;
        int tempy = (chess->getY() + y) / 2;
        ChessMan* tempchess = getChess(tempx, tempy);
        if (tempchess != nullptr) {
            res = false;
        }
    }
    return res;
}

bool ChinaChess::MoveShiR(ChessMan* chess, int x, int y) {
    bool res = false;
    if (abs(chess->getX() - x) == 1 && abs(chess->getY() - y) == 1 && x >= 3 && x <= 5 && y >= 7) {
        res = true;
    }
    return res;
}

bool ChinaChess::MoveShiB(ChessMan* chess, int x, int y) {
    bool res = false;
    if (abs(chess->getX() - x) == 1 && abs(chess->getY() - y) == 1 && x >= 3 && x <= 5 && y <= 2) {
        res = true;
    }
    return res;
}

bool ChinaChess::MoveJiangR(ChessMan* chess, int x, int y) {
    if (x >= 3 && x <= 5 && y >= 7) {
        if (abs(chess->getX() - x) + abs(chess->getY() - y) == 1) {
            return true;
        }
    }
    return false;
}

bool ChinaChess::MoveJiangB(ChessMan* chess, int x, int y) {
    if (x >= 3 && x <= 5 && y <= 2) {
        if (abs(chess->getX() - x) + abs(chess->getY() - y) == 1) {
            return true;
        }
    }
    return false;
}

bool ChinaChess::MovePao(ChessMan* chess, int x, int y) {
    int min = 0, max = 0;
    ChessMan* chessman = getChess(x, y);
    //棋子走竖线的情况
    if (chess->getX() == x, chess->getY() != y) {
        //炮向下移动的情况
        if (chess->getY() < y) {
            min = chess->getY();
            max = y;
            //炮没有吃子的情况
            if (chessman == nullptr) {
                for (int i = min + 1; i < max; ++i) {
                    if (getChess(x, i) != nullptr) {
                        return false;
                    }
                }
                return true;
            }
            //炮吃子的情况
            else {
                int count = 0;
                for (int i = min + 1; i < max; ++i) {
                    if (getChess(x, i) != nullptr) {
                        ++count;
                    }
                }
                if (count == 1) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        //炮向上移动的情况
        else {
            min = y;
            max = chess->getY();
            //炮没有吃子的情况
            if (chessman == nullptr) {
                for (int i = min + 1; i < max; ++i) {
                    if (getChess(x, i) != nullptr) {
                        return false;
                    }
                    return true;
                }
            }
            //炮吃子的情况
            else {
                int count = 0;
                for (int i = min + 1; i < max; ++i) {
                    if (getChess(x, i) != nullptr) {
                        ++count;
                    }
                }
                if (count == 1) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    //炮走横线的情况
    else if (chess->getY() == y && chess->getX() != x) {
        //炮向右走的情况
        if (chess->getX() < x) {
            min = chess->getX();
            max = x;
            //炮没吃子的情况
            if (chessman == nullptr) {
                for (int i = min + 1; i < max; ++i) {
                    if (getChess(i, y) != nullptr) {
                        return false;
                    }
                    return true;
                }
            }
            //炮吃子的情况
            else {
                int count = 0;
                for (int i = min + 1; i < max; ++i) {
                    if (getChess(i, y) != nullptr) {
                        ++count;
                    }
                }
                if (count == 1) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        else {
            min = x;
            max = chess->getX();
            //炮没吃子的情况
            if (chessman == nullptr) {
                for (int i = min + 1; i < max; ++i) {
                    if (getChess(i, y) != nullptr) {
                        return false;
                    }
                    return true;
                }
            }
            //炮吃子的情况
            else {
                int count = 0;
                for (int i = min + 1; i < max; ++i) {
                    if (getChess(i, y) != nullptr) {
                        ++count;
                    }
                }
                if (count == 1) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
}

void ChinaChess::resizeEvent(QResizeEvent* event) {
    this->setFixedSize(this->size());
}

GameType ChinaChess::gameover() {
    for (auto& item : m_lstChess) {
        if (item->getChessType() == Jiang_B && !item->getLive()) {
            return Red_win;
        }
        else if (item->getChessType() == Jiang_R && !item->getLive()) {
            return Black_win;
        }
    }
    return running;
}