#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void deleteNode(struct node** head_ref, int key){
    struct node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted, keep track of the
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);
}

int main() {
    struct node *head, *newnode, *temp;
    head = 0;
    int choice = 1;

    while(choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if(head == 0) {
            head = temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue? (0, 1): ");
        scanf("%d", &choice);
    }

    temp = head;    
    printf("Before deletion: ");
    while(temp != 0) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

    int key;        
    printf("Enter the key to be deleted: ");
    scanf("%d", &key);
    deleteNode(&head, key);

    printf("After deletion: "); 
    temp = head;
    while(temp != 0) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
