#include <stdio.h>
#include <stdlib.h>
#include "mem_errors.h"

int main(){
    //Initialization errors
    uninitialized_use();
    conditional_jump_on_uninitialized();

    //Memory errors
    //invalid_read_write();

    //Incorrect de-allocation/double free
    //double_free();
    //incorrect_free();

    //Memory leaks
    //no_deallocation();
}
