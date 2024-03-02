#include <stdio.h>

#define USERNAMELIMIT 30
#define ROWLIMIT 6
#define COLUMNLIMIT 5

void greet(void);
void getUserName(char*, char*);


int main(){
    char player_1[USERNAMELIMIT], player_2[USERNAMELIMIT];
    char board[ROWLIMIT][COLUMNLIMIT] = {{' ', '|', ' ', '|', ' '}, {'-', '-', '-', '-', '-'}, 
                        {' ', '|', ' ', '|', ' '}, {'-', '-', '-', '-', '-'}, 
                        {' ', '|', ' ', '|', ' '}};
    greet();
    getUserName(player_1, player_2);
    for(int i=0;i<6;i++, printf("\n")){
        for(int j=0;j<5;j++){
            printf(" %c ", board[i][j]);
        }
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