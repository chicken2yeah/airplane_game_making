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

    printf("���̽� ������ �����մϴ�!\n");
    printf("��ǥ: P ���ڸ� F ���ڱ��� �̵���Ű����.\n\n");

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
            printf("\n�����մϴ�! ��ǥ ������ �����߽��ϴ�!\n");
            break;
        }


    }

    printf("\n������ �����մϴ�. �ٽ� �����غ�����!\n");

    return 0;
}
