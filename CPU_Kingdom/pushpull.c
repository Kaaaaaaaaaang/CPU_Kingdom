#include "pushpull.h"

// _getch() value of ESC key
#define ESC 27

// �ּ� 
/*
double rule(char name[][10]);
int result(char name[][10], int* result1, int* result2);
void gotoxy(int x, int y);

int main(void) {
	char name[2][10];
	double time;

	time = rule(name);
}
*/
void pushpull(void) {
	system("cls");

	int x = 100, y = 20;
	char key;

	do {
		gotoxy(96, y);
		printf("�ڡڡڡڡڡڡڡڡڡ� �ٴٸ��� �ڡڡڡڡڡڡڡڡڡ�\n");
		gotoxy(96, 21);
		printf("��");
		gotoxy(144, 21);
		printf("��");
		gotoxy(96, 22);
		printf("��       �����̽��ٿ� ���͸� Ȱ���Ͽ�           ��\n");
		gotoxy(96, 23);
		printf("�� ���� ���� ���� �ڱ������� ���� �����Դϴ�! ��\n");
		gotoxy(96, 24);
		printf("��                 ���� �º�!                   ��\n");
		gotoxy(96, 25);
		printf("��");
		gotoxy(144, 25);
		printf("��");
		gotoxy(96, 26);
		printf("��                    >.<                        �� ");
		gotoxy(144, 26);
		printf("��");
		gotoxy(96, 27);
		printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
		key = _getch();
	} while (key != ESC);
}

/*
double rule(char name[][10]) { 
	double time = 20; //���ѽð� 20��
	int i;
	for (i = 0; i < 3; i++) {
		print("%d�� �� �̸��� �Է����ּ���! -> "); //�� �̸� �Է¹���
		scanf("%s", &name[i]); // for������ 2�� �ݺ�
	}

	printf("\n\n\n");
	printf("�� ���ѽð� : ", time);
	sleep(1000);
	time--; //�ð� ����

	//�߾��� ǥ��
	gotoxy(38, 6); 
	printf("��");
	gotoxy(40, 7);
	printf("��");

	return time;
	
}

int result(char name[][10], int* result1, int* result2) { //����� ���
	gotoxy(1, 14);
	if (*result1 == 2) {
		printf("�١١� %s �¸�! �١١�");
		return 1;
	}
	else if (*result2 == 2) {
		printf("�١١� %s �¸�! �١١�");
		return 2;
	}
	return 0;
}

void rope(int a){ //�ٴٸ��� �� ����
	int i, line[21] = { 0 }; // 21ĭ
	line[10] = 1; //�� ���� ����
	line[4] = 2;
	line[16] = 2;
	gotoxy(1, 8);
	for (i = 0; i < 78; i++) {
		printf(" ");
	}
	gotoxy(a, 8);

	for (i = 0; i < 21; i++) { 
		if (line[i] == 0) {
			printf("��");
		}else if (line[i] == 1) { //�߽���
			printf("��");
		}else
			printf("��");
	}
} */
