#include<time.h>
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>

#define my_Y 31

int game_speed;
int character = 1;
int shop_page[3] = { 1, 0, 0 }, bought_item[3][6], have_the_item[2][6];
int easter_egg1;
int money;
int my_shot_x[50], my_shot_y[50];
int HP = 10,stage = 1, discount_point = 100, level = 0;
int aaa_for_army_nomal_1, bbb_for_army_nomal_1, army_nomal_1_locate, attack_allow_for_army_nomal_1, hp_for_army_nomal_1 = 30;
int aaa_for_army_nomal_2, aaa2_for_army_nomal_2, aaa3_for_army_nomal_2, bbb_for_army_nomal_2, bbb2_for_army_nomal_2, bbb3_for_army_nomal_2, army_nomal_2_locate, attack_allow_for_army_nomal_2[3] = { 0 }, hp_for_army_nomal_2 = 20;
int aaa_for_army_nomal_threo[3] = {160, 160, 160}, bbb_for_army_nomal_thrreo[3] = {20, 30, 40}, hp_for_army_nomal_threo_[3] = {10,10,10}, nomal_threo_help[3], army_threo_attack_time = 0;
int aaa_for_army_nomal_3,aaa2_for_army_nomal_3,aaa_for_army_nomal_3_last = 160, bbb_for_army_nomal_3,bbb2_for_army_nomal_3, army_nomal_3_locate, attack_allow_for_army_nomal_3, attack2_allow_for_army_nomal_3 , hp_for_army_nomal_3 = 30;
int aaa_for_army_nomal_3_2, aaa2_for_army_nomal_3_2, aaa_for_army_nomal_3_2_last = 160, bbb_for_army_nomal_3_2, bbb2_for_army_nomal_3_2, army_nomal_3_2_locate, attack_allow_for_army_nomal_3_2, attack2_allow_for_army_nomal_3_2, hp_for_army_nomal_3_2 = 30;
int aaa_for_army_nomal_4, bbb_for_army_nomal_4, army_nomal_4_locate, attack_allow_for_army_nomal_4, hp_for_army_nomal_4 = 40, army_nomal_4 = 160;

int midle_boss_hp = 100, midle_boss_attacking[5], midle_boss_aaa[5], midle_boss_bbb[5], xxx_midle_boss, yyy_midle_boss, XXX_MIDLE_BOSS, YYY_MIDLE_BOSS, midle_boss_move_allow = 1, midle_boss_xxx_locate, midle_boss_yyy_locate;

struct nomal_army
{
    int hp;
    int locate_y;
    int move;
};

int Keyboard()  //Ű���� �Է¹ޱ�
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    else
    {
        return 0;
    }
}

void mousecursor(int x, int y)     //Ŀ���̵�
{
    COORD xyxyxy;
    xyxyxy.X = x;
    xyxyxy.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xyxyxy);
}

void Text()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
}

void color_Black()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0|0<<4);
}

void color_Blue()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1|1<<4);
}

void color_Green()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2|2<<4);
}

void color_Aqua()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3|3<<4);
}

void color_Red()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4|4<<4);
}

void color_Purple()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5|5<<4);
}

void color_Yellow()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6|6<<4);
}

void color_White()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7|7<<4);
}

void color_Gray()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8|8<<4);
}

void color_Light_Blue()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9|9<<4);
}

void color_Light_Green()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10|10<<4);
}

void color_Light_Aqua()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11|11<<4);
}

void color_Light_Red()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12|12<<4);
}

void color_Light_Purple()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13|13<<4);
}

void color_Light_Yellow()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14|14<<4);
}

void color_Light_White()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15|15<<4);
}

