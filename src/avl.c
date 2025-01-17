#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    unsigned int code, capacity;
    struct _node *left, *right;
    short height;
} Node;

Node *newNode(unsigned int code, unsigned int capacity) {
    Node *node = (Node*) malloc(sizeof(Node));

    if (node) {
        node->code = code;
        node->capacity = capacity;
        node->left = node->right = NULL;
        node->height = 0;
    }
    else 
        perror("\nERRO ao alocar no em 'noNovo()'");
    
    return node;
}

short bigger(short a, short b) {
    return (a > b) ? a : b;
}

short nodeHeight(Node *node) {
    if (node == NULL) 
        return -1;
    else 
        return node->height;
}

short balancingFactor(Node *node) {
    if (node)
        return (nodeHeight(node->left)) - (nodeHeight(node->right));
    else    
        return 0;
}

Node *leftRotation(Node *root) {
    Node *y, *f; //f -> FILHO

    y = root->right;
    f = y->left;

    y->left = root;
    root->right = f; //f se torna o filho a direita de r (caso tenha)

    root->height = bigger(nodeHeight(root->left), nodeHeight(root->right)) + 1;
    y->height = bigger(nodeHeight(y->left), nodeHeight(y->right)) + 1;

    return y;
} 

Node *rightRotation(Node *root) {
    Node *y, *f; // f -> filho

    y = root->left;
    f = y->right;

    y->right = root;
    root->left = f; //f se torna o filho a esquerdo de r (caso tenha)

    root->height = bigger(nodeHeight(root->left), nodeHeight(root->right)) + 1;
    y->height = bigger(nodeHeight(y->left), nodeHeight(y->right)) + 1;

    return y;
} 

Node* leftAndRightRotation(Node *root) {
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

Node* rightAndLeftRotation(Node *root) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

Node *balance(Node *root) {
    short fb = balancingFactor(root);

    // rotacao a esquerda
    if (fb < -1 && balancingFactor(root->right) <= 0)
        root = leftRotation(root);
    // rotacao a direita
    else if (fb > 1 && balancingFactor(root->left) >= 0)
        root = rightRotation(root);
    // Rotacao dupla -> esquerda e direita
    else if (fb > 1 && balancingFactor(root->left) < 0)
        root = leftAndRightRotation(root);
    // Rotacao dupla -> direita e esquerda
    else if (fb < -1 && balancingFactor(root->right) > 0)
        root = rightAndLeftRotation(root);

    return root;
}

Node *inseinsertRoomt(Node *root, unsigned int code, unsigned int capacity) {
    // arvore vazia
    if (root == NULL) 
        return newNode(code, capacity);
    // insercao sera para a esquerda ou direita
    else {
        if (code < root->code)
            root->left = insertRoom(root->left, code, capacity);
        else if (code > root->code)
            root->right = insertRoom(root->right, code, capacity);
        else
            perror("\nInsercao nao realida!");
    }

    // Recalcula a altura de todos os nos entre a root e o novo no inserido
    root->height = bigger(nodeHeight(root->left), nodeHeight(root->right)) + 1;

    // verifica a necessidade de balancear a arvore
    root = balance(root);
    
    return root;
}

Node *removeRoom(Node *root, unsigned int code) {
    if (root == NULL) {
        perror("code nao encontrado!\n");
        return NULL;
    }
    // procura o no a remover
    else {
        if (root->code == code) {
            // remove nos folhas (nos sem filhos)
            if (root->left == NULL && root->right == NULL) {
                free(root);
                printf("Elemento folha removido: %d ! \n", code);
                return NULL;
            }
            else {
                // remover no que possi 2 filhos
                if (root->left != NULL && root->right != NULL) {
                    Node *aux = root->left;
                    while (aux->right != NULL)
                        aux = aux->right;
                    root->code = aux->code;
                    aux->code = code;
                    printf("Elemento trocado: %d !\n", code);
                    root->left = removeRoom(root->left, code);
                    return root;
                }
                else {
                    // remover nos que possuem apenas 1 filho
                    Node *aux;
                    if (root->left != NULL)
                        aux = root->left;
                    else 
                        aux = root->right;
                    free(root);
                    printf("Elemento com 1 filho removido: %d\n", code);
                    return aux;
                }
            }
        } else  {
            if (code < root->code)
                root->left = removeRoom(root->left, code);
            else 
                root->right = removeRoom(root->right, code);
        }

        // Recalcula a altura de todos os nos entre a root e o novo no inserido
        root->height = bigger(nodeHeight(root->left), nodeHeight(root->right)) + 1;

        // verifica a necessidade de balancear a arvore
        root = balance(root);
        
        return root;
    }
    
}

void showAVLTree(Node *root, int level) {
    if (root) {
        showAVLTree(root->right, level + 1);
        printf("\n\n");

        for (int  i = 0; i < level; i++)
            printf("\t");
        
        printf("%d", root->code);
        showAVLTree(root->left, level + 1);
    }
}

