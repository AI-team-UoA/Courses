#pragma once

typedef struct point{
    int x;
    int y;
}Point;

void uninitialized_use();
void conditional_jump_on_uninitialized();
void double_free();
void incorrect_free();
void no_deallocation();
void invalid_read_write();

