#include <stdio.h>
#include <stdlib.h>

#define N 500   // max number of elements 
                // that can be stored in the queue
int Q[N];       // Queue
int last=0;     // initially queue is empty

int enqueue(int item){
   if (last == N){
      printf("Queue is full\n");
      return -1;
   }
   else{
      Q[last] = item;
      last++;
      return 0;
   }
}

int dequeue(){
   int item, i;

   if (last == 0){
      printf("Queue is empty\n");
      return -1;    // if queue has positive values
   }
   else{
      item = Q[0];
      // shift left items in the queue by 1 position
      for (i=1; i< last; i++) 
         Q[i-1] = Q[i];
      last--;
      return item;
   }
}
void reset(){
   last = 0;
}

int main(){
   int i, item;

   for (i=0; i<10; i++)
      enqueue(i);
   printf("Queue: ");
   for (i=0; i<last; i++)
      printf("%d ", Q[i]);
   printf("\n");

   item = dequeue();
   printf("Dequeued item: %d\n", item);
   printf("Queue: ");
   for (i=0; i<last; i++)
      printf("%d ", Q[i]);
   printf("\n");

   item = dequeue();
   printf("Dequeued item: %d\n", item);
   printf("Queue: ");
   for (i=0; i<last; i++)
      printf("%d ", Q[i]);
   printf("\n");

   reset();
   printf("Queue: ");
   for (i=0; i<last; i++)
      printf("%d ", Q[i]);
   printf("\n");

   return 0;
}
