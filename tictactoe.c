#include <stdio.h>

#define USERNAMELIMIT 30
#define ROWLIMIT 5
#define COLUMNLIMIT 5

void greet(void);
void getUserName(char *, char *);
void printBoard(char [][COLUMNLIMIT]);
int updateBoard(int, char [][COLUMNLIMIT], char);
int checkStatus(char [][COLUMNLIMIT]);

int main(){
    char player_1[USERNAMELIMIT], player_2[USERNAMELIMIT];
    char board[ROWLIMIT][COLUMNLIMIT] = {{' ', '|', ' ', '|', ' '}, 
                                         {'-', '-', '-', '-', '-'}, 
                                         {' ', '|', ' ', '|', ' '}, 
                                         {'-', '-', '-', '-', '-'}, 
                                         {' ', '|', ' ', '|', ' '}};
    greet();
    getUserName(player_1, player_2);
    char x = 'X', o = 'O';
    printf("%s takes %c\n%s takes %c\n", player_1, x, player_2, o);
    printBoard(board);
    int turn = 0;
    while(checkStatus(board)){
        int position = 0;
        
        char piece;
        if(0 == turn % 2){
            printf("%s turn\n", player_1);
            printf("Enter position (1-9) : ");
            scanf("%d", &position);
            turn++;
            piece = x;
        }
        else if(1 == turn % 2){
            printf("%s turn\n", player_2);
            printf("Enter position (1-9) : ");
            scanf("%d", &position);
            turn++;
            piece = o;
        }

        if(position > 9 || position < 1){
            printf("Enter a valid position\n");
            turn--;
            printBoard(board);
            continue;
        }
        int r = updateBoard(position, board, piece);
        if(!r){
            printf("Already marked. Choose another\n");
            turn--;
            printBoard(board);
            continue;
        }
        printf("\n");
        printBoard(board);
    }
    return 0;
}

void greet(void){
    printf("Welcome to TicTacToe\n");
    printf("--------------------\n\n");
}

void getUserName(char *p1, char *p2){
    printf("Enter the player names\n");
    printf("Player 1 : ");
    scanf("%[^\n]%*c", p1);
    printf("Player 2 : ");
    scanf("%[^\n]%*c", p2);
    printf("\n");
}

void printBoard(char board[][COLUMNLIMIT]){
    for(int i=0;i<ROWLIMIT;i++, printf("\n")){
        for(int j=0;j<COLUMNLIMIT;j++){
            printf(" %c ", board[i][j]);
        }
    }
}

int updateBoard(int position, char board[][COLUMNLIMIT], char piece){
    int valid_position[9][2] = {{0, 0}, {0, 2}, {0, 4},
                                {2, 0}, {2, 2}, {2, 4},
                                {4, 0}, {4, 2}, {4, 4}};
    int *positions = valid_position[position-1];
    if(board[positions[0]][positions[1]] != ' '){
        return 0;
    }
    board[positions[0]][positions[1]] = piece;
    return 1;
}

int checkStatus(char board[][COLUMNLIMIT]){
    return 0;
}