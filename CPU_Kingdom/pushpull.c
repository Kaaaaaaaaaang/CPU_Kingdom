#include "pushpull.h"
#include <conio.h>
#include<windows.h>

// _getch() value of ESC key
#define ESC 27
#define A 65
#define a 97
#define L 76
#define l 108

void start_game(void);
void game_fun(void);
char key;
char t_name1[20];
char t_name2[20];
int x = 40;
int y = 11;
int win = 0;
int win_lose = 0;

void pushpull(void) {
	char t_name1;
	char t_name2;
	system("cls"); 

	do {
		gotoxy(37, 5);
		printf("�ڡڡڡڡڡڡڡڡڡ� �ٴٸ��� �ڡڡڡڡڡڡڡڡڡ�\n");
		gotoxy(37, 6);
		printf("��");
		gotoxy(85, 6);
		printf("��");
		gotoxy(37, 7);
		printf("��         AŰ�� LŰ�� �������� ��Ÿ!!          ��\n");
		gotoxy(37, 8);
		printf("�� ���� ���� ���� �ڱ������� ���� �����Դϴ�! ��\n");
		gotoxy(37, 9);
		printf("��                 ���� �º�!                   ��\n");
		gotoxy(37, 10);
		printf("��");
		gotoxy(85, 10);
		printf("��");
		gotoxy(37, 11);
		printf("��");
		gotoxy(85, 11);
		printf("��");
		gotoxy(37, 12);
		printf("��  ESC�� ������ �ٽ� ���Ӽ������� ���ư��ϴ�!  �� ");
		gotoxy(37, 13);
		printf("��          �̸��� 6�� �̳��� �����ּ���!       ��");
		gotoxy(37, 14);
		printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
		do {
			x = 40;
			start_game(x, y);
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

	gotoxy(28, 8);
	printf("%s", t_name1);
	gotoxy(86, 8);
	printf("%s", t_name2);

	gotoxy(30, 10);
	printf("��");
	gotoxy(29, 11);
	printf("��|/");
	gotoxy(30, 12);
	printf(" |");
	gotoxy(30, 13);
	printf("/��");

	gotoxy(87, 10);
	printf(" ��");
	gotoxy(86, 11);
	printf("��|/");
	gotoxy(87, 12);
	printf(" |");
	gotoxy(87, 13);
	printf("/��");

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

	gotoxy(45, 19);
	printf("�޴��� ���ư����� ESC�� �����ּ���\n");

	char menu_key = _getch();
	if (menu_key == ESC) {
		pushpull();
	}

}

void start_game() {
	gotoxy(47, 17);
	printf("���� �� �� �̸��� �����ּ���!\n");
	gotoxy(47, 18);
	printf("ù��° �� �̸��Է� �� ����!> ");
	scanf_s("%s", &t_name1,20);
	gotoxy(47, 19);
	printf("�ι�° �� �̸��Է� �� ����!> ");
	scanf_s("%s", &t_name2, 20);
	system("cls");
	line(x, y);
}

void game_fun() {
	char click = _getch();
	if (click == ESC) {
		pushpull();
	}
	switch (click) {
		case A: case a: // A
			x -= 2;
			line(x, y);
			Sleep(100);
			if (x == 28) {
				gotoxy(57, 15);
				printf("%s �¸�!", t_name1);
				gotoxy(48, 17);
				printf("2�� �� ����ȭ������ ���ư��ϴ�.");
				Sleep(2000);
				pushpull();
			}

		case L: case l: // L
			x += 2;
			line(x, y);
			Sleep(100);
			if (x == 52) {
				gotoxy(57, 15);
				printf("%s �¸�!", t_name2);
				gotoxy(48, 17);
				printf("2�� �� ����ȭ������ ���ư��ϴ�.");
				Sleep(2000);
				pushpull();
			}
		}
}
	