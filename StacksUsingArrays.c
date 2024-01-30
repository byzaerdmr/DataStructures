#include <stdio.h>
#include <stdlib.h>

#define N 500

int arr[N];
int sp = 0;

int push(int item){

    if(sp>=N){
        printf("Stack if full\n");
        return -1;
    }
    else {
        arr[sp] = item;
        sp++;
        return 0;
    }
}

int pop(){
    if(sp<=0){
        printf("Stack is empty\n");
        return -1;
    }
    else {
        sp--;
        return arr[sp];
    }
}

void reset(){
    sp = 0;
}

int top(){
   
     return (sp-1);
    
}

int size(){
    return sp;
}

int isEmpty(){
    if(sp==0){
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    int choice, item;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Reset\n");
        printf("4. Top\n");
        printf("5. Size\n");
        printf("6. isEmpty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if(item!=-1){
                    printf("Popped item is: %d\n", item);
                }
                break;
            case 3:
                reset();
                break;
            case 4:
                item = top();
                if(item!=-1){
                    printf("Top item is: %d\n", arr[item]);
                }
                break;
            case 5:
                printf("Size of stack is: %d\n", size());
                break;
            case 6:
                if(isEmpty()){
                    printf("Stack is empty\n");
                }
                else {
                    printf("Stack is not empty\n");
                }
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
