#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _nodeAVL {
    unsigned int code, capacity;
    struct _nodeAVL *left;
    struct _nodeAVL *right;
    short int height;
} NodeAVL;

NodeAVL *newNodeAVL(unsigned int code, unsigned int capacity) {
    NodeAVL *new = (NodeAVL*) malloc(sizeof(NodeAVL));

    if (new) {
        new->code = code;
        new->capacity = capacity;
        new->left = new->right = NULL;
        new->height = 0;
    }
    else 
        perror("Failed to create a new node.\n");
    
    return new;
}

short bigger(short a, short b) {
    return (a > b) ? a : b;
}

short NodeAVLHeight(NodeAVL *NodeAVL) {
    if (NodeAVL == NULL) 
        return -1;
    else 
        return NodeAVL->height;
}

short balancingFactor(NodeAVL *NodeAVL) {
    if (NodeAVL)
        return (NodeAVLHeight(NodeAVL->left)) - (NodeAVLHeight(NodeAVL->right));
    else    
        return 0;
}

NodeAVL *leftRotation(NodeAVL *root) {
    NodeAVL *y, *f; 

    y = root->right;
    f = y->left;

    y->left = root;
    root->right = f; 

    root->height = bigger(NodeAVLHeight(root->left), NodeAVLHeight(root->right)) + 1;
    y->height = bigger(NodeAVLHeight(y->left), NodeAVLHeight(y->right)) + 1;

    return y;
} 

NodeAVL *rightRotation(NodeAVL *root) {
    NodeAVL *y, *f; 

    y = root->left;
    f = y->right;

    y->right = root;
    root->left = f; 

    root->height = bigger(NodeAVLHeight(root->left), NodeAVLHeight(root->right)) + 1;
    y->height = bigger(NodeAVLHeight(y->left), NodeAVLHeight(y->right)) + 1;

    return y;
} 

NodeAVL* leftAndRightRotation(NodeAVL *root) {
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

NodeAVL* rightAndLeftRotation(NodeAVL *root) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

NodeAVL *balance(NodeAVL *root) {
    short fb = balancingFactor(root);

    if (fb < -1 && balancingFactor(root->right) <= 0)
        root = leftRotation(root);
   
    else if (fb > 1 && balancingFactor(root->left) >= 0)
        root = rightRotation(root);
    
    else if (fb > 1 && balancingFactor(root->left) < 0)
        root = leftAndRightRotation(root);
    
    else if (fb < -1 && balancingFactor(root->right) > 0)
        root = rightAndLeftRotation(root);

    return root;
}

NodeAVL *insertRoom(NodeAVL *root, unsigned int code, unsigned int capacity) {
    
    if (root == NULL) 
        return newNodeAVL(code, capacity);
    
    else {
        if (code < root->code)
            root->left = insertRoom(root->left, code, capacity);
        else if (code > root->code)
            root->right = insertRoom(root->right, code, capacity);
        else
            perror("Failed to insert!\n");
    }

    root->height = bigger(NodeAVLHeight(root->left), NodeAVLHeight(root->right)) + 1;
    root = balance(root);
    
    return root;
}

NodeAVL *removeRoom(NodeAVL *root, unsigned int code) {
    if (root == NULL) {
        perror("Code not found.\n");
        return NULL;
    }

    else {
        if (root->code == code) {
        
            if (root->left == NULL && root->right == NULL) {
                free(root);
                return NULL;
            }
            else {
                
                if (root->left != NULL && root->right != NULL) {
                    NodeAVL *aux = root->left;
                    while (aux->right != NULL)
                        aux = aux->right;
                    root->code = aux->code;
                    aux->code = code;
                    root->left = removeRoom(root->left, code);
                    return root;
                }
                else {
                    NodeAVL *aux;
                    if (root->left != NULL)
                        aux = root->left;
                    else 
                        aux = root->right;
                    free(root);
                    return aux;
                }
            }
        } else  {
            if (code < root->code)
                root->left = removeRoom(root->left, code);
            else 
                root->right = removeRoom(root->right, code);
        }

        root->height = bigger(NodeAVLHeight(root->left), NodeAVLHeight(root->right)) + 1;
        root = balance(root);
        
        return root;
    }    
}

NodeAVL *searchNodeAVL(NodeAVL *root, unsigned int code) {
    // If the tree is empty or the root's code matches the search
    if (root == NULL || root->code == code)
        return root;

    // If the code to search is smaller, search the left subtree
    if (code < root->code)
        return searchNodeAVL(root->left, code);

    // If the code to search is larger, search the right subtree
    return searchNodeAVL(root->right, code);
}


void showAVLTree(NodeAVL *root) {
    if (root) {
        showAVLTree(root->left);
        printf("%d ", root->code);
        showAVLTree(root->right);
    }
}

