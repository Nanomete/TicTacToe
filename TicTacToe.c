#include <stdio.h>

void displayBoard(char board[3][3]) {
	printf("\n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%c", board[i][j]);
			if (j < 2) printf(" | ");
		}
		printf("\n");
		if (i < 2) printf("---------\n");
	}
}


void playerMove(char board[3][3], char player) {
	int x, y;
	while(1){
		printf("\nPlayer %c, choose a location: ", player);
		scanf("%d %d", &x, &y);
		
		if(x < 3 && x >= 0 && y < 3 && y >= 0){
			if(board[x][y] == ' '){
				board[x][y] = player;
				break;
			}
		}else printf("Try again.");	
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

main(){
	
	char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	char player = 'X';
	
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

}
