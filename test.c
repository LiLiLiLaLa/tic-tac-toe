#include"game.h"
void menu()
{
	printf("******************\n");
	printf("******1.play******\n");
	printf("******0.exit******\n");
	printf("******************\n");
}//选择进入游戏或退出

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	init_board(board, ROW, COL);//初始化棋盘
	int flag = 1;//表示玩家走棋
	while (1)
	{
		ret = is_win(board, ROW, COL);//判断输赢
		if (ret == 'Y')
		{
			printf_board(board, ROW, COL);
			printf("你明明可以靠脸吃饭却偏要靠智慧\n");//赢
			break;
		}
		if (ret == 'S')
		{
			printf_board(board, ROW, COL);
			printf("游戏输了没什么，谁让你长的好看呢\n");//输
			break;
		}
		if (ret == 'P')
		{
			printf_board(board, ROW, COL);
			printf("竟然平局，建议再来一局一决雌雄\n");//平局
			break;
		}
		printf_board(board, ROW, COL);//每次进入循环前打印棋盘，玩家电脑每走一步就会显示落子位置，方便观察哪些位置是谁的棋子
		if (ret == 'G')//G表示继续游戏
		{
			if (flag)
			{
				player_move(board, ROW, COL);//玩家走棋
				flag = 0;//玩家走棋后改变flag，下次轮到电脑走
			}
			else
			{
				computer_move(board, ROW, COL);//电脑走棋
				flag = 1;//电脑走棋后flag变回1，下次轮到玩家走
				printf("电脑走棋>\n");
			}
		}
	}
}
int main(){
	int input = 0;
	do
	{
		menu();
		printf("进入游戏或者退出：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();//输入1开始游戏
			break;
		case 0:
			printf("退出游戏");//输入0退出游戏
			break;
		default:
			printf("选择错误");
			break;
		}
	} while (input);//当选择1进入游戏一局结束时再次进入循环选择是否再次游戏，实现连续游戏
	return 0;
}
