#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <windows.h>
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"


char board[3][3];

int checkwin() //승리자가 나왔는지 무승부인지 확인한다.
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return 1;

    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return 1;

    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return 1;

    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return 1;

    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return 1;

    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return 1;

    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;

    else if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
        return 1;

    else if (board[0][0] != ' ' && board[1][0] != ' ' && board[2][0] != ' ' &&
        board[0][1] != ' ' && board[1][1] != ' ' && board[2][1] != ' ' && board[0][2]
        != ' ' && board[1][2] != ' ' && board[2][2] != ' ')

        return 0;
    else
        return  -1;
}


int main(void) {
   int x, y, mode;

   //보드를 초기화한다. 
   for (x = 0; x < 3; x++)
      for (y = 0; y < 3; y++) board[x][y] = ' ';

    printf(ANSI_COLOR_CYAN "1. 수동 모드\n2. 자동 모드\n\n" ANSI_COLOR_RESET "모드를 선택하세요: ");

	scanf("%d", &mode);

	printf(ANSI_COLOR_CYAN "게임을 시작합니다." ANSI_COLOR_RESET "\n\n");

   // 사용자로부터 위치를 받아서 보드에 표시한다. 
    for (int round = 0; round < 9; round++) {
		//system("cls");

        printf("(x, y) 좌표: ");
        scanf("%d %d", &x, &y);

        if (round % 2 == 0) {
            if (board[x][y] == ('X' & 'O')) {
                printf(ANSI_COLOR_CYAN "다시 놓으십시오." ANSI_COLOR_RESET "\n");
                round = round - 1;
            }
            else board[x][y] = 'X';
        }

		else if (round % 2 == 1) {
            if (board[x][y] == ('X' & 'O')) {
                printf(ANSI_COLOR_CYAN "다시 놓으십시오." ANSI_COLOR_RESET "\n");
                round = round - 1;
            }
            else board[x][y] = 'O';
        }

        if (x >= 3 || y >= 3 || x < 0 || y < 0) {
            printf(ANSI_COLOR_YELLOW "잘못된 위치입니다." ANSI_COLOR_YELLOW "\n");
            printf(ANSI_COLOR_CYAN "다시 놓으십시오." ANSI_COLOR_RESET "\n");
            round = round - 1;
        }

        printf("player 1 (X)  vs  computer(O)\n");

        for (int i = 0; i < 3; i++) {
            printf("\t---|---|---\n");
            printf("\t %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        }
        printf("\t---|---|---\n\n");



        if (checkwin() == 1) {
            if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == 'X') {
				printf("player1의 승리입니다.\n");
				break;
			}
            else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == 'X') {
				printf("player1의 승리입니다.\n");
				break;
			}
            else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == 'X') {
				printf("player1의 승리입니다.\n");
				break;
			}
            else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == 'X') {
				printf("player1의 승리입니다.\n");
				break;
			}
            else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == 'X') {
				printf("player1의 승리입니다.\n");
				break;
			}
            else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == 'X') {
				printf("player1의 승리입니다.\n");
				break;
			}
            else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'X') {
				printf("player1의 승리입니다.\n");
				break;
			}
            else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] == 'X') {
				printf("player1의 승리입니다.\n");
				break;
			}

            else if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == 'O') {
				printf("computer의 승리입니다.\n");
				break;
			}
            else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == 'O') {
				printf("computer의 승리입니다.\n");
				break;
			}
            else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == 'O') {
				printf("computer의 승리입니다.\n");
				break;
			}
            else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == 'O') {
				printf("computer의 승리입니다.\n");
				break;
			}
            else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == 'O') {
				printf("computer의 승리입니다.\n");
				break;
			}
            else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == 'O') {
				printf("computer의 승리입니다.\n");
				break;
			}
            else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'O') {
				printf("computer의 승리입니다.\n");
				break;
			}
            else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] == 'O') {
				printf("computer의 승리입니다.\n");
				break;
			}

            // else printf("computer의 승리입니다.\n");
        }

        else if (checkwin() == 0)
			printf("무승부입니다.\n");

    }

   return 0;
}

