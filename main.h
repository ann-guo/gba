#ifndef MAIN_H
#define MAIN_H

#include "gba.h"


// TODO: Create any necessary structs

/*
* For example, for a Snake game, one could be:
*
* struct snake {
*   int heading;
*   int length;
*   int row;
*   int col;
* };
*
* Example of a struct to hold state machine data:
*
* struct state {
*   int currentState;
*   int nextState;
* };
*
*/
extern u32 currentButtons;
extern u32 previousButtons;
typedef struct {
    //unsigned short dino1[1739];
    int row;
    int col;

} DINO;
typedef struct {
    int row;
    int col;
} DREAM;
typedef struct {
    int row;
    int col;
    
} ZOMBIE;

#endif
