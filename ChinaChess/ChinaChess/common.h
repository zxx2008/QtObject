#pragma once
//��������
enum ChessType {
	NullChess, //û������
	Che_R,     //�� - ��ɫ
	Ma_R,      //�� - ��ɫ
	Xiang_R,   //�� - ��ɫ
	Shi_R,     //ʿ - ��ɫ
	Jiang_R,   //�� - ��ɫ
	Pao_R,     //�� - ��ɫ
	Bing_R,    //�� - ��ɫ
	Che_B,     //�� - ��ɫ
	Ma_B,      //�� - ��ɫ
	Xiang_B,   //�� - ��ɫ
	Shi_B,     //ʿ - ��ɫ
	Jiang_B,   //�� - ��ɫ
	Pao_B,     //�� - ��ɫ
	Bing_B     //�� - ��ɫ
};

enum GameType
{
	running, //��Ϸ������
	Red_win, //�췽ʤ
	Black_win //�ڷ�ʤ
};

enum RoleType {
	//��ɫ����
	Red, 
	Black
};

extern int g_top;              // ���̵����Ͻ�X�����ʱ����
extern int g_left;             // ���̵����Ͻ�Y�����ʱ����
extern int g_chess_man_width;  // ÿһ�����ӵĿ��
extern int g_cell_width;       // ÿһ�����巽��Ŀ��
extern int g_game_width;       // ��Ϸ����Ŀ��
extern int maps[10][9];