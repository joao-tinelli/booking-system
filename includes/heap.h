#ifndef H_HEAP
#define H_HEAP

typedef struct _nodeHeap NodeHeap;

/**
 * @brief Function to create a new NodeHeap
 * @param code, priority
 * @return *NodeHeap
 */
NodeHeap *createNodeHeap(int code, int priority);

/**
 * @brief Function to swap two Nodes
 * @param *a, *b
 * @return void
 */
void swapNodes(NodeHeap *a, NodeHeap *b);

/**
 * @brief Function to restore the heap's property (Max-Heapify)
 * @param *root
 * @return void
 */
void maxHeapify(NodeHeap* root);

/**
 * @brief Auxiliary function to insert in level
 * @param *root, *newNodeHeap
 * @return void
 */
void insertLevelOrder(NodeHeap *root, NodeHeap *newNodeHeap);

/**
 * @brief Function to insert a NodeHeap (reservation) into the heap
 * @param **root, code, priority
 * @return void
 */
void insert(NodeHeap **root, int code, int priority);

/**
 * @brief Function to remove the highest element (root) of the heap
 * @param **root
 * @return maxpriority
 */
int extractMax(NodeHeap **root);

/**
 * @brief Function to remove a NodeHeap (reservation) given its priority
 * @param *root, priority
 * @return root
 */
NodeHeap *findAndRemoveByPriority(NodeHeap *root, int priority);

/**
 * @brief Function to print the tree (heap) in-order
 * @param *root
 * @return void
 */
void printInOrder(NodeHeap* root);

/**
 * @brief Function to get a room's priority based on its code the tree (heap) in-order
 * @param *root, code
 * @return priority
 */
int findPriorityByCode(NodeHeap *root, int code);

/**
 * @brief Function to deallocate
 * @param *root
 * @return
 */
void freeHeap(NodeHeap *root);

#endif
