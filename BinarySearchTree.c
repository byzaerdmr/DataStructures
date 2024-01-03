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
