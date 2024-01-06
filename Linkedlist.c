#include<stdio.h>
#include<stdlib.h>

typedef struct list{                                     //bağlı liste tanımı
    int data;
    struct list* next;
}  list;

list* first=NULL;
list* last=NULL;

int insert(int value){                         //bağlı listeye ekleme yapma ve size güncelleme
    list* new = (list*)malloc(sizeof(list));
    if (new == NULL){
        printf("Memory failed \n");
        return -1;
    }

    new->data=value;
        new->next=NULL;

    if(first != NULL){    //liste boş değilse ekle ve son elemanı güncelle
    last->next=new;
    last=new; 
    }

    else{                 // liste boşsa ilk elemanı ekle
    first =new;
    last=new;
    }

    return 0;
}

    int display(){       //bağlı listeyi yazdırma

        list* new;
        new= first;

     if (new==NULL){
        printf("List is empty \n");
        return -1;
    }
      while(new!=NULL){
        printf("%d \n", new->data);
        new=new->next;
      }

        return 0;

  }

    int main(){

    int value,i;
    int list[5];

    for(int a=0;a<5;a++) {

        printf("Enter a value: ");
        scanf("%d" , &list[a]);
        insert(list[a]);
    }
   
        display(); //bağlı listeyi yazdırma

        return 0;
    }
