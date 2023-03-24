#include <stdio.h>
#include <stdlib.h>
#include "mem_errors.h"

/*
 *  Lab exercise that showcases invalid reads/writes in memory
 */

void invalid_read_write(){
    char *buf = malloc(sizeof(char)*5);

    for(int i=0;i<6;i++){
        buf[i] = 'a' + i; //Invalid write
    }

    printf("Character is %c\n",buf[5]); //Invalid read

    free(buf);
}

