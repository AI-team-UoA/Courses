#include <stdlib.h>
#include "vector.h"
#include "acutest/acutest.h"

void test_vector_capacity(void) {
    Vector* v = vector_create(3);

    TEST_ASSERT(vector_capacity(v) == 3);

    vector_free(v);
}

void test_vector_size(void) {
    Vector* v = vector_create(3);

    TEST_ASSERT(vector_size(v) == 0);

    vector_free(v);
}

void test_vector_at(void) {
    Vector* v = vector_create(1);

    vector_push_back(v, 1);
    vector_push_back(v, 2);
    vector_push_back(v, 3);

    TEST_ASSERT(vector_at(v, 0) == 1);
    TEST_ASSERT(vector_at(v, 1) == 2);
    TEST_ASSERT(vector_at(v, 2) == 3);

    vector_free(v);
}

void test_vector_set_at(void) {
    Vector* v = vector_create(2);

    vector_push_back(v, 0);
    vector_push_back(v, 1);
    vector_push_back(v, 2);

    TEST_ASSERT(vector_at(v, 0) == 0);
    TEST_ASSERT(vector_at(v, 1) == 1);
    TEST_ASSERT(vector_at(v, 2) == 2);

    vector_set_at(v, 0, 2);
    vector_set_at(v, 1, 1);
    vector_set_at(v, 2, 0);

    TEST_ASSERT(vector_at(v, 0) == 2);
    TEST_ASSERT(vector_at(v, 1) == 1);
    TEST_ASSERT(vector_at(v, 2) == 0);

    vector_free(v);
}

void test_vector_push_back(void) {
    Vector* v = vector_create(1);

    TEST_ASSERT(vector_capacity(v) == 1);
    vector_push_back(v, 1);
    TEST_ASSERT(vector_capacity(v) == 1);
    vector_push_back(v, 2);
    TEST_ASSERT(vector_capacity(v) == 2);
    vector_push_back(v, 3);
    TEST_ASSERT(vector_capacity(v) == 4);

    TEST_ASSERT(vector_at(v, 0) == 1);
    TEST_ASSERT(vector_at(v, 1) == 2);
    TEST_ASSERT(vector_at(v, 2) == 3);

    vector_free(v);
}

TEST_LIST = {
        { "test_vector_capacity", test_vector_capacity },
        { "test_vector_size", test_vector_size },
        { "test_vector_at", test_vector_at  },
        { "test_vector_set_at", test_vector_set_at },
        { "test_vector_push_back", test_vector_push_back },
        { NULL, NULL } /* zeroed record marking the end of the list */
};