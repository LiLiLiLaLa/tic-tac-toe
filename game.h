#ifndef _GAME_H__//��ֹͷ�ļ��ظ�����
#define _GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ROW 3
#define COL 3

void init_board(char board[ROW][COL], int row, int col);//��ʼ������
void printf_board(char board[ROW][COL], int row, int col);//��ӡ����
void player_move(char board[ROW][COL], int row, int col);//�������
void computer_move(char board[ROW][COL], int row, int col);//��������
char is_win(char board[ROW][COL], int row, int col);//�ж���Ӯ
char is_full_board(char board[ROW][COL], int row, int col);//�ж������Ƿ�����


#endif