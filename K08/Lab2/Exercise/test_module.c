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
    List *l = NULL;
    l = list_push(l,1);
    l = list_push(l,2);
    l = list_push(l,3);
    l = list_prepend(l,4);

    TEST_CHECK(list_size(l)==4 && list_get_data(list_first(l)) == 4);

    list_free(l);
}

void test_list_add_after(){
    List *l = NULL;
    l = list_push(l,1);
    l = list_push(l,2);
    l = list_push(l,3);
    l = list_add_after_first(l,4);

    List *next = list_get_next(l);
    TEST_CHECK(list_size(l)==4 && list_get_data(next) == 4);

    list_free(l);
}

void test_list_merge(){
    List *l1 = NULL;
    l1 = list_push(l1,1);
    l1 = list_push(l1,2);
    l1 = list_push(l1,3);

    List *l2 = NULL;
    l2 = list_push(l2,4);
    l2 = list_push(l2,5);
    l2 = list_push(l2,6);

    l1 = list_merge(l1,l2);

    TEST_CHECK(list_size(l1)==6 && list_get_data(list_first(l1)) == 1 && list_get_data(list_last(l1)) == 6);

    list_free(l1);
}

TEST_LIST = {
        { "test_list_push", test_list_push  },
        { "test_list_prepend",  test_list_prepend  }, //EXERCISE
        { "test_list_add_after",  test_list_add_after  }, // EXERCISE
        { "test_list_merge",  test_list_merge  }, // EXERCISE
        { NULL, NULL } /* zeroed record marking the end of the list */
};