void SetConsolesize()     //�ʱ� �ܼ� â ����
{
    CONSOLE_CURSOR_INFO cursor = { 0,0 };
    system("mode con:cols=200 lines=61");
    cursor.dwSize = 1;
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void printing_dot(int xy[21][15], int x, int y)
{
    int a = x;
    int b = y;
    int i, j;
    for (i = 0;i<21;y++, i++)
    {
        for (x = a, j = 0;j<15;x+=2, j++)
        {
            if (xy[i][j] == 0)
            {
                color_Black();
                mousecursor(x, y);
                printf("�Ƣ�");
            }
            else if (xy[i][j] == 1)
            {
                color_Blue();
                mousecursor(x, y);
                printf("�Ƣ�");
            }
            else if (xy[i][j] == 2)
            {
                color_Green();
                mousecursor(x, y);
                printf("�Ƣ�");
            }
            else if (xy[i][j] == 3)
            {
                color_Aqua();
                mousecursor(x, y);
                printf("�Ƣ�");
            }
            else if (xy[i][j] == 4)
            {
                color_Red();
                mousecursor(x, y);
                printf("�Ƣ�");
            }
            else if (xy[i][j] == 5)
            {
                color_Purple();
                mousecursor(x, y);
                printf("�Ƣ�");
            }
            else if (xy[i][j] == 6)
            {
                color_Yellow();
                mousecursor(x, y);
                printf("�Ƣ�");
            }
            else if (xy[i][j] == 7)
            {
                color_White();
                mousecursor(x, y);
                printf("�Ƣ�");
            }
            else if (xy[i][j] == 8)
            {
                color_Gray();
                mousecursor(x, y);
                printf("�Ƣ�");
            }
        }
    }
}
void imformation()
{
    easter_egg1++;
    mousecursor(30,10);
    color_Blue();
    for (int x = 30; x<=170 ;x+=1)
    {

        printf("��");
    }
    mousecursor(30, 50);
    for (int x = 30; x <= 170; x+=1)
    {
        printf("��");
    }
    for (int y = 10; y <= 50 ;y++)
    {
        mousecursor(30,y);
        printf("�Ƣ�");
    }
    for (int y = 10; y <= 50; y++)
    {
        mousecursor(170, y);
        printf("�Ƣ�");
    }
    Text();
    mousecursor(95, 13);
    if (easter_egg1>9)
    {
        printf("�ձ�  ����");
    }
    else
    {
        printf("�ռ�����");
    }
    mousecursor(40, 20);
    printf("1. ����,  �� : w   �Ʒ� : s  �߻� : p (�߻� ���߿��� ������ ��� ����)");
    mousecursor(40, 21);
    printf("          �����̽���(�߰���ų) : ������������ �뽬 �� ��������ü �߻�");
    mousecursor(40, 25);
    printf("2. ���Ӿ�����,   �� : �ڽ��� �� ü��ȸ��(�ʰ����� ������ ���� ȯ��) , �� : ������ ���, �� : �ڽſ��� ����");
    mousecursor(40, 30);
    printf("3. ���Ӹ�ǥ,    ���� ����, ������ Ȧ�� ������ ����� ���� �߽ɺο� ��ġ�� �Ź��� ���߼Ҹ� �ı��ؾ� �մϴ�.");
    mousecursor(40, 31);
    printf("                ���� ���ޱ�, ������, ����� ���� �ı��ϰ� �ڽ��� ��ȭ�Ͽ� �ӹ��� �ϼ��ϼ���!");
    mousecursor(40, 35);
    printf("4. ������ ��ȭ,  1��ȭ: ����ü �ӵ� ����, 2��ȭ: �����̽��� ��ų ����, 3��ȭ: ����ü �߰�, ���� ȿ�� ����");
    mousecursor(85,47);
    system("pause");
    system("Cls");
}

void SetConsolesize_lose_the_game(int point)     //���κ� �ܼ� â ����_1(�й�)
{
    system("Cls");
    system("mode con:cols=30 lines=30");
    Sleep(100);
    system("color 40");
    Sleep(500);
    mousecursor(5, 5);
    printf("�ƢƢƢƢƢƢƢƢƢ�");
    mousecursor(5, 6);
    printf("��G A M E O V E R ��");
    mousecursor(5, 7);
    printf("�ƢƢƢƢƢƢƢƢƢ�");
    Sleep(500);
    mousecursor(9, 12);
    printf("������������");
    Sleep(200);
    mousecursor(20, 14);
    printf("%d ��\n\n\n\n\n\n", point);
    Sleep(100);
}

void shoting()
{
    for (int x = 0, y = 0;x<50;x++, y++)
    {
        if (my_shot_x[x] == 0)
        {
            continue;
        }
        Text();
        mousecursor(my_shot_x[x], my_shot_y[y]+2);
        printf(" ");
        mousecursor(my_shot_x[x], my_shot_y[y]+6);
        printf(" ");
        color_Light_Blue();
        mousecursor(my_shot_x[x] + 2, my_shot_y[y] + 2);
        printf("��");
        mousecursor(my_shot_x[x] + 2, my_shot_y[y] + 6);
        printf("��");
        if (my_shot_x[x]>190)
        {
            Text();
            mousecursor(my_shot_x[x] + 2, my_shot_y[y] + 2);
            printf(" ");
            mousecursor(my_shot_x[x] + 2, my_shot_y[y] + 6);
            printf(" ");
            my_shot_x[x] = 0;
        }
    }

    color_Black();
}

void drawing_my_character(int my_airplane_y) //�÷��̾��� ������ �׸���
{
    color_Gray();
    mousecursor(3, my_airplane_y);
    printf("�ƢƢƢ�");
    mousecursor(1, my_airplane_y + 1);
    printf("�ƢƢƢƢƢƢƢƢƢƢƢ�");
    mousecursor(3, my_airplane_y + 2);
    printf("�ƢƢƢƢƢƢƢƢƢƢƢ�");
    mousecursor(3, my_airplane_y + 3);
    printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
    mousecursor(5, my_airplane_y + 4);
    printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
    mousecursor(3, my_airplane_y + 5);
    printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
    mousecursor(3, my_airplane_y + 6);
    printf("�ƢƢƢƢƢƢƢƢƢƢƢ�");
    mousecursor(1, my_airplane_y + 7);
    printf("�ƢƢƢƢƢƢƢƢƢƢƢ�");
    mousecursor(3, my_airplane_y + 8);
    printf("�ƢƢƢ�");

    Text();
    mousecursor(3, my_airplane_y + 1);
    printf("    ");
    mousecursor(5, my_airplane_y + 2);
    printf("        ");
    mousecursor(5, my_airplane_y + 3);
    printf("          ");
    mousecursor(7, my_airplane_y + 4);
    printf("          ");
    mousecursor(5, my_airplane_y + 5);
    printf("          ");
    mousecursor(5, my_airplane_y + 6);
    printf("        ");
    mousecursor(3, my_airplane_y + 7);
    printf("    ");

    color_Blue();
    mousecursor(3,my_airplane_y + 1);
    printf("�ƢƢƢ�");
    mousecursor(5, my_airplane_y + 2);
    printf("�ƢƢƢƢƢƢƢ�");
    mousecursor(5, my_airplane_y + 3);
    printf("�ƢƢƢƢƢƢƢƢƢ�");
    mousecursor(7, my_airplane_y + 4);
    printf("�ƢƢƢƢƢƢƢƢƢ�");
    mousecursor(5, my_airplane_y + 5);
    printf("�ƢƢƢƢƢƢƢƢƢ�");
    mousecursor(5, my_airplane_y + 6);
    printf("�ƢƢƢƢƢƢƢ�");
    mousecursor(3, my_airplane_y + 7);
    printf("�ƢƢƢ�");

    Text();
    mousecursor(3, my_airplane_y + 1);
    printf("  ");
    mousecursor(9, my_airplane_y + 2);
    printf("    ");
    mousecursor(7, my_airplane_y + 3);
    printf("  ");
    mousecursor(11, my_airplane_y + 4);
    printf("    ");
    mousecursor(7, my_airplane_y + 5);
    printf("  ");
    mousecursor(9, my_airplane_y + 6);
    printf("    ");
    mousecursor(3, my_airplane_y + 7);
    printf("  ");

    color_Black();
    mousecursor(3, my_airplane_y + 1);
    printf("�Ƣ�");
    mousecursor(9, my_airplane_y + 2);
    printf("�ƢƢƢ�");
    mousecursor(7, my_airplane_y + 3);
    printf("�Ƣ�");
    mousecursor(11, my_airplane_y + 4);
    printf("�ƢƢƢ�");
    mousecursor(7, my_airplane_y + 5);
    printf("�Ƣ�");
    mousecursor(9, my_airplane_y + 6);
    printf("�ƢƢƢ�");
    mousecursor(3, my_airplane_y + 7);
    printf("�Ƣ�");
}

void line()
{
    Text();
    mousecursor(0,8);
    for (int x = 0;x<200;x+=4)
    {
        printf(" �� ");
    }
    mousecursor(0, 53);
    for (int x = 0;x<200;x+=4)
    {
        printf(" �� ");
    }
    color_Black();
}

struct nomal_army army_1 = {300, 20, 0};
void drawing_army_1()
{
    color_Gray();
    mousecursor(171, army_1.locate_y);
    printf("�ƢƢƢƢƢƢƢ�");
    mousecursor(168, army_1.locate_y + 1);
    printf("�ƢƢƢƢƢƢƢƢƢ�");
    mousecursor(161, army_1.locate_y + 2);
    printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
    mousecursor(168, army_1.locate_y + 3);
    printf("�ƢƢƢƢƢƢƢƢƢ�");
    mousecursor(171, army_1.locate_y + 4);
    printf("�ƢƢƢƢƢƢƢ�");

    color_Light_Red();
    mousecursor(170, army_1.locate_y+1);
    printf("�ƢƢƢƢƢ�");
    mousecursor(165, army_1.locate_y+2);
    printf("�ƢƢƢƢƢƢƢƢƢ�");
    mousecursor(170, army_1.locate_y+3);
    printf("�ƢƢƢƢƢ�");

    color_Black();
    mousecursor(171, army_1.locate_y+2);
    printf("�Ƣ�");

    if (0)
    {

    }
}

void army_apper() // �� ����
{
    Text();
    mousecursor(100, 1);
    printf("���� ���带 �����մϴ�.");
    mousecursor(110, 3);
    printf(">>5<<");
    Sleep(1000);
    mousecursor(110, 3);
    printf(">>4<<");
    Sleep(1000);
    mousecursor(110, 3);
    printf(">>3<<");
    Sleep(1000);
    mousecursor(110, 3);
    printf(">>2<<");
    Sleep(1000);
    mousecursor(110, 3);
    printf(">>1<<");
    Sleep(1000);
    color_Black();
}

void drawing_HP_bar()  // �÷��̾��� HPǥ��
{
    Text();
    mousecursor(5, 55);
    printf("�âââââââââââ�");
    mousecursor(5, 56);
    printf("��");
    if (HP>10)
    {
        for (;HP>10;HP--)
        {
            level++;
        }
    }
    for (int a = HP; a > 0; a--)
    {
        printf("��");
    }
    mousecursor(27, 56);
    printf("��");
    mousecursor(5, 57);
    printf("�âââââââââââ�");
    color_Black();
}

void drawing_level_bar()
{
    Text();
    mousecursor(105, 55);
    printf("�̢̢̢̢�");
    mousecursor(105, 56);
    printf("��");
    if (level > 9)
    {
        for (;level > 9;level -= 1)
        {
            discount_point += 30;
        }
    }
    for (int x = 0;x<level%3;x++)
    {
        printf("��");
    }
    mousecursor(113, 56);
    printf("��");
    mousecursor(105, 57);
    printf("�̢̢̢̢�");
    mousecursor(115, 56);
    printf("��");
    mousecursor(117, 55);
    printf("�̢̢�");
    mousecursor(117, 56);
    if (level/3 == 3)
    {
        printf("�̡���");
    }
    else
    {
        printf("��%2d��", level%3);
    }
    mousecursor(117, 57);
    printf("�̢̢�");
    color_Black();
}

void money_bar()
{
    Text();
    mousecursor(35,3);
    printf("���� �ܾ� ��%d��", money);
    color_Black();
}

void introduce_stage(int point)
{
    Text();
    mousecursor(150, 55);
    for (int x = 150 ; x<200; x+=10)
    {
        printf("�ޡޡޡޡ�");
    }
    for (int y = 55 ; y<60; y++)
    {
        mousecursor(150, y);
        printf("��");
    }
    for (int x = 150 ; x<190; x+=10)
    {
        printf("�ޡޡޡޡ�");
    }
    printf("�ޡޡޡ�");
    mousecursor(155, 57);
    
    color_Black();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////������//////////////////////////////////////////////////////////////////////
void no_stock()
{
    printf("");
}

void no_money()
{
    printf("");
}

void display_item_1()
{
    if (shop_page[0] == 1)
    {
        mousecursor(25, 16);
        printf("����");
        mousecursor(25, 17);
        printf("�ࢾ��");
        mousecursor(25, 18);
        printf("����");
        mousecursor(35, 16);
        printf("���� ����� ���� ��ġ");
        mousecursor(35, 17);
        printf("   �� : 1000");
        mousecursor(35, 20);
        printf("������� 10���� �������");
        mousecursor(35, 21);
        printf("���� 1�� ����� ȸ��");
        mousecursor(35, 25);
        if (3 - bought_item[0][0] >= 1)
        {
            printf("��� : %d", 3-bought_item[0][0]);
        }
        else
        {
            printf("������");
        }
    }
    else if (shop_page[1] == 1)
    {
        
    }
}

void display_item_2()
{
    if (shop_page[0] == 1)
    {
        mousecursor(74, 16);
        printf("�̢̢�");
        mousecursor(74, 17);
        printf("�̢���");
        mousecursor(74, 18);
        printf("�̢���");
        mousecursor(74, 19);
        printf("�̢̢�");
        mousecursor(84, 16);
        printf("����� ���� ���");
        mousecursor(84, 17);
        printf("   �� : 2000");
        mousecursor(84, 20);
        printf("������� 8���� �������");
        mousecursor(84, 21);
        printf("���� 2�� ����� ȸ��");
        mousecursor(84, 22);
        printf("(���� 5���� �������)");
        mousecursor(84, 23);
        printf("(1�� �߰� ����� ȸ��)");
        mousecursor(84, 25);
        if (2 - bought_item[0][1] >= 1)
        {
            printf("��� : %d", 2 - bought_item[0][1]);
        }
        else
        {
            printf("������");
        }
    }
    else if (shop_page[1] == 1)
    {

    }
}

void display_item_3()
{

}

void shop()
{
    system("color 5");
    mousecursor(10, 10);
    for (int x = 10;x<=190;x+=2)
    {
        printf("��");
    }
    for (int y = 11;y<=50;y++)
    {
        mousecursor(10, y);
        printf("��");
    }
    mousecursor(10, 50);
    for (int x = 10;x<=190;x+=2)
    {
        printf("��");
    }
    for (int y = 11;y<=50;y++)
    {
        mousecursor(190,y);
        printf("��");
    }
    mousecursor(20,13);
    for (int x = 20; x<= 65;x+=2)
    {
        printf("��");
    }
    for (int y = 13;y<=45;y++)
    {
        mousecursor(20, y);
        printf("��");
    }
    mousecursor(22, 14);
    printf("��");
    mousecursor(20, 27);
    for (int x = 20;x<=65;x+=2)
    {
        printf("��");
    }
    for (int y = 13;y<=45;y++)
    {
        mousecursor(66, y);
        printf("��");
    }
    mousecursor(70, 13);
    for (int x = 70 ; x<=115 ; x+=2)
    {
        printf("��");
    }
    for (int y = 13;y<=45;y++)
    {
        mousecursor(70, y);
        printf("��");
    }
    mousecursor(71, 14);
    printf("��");
    mousecursor(70, 27);
    for (int x = 70;x<=115;x+=2)
    {
        printf("��");
    }
    for (int y = 13;y<=45;y++)
    {
        mousecursor(116, y);
        printf("��");
    }
    int out_shop = 1;
    while (out_shop)
    {
        display_item_1();
        display_item_2();
        display_item_3();
        mousecursor(5, 5);
        printf("�ܾע� : %d", money);
        switch (Keyboard())
        {
        case('U'):
        case('u'):
        {
            out_shop = 0;
            break;
        }
        case('D'):
        case('d'):
        {
            if (shop_page[0] == 1)
            {
                shop_page[0] = 0;
                shop_page[1] = 1;
            }
            else if (shop_page[1] == 1)
            {
                shop_page[1] = 0;
                shop_page[2] = 1;
            }
            else
            {
                shop_page[2] = 0;
                shop_page[0] = 1;
            }
            break;
        }
        case('A'):
        case('a'):
        {
            if (shop_page[0] == 1)
            {
                shop_page[0] = 0;
                shop_page[2] = 1;
            }
            else if (shop_page[1] == 1)
            {
                shop_page[1] = 0;
                shop_page[0] = 1;
            }
            else
            {
                shop_page[2] = 0;
                shop_page[1] = 1;
            }
            break;
        }
        case('1'):
        case('!'):
        {
            if (shop_page[0] == 1)
            {   
                if (money >= 1000)
                {
                    if (bought_item[0][0] <3)
                    {
                        bought_item[0][0] += 1;
                        money -= 1000;
                        have_the_item[0][0] += 1;
                    }
                }
                else
                {
                    no_money();
                }
            }
            else if (shop_page[1] == 1)
            {
                if (money >= 1000)
                {
                    if (bought_item[1][0] < 3)
                    {
                        bought_item[1][0] += 1;
                        money -= 1000;
                    }
                }
                else
                {
                    no_money();
                }
            }
            else
            {
                if (money >= 5000)
                {
                    if (bought_item[2][0] == 0)
                    {
                        bought_item[2][0] = 1;
                        money -= 5000;
                        character = 2;
                    }
                    else if (bought_item[2][0] == 1)
                    {
                        character = 2;
                    }
                }
                else
                {
                    no_money();
                }
            }
            break;
        }
        case('2'):
        case('@'):
        {
            if (shop_page[0] == 1)
            {
                if (money >= 2000)
                {
                    if (bought_item[0][1] < 2)
                    {
                        bought_item[0][1] += 1;
                        money -= 2000;
                        have_the_item[0][1] += 1;
                    }
                }
                else
                {
                    no_money();
                }
            }
            else if (shop_page[2] == 1)
            {

            }
            break;
        }
        case('3'):
        case('#'):
        {
            if (shop_page[0] == 1)
            {
                if (money >= 4000)
                {
                    if (bought_item[0][2] < 2)
                    {
                        bought_item[0][2] += 1;
                        money -= 4000;
                        have_the_item[0][2] += 1;
                    }
                }
                else
                {
                    no_money();
                }
            }
        }
        case('4'):
        case('$'):
        {
            if (shop_page[0] == 1)
            {

            }
        }
        }
        Sleep(100);
    }

    system("Cls");
}

void item_1_hp_heal_mini()
{
    if (have_the_item[0][0] > 0)
    {
        mousecursor(45, 55);
        printf("����");
        mousecursor(45, 56);
        printf("�ࢾ��");
        mousecursor(45, 57);
        printf("����");
        mousecursor(45, 59);
        printf("�ܿ� %d", have_the_item[0][0]);
    }
}

void item_2_hp_heal()
{
    if (have_the_item[0][1] > 0)
    {
        mousecursor(50, 55);
        printf("�̢̢̢�");
        mousecursor(50, 56);
        printf("�̢�����");
        mousecursor(50, 57);
        printf("�̢̢̢�");
        mousecursor(50, 59);
        printf("�ܿ� %d", have_the_item[0][1]);
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int move_plane_y;
    int shot = 0;
    int point, clear_game = 0;
    int show_army_stage = 0;
    move_plane_y = my_Y;
    srand((unsigned)time(NULL));
    SetConsolesize();
    Sleep(100);
    for (int speed_set = 0;speed_set != 1;)
    {
        Text();
        mousecursor(80, 30);
        printf("<<<���� ����ӵ��� ������ �ּ���>>>");
        mousecursor(80, 31);
        printf("(���� �������� ����ӵ��� �����ϴ�)");
        mousecursor(80, 32);
        printf("        (���� : 70 ~ 100)");
        mousecursor(80, 35);
        printf("==>                                 ");
        mousecursor(85, 35);
        scanf_s("%d", &game_speed);
        if (game_speed > 0)
        {
            speed_set = 1;
        }
        else
        {
            mousecursor(80, 40);
            printf("�ٽ� �Է��� �ּ���");
        }
    }
    system("Cls");
    
    drawing_my_character(move_plane_y);
    for (point = 1; clear_game < 1; point++)
    {
        int plane_y_change = move_plane_y;
        switch (Keyboard())
        {
        case('2'):
        case('@'):
        {
            if (HP < 5 && have_the_item[0][1] > 0)
            {
                HP += 3;
                have_the_item[0][1] -= 1;
            }
            else if(HP <8 && have_the_item[0][1] > 0)
            {
                HP += 2;
                have_the_item[0][1] -= 1;
            }
            break;
        }
        case('1'):
        case('!'):
        {
            if (HP < 10&&have_the_item[0][0] > 0)
            {
                HP++;
                have_the_item[0][0] -= 1;
            }
            break;
        }
        case('U'):
        case('u'):
        {
            shop();
            break;
        }
        case('I'):
        case('i'):
        {
            imformation();
            break;
        }
        case('W'):
        case('w'):
        {
            if (move_plane_y >= 10)
            {
                move_plane_y -= 1;
            }

            break;
        }
        case('S'):
        case('s'):
        {
            if (move_plane_y <= 43)
            {
                move_plane_y += 1;
            }

            break;
        }
        case('P'):
        case('p'):
        {
            shot = 1;
            break;
        }

        default:
        {
            break;
        }
        }
        
        shoting();
        money_bar();

        introduce_stage(point);
        Text();
        mousecursor(190, 2);
        printf("��i��");
        mousecursor(55, 3);
        printf("������");
        mousecursor(55, 4);
        printf("�����");
        mousecursor(55, 5);
        printf("������");
        color_Black();
        Text();
        mousecursor(5, 3);
        printf("���� ����>%d<", point);
        color_Black();
        drawing_level_bar();

        
        if (shot == 1)
        {
            for (int x = 0 ; x<50 ; x++)
            {
                if (my_shot_x[x] == 0)
                {
                    my_shot_x[x] = 15;
                    my_shot_y[x] = move_plane_y;
                    shot = 0;
                    break;
                }
            }
        }
        for (int x = 0;x<50;x++)
        {
            if (my_shot_x[x] >= 1)
            {
                my_shot_x[x] += 2;
            }
        }

        if(point >=50&&stage == 1)
        {
            //drawing_army_1();
        }

        if (HP < 1)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////���߿� �̴ϰ��� �߰�//////////////
        {
            clear_game = 2;
            break;
        }
        else
        {
            drawing_HP_bar();
        }


        
        if (point >= discount_point)
        {
            point--;
        }
        if (plane_y_change != move_plane_y)
        {
            Sleep(game_speed);
            color_Black();
            mousecursor(0, plane_y_change);
            printf("                    \n                 \n                 \n                   \n                   \n                  \n                  \n                  \n                    ");
            drawing_my_character(move_plane_y);
        }

    }
    if (clear_game == 2)
    {
        SetConsolesize_lose_the_game(point);
    }
    Sleep(game_speed);
}