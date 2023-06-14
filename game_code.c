#include<time.h>
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>

#define my_Y 31
#define gun_speed 5

int game_speed = 80;
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

//hp , y , move , show
struct nomal_army
{
    int hp;
    int locate_y;
    int move;
    int show;
};

char Keyboard()  //키보드 입력받기
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

void mousecursor(int x, int y)     //커서이동
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

void SetConsolesize()     //초기 콘솔 창 설정
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

            }
            else if (xy[i][j] == 1)
            {
                color_Blue();
                mousecursor(x, y);
                printf("▒▒");
            }
            else if (xy[i][j] == 2)
            {
                color_Green();
                mousecursor(x, y);
                printf("▒▒");
            }
            else if (xy[i][j] == 3)
            {
                color_Aqua();
                mousecursor(x, y);
                printf("▒▒");
            }
            else if (xy[i][j] == 4)
            {
                color_Red();
                mousecursor(x, y);
                printf("▒▒");
            }
            else if (xy[i][j] == 5)
            {
                color_Purple();
                mousecursor(x, y);
                printf("▒▒");
            }
            else if (xy[i][j] == 6)
            {
                color_Yellow();
                mousecursor(x, y);
                printf("▒▒");
            }
            else if (xy[i][j] == 7)
            {
                color_White();
                mousecursor(x, y);
                printf("▒▒");
            }
            else if (xy[i][j] == 8)
            {
                color_Gray();
                mousecursor(x, y);
                printf("▒▒");
            }
        }
    }
}

void imformation()
{
    easter_egg1++;
    system("Cls");
    mousecursor(30,10);
    color_Blue();
    for (int x = 30; x<=170 ;x+=1)
    {

        printf("▒");
    }
    mousecursor(30, 50);
    for (int x = 30; x <= 170; x+=1)
    {
        printf("▒");
    }
    for (int y = 10; y <= 50 ;y++)
    {
        mousecursor(30,y);
        printf("▒▒");
    }
    for (int y = 10; y <= 50; y++)
    {
        mousecursor(170, y);
        printf("▒▒");
    }
    Text();
    mousecursor(95, 13);
    if (easter_egg1>9)
    {
        printf("Φ그  만Φ");
    }
    else
    {
        printf("Φ설명서Φ");
    }
    mousecursor(40, 20);
    printf("1. 조작,  위 : w   아래 : s  발사 : p (발사 도중에는 움직임 잠시 제한)");
    mousecursor(40, 21);
    printf("          스페이스바(추가스킬) : 지정방향으로 대쉬 및 보조투사체 발사");
    mousecursor(40, 25);
    printf("2. 게임아이템,   ♥ : 자신의 총 체력회복(초과분은 레벨업 재료로 환산) , § : 레벨업 재료, ※ : 자신에게 피해");
    mousecursor(40, 30);
    printf("3. 게임목표,    당신은 환각을 보게하는 괴물과 맞서 싸워야합니다, 환각을 빠져나오고 적을 제압하세요.");
    mousecursor(40, 35);
    printf("4. 레벨당 강화,  1강화: 투사체 속도 증가, 2강화: 스페이스바 스킬 해제, 3강화: 투사체 추가, 이전 효과 증폭");
    mousecursor(85,47);
    system("pause");
    system("Cls");
}

void SetConsolesize_lose_the_game(int point)     //끝부분 콘솔 창 설정_1(패배)
{
    system("Cls");
    system("mode con:cols=30 lines=30");
    Sleep(100);
    system("color 40");
    Sleep(500);
    mousecursor(5, 5);
    printf("▒▒▒▒▒▒▒▒▒▒");
    mousecursor(5, 6);
    printf("▒G A M E O V E R ▒");
    mousecursor(5, 7);
    printf("▒▒▒▒▒▒▒▒▒▒");
    Sleep(500);
    mousecursor(9, 12);
    printf("★최종점수★");
    Sleep(200);
    mousecursor(20, 14);
    printf("%d 점\n\n\n\n\n\n", point);
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
        mousecursor(my_shot_x[x] + gun_speed, my_shot_y[y] + 2);
        printf("▒");
        mousecursor(my_shot_x[x] + gun_speed, my_shot_y[y] + 6);
        printf("▒");
        if (my_shot_x[x]>190)
        {
            Text();
            mousecursor(my_shot_x[x] + gun_speed, my_shot_y[y] + 2);
            printf("   ");
            mousecursor(my_shot_x[x] + gun_speed, my_shot_y[y] + 6);
            printf("   ");
            my_shot_x[x] = 0;
        }
    }

    color_Black();
}

