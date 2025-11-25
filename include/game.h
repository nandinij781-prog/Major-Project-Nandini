#ifndef GAME_H
#define GAME_H

typedef struct {
    int userChoice;
    int compChoice;
    int result;
} GameResult;

extern const char *rpsNames[3];
extern const char *swgNames[3];

#endif
