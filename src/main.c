#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessNumber();
void rockPaperScissors();
void snakeWaterGun();

int main() {
    int choice;
    srand(time(NULL));

    while (1) {
        printf("\n----- MINI GAME PACK -----\n");
        printf("1. Guess The Number\n");
        printf("2. Rock Paper Scissors\n");
        printf("3. Snake Water Gun\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            guessNumber();
        }
        else if (choice == 2) {
            rockPaperScissors();
        }
        else if (choice == 3) {
            snakeWaterGun();
        }
        else if (choice == 4) {
            printf("Thank you for playing!\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
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
        }
        else if (guess < num) {
            printf("Too low!\n");
        }
        else {
            printf("Correct! You guessed it in %d tries.\n", tries);
        }

    } while (guess != num);
}

void rockPaperScissors() {
    int user, comp;
    comp = rand() % 3;

    printf("\n0 = Rock, 1 = Paper, 2 = Scissors\n");
    printf("Enter your choice: ");
    scanf("%d", &user);

    printf("Computer chose: %d\n", comp);

    if (user == comp) {
        printf("Draw!\n");
    }
    else if ((user == 0 && comp == 2) ||
             (user == 1 && comp == 0) ||
             (user == 2 && comp == 1)) {
        printf("You win!\n");
    }
    else {
        printf("Computer wins!\n");
    }
}

void snakeWaterGun() {
    int user, comp;
    comp = rand() % 3;

    printf("\n0 = Snake, 1 = Water, 2 = Gun\n");
    printf("Enter your choice: ");
    scanf("%d", &user);

    printf("Computer chose: %d\n", comp);

    if (user == comp) {
        printf("Draw!\n");
    }
    else if ((user == 0 && comp == 1) ||   // Snake drinks water
             (user == 1 && comp == 2) ||   // Water spoils gun
             (user == 2 && comp == 0)) {   // Gun kills snake
        printf("You win!\n");
    }
    else {
        printf("Computer wins!\n");
    }
}