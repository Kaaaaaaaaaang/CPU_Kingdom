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
#define X 50
#define Y 10

// line spacing (menu)
#define DISTANCE 3

// menu coordinates
#define FIRST (Y + DISTANCE)
#define LAST (FIRST + 3 * DISTANCE)

// tile size
#define TILE_WIDTH 14
#define TILE_HEIGHT 6

// column
#define TILE_LINE 4

// name size
#define NAME_SIZE 20

// global variables
// player name
char name[NAME_SIZE];
// game score, fail count, current step
int score, fail, step = 1;

// functions
// menu
void menu(void);
void draw_menu(void);
int select_menu(void);
void menu_process(int selected_menu);
// game
void game_process(void);
void get_player_name(void);
void draw_rectangle(void);
void game_ready(void);
void game_start(void);
void print_score(void);
void game_over(void);
// manual
void manual(int flag);
// ranking
void save_score(void);
void ranking(void);
// modules
void print_str(int* x, int* y, char* str);
void print_tile(int x, int y);
void remove_tile(int x, int y);

void ciano_tiles(void) {
	system("cls");

	// bgm
	PlaySound(TEXT("ciano_tiles.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	// draw menu
	// draw_menu();

	// user select a menu
	// int selected_menu = select_menu();

	// check selected menu
	// menu_process(selected_menu);

	// 2021-06-17
	// manual
	manual(0);
}

void menu(void) {
	system("cls");

	// draw menu
	draw_menu();

	// user select a menu
	int selected_menu = select_menu();

	// check selected menu
	menu_process(selected_menu);
}

void print_tile(int x, int y) {
	gotoxy(x, y);
	printf("��������");
	gotoxy(x, y + 1);
	printf("��������");
	gotoxy(x, y + 2);
	printf("��������");
}

void remove_tile(int x, int y) {
	gotoxy(x, y);
	printf("              ");
	gotoxy(x, y + 1);
	printf("              ");
	gotoxy(x, y + 2);
	printf("              ");
}

// y += DISTANCE;
// gotoxy(x, y);
// printf("%s", str);
void print_str(int* x, int* y, char* str) {
	*y += DISTANCE;
	gotoxy(*x, *y);
	printf("%s", str);
}

void rectangle(int width, int height, int x, int y) {
	// ������������
	gotoxy(x, y);
	printf("��");
	for (int i = 1; i < width; i++) {
		printf("��");
	}
	printf("��");

	// ��      ��
	for (int i = 1; i < height; i++) {
		gotoxy(x, y + i);
		// ��      ��
		printf("��");

		for (int j = 1; j < width - 1; j++) {
			printf(" ");
		}
		printf(" ");

		printf("��");
	}

	// ������������
	gotoxy(x, y + height);
	printf("��");
	for (int i = 1; i < width; i++) {
		printf("��");
	}
	printf("��");
}

void piano_ascii_art(void) {
	int x = X - 30;
	int y = Y;
	print_auto_y(&x, &y, "              ��������������");
	print_auto_y(&x, &y, "             /  ��   /");
	print_auto_y(&x, &y, "            /    ��  ��__");
	print_auto_y(&x, &y, "           /      ��     )");
	print_auto_y(&x, &y, "        __/__      ��___/");
	print_auto_y(&x, &y, "   ____/     |------��------,");
	print_auto_y(&x, &y, " __|_________|_________/----|");
	print_auto_y(&x, &y, "(// /// // /// // /// //)___|");
	print_auto_y(&x, &y, "   |  | ------   |    |  |");
	print_auto_y(&x, &y, "   | |  | || |  |     | |");
	print_auto_y(&x, &y, "    ��..|,||  | |      ��");
	print_auto_y(&x, &y, "      .. . ,  ||");
	print_auto_y(&x, &y, "               ��");

	print_by_name("���ϴ�");
}

// draw menu (chohadam 21-03-20)
void draw_menu(void) {
	rectangle(114, 29, 2, 1);
	piano_ascii_art();

	int x = X + 25;
	int y = Y - 2;

	y -= DISTANCE;
	// set color : green
	setColor(BLUE);
	print_str(&x, &y, "    �ǾƳ�  Ÿ��");

	// set color
	setColor(WHITE);
	y += 2;
	print_str(&x, &y, "        ����");

	print_str(&x, &y, "      ���� ���");

	print_str(&x, &y, "        ��ŷ");

	// set color
	setColor(GREY);
	print_str(&x, &y, "        ����");

	// set color
	setColor(WHITE);
}

// select menu (chohadam 21-03-20)
int select_menu(void) {
	// Enter, Up, Down
	char pressed_key;

	// set x, y
	int x = X + 25;
	int y = FIRST;

	do {
		gotoxy(x, y);
		// print cursor
		printf(">");

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
		game_process();
	}
	// game manual
	else if (selected_menu == FIRST + DISTANCE) {
		manual(1);
	}
	// ranking
	else if (selected_menu == FIRST + DISTANCE * 2) {
		ranking();
	}
	// end
	else if (selected_menu == LAST) {
		// stop sound (ciano tiles)
		PlaySound(NULL, 0, 0);
		// back main
		main();
		return;
	}
	// error
	else {
		printf("Something Wrong");
		exit(1);
	}
}

// start game (chohadam, 21-03-22)
void game_process(void) {
	get_player_name();
	draw_rectangle();
	game_ready();
	game_start();
	menu();
}

// input player name (chohadam, 21-03-23)
void get_player_name(void) {
	// clear console
	system("cls");

	// set x, y
	int x = X;
	int y = Y;

	// print description
	print_str(&x, &y, "�̸��� �Է����ּ���.");
	print_str(&x, &y, ">> ");
	
	// input player name
	scanf_s("%s", &name, 20);
	fflush(stdin);
}

// draw the area where tiles down (chohadam, 21-03-22)
void draw_rectangle(void) {
	int x = X - 35;
	int y = Y - 7;

	int width = TILE_WIDTH * TILE_LINE + 2;
	int height = TILE_HEIGHT * 4 - 1;

	// clear console
	system("cls");

	// ������������
	gotoxy(x, y);
	printf("��");
	for (int i = 1; i < width; i++) {
		printf("��");
	}
	printf("��");

	// ��      ��
	// ������������
	for (int i = 1; i < height; i++) {
		gotoxy(x, y + i);
		if (i == height - 4) {
			// ������������
			printf("��");
			for (int j = 1; j < width; j++) {
				printf("��");
			}
			printf("��");
		}
		else {
			// ��      ��
			printf("��");

			for (int j = 1; j < width - 1; j++) {
				printf(" ");
			}
			printf(" ");

			printf("��");
		}
	}

	// ������������
	gotoxy(x, y + height);
	printf("��");
	for (int i = 1; i < width; i++) {
		printf("��");
	}
	printf("��");
}

void print_desc(int x, int y, char* str, int color) {
	while (1) {
		if (_kbhit()) {
			break;
		}
		gotoxy(x, y);
		// set color
		setColor(color);
		printf(str);
		Sleep(400);

		gotoxy(x, y);
		printf("                                           ");
		Sleep(400);
	}
	char _ = _getch();
	// reset color
	setColor(WHITE);
}

// game ready description (chohadam, 21-03-22)
void game_ready(void) {
	int x = X - 25;
	int y = Y + 3;

	// print description
	print_desc(x, y, "<  �ƹ� Ű�� ������ ������ ���۵˴ϴ�  >", BLUE);
}

// start block down (chohadam, 21-03-24)
void game_start(void) {
	// draw rectangle x - 2
	// draw rectangle y - 1
	int x = X - 33;
	int y = Y - 6;

	int rnd = rand() % TILE_LINE;
	int tile_y = y;
	int tile_x[TILE_LINE] = {
		x,
		x + TILE_WIDTH,
		x + TILE_WIDTH * 2,
		x + TILE_WIDTH * 3,
		// x + TILE_WIDTH * 4
	};

	// ���� ���� ����
	int user_y = y + TILE_HEIGHT * 4 - 5;
	int user_x = x;

	// setting use random
	srand((unsigned int)time(NULL));

	// default delay time
	int delay = 50;

	char pressed_key;
	while ((pressed_key = get_key()) != ESC) {
		// print name, score, fail, step, etc.
		print_score();

		// print user tile
		print_tile(user_x, user_y);

		// print tile during delay time
		print_tile(tile_x[rnd], tile_y);
		Sleep(delay);
		remove_tile(tile_x[rnd], tile_y);

		// ������ + (Ÿ�� ���� * 4) - ���� ���� - �� �Ʒ�
		if (tile_y < y + TILE_HEIGHT * 4 - 6 - 3) {
			// falling
			tile_y += 1;
		}
		else {
			if (tile_x[rnd] == user_x) {
				// tile position == user tile position
				score += 100;
			}
			else {
				// fail
				// minus score
				if (score >= 50) {
					score -= 50;
				}
				fail += 1;
				if (fail == 5) {
					// game over
					game_over();
					break;
				}
			}
			// get random number
			rnd = rand() % TILE_LINE;
			// top
			tile_y = y;
		}

		// remove user tile
		remove_tile(user_x, user_y);
		// move user tile
		move_arrow_key(
			pressed_key,
			&user_x,
			&user_y,
			TILE_WIDTH,
			user_y,
			user_y,
			x,
			x + TILE_WIDTH * (TILE_LINE - 1)
		);

		// set step and delay time
		if (score >= 500 && score < 1500) {
			// stage 2
			step = 2;
			delay = 40;
		}
		else if (score >= 1500 && score < 3000) {
			// stage 3
			step = 3;
			delay = 30;
		}
		else if (score >= 3000 && score < 5000) {
			// stage 4
			step = 4;
			delay = 20;
		}
		else if (score >= 5000) {
			// stage 5
			step = 5;
			delay = 10;
		}
	}

	// reset
	score = 0;
	fail = 0;
	step = 1;
}

void game_over(void) {
	// clear console
	system("cls");

	// print game over
	// color red
	setColor(RED);
	gotoxy(X + 5, Y + 5);
	printf("GAME OVER");

	// 2�ʰ� ������
	Sleep(2000);

	// color white
	setColor(WHITE);
	gotoxy(X - 10, Y + 10);
	printf("<  �ƹ� Ű�� ������ �޴��� ���ư��ϴ�  >");
	
	char _ = _getch();

	// save score
	save_score();

	// go to menu
	menu();
}

// print score, fail, step, etc. (chohadam, 21-03-24)
void print_score(void) {
	int x = X + 33;
	int y = Y - 7;

	// string temp
	char str[20];

	// color mint
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MINT);
	sprintf_s(str, sizeof(str), "[  %s  ] ��", name);
	print_str(&x, &y, str);

	// color white
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	sprintf_s(str, sizeof(str), "%d�ܰ�", step);
	print_str(&x, &y, str);

	y += DISTANCE;
	// color blue
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
	sprintf_s(str, sizeof(str), "����\t\t\t%5d", score);
	print_str(&x, &y, str);

	// color red
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	sprintf_s(str, sizeof(str), "����\t\t\t%5d", fail);
	print_str(&x, &y, str);

	// color white
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	print_str(&x, &y, "�̵�\t\t\t�� ��");

	print_str(&x, &y, "����\t\t\t  ESC");
}

// print game manual (chohadam, 21-03-21)
void manual(int flag) {
	// clear console
	system("cls");

	// set x, y
	int x = X - 40;
	int y = Y - 5;

	// draw game screenshot
	print_tile(x, y);

	y += DISTANCE * 2;
	print_str(&x, &y, "      ��      ");
	y -= DISTANCE - 1;
	print_str(&x, &y, "      ��      ");

	y += DISTANCE * 2;
	print_tile(x, y);
	y -= 2;
	x -= 6;
	print_str(&x, &y, "��");
	y -= DISTANCE;
	x += 24;
	print_str(&x, &y, "��");

	x = X - 15;
	y = Y - 5;
	print_str(&x, &y, "1�ܰ�");
	y += 1;

	// color: mint
	setColor(MINT);
	print_str(&x, &y, "����\t\t0");

	// color red
	setColor(RED);
	print_str(&x, &y, "����\t\t0");

	// color white
	setColor(WHITE);
	y += 1;
	print_str(&x, &y, "�̵�\t\t�� ��");
	print_str(&x, &y, "����\t\tESC");


	// draw description
	x = X + 20;
	y = Y - 5;

	y -= DISTANCE;
	print_str(&x, &y, "�� ĭ�� �������� Ÿ�ϰ� ���� ��ġ��");
	y -= 1;
	print_str(&x, &y, "���� ������ ������");
	y -= 1;
	print_str(&x, &y, "������ 100���� �ö󰩴ϴ�.");
	y -= 1;
	print_str(&x, &y, "������ ��� 50�� �����Ǹ�");
	y -= 1;
	print_str(&x, &y, "5�� ������ ��� ������ ����ǰ�");
	y -= 1;
	print_str(&x, &y, "������ ��ϵ˴ϴ�.");

	print_str(&x, &y, "������ ���� ���� Ÿ���� ��������");
	y -= 1;
	print_str(&x, &y, "�ӵ��� �������ϴ�.");

	y += 1;
	print_str(&x, &y, "���� �ٷ� 1���Ϸ� GO GO!");

	y += DISTANCE + 1;
	x = X - 40;

	// flag == 1
	// �޴� �������� �� ��
	if (flag) {
		print_desc(x, y, "<  �ƹ� Ű�� ������ �޴��� �̵��մϴ�  >", YELLOW);

		// go to the menu
		menu();
	}
	else {
		// ù ����
		print_desc(x, y, "<  �ƹ� Ű�� ���� ������ �����غ�����  >", YELLOW);

		// game
		game_process();
	}
}

// save score and player name to file (chohadam, 21-03-30)
void save_score(void) {
	FILE* fp;
	// file name
	char* filename = "ciano-tiles-score.txt";

	fopen_s(&fp, filename, "a");
	
	if (fp != NULL) {
		// write name and score
		fprintf_s(fp, "%s %d\n", name, score);
		// close
		fclose(fp);
	}

	// reset
	score = 0;
	fail = 0;
	step = 1;
}

// get score and player name from file (chohadam, 21-03-30)
void ranking(void) {
	FILE* fp;
	char* filename = "ciano-tiles-score.txt";

	// read file
	fopen_s(&fp, filename, "r");

	// info variables of 100 people
	char players_name[100][20];
	int players_score[100];

	// set x, y
	int x = X - 8, y = Y - 7;

	// used variables
	int count = 0, score_temp;
	char name_temp[NAME_SIZE];

	// clear console
	system("cls");

	// print
	//		��ŷ
	// �̸�		����
	gotoxy(x + 17, y);
	printf("��ŷ");
	y += DISTANCE;
	print_str(&x, &y, "�̸�");
	gotoxy(x + 32, y);
	printf("����");

	if (fp != NULL) {
		while (!feof(fp)) {
			// read line from file
			fscanf_s(fp, "%s %d\n", players_name[count], NAME_SIZE, &players_score[count]);
			count++;
		}

		// order by desc (score)
		for (int i = 0; i < count - 1; i++) {
			for (int j = i + 1; j < count; j++) {
				if (players_score[i] < players_score[j]) {
					score_temp = players_score[i];
					players_score[i] = players_score[j];
					players_score[j] = score_temp;

					// move player name
					strcpy_s(name_temp, NAME_SIZE - 1, players_name[i]);
					strcpy_s(players_name[i], NAME_SIZE - 1, players_name[j]);
					strcpy_s(players_name[j], NAME_SIZE - 1, name_temp);
				}
			}
		}

		// print 4 people
		count = count < 4 ? count : 4;

		// print name and score
		for (int i = 0; i < count; i++) {
			print_str(&x, &y, players_name[i]);
			gotoxy(x + 30, y);
			printf("%5d", players_score[i]);
		}

		// close
		fclose(fp);

		gotoxy(x - 2, y + 5);
		printf("<  �ƹ� Ű�� ������ �޴��� �̵��մϴ�  >");

		int _ = _getch();

		menu();
	}
	else {
		gotoxy(x - 2, Y + 15);
		printf("<  �ƹ� Ű�� ������ �޴��� �̵��մϴ�  >");

		int _ = _getch();

		menu();
	}
}
