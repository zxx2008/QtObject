#include "common.h"
int maps[10][9] = {
    {Che_B, Ma_B, Xiang_B, Shi_B, Jiang_B, Shi_B, Xiang_B, Ma_B, Che_B},
    {NullChess, NullChess, NullChess, NullChess, NullChess, NullChess,
     NullChess, NullChess, NullChess},
    {NullChess, Pao_B, NullChess, NullChess, NullChess, NullChess, NullChess,
     Pao_B, NullChess},
    {Bing_B, NullChess, Bing_B, NullChess, Bing_B, NullChess, Bing_B, NullChess,
     Bing_B},
    {NullChess, NullChess, NullChess, NullChess, NullChess, NullChess,
     NullChess, NullChess, NullChess},
    {NullChess, NullChess, NullChess, NullChess, NullChess, NullChess,
     NullChess, NullChess, NullChess},
    {Bing_R, NullChess, Bing_R, NullChess, Bing_R, NullChess, Bing_R, NullChess,
     Bing_R},
    {NullChess, Pao_R, NullChess, NullChess, NullChess, NullChess, NullChess,
     Pao_R, NullChess},
    {NullChess, NullChess, NullChess, NullChess, NullChess, NullChess,
     NullChess, NullChess, NullChess},
    {Che_R, Ma_R, Xiang_R, Shi_R, Jiang_R, Shi_R, Xiang_R, Ma_R, Che_R} };

int g_top = 0;              // ���̵����Ͻ�X�����ʱ����
int g_left = 0;             // ���̵����Ͻ�Y�����ʱ����
int g_chess_man_width = 0;  // ÿһ�����ӵĿ��
int g_cell_width = 0;       // ÿһ�����巽��Ŀ��
int g_game_width = 0;       // ��Ϸ����Ŀ��