#include "bluewhite.h"

#define MAGIC_KEY 224 //����Ű
#define SPACE 32
#define ENTER 13

int check = 0;
int key;
int score_bluewhite = 0;
int RoundCnt = 1;

enum MENU
{
    GAMESTART = 0,
    INFO,
    QUIT
};

enum KEYBOARD
{
    UP = 72,
    LEFT = 75,
    RIGHT = 77,
    DOWN = 80
};


void PlayGame();
void animation();
void erase();

//���� ����
int main_bluewhtie(void)
{
    while (1)
    {
        switch (ReadyGame())    //���ϰ� �޾Ƽ� �Ǵ�.
        {
        case GAMESTART:
            PlayGame();
            break;
        case QUIT:
            if (key == ENTER) exit(0);  //exit(0) ��������
            return 0;
        }
    }
    return 0;
}

//����ȭ��
void DrawReadyGame()
{
    system("cls");          //clean screen - ȭ�� û��
    gotoxy(45, 5);
    printf("              ��");
    gotoxy(45, 6);
    printf("              |");
    gotoxy(45, 7);
    printf("******************************");
    gotoxy(45, 8);
    printf("*        û �� �� ��         *");
    gotoxy(45, 9);
    printf("******************************");
    gotoxy(38, 10);
    printf("********************************************");
    gotoxy(38, 11);
    printf("|     ���ѽð��� 15���̸� �� 3�ܰ��Դϴ�   |");
    gotoxy(38, 12);
    printf("|                                          |");
    gotoxy(38, 13);
    printf("|                Game Start                |");
    gotoxy(38, 14);
    printf("|                   Quit                   |");
    gotoxy(38, 15);
    printf("|                                          |");
    gotoxy(38, 16);
    printf("|         û�� �÷� Q  û�� ���� A         |");
    gotoxy(38, 17);
    printf("|         ��� �÷� E  ��� ���� D         |");
    gotoxy(38, 18);
    printf("|                                          |");
    gotoxy(38, 19);
    printf("********************************************");
    gotoxy(38, 19);
    printf("********************************************");
    gotoxy(98, 30);
    printf("������ ������ Ȳ����");

}

enum MENU ReadyGame()
{
    int y = 0; //Ŀ���� y��ġ
    int input = 0; // Ű���� �Է� �� ���� ����
    while (1)            //���� ����
    {

        DrawReadyGame();    //�غ�ȭ��

        //DrawUserCursor �Լ�
        if (y <= 0)        //Ŀ���� ���� �� �ö��� �ʰ�
        {
            y = 0;
        }
        else if (y >= 2) //Ŀ���� �Ʒ��� �׸� ��������
        {
            y = 1;
        }

        gotoxy(53, 13 + y); // Ŀ�� �޴��� ���缭 ��ġ����
        printf(">");

        input = _getch();    //Ű����� �ϳ��� Ű �Է�

        if (input == MAGIC_KEY) //����Ű�� ������ ��� -> ����Ű �Ǻ�
        {
            switch (_getch())
            {
            case UP:            //����Ű ��
                --y;
                break;
            case DOWN:            //����Ű �Ʒ�
                ++y;
                break;
            }
        }
        else if (input == ENTER) //enter ������ ���
        {
            switch (y)            //y��ġ�� ���� �Ǵ�
            {
            case 0:    //���ӽ���
                return GAMESTART;
            case 1:     //������
                return QUIT;

            }
        }
    }
}

void GameOver() {
    //�ð��ʰ��� ���ӿ��� 
    Sleep(2000);
    system("cls");
    gotoxy(45, 8);
    printf("******************************");
    gotoxy(45, 9);
    printf("*      G A M E  O V E R      *");
    gotoxy(45, 10);
    printf("******************************");
    gotoxy(45, 11);
    printf("    �ð��� �ʰ� �Ǿ����ϴ�");
    gotoxy(44, 12);
    printf(" ����� �� ������ %d�� �Դϴ�", score_bluewhite);
    gotoxy(37, 15);
    printf("����ȭ������ �Ѿ���� �ƹ�Ű�� 1�� �����ּ���");
    score_bluewhite = 0;
    RoundCnt = 1;

    system("pause>null");
}

