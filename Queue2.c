#include <stdio.h>
#include <stdlib.h>


typedef struct q{
   int item;
   struct q *next;
}QUEUE;

QUEUE *front = NULL, *last = NULL;

int enqueue(int item){
   QUEUE *p;
   p = (QUEUE *)malloc(sizeof(QUEUE));
   if (p == NULL){
      printf("Memory is full\n");
      return -1;
   }
   p->item = item;
   p->next = NULL;
   if (front == NULL){  // if queue is empty
      front = p;        // after enqueue, it has 1 element
      last = p;
   }
   else {               // otherwise, insert the new element
      last->next = p;   // at the end
      last = p;
   }
   return 1;
}

int dequeue(){
   QUEUE *p;
   int item;
   if (front == NULL){
      printf("Queue is empty\n");
      return -1;
   }
   p = front;
   front = front->next;
   if (front == NULL){
      last = NULL;
   }
   item = p->item;
   free(p);
   return item;
}
void reset(){
   QUEUE *p;
   p = front;
   while (p){
      front = front->next;
      free(p);
      p = front;
   }
   last = NULL;
} 


int main(){
   int i, item;

   for (i=0; i<10; i++)
      enqueue(i);
   printf("Queue: ");
   while (front){
      item = dequeue();
      printf("%d ", item);
   }
   printf("\n");

   for (i=0; i<10; i++)
      enqueue(i);
   printf("Queue: ");
   while (front){
      item = dequeue();
      printf("%d ", item);
   }
   printf("\n");

   return 0;
}
