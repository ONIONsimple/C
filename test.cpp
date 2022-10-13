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


//存储数据
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
				printf("退出游戏\n"); break;
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
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);

	char flag = '\0'; //接受游戏状态

	while (1) {
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断
		flag = HowWin(board,ROW,COL);
		if (flag != 'C') {
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断
		flag = HowWin(board, ROW, COL);
		if (flag != 'C') {
			break;
		}

	}
	if (flag == '*') {
		printf("玩家WIN!\n");
		DisplayBoard(board, ROW, COL);
	}
	else if (flag == '#') {
		printf("电脑WIN!\n");
		DisplayBoard(board, ROW, COL);
	}
	else {
		printf("平局\n");
		DisplayBoard(board, ROW, COL);
	}
}


//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] ='\0';
		}
	}
}


//打印棋盘
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


//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col) {
	int x = 0, y = 0;
	printf("玩家走=>\n");

	while (1) {
		printf("输入你的坐标=>");
		scanf("%d %d", &x, &y);
		//判断坐标
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			//下棋
			//判读坐标是否被占用
			if (board[x - 1][y - 1]=='\0') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("坐标已被占用!\n");
			}
		}
		else {
			printf("输入错误!请重新输入\n");
		}
	}
	
}


//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col) {
	printf("电脑走=>\n");

	
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
	//判断三行
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != '\0') {
			return board[i][1];
		}
	}
	//判断三列
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != '\0') {
			return board[1][i];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != '\0') {
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != '\0') {
		return board[1][1];
	}

	//判断平局
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