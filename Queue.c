#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear= NULL;

int enqueue(int data){       //Sıraya eleman ekleme O(1)
    
    if(front==NULL){
        
    struct node *new=( struct node *)malloc(sizeof(struct node));
    new -> data= data;
    new -> next = NULL;

    front=rear=new;
}
     else{
     struct node *new=(struct node*)malloc(sizeof(struct node));
     new -> data = data;
     new -> next = NULL;

        rear -> next =new;
        rear=new;  
    }
    
    return 1;
}

int display(){    //sırayı yazdırma

    
    if(front==NULL){
        printf("Queue is empty.\n");
        return 1;
    }

    printf("Queues: \n ");
    struct node *index = front;
    while(index!=NULL){
        printf("%d \n ", index->data);
        index=index->next;
    }
    return 1;
}

int dequeue() {      //eleman silme

    if(front==NULL){
        printf("Queue is empty. \n");
        return 1;
    }

    struct node *temp=front;
    front=front -> next;
    free(temp);

    return 1;
}

void reset() {                       //sırayı boşaltma
    struct node *current = front;
    struct node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    front = rear = NULL;
}

int main(){

    enqueue(9);
    enqueue(13);
    enqueue(4);
    enqueue(8);

    display();

    dequeue();
    dequeue();
    display();

    dequeue();
    dequeue();
    display();

    enqueue(1);
    enqueue(16);
    display();

    reset();
    display();
    
    return 0;

}
