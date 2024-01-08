#include <stdio.h>
#include <stdlib.h>

struct node {          //stack tanımı
    int data;
    struct node *link;
};

struct node *top=0;

void push (int x){      //stack'e eleman ekleme 

    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode ->link = top;
    top = newnode;

}

void display(){
    struct node*temp;      //geçici bir temp değişkeni oluştur ve top'a eşitle
    temp=top;            
    if(top==0) {
        printf(" List is empty. \n");
    }
    
    else {
        while (temp!=0){
            printf("\n %d \n", temp -> data);
            temp=temp->link;
        }
    }
}
void peek(){
    if(top==0)
    printf("List is empty.");
    else{
        printf("Top element is %d \n", top ->data);
    
    }
}

void pop(){
    struct node *temp;
    temp=top;
    if(top==0){
    printf("List is empty.");
    }
    
    else {
        printf("Pooped element is %d \n", top->data);
        top =top->link;
        free(temp);
    
    }
}

int main(){
    push(7);
    push(9);
    push(15);
    display();
    peek();
    pop();
    peek();
    display();

    return 0;

}