void drawing_my_character(int my_airplane_y) //플래이어의 전투기 그리기
{
    color_Gray();
    mousecursor(3, my_airplane_y);
    printf("▒▒▒▒");
    mousecursor(1, my_airplane_y + 1);
    printf("▒▒▒▒▒▒▒▒▒▒▒▒");
    mousecursor(3, my_airplane_y + 2);
    printf("▒▒▒▒▒▒▒▒▒▒▒▒");
    mousecursor(3, my_airplane_y + 3);
    printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
    mousecursor(5, my_airplane_y + 4);
    printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
    mousecursor(3, my_airplane_y + 5);
    printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
    mousecursor(3, my_airplane_y + 6);
    printf("▒▒▒▒▒▒▒▒▒▒▒▒");
    mousecursor(1, my_airplane_y + 7);
    printf("▒▒▒▒▒▒▒▒▒▒▒▒");
    mousecursor(3, my_airplane_y + 8);
    printf("▒▒▒▒");

    color_Blue();
    mousecursor(3,my_airplane_y + 1);
    printf("▒▒▒▒");
    mousecursor(5, my_airplane_y + 2);
    printf("▒▒▒▒▒▒▒▒");
    mousecursor(5, my_airplane_y + 3);
    printf("▒▒▒▒▒▒▒▒▒▒");
    mousecursor(7, my_airplane_y + 4);
    printf("▒▒▒▒▒▒▒▒▒▒");
    mousecursor(5, my_airplane_y + 5);
    printf("▒▒▒▒▒▒▒▒▒▒");
    mousecursor(5, my_airplane_y + 6);
    printf("▒▒▒▒▒▒▒▒");
    mousecursor(3, my_airplane_y + 7);
    printf("▒▒▒▒");

    color_Black();
    mousecursor(3, my_airplane_y + 1);
    printf("▒▒");
    mousecursor(9, my_airplane_y + 2);
    printf("▒▒▒▒");
    mousecursor(7, my_airplane_y + 3);
    printf("▒▒");
    mousecursor(11, my_airplane_y + 4);
    printf("▒▒▒▒");
    mousecursor(7, my_airplane_y + 5);
    printf("▒▒");
    mousecursor(9, my_airplane_y + 6);
    printf("▒▒▒▒");
    mousecursor(3, my_airplane_y + 7);
    printf("▒▒");
}

void line()
{
    Text();
    mousecursor(0,8);
    for (int x = 0;x<200;x+=4)
    {
        printf(" ▦ ");
    }
    mousecursor(0, 53);
    for (int x = 0;x<200;x+=4)
    {
        printf(" ▦ ");
    }
    color_Black();
}

struct nomal_army army_1 = {1000, 20, 0, 1};
void drawing_nomal_army_1()
{
    if (army_1.show == 1)
    {
        mousecursor(1,army_1.locate_y);
    }
    else
    {

    }
}

void drawing_HP_bar()  // 플래이어의 HP표시
{
    Text();
    mousecursor(5, 55);
    printf("▣▣▣▣▣▣▣▣▣▣▣▣");
    mousecursor(5, 56);
    printf("▣");
    if (HP>10)
    {
        for (;HP>10;HP--)
        {
            level++;
        }
    }
    for (int a = HP; a > 0; a--)
    {
        printf("♥");
    }
    mousecursor(27, 56);
    printf("▣");
    mousecursor(5, 57);
    printf("▣▣▣▣▣▣▣▣▣▣▣▣");
    color_Black();
}

void drawing_level_bar()
{
    Text();
    mousecursor(105, 55);
    printf("▩▩▩▩▩");
    mousecursor(105, 56);
    printf("▩");
    if (level > 9)
    {
        for (;level > 9;level -= 1)
        {
            discount_point += 30;
        }
    }
    for (int x = 0;x<level%3;x++)
    {
        printf("§");
    }
    mousecursor(113, 56);
    printf("▩");
    mousecursor(105, 57);
    printf("▩▩▩▩▩");
    mousecursor(115, 56);
    printf("□");
    mousecursor(117, 55);
    printf("▩▩▩");
    mousecursor(117, 56);
    if (level/3 == 3)
    {
        printf("▩×▩");
    }
    else
    {
        printf("▩%2d▩", level%3);
    }
    mousecursor(117, 57);
    printf("▩▩▩");
    color_Black();
}

