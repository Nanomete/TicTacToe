#include <stdio.h>

void displayBoard(char board[3][3]) {
    printf("_____________\n");
    printf("_|_1_|_2_|_3_");
	printf("\n");
	for(int i=0;i<3;i++){
        printf("%d|", i+1);
		for(int j=0;j<3;j++){
			printf(" %c", board[i][j]);
			if (j < 2) {
                printf(" |");
                if (j == 2) {
                    printf("  |\n");
                }
            }
		}
		printf("\n");
		if (i < 2) printf("-|---+---+---\n");
	}
}


void playerMove(char board[3][3], char player) {
	int x, y;
	while(1){
		printf("\nPlayer %c, choose a location: ", player);
		scanf("%d %d", &x, &y);
		printf("\n");
		if(x <= 3 && x > 0 && y <= 3 && y > 0){
			if(board[x-1][y-1] == ' '){
				board[x-1][y-1] = player;
				break;
			}
		}else {
            printf("Try again.\n");
            displayBoard(board);
        }	
	}
}

int checkWinner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return (board[i][0] == 'X') ? 1 : 2;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return (board[0][j] == 'X') ? 1 : 2;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return (board[0][0] == 'X') ? 1 : 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return (board[0][2] == 'X') ? 1 : 2;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 3;
}

int main(){
	
	char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	char player;
    char seLect_player;
    int state = 0;
    printf("--------------------------------\n");
    printf(" Welcome to Tic Tac Toe game!!! \n");
    printf("--------------------------------\n");
    while (state == 0) {
        printf("select player X or O : ");
        scanf("%c", &seLect_player);
        getchar();
        if (seLect_player == 'x') seLect_player = 'X';
        if (seLect_player == 'o') seLect_player = 'O';
        switch (seLect_player)
        {
        case 'X':
            player = seLect_player;
            state = 1;
            break;
        case 'O':
            player = seLect_player;
            state = 1;
            break;
        default:
            printf("Please select player again\n");
            break;
        } 

    }
	int gameStatus = 0;
	
	while (gameStatus == 0) {
        displayBoard(board);
        playerMove(board, player);
        gameStatus = checkWinner(board);
        player = (player == 'X') ? 'O' : 'X';
    }
    
    displayBoard(board);
    
    if (gameStatus == 1) {
        printf("Player X wins!\n");
    } else if (gameStatus == 2) {
        printf("Player O wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;

}