#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int code, priority;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int code, int priority)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->code = code;
    newNode->priority = priority;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(Node* root)
{
    if (root == NULL)
        return;
    Node *largest = root;
    if (root->left && root->left->priority > largest->priority)
        largest = root->left;
    if (root->right && root->right->priority > largest->priority)
        largest = root->right;
    if (largest != root)
    {
        swap(&root->priority, &largest->priority);
        maxHeapify(largest);
    }
}

void insertLevelOrder(Node *root, Node *newNode)
{
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node *current = queue[front++];
        // Insere no primeiro espaço disponível
        if (!current->left) {
            current->left = newNode;
            return;
        } else {
            queue[rear++] = current->left;
        }
        if (!current->right) {
            current->right = newNode;
            return;
        } else {
            queue[rear++] = current->right;
        }
    }
}

void insert(Node **root, int code, int priority)
{
    Node* newNode = createNode(code, priority);
    if (*root == NULL)
    {
        *root = newNode;
        return;
    }
    insertLevelOrder(*root, newNode);
    // Restaura a propriedade de Heap subindo o valor
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;
    while (front < rear) {
        Node* current = queue[front++];
        maxHeapify(current);
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}

// Função para remover o maior elemento (raiz) do Heap
int extractMax(Node** root)
{
    if (*root == NULL) {
        printf("Heap vazio!\n");
        return -1;
    }
    int maxpriority = (*root)->priority;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;
    Node* lastNode = NULL;
    while (front < rear) {
        lastNode = queue[front++];
        if (lastNode->left) queue[rear++] = lastNode->left;
        if (lastNode->right) queue[rear++] = lastNode->right;
    }
    if (lastNode) {
        (*root)->priority = lastNode->priority;
        Node* parent = NULL;
        front = 0;
        rear = 0;
        queue[rear++] = *root;
        while (front < rear) {
            Node* current = queue[front++];
            if (current->left) {
                if (current->left == lastNode) {
                    free(current->left);
                    current->left = NULL;
                    break;
                }
                queue[rear++] = current->left;
            }
            if (current->right) {
                if (current->right == lastNode) {
                    free(current->right);
                    current->right = NULL;
                    break;
                }
                queue[rear++] = current->right;
            }
        }
    }
    maxHeapify(*root);
    return maxpriority;
}

// Função para imprimir a árvore em ordem
void printInOrder(Node* root)
{
    if (root == NULL)
        return;
        
    printInOrder(root->left);
    printf("%d ", root->priority);
    printInOrder(root->right);
}




