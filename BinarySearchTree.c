#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Insert, delete, list, search , exit

struct BstNode{

int data;
struct BstNode * left;
struct BstNode * right;
};

struct BstNode* newNodeCreate(int value)
{
    struct BstNode* new = (struct BstNode*)malloc(sizeof(struct BstNode));
    new -> data = value;
    new  ->left = new -> right = NULL;
    return new;

}

struct BstNode* searchNode(struct BstNode* root, int target)
{
    if(root == NULL || root ->data==target)
    {
        return root;
    }
    if(root -> data < target){

        return searchNode(root -> right, target);
    }
    return searchNode(root-> left, target);    
}

struct BstNode* insertNode(struct BstNode* node, int value)
{
    if(node==NULL){
        return newNodeCreate(value);
    }
    if (value<node ->data) {
        node->left = insertNode(node->left, value);
    }
    else if( value> node->data){
        node->right=insertNode(node->right, value);
    }
    return node;
}

void postOrder(struct BstNode* root)
{
    if (root != NULL) {
       postOrder(root->left);
       postOrder(root->right);
       printf("%d", root ->data); 
    }
}

void inOrder(struct BstNode* root)  // left-root-right
{
    if(root!=NULL) {
        inOrder(root->left);
        printf("%d", root->data);
        inOrder(root ->right);
    }
}

void preOrder(struct BstNode* root)    //root-left-right
{
    if(root!=NULL){
        printf("%d", root->data);
        preOrder(root->left);
        preOrder(root ->right);
    }
}

struct BstNode* deleteNode(struct BstNode* root, int x)
{
    if(root==NULL)
    return root;
    
    if(x > root->data){
        root ->right= deleteNode(root -> right, x);
    }
    else if(x < root->data) {
        root ->left = deleteNode(root->left, x);
    }
    else{
        if(root -> left == NULL){
            struct BstNode* temp = root ->right;
            free(root);
            return temp;
       }
        else if (root ->right == NULL){
            struct BstNode* temp = root -> left;
            free(root);
            return temp;
        }
        struct BstNode* temp = root ->right;
        while( temp->left !=NULL){
            temp = temp->left;
        }
        root -> data = temp -> data;

        root -> right = deleteNode(root->right, temp -> data);
    }
    
    return root;
} 

