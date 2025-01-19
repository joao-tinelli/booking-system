#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct _nodeHeap {
    int code, priority;
    struct _nodeHeap *left;
    struct _nodeHeap *right;
} NodeHeap;

NodeHeap *createNodeHeap(int code, int priority)
{
    NodeHeap* newNodeHeap = (NodeHeap*)malloc(sizeof(NodeHeap));
    newNodeHeap->code = code;
    newNodeHeap->priority = priority;
    newNodeHeap->left = NULL;
    newNodeHeap->right = NULL;
    return newNodeHeap;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(NodeHeap *root)
{
    if (root == NULL)
        return;
    NodeHeap *largest = root;
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

void insertLevelOrder(NodeHeap *root, NodeHeap *newNodeHeap)
{
    NodeHeap* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        NodeHeap *current = queue[front++];
        // Insere no primeiro espaço disponível
        if (!current->left) {
            current->left = newNodeHeap;
            return;
        } else {
            queue[rear++] = current->left;
        }
        if (!current->right) {
            current->right = newNodeHeap;
            return;
        } else {
            queue[rear++] = current->right;
        }
    }
}

void insert(NodeHeap **root, int code, int priority)
{
    NodeHeap* newNodeHeap = createNodeHeap(code, priority);
    if (*root == NULL)
    {
        *root = newNodeHeap;
        return;
    }
    insertLevelOrder(*root, newNodeHeap);
    // Restaura a propriedade de Heap subindo o valor
    NodeHeap* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;
    while (front < rear) {
        NodeHeap* current = queue[front++];
        maxHeapify(current);
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
}

// Função para remover o maior elemento (raiz) do Heap
int extractMax(NodeHeap** root)
{
    if (*root == NULL) {
        printf("Empty heap!\n");
        return -1;
    }
    int maxpriority = (*root)->priority;
    NodeHeap* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;
    NodeHeap* lastNodeHeap = NULL;
    while (front < rear) {
        lastNodeHeap = queue[front++];
        if (lastNodeHeap->left) queue[rear++] = lastNodeHeap->left;
        if (lastNodeHeap->right) queue[rear++] = lastNodeHeap->right;
    }
    if (lastNodeHeap) {
        (*root)->priority = lastNodeHeap->priority;
        front = 0;
        rear = 0;
        queue[rear++] = *root;
        while (front < rear) {
            NodeHeap* current = queue[front++];
            if (current->left) {
                if (current->left == lastNodeHeap) {
                    free(current->left);
                    current->left = NULL;
                    break;
                }
                queue[rear++] = current->left;
            }
            if (current->right) {
                if (current->right == lastNodeHeap) {
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

NodeHeap *findAndRemoveByPriority(NodeHeap* root, int priority)
{
    if (root == NULL) {
        printf("The heap is empty or the NodeHeap does not exist.\n");
        return NULL;
    }

    // If the root has the matching priority
    if (root->priority == priority) {
        extractMax(&root);  // Reuse extractMax to handle the removal and restructuring
        return root;
    }

    // Perform level-order traversal to find the NodeHeap with the matching priority
    NodeHeap* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        NodeHeap* current = queue[front++];

        // Check the left child
        if (current->left) {
            if (current->left->priority == priority) {
                NodeHeap* temp = current->left;

                // Replace the NodeHeap to be removed with the last NodeHeap
                extractMax(&temp);  // Reuse extractMax to remove and restore the heap
                current->left = NULL;
                return root;
            } else {
                queue[rear++] = current->left;
            }
        }

        // Check the right child
        if (current->right) {
            if (current->right->priority == priority) {
                NodeHeap* temp = current->right;

                // Replace the NodeHeap to be removed with the last NodeHeap
                extractMax(&temp);  // Reuse extractMax to remove and restore the heap
                current->right = NULL;
                return root;
            } else {
                queue[rear++] = current->right;
            }
        }
    }

    printf("NodeHeap with priority %d not found.\n", priority);
    return root;
}


// Função para imprimir a árvore em ordem
void printInOrder(NodeHeap* root)
{
    if (root == NULL)
        return;
        
    printInOrder(root->left);
    printf("%d ", root->priority);
    printInOrder(root->right);
}

int findPriorityByCode(NodeHeap *root, int code) {
    if (root == NULL) {
        printf("The heap is empty.\n");
        return -1; // Return an invalid priority to indicate the node was not found
    }

    // Perform level-order traversal to search for the node with the given code
    NodeHeap* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        NodeHeap* current = queue[front++];

        if (current->code == code) {
            return current->priority; // Return the priority if the code matches
        }

        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }

    printf("Node with code %d not found.\n", code);
    return -1; // Return an invalid priority if the node is not found
}





