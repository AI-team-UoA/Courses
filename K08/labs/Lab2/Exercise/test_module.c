#include <stdlib.h>
#include <limits.h>
#include "list.h"
#include "acutest/acutest.h"

void test_list_push(){
    List *l = NULL;
    l = list_push(l,1);
    l = list_push(l,2);
    l = list_push(l,3);

    TEST_CHECK(list_size(l)==3 && list_get_data(list_first(l)) == 1 && list_get_data(list_last(l)) == 3);

    list_free(l);
}

//FUNCTIONS - LAB EXERCISE

void test_list_prepend(){

    //DELETE THIS
    TEST_CHECK(1 > 0);
}

void test_list_add_after(){

    //DELETE THIS
    TEST_CHECK(1 > 0);
}

void test_list_merge(){

    //DELETE THIS
    TEST_CHECK(1 > 0);
}

TEST_LIST = {
        { "test_list_push", test_list_push  },
        { "test_list_prepend",  test_list_prepend  }, //EXERCISE
        { "test_list_add_after",  test_list_add_after  }, // EXERCISE
        { "test_list_merge",  test_list_merge  }, // EXERCISE
        { NULL, NULL } /* zeroed record marking the end of the list */
};

