#include <stdio.h>
#include <stdlib.h>

struct BstNode{   //binary search tree tanımı

int data;
struct BstNode * left;
struct BstNode * right;

};

struct BstNode * newNodeCreate(int data){  //yeni bir düğüm oluşturur
    
    struct BstNode * node = (struct BstNode *)malloc(sizeof(struct BstNode));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

struct BstNode * insert(struct BstNode * root, int data){ //düğüm ekleme

    if(root == NULL){
        root = newNodeCreate(data);
    }
    else if(data <= root -> data){
        root -> left = insert(root -> left, data);
    }
    else{
        root -> right = insert(root -> right, data);
    }
    return root;
}

int search(struct BstNode * root, int data){ //düğüm arama

    if(root == NULL){
        return 0;
    }
    else if(root -> data == data){
        return 1;
    }
    else if(data <= root -> data){
        return search(root -> left, data);
    }
    else{
        return search(root -> right, data);
    }
}

void preorder(struct BstNode * root){ // root -> left -> right

    if(root == NULL){
        return;
    }
    printf("%d ", root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(struct BstNode * root){ // left -> root -> right

    if(root == NULL){
        return;
    }
    inorder(root -> left);
    printf("%d ", root -> data);
    inorder(root -> right);
}

void postorder(struct BstNode * root){ // left -> right -> root

    if(root == NULL){
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ", root -> data);
}

struct BstNode* deleteNode(struct BstNode* root, int x)  //düğüm silme
{
    if (root == NULL)
        return root;
 
    if (x > root->data) {
        root->right = deleteNode(root->right, x);
    }
    else if (x < root->data) {
        root->left = deleteNode(root->left, x);
    }
    else {
        if (root->left == NULL) {
            struct BstNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
      		struct BstNode* temp = root->left;
      		free(root);
      		return temp;
    	}
        
        struct BstNode* temp = root->right; //node iki çocuğa sahipse
        while (temp->left != NULL) {
            temp = temp->left;
        }
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int main(){

struct BstNode* root = NULL;
int x, choice;

while(1){
    printf("\n 1.Insert \n 2.Delete \n 3.List \n 4.Search \n 5.Exit \n Enter your choice : ");
    scanf("%d", &choice); 

    switch(choice){
        case 1:
            printf("Enter the number you want to add : ");
            scanf("%d", &x);
            root = insert(root, x);
            break;
        case 2:
            printf("Enter the number you want to delete : ");
            scanf("%d", &x);
            root = deleteNode(root, x);
            break;
        case 3:
            printf("Preorder : ");
            preorder(root);
            printf("\nInorder : ");
            inorder(root);
            printf("\nPostorder : ");
            postorder(root);
            break;
        case 4:
            printf("Enter the number you want to search : ");
            scanf("%d", &x);
            if(search(root, x) == 1){
                printf("Found\n");
            }
            else{
                printf("Not Found\n");
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong choice\n");
     }
 }

 return 0;

}
