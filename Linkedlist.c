#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int info;
    struct list* next;
}list;

list* first = NULL;
list* last = NULL;

int insert(int value) {
    list* p = (list*)malloc(sizeof(list));
    if (p == NULL) {
        printf("Memory failed\n");
        return -1;
    }
    p->info = value;
    p->next = NULL;

    if (first != NULL) {
        last->next = p;
        last = p;
    }
    else {
        first = p;
        last = p;

    }
    return 0;
}

int display() {
    list* p;
    p = first;
    if (p == NULL) {
        printf("List is empty\n");
        return -1;
    }
    while (p != NULL) {
        printf("%d \n", p->info);
        p = p->next;
    }

    return 0;
}


int main() {
    int value, i;
    int list[5];
    for (int a = 0;a < 5;a++) {
        printf("PLease enter the value: \n");
        scanf("%d", &list[a]);
        insert(list[a]);
    }
    display();

    return 0;
}
