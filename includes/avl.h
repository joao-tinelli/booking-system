#ifndef H_AVL
#define H_AVL

typedef struct _node Node;

/**
 * @brief Funcao de criacao de um novo no
 * @param code, capacity
 * @return *node
 */
Node *newNode(unsigned int code, unsigned int capacity);

/**
 * @brief Retorna o maior codigo
 * @param a, b
 * @return a ou b
 */
short bigger(short a, short b);

/**
 * @brief Retorna a altura de um no ou -1, caso ele seja Null
 * @param *node
 * @return short (height);
 */
short nodeHeight(Node *node);

/**
 * @brief Calcula o fator de balanceamento
 * @param *node
 * @return short (fator de balanceamento)
 */
short balancingFactor(Node *node);

/**
 * @brief Funcao para realizar a rotacao a esquerda;
 * @param *root
 * @return y (nova root)
 */
Node *leftRotation(Node *root);

/**
 * @brief Funcao para realizar a rotacao a direita
 * @param *root
 * @return y (nova root)
 */
Node *rightRotation(Node *root);

/**
 * @brief Funcao para realizar a rotacao dupla (esquerda - direita)
 * @param *root
 * @return rotacao a esquerdaa e a direita
 */
Node* leftAndRightRotation(Node *root);

/**
 * @brief Funcao para realizar a rotacao dupla (esquerda - direita)
 * @param *root
 * @return rotacao a esquerdaa e a direita
 */
Node* leftAndRightRotation(Node *root);

/**
 * @brief Funcao para realizar a rotacao dupla (direita - esquerda)
 * @param *root
 * @return rotacao a esquerda e a direita
 */
Node* rightAndLeftRotation(Node *root);

/**
 * @brief Funcao para realizar o balanceamento apos uma insercao ou remocao
 * @param *root
 * @return *root
 */
Node *balance(Node *root);

/**
 * @brief Insere um novo nó na arvore
 * @param *root, code, capacity
 * @return *root
 */
Node *insertRoom(Node *root, unsigned int code, unsigned int capacity);

/**
 * @brief Funcao para remover um no da arvore
 * @param *root, code
 * @return *root
 */
Node *removeRoom(Node *root, unsigned int code);

/**
 * @brief Function to search a node (room) by its code
 * @param *root, code
 * @return NULL or Node
 */
Node *searchNode(Node *root, unsigned int code);

/**
 * @brief Funcao para mostrar a arvore avl
 * @param *root, level
 * @return void
 */
void showAVLTree(Node *root, int level);


#endif
