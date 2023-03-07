#include <stdlib.h>
#include <limits.h>
#include "faulty_stack.h"
#include "acutest/acutest.h"

void test_stack_create(void){
    Stack *s = stack_init();

    TEST_CHECK( stack_peek(s) == INT_MIN );

    TEST_CHECK( stack_size(s) == 0 );

    stack_destroy(s);
}

void test_stack_push_peek(void){
    Stack *s = stack_init();

    s = stack_push(s,2);

    TEST_CHECK( stack_size(s) == 1  && stack_peek(s) == 2);

    s = stack_push(s,4);
    s = stack_push(s,6);
    s = stack_push(s,8);

    TEST_CHECK( stack_size(s) == 4 && stack_peek(s) == 8);

    stack_destroy(s);
}

void test_stack_pop(void){
    Stack *s = stack_init();

    s = stack_push(s,2);
    s = stack_push(s,4);
    s = stack_push(s,6);
    s = stack_push(s,8);

    int elem = stack_pop(s);
    TEST_CHECK( stack_size(s) == 3 && elem == 8);
    elem = stack_pop(s);
    TEST_CHECK( stack_size(s) == 2 && elem == 6);
    elem = stack_pop(s);
    TEST_CHECK( stack_size(s) == 1 && elem == 4);
    elem = stack_pop(s);
    TEST_CHECK( stack_size(s) == 0 && elem == 2);
    elem = stack_pop(s);
    TEST_CHECK( stack_size(s) == 0 && elem == INT_MIN);

    stack_destroy(s);
}

void test_stack_merge(void){
    Stack *s1 = stack_init();
    s1 = stack_push(s1,1);
    s1 = stack_push(s1,2);
    s1 = stack_push(s1,3);

    Stack *s2 = stack_init();
    s2 = stack_push(s2,4);
    s2 = stack_push(s2,5);
    s2 = stack_push(s2,6);

    Stack *s = stack_merge(s1,s2);

    int elem = stack_pop(s);
    TEST_CHECK( stack_size(s) == 5 && elem == 6);
    elem = stack_pop(s);
    TEST_CHECK( stack_size(s) == 4 && elem == 5);
    elem = stack_pop(s);
    TEST_CHECK( stack_size(s) == 3 && elem == 4);
    elem = stack_pop(s);
    TEST_CHECK( stack_size(s) == 2 && elem == 3);
    elem = stack_pop(s);
    TEST_CHECK( stack_size(s) == 1 && elem == 2);
    elem = stack_pop(s);
    TEST_CHECK( stack_size(s) == 0 && elem == 1);

    stack_destroy(s);
}

TEST_LIST = {
        { "test_stack_create", test_stack_create  },
        { "test_stack_push_peek", test_stack_push_peek },
        { "test_stack_pop", test_stack_pop },
        { "test_stack_merge",  test_stack_merge  },
        { NULL, NULL } /* zeroed record marking the end of the list */
};