void money_bar()
{
    Text();
    mousecursor(35,3);
    printf("현재 잔액 ♧%d♧", money);
    color_Black();
}

void introduce_stage(int point)
{
    Text();
    mousecursor(150, 55);
    for (int x = 150 ; x<200; x+=10)
    {
        printf("◇◇◇◇◇");
    }
    for (int y = 55 ; y<60; y++)
    {
        mousecursor(150, y);
        printf("◇");
    }
    for (int x = 150 ; x<190; x+=10)
    {
        printf("◇◇◇◇◇");
    }
    printf("◇◇◇◇");
    mousecursor(155, 57);
    
    color_Black();
}

void print_speak(char text[50])
{
    for (int c = 0;c<50;c++)
    {
        if (text[c] == 0)
        {
            break;
        }
        printf("%c", text[c]);
        Sleep(30);
    }
}

int clear_dal_go_na = 0;
int nemocheck[15][30] =
{
    7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,6,7,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,7,
};
int total = 0;
void check(int a, int b) {
    int i;
    if ((90 < a && a < 120) && (b == 20 || b == 34))
    {
        if (a == 119)
        {

            color_Black();

            printf("  ");
        }
        else
        {
            color_Black();

            printf(" ");
        }
        i = 0;
    }
    else if ((a == 91 || a == 119) && (20 < b && b < 34))
    {

        color_Black();

        printf("00");
        i = 0;
    }
    else
    {
        color_Red();
        printf("ads");
        Sleep(1000);
        color_Black();
        system("Cls");
        i = 1;
    }

    if (i == 0)
    {
        int a1 = a - 91, b1 = b - 20;
        if (nemocheck[b1][a1] == 6)
        {
            nemocheck[b1][a1] = 7;
            total++;
        }
    }
    
    if (total == 83)
    {
        clear_dal_go_na = 1;
    }
}
void look(void) {
    int a = 91, b = 20;
    mousecursor(a, b);
    color_Black();
    printf("a");
    while (clear_dal_go_na == 0) {
        switch (Keyboard())
        {
        case('W'):
        case('w'):
        {
            b--;
            mousecursor(a, b);
            check(a, b);
            Sleep(100);
            break;
        }
        case('S'):
        case('s'):
        {
            b++;
            mousecursor(a, b);
            check(a, b);
            Sleep(100);
            break;
        }
        case('A'):
        case('a'):
        {
            a--;
            mousecursor(a, b);
            check(a, b);
            Sleep(100);
            break;
        }
        case('D'):
        case('d'):
        {
            a++;
            mousecursor(a, b);
            check(a, b);
            Sleep(100);
            break;
        }
        }
       

    }
}
void printing_O(int xy[38][40], int x, int y)
{
    int a = x;
    int b = y;
    int i, j;
    for (i = 0; i < 38; y++, i++)
    {
        for (x = a, j = 0; j < 40; j++, x += 2)
        {

            if (xy[i][j] == 6)
            {
                color_Light_Yellow();
                mousecursor(x, y);
                printf("▒▒");
            }
            else if (xy[i][j] == 7)
            {
                color_Yellow();
                mousecursor(x, y);
                printf("▒▒");
            }
            else if (xy[i][j] == 9)
            {
                color_Gray();
                mousecursor(x, y);
                printf("▒▒");
            }
        }
    }
}


