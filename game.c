#include"game.h"
void init_board(char board[ROW][COL], int row, int col){
	int i, j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//每个落子位置放上空格
		}
	}

}//初始化棋盘


void printf_board(char board[ROW][COL], int row, int col){
	int i, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (j < COL - 1)
			{
				printf(" %c |", board[i][j]);
			}
			else
			{
				printf(" %c\n", board[i][j]);
			}
		}
		if (i < ROW - 1)
		{
			for (j = 0; j < COL; j++)
			{
				if (j < COL - 1)
				{
					printf("---|");
				}
				else{
					printf("---\n");
				}
			}
		}
	}
}//打印棋盘


void player_move(char board[ROW][COL], int row, int col){
	int x, y = 0;
	while (1)
	{
		printf("请输入您想落子的坐标：");
		scanf_s("%d %d", &x, &y);
		if ((x > 0 && (x - 1) <= ROW) && (y > 0 && (y - 1) <= COL) && (board[x - 1][y - 1] == ' '))
		{
			board[x - 1][y - 1] = '*';//玩家落子处用*表示
			break;
		}
		else
			printf("落子错误\n");
	}
}//玩家走


void computer_move(char board[ROW][COL], int row, int col){
	int tmp1, tmp2 = 0;
	while (1)
	{
		tmp1 = rand() % 3;
		tmp2 = rand() % 3;//产生两个随机数作为电脑落子坐标
		if (board[tmp1][tmp2] == ' ')
		{
			board[tmp1][tmp2] = '$';//电脑落子出用$表示
			break;
		}
	}
}//电脑走


char is_full_board(char board[ROW][COL], int row, int col)
{
	int i, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}//判断棋盘是否已满


char is_win(char board[ROW][COL], int row, int col){
	int i, j = 0;
	for (i = 0; i < ROW; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))//横着三个子连成一线
		{
			if (board[i][0] == '*')
			{
				return'Y';//玩家赢
			}
			if (board[i][0] == '$')
			{
				return'S';//电脑赢
			}
		}
	}
	for (j = 0; j < COL; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]))//竖着三子连成一线
		{
			if (board[0][j] == '*')
			{
				return'Y';//玩家赢
			}
			if (board[0][j] == '$')
			{
				return'S';//电脑赢
			}
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))//斜下三子连成一线
	{
		if (board[0][0] == '*')
		{
			return'Y';//玩家赢
		}
		if (board[0][0] == '$')
		{
			return'S';//电脑赢
		}
	}
	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))//斜上三子连成一线
	{
		if (board[0][2] == '*')
		{
			return'Y';//玩家赢
		}
		if (board[0][2] == '$')
		{
			return'S';//电脑赢
		}
	}

	if (is_full_board(board, ROW, COL) == 1)
	{
		return 'P';//棋盘已满显示平局
	}

	return 'G';//玩家电脑均没赢且棋盘未满返回G，继续游戏
}//判断输赢

