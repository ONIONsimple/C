#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

void menu();
void game();
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char HowWin(char board[ROW][COL], int row, int col);


//�洢����
char board[ROW][COL];

int main() {
	int input;
	srand((unsigned int)time(NULL));

	do {
		menu();
		printf("==>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game(); break;
			case 0:
				printf("�˳���Ϸ\n"); break;
			default:
				printf("error\n"); break;
		}
	} while (input);
	
}

void menu() {
	printf("********************************\n");
	printf("******      1.play       *******\n");
	printf("******      0.exit       *******\n");
	printf("********************************\n");
}

void game() {
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);

	char flag = '\0'; //������Ϸ״̬

	while (1) {
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�
		flag = HowWin(board,ROW,COL);
		if (flag != 'C') {
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�
		flag = HowWin(board, ROW, COL);
		if (flag != 'C') {
			break;
		}

	}
	if (flag == '*') {
		printf("���WIN!\n");
		DisplayBoard(board, ROW, COL);
	}
	else if (flag == '#') {
		printf("����WIN!\n");
		DisplayBoard(board, ROW, COL);
	}
	else {
		printf("ƽ��\n");
		DisplayBoard(board, ROW, COL);
	}
}


//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] ='\0';
		}
	}
}


//��ӡ����
void DisplayBoard(char board[ROW][COL],int row ,int col) {
	int i,j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %c  ",board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
			
		}
		printf("\n");
		if (i < row - 1) {
			int l = 0;
			for (l = 0; l < col; l++) {
				printf("---");
				if (l < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
		
	}
}


//�������
void PlayerMove(char board[ROW][COL], int row, int col) {
	int x = 0, y = 0;
	printf("�����=>\n");

	while (1) {
		printf("�����������=>");
		scanf("%d %d", &x, &y);
		//�ж�����
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			//����
			//�ж������Ƿ�ռ��
			if (board[x - 1][y - 1]=='\0') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("�����ѱ�ռ��!\n");
			}
		}
		else {
			printf("�������!����������\n");
		}
	}
	
}


//��������
void ComputerMove(char board[ROW][COL], int row, int col) {
	printf("������=>\n");

	
	while (1) {
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y]=='\0') {
				board[x][y] = '#';
				break;
			}
	}
	
}

char HowWin(char board[ROW][COL], int row, int col) {
	int i, j;
	//�ж�����
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != '\0') {
			return board[i][1];
		}
	}
	//�ж�����
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != '\0') {
			return board[1][i];
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != '\0') {
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != '\0') {
		return board[1][1];
	}

	//�ж�ƽ��
	int a=1;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == '\0') {
				a = 0;
			}
		}
	}
	if (a) {
		return 'Q';
	}

	return 'C';

}	