#include "pushpull.h"
#include <conio.h>

// _getch() value of ESC key
#define ESC 27

void start_game(void);
void game_fun(void);
char key;
char t_name1;
char t_name2;
int x = 40;
int y = 11;
int win = 0;
int win_lose = 0;

void pushpull(void) {
	char t_name1;
	char t_name2;
	system("cls"); 

	do {
		gotoxy(35, 5);
		printf("�ڡڡڡڡڡڡڡڡڡ� �ٴٸ��� �ڡڡڡڡڡڡڡڡڡ�\n");
		gotoxy(35, 6);
		printf("��");
		gotoxy(83, 6);
		printf("��");
		gotoxy(35, 7);
		printf("��         AŰ�� LŰ�� �������� ��Ÿ!!          ��\n");
		gotoxy(35, 8);
		printf("�� ���� ���� ���� �ڱ������� ���� �����Դϴ�! ��\n");
		gotoxy(35, 9);
		printf("��                 ���� �º�!                   ��\n");
		gotoxy(35, 10);
		printf("��");
		gotoxy(83, 10);
		printf("��");
		gotoxy(35, 11);
		printf("��");
		gotoxy(83, 11);
		printf("��");
		gotoxy(35, 12);
		printf("��  ESC�� ������ �ٽ� ���Ӽ������� ���ư��ϴ�!  �� ");
		gotoxy(35, 13);
		printf("��");
		gotoxy(83, 13);
		printf("��");
		gotoxy(35, 14);
		printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
		do {
			start_game();
			do {
				game_fun();
				} while (key != ESC);
			} while (key != ESC);
	} while (key != ESC);
}

void line(int x, int y)
{
	system("cls");
	int i, line[21] = { 0 };
	line[10] = 1;
	line[4] = 2;
	line[16] = 2;
	gotoxy(31, 13);
	for (i = 0; i < 78; i++)
		printf(" ");

	gotoxy(35, 10);
	printf("%s", &t_name1);
	gotoxy(87, 10);
	printf("%s", &t_name2);

	gotoxy(x, y);
	for (i = 0; i < 21; i++)
		if (line[i] == 0)
			printf("��");
		else if (line[i] == 1)
			printf("��");
		else
			printf("��");

	gotoxy(58, 8);
	printf("������");
	gotoxy(60, 10);
	printf("��");
	gotoxy(60, 12);
	printf("��");

	gotoxy(43, 15);
	printf("�޴��� ���ư����� ESC�� �����ּ���\n");

	char menu_key = _getch();
	if (menu_key == ESC) {
		pushpull();
	}

}

void start_game() {
	gotoxy(45, 16);
	printf("���� �� �� �̸��� �����ּ���!\n");
	gotoxy(45, 17);
	printf("ù��° �� �̸��Է� �� ����!> ");
	scanf_s("%s", &t_name1,100);
	gotoxy(45, 18);
	printf("�ι�° �� �̸��Է� �� ����!> ");
	scanf_s("%s", &t_name2, 100);
	system("cls");
	line(x, y);

}

void game_fun() {
	char click = _getch();
	if (click == ESC) {
		pushpull();
	}
	switch (click) {
	case 65: case 97: // A
		line(x - 2, y);
		Sleep(100);
		if (x == 46) {
			printf("%s �¸�!", &t_name1);
			break;
		}

	case 76: case 108: // L
		line(x + 2, y);
		Sleep(100);
		if (x == 34) {
			printf("%s �¸�!", &t_name2);
			break;
		}
	}
}
	