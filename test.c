#include"game.h"
void menu()
{
	printf("******************\n");
	printf("******1.play******\n");
	printf("******0.exit******\n");
	printf("******************\n");
}//ѡ�������Ϸ���˳�

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	init_board(board, ROW, COL);//��ʼ������
	int flag = 1;//��ʾ�������
	while (1)
	{
		ret = is_win(board, ROW, COL);//�ж���Ӯ
		if (ret == 'Y')
		{
			printf_board(board, ROW, COL);
			printf("���������Կ����Է�ȴƫҪ���ǻ�\n");//Ӯ
			break;
		}
		if (ret == 'S')
		{
			printf_board(board, ROW, COL);
			printf("��Ϸ����ûʲô��˭���㳤�ĺÿ���\n");//��
			break;
		}
		if (ret == 'P')
		{
			printf_board(board, ROW, COL);
			printf("��Ȼƽ�֣���������һ��һ������\n");//ƽ��
			break;
		}
		printf_board(board, ROW, COL);//ÿ�ν���ѭ��ǰ��ӡ���̣���ҵ���ÿ��һ���ͻ���ʾ����λ�ã�����۲���Щλ����˭������
		if (ret == 'G')//G��ʾ������Ϸ
		{
			if (flag)
			{
				player_move(board, ROW, COL);//�������
				flag = 0;//��������ı�flag���´��ֵ�������
			}
			else
			{
				computer_move(board, ROW, COL);//��������
				flag = 1;//���������flag���1���´��ֵ������
				printf("��������>\n");
			}
		}
	}
}
int main(){
	int input = 0;
	do
	{
		menu();
		printf("������Ϸ�����˳���");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();//����1��ʼ��Ϸ
			break;
		case 0:
			printf("�˳���Ϸ");//����0�˳���Ϸ
			break;
		default:
			printf("ѡ�����");
			break;
		}
	} while (input);//��ѡ��1������Ϸһ�ֽ���ʱ�ٴν���ѭ��ѡ���Ƿ��ٴ���Ϸ��ʵ��������Ϸ
	return 0;
}