int main()
{
    int move_plane_y;
    int shot = 0;
    int point, clear_game = 0;
    int show_army_stage = 0;
    move_plane_y = my_Y;
    srand((unsigned)time(NULL));
    SetConsolesize();

    int O[38][40] =
    {
    0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7,7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,7,7,7,9,9,9,9,9,9,9,9,9,9,9,9,9,9,7,7,7,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,7,7,9,9,9,9,7,7,7,7,7,7,7,7,7,7,7,7,9,9,9,9,7,7,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,7,9,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,9,7,0,0,0,0,0,0,0,
    0,0,0,0,0,0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,7,0,0,0,0,0,0,
    0,0,0,0,0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,7,0,0,0,0,0,
    0,0,0,0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,7,0,0,0,0,
    0,0,0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,7,0,0,0,
    0,0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,7,0,0,
    0,0,7,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,7,0,0,
    0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,7,0,
    0,7,9,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,9,7,0,
    0,7,9,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,9,7,0,
    7,9,9,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,9,9,7,
    7,9,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,9,7,
    7,9,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,9,7,
    7,9,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,9,7,
    7,9,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,9,7,
    7,9,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,9,7,
    7,9,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,9,7,
    7,9,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,9,7,
    7,9,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,9,7,
    7,9,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,9,7,
    7,9,9,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,9,9,7,
    0,7,9,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,7,7,7,9,7,0,
    0,7,9,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,9,7,0,
    0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,7,0,
    0,0,7,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,7,0,0,
    0,0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,7,0,0,
    0,0,0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,7,0,0,0,
    0,0,0,0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,7,0,0,0,0,
    0,0,0,0,0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,7,0,0,0,0,0,
    0,0,0,0,0,0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,7,0,0,0,0,0,0,
    0,0,0,0,0,0,0,7,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,7,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,7,9,9,9,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,9,9,9,7,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,7,7,9,9,9,9,9,7,7,7,7,7,7,7,7,7,7,9,9,9,9,7,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,9,9,9,9,9,9,9,9,9,9,9,9,7,7,7,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };
    


    /*printing_O(O, 65, 9);

    look();
    system("Cls");*/



    Sleep(3000);
    Text();
    mousecursor(70, 30);
    print_speak("접속승인.");
    Sleep(3000);
    mousecursor(150, 35);
    for (int x = 198;x>146;x-=2)
    {
        color_Gray();
        mousecursor(x, 35);
        printf("▒▒");
        color_Light_White();
        mousecursor(x, 36);
        printf("▒▒");
        mousecursor(x, 37);
        printf("▒▒");
        mousecursor(x, 38);
        printf("▒▒");
        color_Gray();
        mousecursor(x, 39);
        printf("▒▒");
        Sleep(50);
    }
    Sleep(1000);
    mousecursor(150, 36);
    color_Black();
    for (int x = 5;x>0;x--)
    {
        printf("▒");
        Sleep(100);
    }
    Sleep(1000);
    for (int x = 150, y = 36;y>30;y--, x--)
    {
        color_White();
        mousecursor(x, y);
        printf("▒▒▒▒▒");
        Sleep(70);
    }
    Sleep(500);
    color_Black();
    mousecursor(146,31);
    for (int x = 3;x>0;x--)
    {
        printf("▒");
        Sleep(100);
    }

    Sleep(1000);
    color_Blue();
    mousecursor(146, 31);
    printf("▒▒▒");
    Sleep(1000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    mousecursor(147, 30);
    printf("▒");
    Sleep(100);
    mousecursor(144, 29);
    printf("▒▒▒▒▒▒▒");
    Sleep(100);
    mousecursor(141, 28);
    printf("▒▒▒▒▒▒▒▒▒▒▒▒▒");
    Sleep(100);
    mousecursor(135, 27);
    printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
    Sleep(100);
    mousecursor(135, 26);
    printf("▒");
    Sleep(100);
    mousecursor(135, 25);
    printf("▒");
    Sleep(100);
    mousecursor(135, 24);
    printf("▒");
    Sleep(2000);
    mousecursor(137, 25);
    print_speak(". . .");
    Sleep(3000);
    mousecursor(137, 25);
    print_speak("미열람 음성녹음이 1건 발견되었습니다.");
    Sleep(3000);
    mousecursor(137, 25);
    print_speak("재생하시겠습니까?    Y / N           ");
    int yes_or_no_story_select = 0;
    while (yes_or_no_story_select == 0)
    {
        switch (Keyboard())
        {
        case('Y'):
        case('y'):
        {
            yes_or_no_story_select = 1;
            break;
        }
        case('N'):
        case('n'):
        {
            yes_or_no_story_select = 2;
            break;
        }

        }
    }

    if (yes_or_no_story_select == 1)
    {
        
    }
    system("Cls");
    Sleep(2000);
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
        printf("【i】");
        mousecursor(55, 3);
        printf("♣♣♣");
        mousecursor(55, 4);
        printf("♣ⓤ♣");
        mousecursor(55, 5);
        printf("♣♣♣");
        color_Black();
        Text();
        mousecursor(5, 3);
        printf("현재 점수>%d<", point);
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
                my_shot_x[x] += gun_speed;
            }
        }

        if(point >=50&&stage == 1)
        {
            //drawing_army_1();
        }

        if (HP < 1)/////////////////////////////////////////////////////////////////////////////////////////////////////////////////나중에 미니게임 추가//////////////
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
        Sleep(game_speed);
    }
    if (clear_game == 2)
    {
        SetConsolesize_lose_the_game(point);
    }
}