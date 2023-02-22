#include <stdlib.h>

typedef struct vector_struct Vector;
typedef int datatype;

Vector*     vector_create(size_t capacity);
void        vector_free(Vector* vector);
datatype    vector_at(Vector* vector, int index);
void        vector_set_at(Vector* vector, int index, datatype data);
void        vector_push_back(Vector* vector, datatype data);
size_t      vector_size(Vector* vector);
size_t      vector_capacity(Vector* vector);