//û���� ����
void FlagRandom() {

    srand((int)time(NULL));     //���� �ߺ�����
    int c;

    clock_t old_time, cur_time;

    char flag[12][50] = { "û�� �÷�","��� ������ ���� û�� �÷�", "û�� �ø��� ��� ��������",//Q Ű
                          "û�� ����","��� �ø��� ���� û�� ����","û�� ������ ��� �ø�����",//A Ű
                          "��� �÷�","û�� ������ ���� ��� �÷�","��� �ø��� û�� ��������", //E Ű
                          "��� ����", "û�� �ø��� ���� ��� ����","��� ������ û�� �ø�����" //D Ű
    };

    gotoxy(54, 3);
    printf("\n �������� : %d", score_bluewhite);
    old_time = clock();    //���� �ð�
    animation(0);

    for (int j = 1; j <= 10; j++) {  //���� ����
        system("cls");
        gotoxy(57, 5);
        printf("%dROUND \n", RoundCnt);
        gotoxy(55, 3);
        printf("�������� : %d", score_bluewhite);
        gotoxy(46, 7);
        int rn = (rand() % 12) + 1;
        printf("%d. %s", j, flag[rn - 1]);

        cur_time = clock();  //����  �ð�
        if (((double)(cur_time - old_time) / CLOCKS_PER_SEC) > 15) {
            GameOver(); main_bluewhtie();  break; //check = 0;
        }

        animation(0);

        if (c = _getch()) { //Ű�� �Է¹޾� ����Ű���� �Ǵ��ϰ� ���� ����
            switch (c) {
            case 27: score_bluewhite = 0; main_bluewhtie(); break;
            case 'q':
                animation(c);

                Sleep(500);
                if (rn == 1 || rn == 2 || rn == 3)
                    score_bluewhite += 50;
                else {
                    gotoxy(59, 9);
                    printf("�ٽ�!");
                    c = _getch();
                }
                break;
            case 'a':
                animation(c);
                Sleep(500);
                if (rn == 4 || rn == 5 || rn == 6)
                    score_bluewhite += 50;
                else {
                    gotoxy(59, 9);
                    printf("�ٽ�!");
                    c = _getch();
                }
                break;
            case 'e':
                animation(c);
                Sleep(500);
                if (rn == 7 || rn == 8 || rn == 9)
                    score_bluewhite += 50;
                else {
                    gotoxy(59, 9);
                    printf("�ٽ�!");
                    c = _getch();
                }
                break;
            case 'd':
                animation(c);
                Sleep(500);
                if (rn == 10 || rn == 11 || rn == 12)
                    score_bluewhite += 50;
                else {
                    gotoxy(59, 9);
                    printf("�ٽ�!");
                    c = _getch();
                }
                break;
            default: gotoxy(59, 9); printf("�ٽ�!"); c = _getch(); break; //Q A E D�� �ƴϸ� �׳� ���
            }

        }
        if (j == 10) {
            RoundCnt++;
            check = 1;
            system("cls");
            gotoxy(45, 8);
            printf("******************************");
            gotoxy(45, 9);
            printf("*       TOTAL SCORE=%d        *", score_bluewhite);
            gotoxy(45, 10);
            printf("******************************");

            Sleep(1000);
            gotoxy(37, 15);
            printf("����ȭ������ �Ѿ���� �ƹ�Ű�� 2�� �����ּ���");
            Sleep(1000);
        }
    }
    system("pause>null");
}


void basicAni() {
    gotoxy(57, 12);
    printf("�����");
    gotoxy(57, 13);
    printf("#��##��#");
    gotoxy(57, 14);
    printf("#######");
    gotoxy(57, 15);
    printf("#_____#");
    gotoxy(57, 16);
    printf("#######");
    gotoxy(59, 17);
    printf("##");
    gotoxy(47, 18);
    printf("���������������ᦡ��");
    gotoxy(53, 19);
    printf("��������");
    gotoxy(53, 20);
    printf("��������");
    gotoxy(53, 21);
    printf("��������");
    gotoxy(53, 22);
    printf("��������");
}


