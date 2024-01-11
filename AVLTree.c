#include <stdio.h>
#include <stdlib.h>

struct AvlNode{   //AVL Ağacı Düğümü
    int data;
    struct AvlNode* right;
    struct AvlNode* left;
    int height;
};


struct AvlNode* newNode(int data){                                              //Yeni bir AVL düğümü oluşturur
    struct AvlNode* node=(struct AvlNode*)malloc(sizeof(struct AvlNode));
    node->data=data;
    node->right=NULL;
    node->left=NULL;
    node->height=1;                                                              //düğüm eklediğimiz için yükseklik 1 olur
    return node;
}
                                         
int updateHeight(struct AvlNode* node){                                           //yüksekliği güncelleme
    if(node==NULL) 
        return 0;
    
    int leftHeight=(node->left!=NULL) ? node->left->height : 0;
    int rightHeight=(node->right!=NULL) ? node->right->height : 0;
    return 1+ ((leftHeight>rightHeight) ? leftHeight : rightHeight);
}


int getBalanceFactor(struct AvlNode* node){                                        //balance hsaplama sol alt- sağ alt
    if(node==NULL) return 0;
    int leftHeight=(node->left!=NULL) ? node->left->height : 0;
    int rightHeight=(node->right!=NULL) ? node->right->height : 0;
    return leftHeight-rightHeight;
}

struct AvlNode* rotateRight(struct AvlNode* y){ 
    struct AvlNode* x = y->left;
    struct AvlNode* T2 = x->right;

   
    x->right = y;
    y->left = T2;

    y->height = updateHeight(y);
    x->height = updateHeight(x);

    return x;
}

struct AvlNode* rotateLeft(struct AvlNode* x){
    struct AvlNode* y = x->right;
    struct AvlNode* T2 = y->left;

   
    y->left = x;
    x->right = T2;  //geçici bir alt ağacı temsil eder

    x->height = updateHeight(x);
    y->height = updateHeight(y);

    return y;
}


struct AvlNode* insert(struct AvlNode* node, int data){
    
    if(node == NULL)
        return newNode(data);

    // Düğüm ekleme işlemi
    if(data < node->data)
        node->left = insert(node->left, data);
    else if(data > node->data)
        node->right = insert(node->right, data);
    else
        return node;                                            // Aynı veriye sahip düğüm zaten var tekrar eklenmiyor

    node->height = updateHeight(node);

   
    int balanceFactor = getBalanceFactor(node);               // balance faktörünü al

    // Denge faktörüne göre durumu kontrol et
    if(balanceFactor > 1){
        if(data < node->left->data){
            // Sol-sol durumu: Sağa dönme
            return rotateRight(node);
        }
        else if(data > node->left->data){
            // Sol-sağ durumu: Sol çocuğu sola, ardından sağa dönme
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    if(balanceFactor < -1){
        if(data > node->right->data){
            // Sağ-sağ durumu: Sola dönme
            return rotateLeft(node);
        }
        else if(data < node->right->data){
            // Sağ-sol durumu: Sağ çocuğu sağa, ardından sola dönme
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }
    return node; // Denge faktörü uygun, düğümü geri döndür
}

void inOrder(struct AvlNode* root) {
     if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }

}
   void postOrder(struct AvlNode* root)
{
    if (root != NULL) {
       postOrder(root->left);
       postOrder(root->right);
       printf("%d ", root ->data); 
    }
}
void preOrder(struct AvlNode* root)
{
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root ->right);
    }
}



int main(){

    struct AvlNode* root=NULL;
    root=insert(root,21);
    root=insert(root,26);
    root=insert(root,30);
    root=insert(root,9);   
    root=insert(root,4);
    root=insert(root,14);
    root=insert(root,28);
    root=insert(root,18);
    root=insert(root,15);
    root=insert(root,10);

    printf("\nPostorder traversal after insertion:\n");
    postOrder(root);

    
    printf("\nPreorder traversal after insertion:\n");
    preOrder(root);

    printf("\nInorder traversal after insertion:\n");
    inOrder(root);

    return 0;
}
