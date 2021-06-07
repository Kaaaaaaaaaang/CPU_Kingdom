#include "guess_note.h"

// _getch() value of ESC key
#define ESC 27
#define UP 72
#define DOWN 80
#define SUBMIT 4

/* �Լ� ���� */
int keyControl(); 

int keyControl() {
	char temp;
	while (1) {
		if (_kbhit()) {
			temp = _getch();
			if (temp == -32) {
				temp = _getch();
				switch (temp) {
				case UP:
					return UP;
					break;
				case DOWN:
					return DOWN;
					break;
				}
			}
			if (temp == ' ') {
				return SUBMIT;
			}
		}
		return 0;
	}
}

int menuDraw() {	
	system("cls");
	int x = 50;
	int y = 13;

	gotoxy(x-2, y); // -2�� ������ >�� ����ϱ� ���ؼ�
	printf(">     �� �� �� �� \n");
	gotoxy(x, y + 2);
	printf("    �� �� �� ��  \n");
	gotoxy(x, y + 4);
	printf("       �� �� \n");


	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 13) { //y�� 12~14������ �̵�
				gotoxy(x - 2, y); // x-2�ϴ� ������ >�� �� ĭ ������ ����ϱ� ���ؼ�
				printf(" ");

				gotoxy(x - 2, y-=2); //���� �̵��� ��ġ�� �̵��Ͽ�
				printf(">"); //�ٽ� �׸���
			}
			break;
		}
		case DOWN: {
			if (y < 17) { //�ִ� 17
				gotoxy(x - 2, y);
				printf(" ");

				gotoxy(x - 2, y+=2);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 13; 
		}
		}
	}
	return 0;
}

void print_piano() {
	puts("�������������� �������� ��  �� ������������ ��  �� �������� ��  ��");
	puts("�������������� �������� ��  �� ������������ ��  �� �������� ��  ��");
	puts("�������������� �������� ��  �� ������������ ��  �� �������� ��  ��");
	puts("�������������� �������� ��  �� ������������ ��  �� �������� ��  ��");
	puts("�������������� �������� ��  �� ������������ ��  �� �������� ��  ��");
	puts("�������������� �������� ��  �� ������������ ��  �� �������� ��  ��");
	puts("��������������  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��");
	puts("��������������  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��");
	puts("��������������  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��");
	puts("������������������������������������������������������������������");

}

int pr_str_array(char** dp, int n) {
	while (1) {
		double frequency[] = { 523.2511, 587.3295, 659.2551, 698.456, 783.9909, 880, 987.7666 };
		const int note_len = 600;

		srand((unsigned int)time(NULL));
		int random = (rand() % 7);

		for (int i = 0; i < 7; i++) {
			if (random == i + 1) {
				Sleep(200);
			}
		}
		Beep(frequency[random], note_len);


		system("cls");

		char answer[10];

		print_piano();

		gotoxy(29, 17);
		printf("���� ���ϱ��?: ");
		scanf("%s", answer);

		if (!strcmp(answer, *(dp + random))) {
			printf("�����Դϴ�.\n");
		}
		else {
			printf("Ʋ�Ƚ��ϴ�. ������ %s�Դϴ�.\n", *(dp + random));
			//2�� �Ŀ� ������
			break;
		}
	}
	return 0;
}

int playGame() {
	char* p[SIZE] = { "��", "��", "��", "��", "��" , "��", "��" };
	while (1) {
		if (keyControl() == SUBMIT)
			break;
		int n = keyControl();
		switch (n) {
		case SUBMIT: {
			return pr_str_array(p, SIZE);
		}
		}
	}
	return 0;
}
void rule() {
	system("cls");
	gotoxy(26, 14);
	printf("�׳� ��� ���߼���");
	gotoxy(75, 29);
	printf("������ �����Ϸ��� �����̽��ٸ� ��������...");
	playGame();
}

void guess_note(void) {
	system("cls");

	char* p[SIZE] = { "��", "��", "��", "��", "��" , "��", "��" };
	int x = 100, y = 20;
	char key;	


	while (1) {
		int menuCode = menuDraw();
		switch (menuCode) {
		case 0:
			pr_str_array(p, SIZE);
			break;
		case 2:
			rule();
			break;
		case 4:
			main();
			break;
		}
		system("cls");
	}

	do {
		gotoxy(x, y);
		printf("guess note");
		key = _getch();
	} while (key != ESC);

	return 0;
}