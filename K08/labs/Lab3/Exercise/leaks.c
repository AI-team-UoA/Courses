#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mem_errors.h"

/*
 *  Lab exercise that showcases the use of valgrind to pinpoint memory leaks
 */

void no_deallocation(){
    Point *p = malloc(sizeof(Point));
    p->x = 5;
    p->y = 3;

    printf("This is a point (%d,%d)\n",p->x,p->y);

    int n=5;
    int *array = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        array[i]=i+1;
    }

    int sum = 0;
    for(int i=0;i<5;i++){
        sum += array[i];
    }
    printf("Sum of the array is %d\n",sum);

    Point *p2 = malloc(sizeof(Point));
    p2->x = 10;
    p2->y = 7;

    printf("This is a second point (%d,%d)\n",p2->x,p2->y);

    int value = (abs(p->x - p2->x)+abs(p->y - p2->y)) / sum;

    if(value>3) {
        printf("OK!\n");
    }
    else{
        printf("NOT OK! I WILL REVERSE MY ARRAY\n");

        int *reversed = malloc(sizeof(int)*n);
        for(int i=0;i<n;i++){
            reversed[i]=array[n-1-i];
        }

        printf("My reversed array is :\n");
        for(int i=0;i<n;i++){
            printf("%d\n",reversed[i]);
        }
    }
}

