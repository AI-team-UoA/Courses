#include <stdio.h>
#include <stdlib.h>
#include "mem_errors.h"

/*
 *  Lab exercise that showcases uninitialized errors and how to
 *  deal with them using valgrind.
 */

//What happens when we don't allocate space for
//a structure that we want to use
void uninitialized_use(){
    Point *p;
    //p=malloc(sizeof(Point));
    p->x = 5;
    p->y = 6;
    free(p);
}

//A common error. Using arrays/buffers without initialized their values.
void conditional_jump_on_uninitialized(){
    int array[10];
    /*
     for(int i=0;i<10;i++){
        array[i]=0;
     }
     */
    if(array[0]==0)
        printf("Is it ok?\n");
    else
        printf("Something went wrong!\n");
}
