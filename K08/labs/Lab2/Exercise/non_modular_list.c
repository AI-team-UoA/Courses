#include <stdio.h>
#include <stdlib.h>

typedef struct list List;
struct list{
    int data;
    List *next;
};

//Function to add an element at the end of the list
List *list_push(List *l, int data){
    List *node = malloc(sizeof(List));
    node->next = NULL;
    node->data = data;

    if(l==NULL){
        l = node;
    }
    else{
        List *cur = l;
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = node;
    }

    return l;
}

//Function to return the first element of the list
List *list_first(List *l){
    return l;
}

//Function to return the last element of a list
List* list_last(List* l){
    if (l == NULL)
        return l;

    while (l->next != NULL) {
        l = l->next;
    }
    return l;
}

//Function de-allocate a list
void list_free(List* l){
    List* cur = NULL;
    while (l != NULL) {
        cur = l->next;
        free(l);
        l = cur;
    }
}

//Helper function to print a list
void list_print(List *l){
    List *cur = l;
    printf("[");
    while(cur!=NULL){
        if(cur->next!=NULL){
            printf("%d, ",cur->data);
        }
        else{
            printf("%d",cur->data);
        }
        cur = cur->next;
    }
    printf("]\n");
}

//Function to return the size of a list
int list_size(List *l){
    List *cur = l;
    int count = 0;
    while(cur!=NULL){
        count++;
        cur = cur->next;
    }
    return count;
}

//Function to return the data from a node
int list_get_data(List *l){
    return l->data;
}

//Function to return the next node in the list
List *list_get_next(List *l){
    return l->next;
}

int main(){
    List *l = NULL;
    l = list_push(l,2);
    l = list_push(l,4);
    l = list_push(l,6);
    l = list_push(l,8);
    l = list_push(l,10);

    printf("The first element of the list is %d\n", list_get_data(list_first(l)));
    printf("The last element of the list is %d\n", list_get_data(list_last(l)));

    printf("The list is:\n");
    list_print(l);

    list_free(l);
    return 0;
}
