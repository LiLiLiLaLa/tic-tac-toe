#include"game.h"
void init_board(char board[ROW][COL], int row, int col){
	int i, j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//ÿ������λ�÷��Ͽո�
		}
	}

}//��ʼ������


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
}//��ӡ����


void player_move(char board[ROW][COL], int row, int col){
	int x, y = 0;
	while (1)
	{
		printf("�������������ӵ����꣺");
		scanf_s("%d %d", &x, &y);
		if ((x > 0 && (x - 1) <= ROW) && (y > 0 && (y - 1) <= COL) && (board[x - 1][y - 1] == ' '))
		{
			board[x - 1][y - 1] = '*';//������Ӵ���*��ʾ
			break;
		}
		else
			printf("���Ӵ���\n");
	}
}//�����


void computer_move(char board[ROW][COL], int row, int col){
	int tmp1, tmp2 = 0;
	while (1)
	{
		tmp1 = rand() % 3;
		tmp2 = rand() % 3;//���������������Ϊ������������
		if (board[tmp1][tmp2] == ' ')
		{
			board[tmp1][tmp2] = '$';//�������ӳ���$��ʾ
			break;
		}
	}
}//������


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
}//�ж������Ƿ�����


char is_win(char board[ROW][COL], int row, int col){
	int i, j = 0;
	for (i = 0; i < ROW; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))//��������������һ��
		{
			if (board[i][0] == '*')
			{
				return'Y';//���Ӯ
			}
			if (board[i][0] == '$')
			{
				return'S';//����Ӯ
			}
		}
	}
	for (j = 0; j < COL; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]))//������������һ��
		{
			if (board[0][j] == '*')
			{
				return'Y';//���Ӯ
			}
			if (board[0][j] == '$')
			{
				return'S';//����Ӯ
			}
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))//б����������һ��
	{
		if (board[0][0] == '*')
		{
			return'Y';//���Ӯ
		}
		if (board[0][0] == '$')
		{
			return'S';//����Ӯ
		}
	}
	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))//б����������һ��
	{
		if (board[0][2] == '*')
		{
			return'Y';//���Ӯ
		}
		if (board[0][2] == '$')
		{
			return'S';//����Ӯ
		}
	}

	if (is_full_board(board, ROW, COL) == 1)
	{
		return 'P';//����������ʾƽ��
	}

	return 'G';//��ҵ��Ծ�ûӮ������δ������G��������Ϸ
}//�ж���Ӯ

