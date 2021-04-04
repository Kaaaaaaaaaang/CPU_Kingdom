#include "guess_note.h"

// _getch() value of ESC key
#define ESC 27

void guess_note(void) {
	system("cls");

	int x = 100, y = 20;
	char key;

	char* p[SIZE] = { "��", "��", "��", "��", "��" , "��", "��" };
	pr_str_array(p, SIZE);

	do {
		gotoxy(x, y);
		printf("guess note");
		key = _getch();
	} while (key != ESC);
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


		char answer[10];

		printf("������ �����ϱ��?: ");
		scanf("%s", answer);

		if (!strcmp(answer, *(dp + random))) {
			printf("�¾ҽ��ϴ�.\n");
		}
		else {
			printf("Ʋ�Ƚ��ϴ�. ������ %s�Դϴ�.\n", *(dp + random));
			break;
		}
	}
	return 0;
}