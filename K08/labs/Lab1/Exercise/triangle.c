#include <stdio.h>
#include <stdlib.h>


typedef struct point {
    // CHANGE
} Point;

struct triangle_static {
    Point points[3];
};
typedef ... Triangle; // CHANGE

void point_print(Point p) 
{
    printf("(%d, %d)", p.x, p.y);
}

// CHANGE
void point_move_horizontally(Point p, int units) 
{
    p.x += units;
}

void triangle_print(Triangle* t) 
{
    for (int i = 0; ... ; i++) { // CHANGE 
        point_print(t->points[i]);
    }
}

void triangle_move_horizontally(Triangle* t, int units) 
{
    for (int i = 0; ... ; i++) { // CHANGE 
        t->points[i].x += units;
    }
}

int main(void)
{
    Point* a = ... // CHANGE
    a->x = 0;
    a->y = 0;

    point_print(*a);
    printf("\n");

    point_move_horizontally(*a, 5); // CHANGE

    point_print(*a);
    printf("\n");

    free(a);

    struct triangle_static* t = malloc(sizeof(struct triangle_static));
    t->points[0].x = 0;
    t->points[0].y = 0;
    t->points[1].x = 1;
    t->points[1].y = 0;
    t->points[2].x = 0;
    t->points[2].y = 1;

    triangle_print(t);
    printf("\n");

    triangle_move_horizontally(t, 5);

    triangle_print(t);
    printf("\n");

    free(...); // CHANGE

    return 0;
}