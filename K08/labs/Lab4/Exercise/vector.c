#include "vector.h"
#include <assert.h>

struct vector_struct {
    datatype*   array;
    size_t      size;
    size_t      capacity;
};

Vector* vector_create(size_t capacity)
{
    Vector* v = malloc(sizeof(Vector));
    v->array = malloc(sizeof(datatype) * capacity);
    v->capacity = capacity;
    v->size = 0;
    return v;
}

/* -------------------------- */
/* FUNCTIONS FOR LAB EXERCISE */
/* -------------------------- */

// Free all memory allocated for the vector.
void vector_free(Vector* vector)
{
    /* EXERCISE */
}

// Return the value stored at the given index (equivalent to [i] for arrays)
datatype vector_at(Vector* vector, int index)
{
    /* EXERCISE */
}

// Set the value stored at the given index. It should handle out of bounds indices without crashing.
void vector_set_at(Vector* vector, int index, datatype data)
{
    /* EXERCISE */
}

// Add a new value at the end of the vector. This can grow the size of the vector.
void vector_push_back(Vector* vector, datatype data)
{
    /* EXERCISE */
}

size_t vector_size(Vector* vector)
{
    /* EXERCISE */
}

size_t vector_capacity(Vector* vector)
{
    /* EXERCISE */
}
