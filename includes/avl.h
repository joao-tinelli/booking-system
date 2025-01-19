#ifndef H_AVL
#define H_AVL

typedef struct _node Node;

/**
 * @brief Function to create a new node
 * @param code, capacity
 * @return *node
 */
Node *newNode(unsigned int code, unsigned int capacity);

/**
 * @brief Returns the larger value between two codes
 * @param a, b
 * @return a or b
 */
short bigger(short a, short b);

/**
 * @brief Returns the height of a node or -1 if it is NULL
 * @param *node
 * @return short (height)
 */
short nodeHeight(Node *node);

/**
 * @brief Calculates the balancing factor
 * @param *node
 * @return short (balancing factor)
 */
short balancingFactor(Node *node);

/**
 * @brief Function to perform a left rotation
 * @param *root
 * @return y (new root)
 */
Node *leftRotation(Node *root);

/**
 * @brief Function to perform a right rotation
 * @param *root
 * @return y (new root)
 */
Node *rightRotation(Node *root);

/**
 * @brief Function to perform a double rotation (left - right)
 * @param *root
 * @return result of left and right rotations
 */
Node *leftAndRightRotation(Node *root);

/**
 * @brief Function to perform a double rotation (right - left)
 * @param *root
 * @return result of right and left rotations
 */
Node *rightAndLeftRotation(Node *root);

/**
 * @brief Function to balance the tree after an insertion or removal
 * @param *root
 * @return *root
 */
Node *balance(Node *root);

/**
 * @brief Inserts a new node into the tree
 * @param *root, code, capacity
 * @return *root
 */
Node *insertRoom(Node *root, unsigned int code, unsigned int capacity);

/**
 * @brief Function to remove a node from the tree
 * @param *root, code
 * @return *root
 */
Node *removeRoom(Node *root, unsigned int code);

/**
 * @brief Function to search for a node (room) by its code
 * @param *root, code
 * @return NULL or Node
 */
Node *searchNode(Node *root, unsigned int code);

/**
 * @brief Function to display the AVL tree
 * @param *root, level
 * @return void
 */
void showAVLTree(Node *root, int level);

#endif
