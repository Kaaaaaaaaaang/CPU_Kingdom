#include "guess_note.h"
#include "string.h"
#include "time.h"

// _getch() value of ESC key
#define ESC 27

void guess_note(void) {
	system("cls");

	int x = 100, y = 20;
	char key;

	makeRandom();

	do {
		gotoxy(x, y);
		printf("guess note");
		key = _getch();
	} while (key != ESC);
}

int makeRandom() {
	system("cls");
	int count = 0;
	while (1) {
		char note[7][2] = { "��", "��", "��", "��", "��", "��", "��" };
		double frequency[] = { 523.2511, 587.3295, 659.2551, 698.456, 783.9909, 880, 987.7666 };
		const int note_len = 600;

		//1-7������ ���� ����
		srand((unsigned int)time(NULL));
		int random = 1 + (rand() % 7); 
		int strcmp(const void* ptr1, const void* ptr2);
		char answer[20];

		for (int i = 0; i < 7; i++) {
			if (random == i + 1) {
				Sleep(200);
			}
		}
		Beep(frequency[random - 1], note_len);

		printf("������ �����ϱ��?: ");
		scanf_s("%s", answer);

		if (!strcmp(answer, note[random - 1])) {
			printf("�¾ҽ��ϴ�.\n");
			rewind(stdin);
		}
		else {
			printf("Ʋ�Ƚ��ϴ�.");
			printf("������ %s�Դϴ�. ", note[random - 1]);
			break;
		}
	}
	return 0;
}