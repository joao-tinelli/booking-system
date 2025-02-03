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

void swapNodes(NodeHeap *a, NodeHeap *b)
{
    int tempCode = a->code;
    int tempPriority = a->priority;

    a->code = b->code;
    a->priority = b->priority;

    b->code = tempCode;
    b->priority = tempPriority;
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
        swapNodes(root, largest);
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

int extractMax(NodeHeap **root)
{
    if (*root == NULL) {
        printf("Empty heap!\n");
        return -1;
    }
    int maxPriority = (*root)->priority; // Save the max priority to return later

    NodeHeap* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;
    NodeHeap* lastNodeHeap = NULL;

    // Find the last node
    while (front < rear) {
        lastNodeHeap = queue[front++];
        if (lastNodeHeap->left) queue[rear++] = lastNodeHeap->left;
        if (lastNodeHeap->right) queue[rear++] = lastNodeHeap->right;
    }

    if (lastNodeHeap) {
        // Move the last node's data to the root
        (*root)->code = lastNodeHeap->code;
        (*root)->priority = lastNodeHeap->priority;

        // Remove the last node
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
    // Restore the heap property
    maxHeapify(*root);
    return maxPriority; // Return the priority (or return maxCode if needed)
}

NodeHeap *findAndRemoveByPriority(NodeHeap* root, int priority)
{
    if (root == NULL) {
        printf("The heap is empty or the Node does not exist.\n");
        return NULL;
    }

    // If the root has the matching priority
    if (root->priority == priority) {
        extractMax(&root);  // This now handles both code and priority properly
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
                extractMax(&temp);  // This removes the node correctly
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
                extractMax(&temp);  // This removes the node correctly
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

void printInOrder(NodeHeap* root)
{
    if (root == NULL)
        return;
        
    printInOrder(root->left);
    printf("ROOM --- CODE: '%d' --- PRIORITY: '%d'\n", root->code, root->priority);
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

void freeHeap(NodeHeap *root) {
    if (root != NULL) {
        freeHeap(root->left);
        freeHeap(root->right);
        free(root);
    }
}
