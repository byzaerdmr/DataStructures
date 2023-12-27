#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;

};

// front&rear
struct node *front = NULL;
struct node *rear= NULL;

//enqueue
int enqueue(int data){
    
     //Queue is empty
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
//display queue
int display(){

    //queue is empty
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
//dequeue
int dequeue() {

    //Queue is empty
    if(front==NULL){
        printf("Queue is empty. \n");
        return 1;
    }

    struct node *temp=front;
    front=front -> next;
    free(temp);

    return 1;
}

int main(){

    enqueue(9);
    enqueue(13);
    enqueue(4);
    enqueue(-1);

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

    return 0;

}
