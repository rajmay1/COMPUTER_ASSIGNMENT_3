#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//here we have created a function which we are going to use for getting random output from a dice 
int rollDice() {
    return (rand() % 6) + 1;
}

void printDice(int num) {
    switch(num) {
        case 1:
            printf("+-----+\n");
            printf("¦     ¦\n");
            printf("¦  $  ¦\n");
            printf("¦     ¦\n");
            printf("+-----+\n");
            break;
        case 2:
            printf("+-----+\n");
            printf("¦ $   ¦\n");
            printf("¦     ¦\n");
            printf("¦   $ ¦\n");
            printf("+-----+\n");
            break;
        case 3:
            printf("+-----+\n");
            printf("¦ $   ¦\n");
            printf("¦  $  ¦\n");
            printf("¦   $ ¦\n");
            printf("+-----+\n");
            break;
        case 4:
            printf("+-----+\n");
            printf("¦ $ $ ¦\n");
            printf("¦     ¦\n");
            printf("¦ $ $ ¦\n");
            printf("+-----+\n");
            break;
        case 5:
            printf("+-----+\n");
            printf("¦ $ $ ¦\n");
            printf("¦  $  ¦\n");
            printf("¦ $ $ ¦\n");
            printf("+-----+\n");
            break;
        case 6:
            printf("+-----+\n");
            printf("¦ $ $ ¦\n");
            printf("¦ $ $ ¦\n");
            printf("¦ $ $ ¦\n");
            printf("+-----+\n");
            break;
    }
}

void diceRollAnimation() {
    for (int i = 0; i < 5; i++) {
        int temp = rollDice();
        printDice(temp);
        Sleep(200);
        system("cls");
    }
}

int main() {
    srand(time(0));
    char pl1[50];
    char pl2[50];
    printf("Name of player 1 :");
	scanf("%49s",&pl1);
	printf("Name of player 2 :");
    scanf("%49s",&pl2);
	int rounds;
    printf("Enter number of rounds: ");
    scanf("%d", &rounds);

    int player1Score = 0, player2Score = 0;

    for (int i = 1; i <= rounds; i++) {

        printf("\n--- Round %d ---\n", i);

        // PLAYER 1
        printf("Player 1 rolling dice...\n");
        diceRollAnimation();
        int p1 = rollDice();
        setColor(12);
        printDice(p1);
        setColor(7);
        player1Score += p1;

        // PLAYER 2
        printf("Player 2 rolling dice...\n");
        diceRollAnimation();
        int p2 = rollDice();
        setColor(9);
        printDice(p2);
        setColor(7);
        player2Score += p2;

        printf("\nScores after  %d -> %s: %d | %s: %d\n",
               i,pl1, player1Score,pl2, player2Score);
    }

    printf("\n-------- Game Over --------\n\n");
    
    printf("Final Scores -> %s = %d | %s = %d\n",pl1,
           player1Score,pl2, player2Score);

    if (player1Score > player2Score){
	
        printf("%s Wins!!!\n",pl1);
        printf("%s Deserves a Treat From %s :) ",pl1,pl2);}
    else if (player2Score > player1Score){
	
        printf("%s Wins!!!\n",pl2);
        printf("%s Deserves a Treat From %s :) ",pl2,pl1);}
    else
        printf("It's a Tie!\n");

    return 0;
}

