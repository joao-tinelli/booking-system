#ifndef H_AVL
#define H_AVL

typedef struct _nodeAVL NodeAVL;

/**
 * @brief Function to create a new NodeAVL
 * @param code, capacity
 * @return *NodeAVL
 */
NodeAVL *newNodeAVL(unsigned int code, unsigned int capacity);

/**
 * @brief Returns the larger value between two codes
 * @param a, b
 * @return a or b
 */
short bigger(short a, short b);

/**
 * @brief Returns the height of a NodeAVL or -1 if it is NULL
 * @param *NodeAVL
 * @return short (height)
 */
short NodeAVLHeight(NodeAVL *NodeAVL);

/**
 * @brief Calculates the balancing factor
 * @param *NodeAVL
 * @return short (balancing factor)
 */
short balancingFactor(NodeAVL *NodeAVL);

/**
 * @brief Function to perform a left rotation
 * @param *root
 * @return y (new root)
 */
NodeAVL *leftRotation(NodeAVL *root);

/**
 * @brief Function to perform a right rotation
 * @param *root
 * @return y (new root)
 */
NodeAVL *rightRotation(NodeAVL *root);

/**
 * @brief Function to perform a double rotation (left - right)
 * @param *root
 * @return result of left and right rotations
 */
NodeAVL *leftAndRightRotation(NodeAVL *root);

/**
 * @brief Function to perform a double rotation (right - left)
 * @param *root
 * @return result of right and left rotations
 */
NodeAVL *rightAndLeftRotation(NodeAVL *root);

/**
 * @brief Function to balance the tree after an insertion or removal
 * @param *root
 * @return *root
 */
NodeAVL *balance(NodeAVL *root);

/**
 * @brief Inserts a new NodeAVL into the tree
 * @param *root, code, capacity
 * @return *root
 */
NodeAVL *insertRoom(NodeAVL *root, unsigned int code, unsigned int capacity);

/**
 * @brief Function to remove a NodeAVL from the tree
 * @param *root, code
 * @return *root
 */
NodeAVL *removeRoom(NodeAVL *root, unsigned int code);

/**
 * @brief Function to search for a NodeAVL (room) by its code
 * @param *root, code
 * @return NULL or NodeAVL
 */
NodeAVL *searchNodeAVL(NodeAVL *root, unsigned int code);

/**
 * @brief Function to display the AVL tree
 * @param *root, level
 * @return void
 */
void showAVLTree(NodeAVL *root, int level);

#endif
