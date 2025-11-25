#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "utils.h"

void showMainMenu() {
    printf("\n----- MINI GAME PACK -----\n");
    printf("1. Guess The Number\n");
    printf("2. Rock Paper Scissors\n");
    printf("3. Snake Water Gun\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void guessNumber() {
    int num, guess, tries = 0;

    num = rand() % 100 + 1;

    printf("\nGuess the number between 1 to 100:\n");

    do {
        printf("Enter guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess > num) {
            printf("Too high!\n");
        } else if (guess < num) {
            printf("Too low!\n");
        } else {
            printf("Correct! You guessed it in %d tries.\n", tries);
        }
    } while (guess != num);
}

void rockPaperScissors() {
    GameResult gr;
    gr.compChoice = rand() % 3;

    printf("\n0 = Rock, 1 = Paper, 2 = Scissors\n");
    printf("Enter your choice: ");
    scanf("%d", &gr.userChoice);

    if (gr.userChoice < 0 || gr.userChoice > 2) {
        printf("Invalid choice!\n");
        return;
    }

    printf("You chose: %s\n", rpsNames[gr.userChoice]);
    printf("Computer chose: %s\n", rpsNames[gr.compChoice]);

    if (gr.userChoice == gr.compChoice) {
        gr.result = 0;
        printf("Draw!\n");
    }
    else if ((gr.userChoice == 0 && gr.compChoice == 2) ||
             (gr.userChoice == 1 && gr.compChoice == 0) ||
             (gr.userChoice == 2 && gr.compChoice == 1)) { 
        gr.result = 1;
        printf("You win!\n");
    } else {
        gr.result = -1;
        printf("Computer wins!\n");
    }
}

void snakeWaterGun() {
    GameResult gr;
    gr.compChoice = rand() % 3;

    printf("\n0 = Snake, 1 = Water, 2 = Gun\n");
    printf("Enter your choice: ");
    scanf("%d", &gr.userChoice);

    if (gr.userChoice < 0 || gr.userChoice > 2) {
        printf("Invalid choice!\n");
        return;
    }

    printf("You chose: %s\n", swgNames[gr.userChoice]);
    printf("Computer chose: %s\n", swgNames[gr.compChoice]);

    if (gr.userChoice == gr.compChoice) {
        gr.result = 0;
        printf("Draw!\n");
    }
    else if ((gr.userChoice == 0 && gr.compChoice == 1) ||  
             (gr.userChoice == 1 && gr.compChoice == 2) || 
             (gr.userChoice == 2 && gr.compChoice == 0)) { 
        gr.result = 1;
        printf("You win!\n");
    } else {
        gr.result = -1;
        printf("Computer wins!\n");
    }
}
