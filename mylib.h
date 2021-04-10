#ifndef MYLIB
#define MYLIB
#include "main.h"

extern int gravity;
extern int jumping;
extern int currentSpeed;
extern DINO dino;
extern ZOMBIE obj;
extern DREAM dream;
extern volatile int score;



void moveCactus(int x);
void moveSprite(DINO* sp, int x, int y);
void newFrame(const u16 *image);
int detectCollision(DREAM *dreamc, ZOMBIE *zom);
void jump(DREAM *dinoObj);
void move(void);
double sqrt(double x);
void nextRoom(void);

#endif