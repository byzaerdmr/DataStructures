#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int data;
    struct s* next; 
}STACK;

STACK *sp= NULL;

int push(int data){
    STACK *p=(STACK*)malloc(sizeof(STACK));
    if(p==NULL){
        printf("nOT ENOUGH MEMORY!\n");
        return -1;
    }
    else{
    p->data=data;
    p->next=sp;
    sp=p;
    return 0;
    }
}

int pop(){
    STACK *p;
    int i;
    if(sp==NULL){
        printf("STACK IS EMPTY!\n");
        return -1;
    }
    else{
        p=sp;
        i=p->data;
        sp=sp->next;
        free(p);
        return i;
    }
}

void reset (){
    STACK *p;
    while(sp!=NULL){
        p=sp;
        sp=sp->next;
        free(p);
    }
}

STACK *top(){
    return sp;
}

int size (){
    STACK *p;
    int i=0;
    p=sp;
    while(p){
        i++;
        p=p->next;
    }
    return i;
}

STACK *isEmpty(){
    return sp;
}

int main() {
    int i;
    for (i = 0; i < 10; i++)
        push(i);

    printf("Size of stack: %d\n", size());
    printf("Top element of stack: %d\n", top()->data);

    printf("Pop all elements of stack: ");
    while (sp != NULL)
        printf("%d ", pop());

    printf("\nSize of stack: %d\n", size());

    reset();
    printf("Size of stack after reset: %d\n", size());

    return 0;
}
