#include <stdio.h>
#include <conio.h>

#define TRACK_LENGTH 20
#define PLAYER_SYMBOL 'P'
#define FINISH_LINE 'F'


void printTrack(int playerPosition) {
    for (int i = 0; i < TRACK_LENGTH; i++) {
        if (i == playerPosition)
            printf("%c", PLAYER_SYMBOL);
        else
            printf("-");
    }
    printf("%c\n", FINISH_LINE);
}

int main() {
    int playerPosition = 0;
    char key;
    char prevKey = '\0';

    printf("레이싱 게임을 시작합니다\n");
    printf("목표: P 문자를 F 문자까지 이동시키세요.\n\n");

    while (1) {
        printTrack(playerPosition);
        key = _getch();

        if ((key == 'a' || key == 'd') && key != prevKey) 
        {
            if ((key == 'a' && playerPosition < TRACK_LENGTH - 1)||(key == 'd' && playerPosition < TRACK_LENGTH - 1))
                playerPosition++;
            prevKey = key;
        }
        else if (key == 'q')
            break;

        if (playerPosition == TRACK_LENGTH - 1) {
            printf("\n축하합니다! 목표 지점에 도착했습니다!\n");
            break;
        }


    }

    printf("\n게임을 종료합니다. 다시 도전해보세요!\n");

    return 0;
}
