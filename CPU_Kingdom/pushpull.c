#include "pushpull.h"
#include <conio.h>

// _getch() value of ESC key
#define ESC 27

void start_game(void);
void game_fun(void);
char key;
char t_name1;
char t_name2;
int line_start = 100;
int win = 0;
int win_lose = 0;

void pushpull(void) {
	char t_name1;
	char t_name2;
	system("cls"); 

	do {
		gotoxy(96, 15);
		printf("�ڡڡڡڡڡڡڡڡڡ� �ٴٸ��� �ڡڡڡڡڡڡڡڡڡ�\n");
		gotoxy(96, 16);
		printf("��");
		gotoxy(144, 16);
		printf("��");
		gotoxy(96, 17);
		printf("��         AŰ�� LŰ�� �������� ��Ÿ!!          ��\n");
		gotoxy(96, 18);
		printf("�� ���� ���� ���� �ڱ������� ���� �����Դϴ�! ��\n");
		gotoxy(96, 19);
		printf("��                 ���� �º�!                   ��\n");
		gotoxy(96, 20);
		printf("��");
		gotoxy(144, 20);
		printf("��");
		gotoxy(96, 21);
		printf("��");
		gotoxy(144, 21);
		printf("��");
		gotoxy(96, 22);
		printf("��  ESC�� ������ �ٽ� ���Ӽ������� ���ư��ϴ�!  �� ");
		gotoxy(96, 23);
		printf("��");
		gotoxy(144, 23);
		printf("��");
		gotoxy(96, 24);
		printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
		do {
			start_game();
			do {
				game_fun();
				} while (key != ESC);
			} while (key != ESC);
	} while (key != ESC);
}

void line(int r)
{
	system("cls");
	int i, line[21] = { 0 };
	line[10] = 1;
	line[4] = 2;
	line[16] = 2;
	gotoxy(107, 17);
	for (i = 0; i < 78; i++)
		printf(" ");

	gotoxy(88, 16);
	printf("%s", &t_name1);
	gotoxy(153, 16);
	printf("%s", &t_name2);

	gotoxy(r, 17);

	for (i = 0; i < 21; i++)
		if (line[i] == 0)
			printf("��");
		else if (line[i] == 1)
			printf("��");
		else
			printf("��");

	gotoxy(118, 20);
	printf("������");
	gotoxy(120, 16);
	printf("��");
	gotoxy(120, 18);
	printf("��");

	gotoxy(105, 30);
	printf("�޴��� ���ư����� ESC�� �����ּ���\n");

	char menu_key = _getch();
	if (menu_key == ESC) {
		pushpull();
	}

}

void start_game() {
	gotoxy(107, 26);
	printf("���� �� �� �̸��� �����ּ���!\n");
	gotoxy(105, 27);
	printf("ù��° �� �̸��Է� �� ����!> ");
	scanf_s("%s", &t_name1,100);
	gotoxy(105, 28);
	printf("�ι�° �� �̸��Է� �� ����!> ");
	scanf_s("%s", &t_name2, 100);
	system("cls");
	line(line_start);

}

void game_fun() {
	int count = 0;
	char click;
	if (_kbhit()) {
		click = _getch();
		switch (click) {
		case 65: case 97: // A
			count -= 10;
			for (int i = line_start; i > (line_start + count); i--) {
				line(i);
				Sleep(100);
			}
			break;
		case 76: case 108: // L
			count += 10;
			for (int i = line_start; i < (line_start + count); i++) {
				line(i);
				Sleep(100);
			}
			break;
		case ESC:
			exit(0);
		}
	}
	
}