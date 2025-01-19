#ifndef H_HEAP
#define H_HEAP

typedef struct _node Node;

/**
 * @brief Function to create a new node
 * @param code, priority
 * @return *node
 */
Node *createNode(int code, int priority);

/**
 * @brief Function to swap two values
 * @param *a, *b
 * @return void
 */
void swap(int *a, int *b);

/**
 * @brief Function to restore the heap's property (Max-Heapify)
 * @param *root
 * @return void
 */
void maxHeapify(Node* root);

/**
 * @brief Auxiliary function to insert in level
 * @param *root, *newNode
 * @return void
 */
void insertLevelOrder(Node *root, Node *newNode);

/**
 * @brief Function to insert a node (reservation) into the heap
 * @param **root, code, priority
 * @return void
 */
void insert(Node **root, int code, int priority);

/**
 * @brief Function to remove the highest element (root) of the heap
 * @param **root
 * @return maxpriority
 */
int extractMax(Node **root);

/**
 * @brief Function to remove a node (reservation) given its priority
 * @param *root, priority
 * @return root
 */
Node *findAndRemoveByPriority(Node *root, int priority);

/**
 * @brief Function to print the tree (heap) in-order
 * @param *root
 * @return void
 */
void printInOrder(Node* root);

#endif
