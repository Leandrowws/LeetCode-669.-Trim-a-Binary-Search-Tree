#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    
    if(root == NULL) {
        return NULL;
    }

    if(root->val < low) {
        return trimBST(root->right, low, high);
    }

    if(root->val > high) {
        return trimBST(root->left, low, high);
    }

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
}

struct TreeNode* Inserir(struct TreeNode* root, int val) {
    if(root==NULL) {
        struct TreeNode* aux = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        aux->val = val;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    } else {
        if(val < root->val) {
            root->left = Inserir(root->left, val);
        } else {
            root->right = Inserir(root->right, val);
        }
        return root;
    }
}

void Imprimir(struct TreeNode* root) {
    if(root!=NULL) {
        Imprimir(root->left);
        printf("%d ", root->val);
        Imprimir(root->right);
    }
}

int main() {
    struct TreeNode *arv = NULL;
    int low = 6;
    int high = 20;

    arv = Inserir(arv, 10);
    arv = Inserir(arv, 5);
    arv = Inserir(arv, 12);
    arv = Inserir(arv, 4);
    arv = Inserir(arv, 7);
    arv = Inserir(arv, 25);

    printf("Arvore antes de podar: ");
    Imprimir(arv);
    trimBST(arv, low, high);
    printf("\nArvore depois de podar: ");
    Imprimir(arv);
    printf("\n(Valores entre %d e %d)", low, high);
   

    return 0;
}