#include <stdio.h>
#include <stdlib.h> 

#define N 500   // max number of elements 
                // that can be stored in the queue

int Q[N];
int front=0, last=0, count=0;

int enqueue(int item){
   if (count >= N){
      printf("Queue is full\n");
      return -1;
   }
   else{
      Q[last] = item;
      last = (last + 1) % N;
      count++;
      return 0;
   }
}


int dequeue(){
   int item;
   if (count == 0){
      printf("Queue is empty\n");
      return -1;
   }
   else{
      item = Q[front];
      front = (front + 1) % N;
      count--;
      return item;
   }
}


int main(){
   int i, item;

   for (i=0; i<10; i++)
      enqueue(i);
   printf("Queue: ");
   for (i=0; i<count; i++)
      printf("%d ", Q[(front+i)%N]);
   printf("\n");

   item = dequeue();
   printf("Dequeued item: %d\n", item);
   printf("Queue: ");
   for (i=0; i<count; i++)
      printf("%d ", Q[(front+i)%N]);
   printf("\n");

   item = dequeue();
   printf("Dequeued item: %d\n", item);
   printf("Queue: ");
   for (i=0; i<count; i++)
      printf("%d ", Q[(front+i)%N]);
   printf("\n");

   return 0;
}
