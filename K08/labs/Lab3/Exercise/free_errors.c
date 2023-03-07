#include <stdio.h>
#include <stdlib.h>
#include "mem_errors.h"

/*
 *  Lab exercise that showcases incorrect de-allocations and double frees.
 */

//Function that showcases the problem with double frees
void double_free(){
    //Allocate array memory
    int *array = malloc(sizeof(int)*10);

    //Initialize array
    for(int i=0;i<10;i++) {
        array[i] = i;
    }

    //Perform some operations with the array
    for(int i=0;i<10;i++){
        array[i] = array[i] + i*2;
    }

    int sum=0;
    for(int i=0;i<10;i++){
        sum = sum + array[i];
    }

    //The array is not needed anymore - its memory is deallocated
    free(array);

    printf("The array sum is %d\n",sum);
    int mean = sum/10;
    printf("The array mean value is %d\n",mean);

    //Double free on the array
    free(array);
}


//What happens when we free a variable and then use it again
void incorrect_free(){
    Point *p1 = malloc(sizeof(Point));
    p1->x = 5;
    p1->y = 3;

    printf("My point is (%d,%d)\n",p1->x,p1->y);

    //point freed
    free(p1);

    Point *p2 = malloc(sizeof(Point));
    p2->x = 2;
    p2->y = 1;

    printf("New point is (%d,%d)\n",p2->x,p2->y);

    //Calculation using freed Point p1
    int d = abs(p1->x - p2->x) + abs(p1->y - p2->y);

    printf("Distance is %d:", d);

    free(p2);
}