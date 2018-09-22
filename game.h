#ifndef _GAME_H__//防止头文件重复包含
#define _GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ROW 3
#define COL 3

void init_board(char board[ROW][COL], int row, int col);//初始化棋盘
void printf_board(char board[ROW][COL], int row, int col);//打印棋盘
void player_move(char board[ROW][COL], int row, int col);//玩家走棋
void computer_move(char board[ROW][COL], int row, int col);//电脑走棋
char is_win(char board[ROW][COL], int row, int col);//判断输赢
char is_full_board(char board[ROW][COL], int row, int col);//判断棋盘是否已满


#endif