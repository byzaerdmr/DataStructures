#include <stdio.h>
#include <stdlib.h>

#define N 500

int arr[N];
int last = 0;

int enqueue(int item){

    if(last>=N){
        printf("Queue if full\n");
        return -1;
    }
    else {
        arr[last] = item;
        last++;
        return 0;
    }
}

int dequeue(){
    int item,i;

    if(last<=0){
        printf("Queue is empty\n");
        return -1;
    }
    else {

        item = arr[0];
        for(i=1; i<last; i++){
            arr[i-1] = arr[i];
        }
        last--;
        return item;
    }
}

void reset(){
    last = 0;
}

int main(){
    int i;  
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    for(i=0; i<5; i++){
        printf("%d\n", dequeue());
    }
    return 0;   
}
