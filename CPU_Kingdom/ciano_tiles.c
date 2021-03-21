// The Game Made by Hadam Cho

#include "ciano_tiles.h"

// _getch() values
#define ESC 27
#define ENTER 13
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

// default coordinates
#define X 120
#define Y 25

// line spacing (menu)
#define DISTANCE 3

// menu coordinates
#define FIRST (Y + 2 + DISTANCE)
#define LAST (FIRST + 3 * DISTANCE)

// functions
void draw_menu();
int select_menu();
void menu_process(int selected_menu);
void manual();
// modules
void print_str(int* x, int* y, char* str);

void ciano_tiles(void) {
	system("cls");

	// draw menu
	draw_menu();

	// user select a menu
	int selected_menu = select_menu();

	// check selected menu
	menu_process(selected_menu);
}

// y += DISTANCE;
// gotoxy(x, y);
// printf("%s", str);
void print_str(int* x, int* y, char* str) {
	*y += DISTANCE;
	gotoxy(*x, *y);
	printf("%s", str);
}

// draw menu (chohadam 21-03-20)
void draw_menu() {
	int x = X;
	int y = Y;

	y -= DISTANCE;
	print_str(&x, &y, "  CIANO TILES");

	y += 2;
	print_str(&x, &y, "      ����");

	print_str(&x, &y, "    ���� ���");

	print_str(&x, &y, "      ��ŷ");

	print_str(&x, &y, "      ����");
}

// select menu (chohadam 21-03-20)
int select_menu() {
	// Enter, Up, Down
	char pressed_key;

	// set x, y
	int x = X;
	int y = FIRST;

	do {
		gotoxy(x, y);
		// print cursor
		printf("��");

		pressed_key = _getch();
		// remove cursor
		gotoxy(x, y);
		printf("  ");

		switch (pressed_key) {
		// ��
		case UP:
			y -= DISTANCE;
			// press the UP key on the first menu
			if (y < FIRST) {
				// go to last menu
				y = LAST;
			}
			break;
		
		// ��
		case DOWN:
			y += DISTANCE;
			// press the DOWN key on the last menu
			if (y > LAST) {
				// go to first menu
				y = FIRST;
			}
			break;

		default:
			break;
		}
	} while (pressed_key != ENTER);

	return y;
}

// check selected menu (chohadam, 21-03-20)
void menu_process(int selected_menu) {
	// start
	if (selected_menu == FIRST) {
		ciano_tiles();
	}
	// game manual
	else if (selected_menu == FIRST + DISTANCE) {
		manual();
	}
	// ranking
	else if (selected_menu == FIRST + DISTANCE * 2) {
		ciano_tiles();
	}
	// end
	else if (selected_menu == LAST) {
		return;
	}
	// error
	else {
		printf("Something Wrong");
		exit(1);
	}
}

// print game manual (chohadam, 21-03-21)
void manual() {
	// set x, y
	int x = -10 + X;
	int y = -5 + Y;

	// clear console
	system("cls");

	y -= DISTANCE;
	print_str(&x, &y, "�� ĭ�� �������� Ÿ�ϰ� ���� ��ġ��");

	print_str(&x, &y, "���� ������ ������");

	print_str(&x, &y, "������ 100���� �ö󰩴ϴ�.");

	print_str(&x, &y, "������ ��� 50�� �����Ǹ�");

	print_str(&x, &y, "5�� ������ ��� ������ ����ǰ�");

	print_str(&x, &y, "������ ��ϵ˴ϴ�.");

	print_str(&x, &y, "������ ���� ���� Ÿ���� ��������");

	print_str(&x, &y, "�ӵ��� �������ϴ�.");

	print_str(&x, &y, "���� �ٷ� 1���Ϸ� GO GO!");

	y += DISTANCE;
	print_str(&x, &y, "�ƹ� Ű�� ������ �޴��� �̵��մϴ�.");

	_getch();

	ciano_tiles();
}