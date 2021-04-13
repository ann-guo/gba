#include <string.h>
#include "mylib.h"
#include "main.h"
#include "gba.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


#include "images/garbage.h"

#include "images/zombie.h"



DREAM dream;
ZOMBIE obj;
int jumping;
int currentspeedY;
int gravity = -1;
volatile int score;
int count;


void newFrame(const u16 *image) {
  drawFullScreenImageDMA(image);
  
  
}

int detectCollision(DREAM *obj1, ZOMBIE *obj2) {
    if(obj1->col < 139 || obj1->col >=170) {
        double dx = abs(obj1->col - obj2->col);
        double dy = abs(obj1->row - obj2->row);
        double distance = sqrt((dx*dx) + (dy*dy));
        if(distance <= 19) { //collision
            
            return -1;
        } 
    }
    if(obj1->col >= 139 && obj1->col <170) {
        double dx = abs(obj1->col - obj2->col);
        double dy = abs(obj1->row - obj2->row);
        double distance2 = sqrt((dx*dx) + (dy*dy));
        if(distance2 <= 38) {
            return -1;
        }
    }
    return 0;
    
    
}

double sqrt(double x) {
    if (x <= 0)
        return 0;       // if negative number throw an exception?
    int exp = 0;
    x = frexp(x, &exp); // extract binary exponent from x
    if (exp & 1) {      // we want exponent to be even
        exp--;
        x *= 2;
    }
    double y = (1+x)/2; // first approximation
    double z = 0;
    while (y != z) {    // yes, we CAN compare doubles here!
        z = y;
        y = (y + x/y) / 2;
    }
    return ldexp(y, exp/2); // multiply answer by 2^(exp/2)
}
void moveZombie(ZOMBIE *zomb) {
  undrawImage3(obj.row, obj.col, 19, 38, zombie);
  zomb-> col -= 2;
  drawImageDMA(obj.row, obj.col, 19, 38, zombie);
    
}


void jump(DREAM *dreamc) {
  
  if(jumping==0){
    jumping=1;
    currentspeedY = 11;
  }
  
  
  currentspeedY = currentspeedY + gravity;
  dreamc->row -= currentspeedY;
    
  if(dreamc->row >= 75) {
    jumping = 0;
    
    dream.row = 75;
  } else {
    //mid air - apply gravity
    //if(detectCollision(&dino,&obj) == -1) {
    //  fillScreenDMA(RED);
  //}
    
    dreamc->row -=currentspeedY;
    dream.row = dreamc->row;
    //moveSprite(&(*dinoObj), dino.row, dino.col);
    
    
  }
  
}
void move(void) {
   
    if((KEY_HELD(BUTTON_UP, currentButtons, previousButtons) || jumping == 1 ) && KEY_HELD(BUTTON_RIGHT, currentButtons, previousButtons)) {
          jump(&dream);
          dream.col +=5;
          
    }
    if(KEY_HELD(BUTTON_RIGHT, currentButtons, previousButtons)) {
          dream.col += 3;
    }
    if(KEY_HELD(BUTTON_LEFT, currentButtons, previousButtons)) {
        dream.col -= 3;
    }
    if ((KEY_HELD(BUTTON_LEFT, currentButtons,previousButtons)) && (KEY_HELD(BUTTON_UP, currentButtons, previousButtons) || jumping == 1 )) {
        jump(&dream);
        dream.col -=5;
    }
}


    