void animation(char key) {

    basicAni();
    erase();

    switch (key)
    {
    case 'q':
        basicAni();

        gotoxy(45, 16);
        printf("��");
        gotoxy(45, 17);
        printf("��");
        gotoxy(45, 18);
        printf("��");
        gotoxy(74, 18);
        printf("��");
        gotoxy(76, 18);
        printf("��");
        break;
    case 'a':
        basicAni();
        gotoxy(45, 20);
        printf("��");
        gotoxy(45, 19);
        printf("��");
        gotoxy(45, 18);
        printf("��");
        gotoxy(74, 18);
        printf("��");
        gotoxy(76, 18);
        printf("��");
        break;
    case 'e':
        basicAni();
        gotoxy(74, 16);
        printf("��");
        gotoxy(74, 17);
        printf("��");
        gotoxy(74, 18);
        printf("��");
        gotoxy(45, 18);
        printf("��");
        gotoxy(43, 18);
        printf("��");
        break;
    case 'd':
        basicAni();
        gotoxy(74, 20);
        printf("��");
        gotoxy(74, 19);
        printf("��");
        gotoxy(74, 18);
        printf("��");
        gotoxy(45, 18);
        printf("��");
        gotoxy(43, 18);
        printf("��");
        break;
    default:
        basicAni();
        gotoxy(74, 18);
        printf("��");
        gotoxy(76, 18);
        printf("��");
        gotoxy(45, 18);
        printf("��");
        gotoxy(43, 18);
        printf("��");
        break;
    }
}
void erase(void)
{
    gotoxy(40, 12);
    printf("                                                                                                                                                                                                                                                                                                                           ");
    gotoxy(40, 13);
    printf("                                                                                                                                                                                                                                                                                                                           ");
    gotoxy(40, 14);
    printf("                                                                                                                                                                                                                                                                                                                           ");
    gotoxy(40, 15);
    printf("                                                                                                                                                                                                                                                                                                                           ");
    gotoxy(40, 16);
    printf("                                                                                                                                                                                                                                                                                                                           ");
    gotoxy(40, 17);
    printf("                                                                                                                                                                                                                                                                                                                           ");
    gotoxy(40, 18);
    printf("                                                                                                                                                                                                                                                                                                                           ");
    gotoxy(40, 19);
    printf("                                                                                                                                                                                                                                                                                                                           ");
    gotoxy(40, 20);
    printf("                                                                                                                                                                                                                                                                                                                           ");
    gotoxy(40, 21);
    printf("                                                                                                                                                                                                                                                                                                                           ");
    gotoxy(40, 22);
    printf("                                                                                                                                                                                                                                                                                                                           ");

}


void GameClear() {
    system("cls");
    gotoxy(45, 8);
    printf("******************************");
    gotoxy(45, 9);
    printf("*    G A M E  C L E A R      *");
    gotoxy(45, 10);
    printf("******************************");
    gotoxy(45, 11);
    printf("  ����� �� ������ %d�� �Դϴ�", score_bluewhite);
    gotoxy(37, 15);
    printf("����ȭ������ �Ѿ���� �ƹ�Ű�� 2�� �����ּ���");
    score_bluewhite = 0;
    RoundCnt = 1;
    system("pause>null");

}; //3�ܰ���� �����ϸ�


//1�ܰ�
void Step1() {
    int time = 20; //���ѽð�
    gotoxy(57, 5);
    printf("1ROUND \n");
    Sleep(1000); //1���� ����
    //Timer20();//20�����ѽð�
    FlagRandom(20);
    system("pause>null");
}

//2�ܰ�
void Step2() {
    int time = 15; //���ѽð�
    gotoxy(57, 5);
    printf("2ROUND \n");
    Sleep(1000); //1���� ����
    FlagRandom();
    system("pause>null");
}
void Step3() {
    int time = 15; //���ѽð�
    gotoxy(57, 5);
    printf("3ROUND \n");
    Sleep(1000); //1���� ����
    FlagRandom();
    system("pause>null");
}

//2��Ÿ�̸�
void Timer2() {
    gotoxy(52, 1);
    printf("2���� ���� �մϴ�\n");
    Sleep(2000); //1000 -> 1��
    system("cls");
}

//���� ����
void PlayGame() {

    system("cls");
    Timer2();
    Step1();
    Timer2();
    Step2();
    Timer2();
    Step3();
    GameClear();
    system("pause>null");
}


