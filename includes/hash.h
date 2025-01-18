#ifndef H_HASH
#define H_HASH

typedef struct _node NodeHash;

typedef struct ListHash;

/**
 * @brief Função para inicializar a lista de cada elemento da tabela hash.
 * @param *list
 * @return (void)
 */
void inicializeList(ListHash *list);

/**
 * @brief Função para inserir na lista de uma posição específica da tabela hash.
 * @param *list, code, *status
 * @return (void)
 */
void insertIntoList(ListHash *list, unsigned int code, char *status);

/**
 * @brief Função para atualizar o status de uma sala dentro de uma lista de uma posição específica da tabela hash.
 * @param *list, code, *newStatus
 * @return (void)
 */
void updateRoomStatus(ListHash *list, unsigned int code, char *newStatus);

/**
 * @brief Função para buscar o status de uma sala dentro de uma lista de uma posição específica da tabela hash.
 * @param *list, code
 * @return status
 */
char *searchList(ListHash *list, unsigned int code);

/**
 * @brief Função para imprimir a lista de uma posição específica da tabela hash.
 * @param *list
 * @return (void)
 */
void printList(ListHash *list);

/**
 * @brief Função para inicializar a tabela hash.
 * @param t[], size
 * @return (void)
 */
void inicializeHashTable(ListHash t[], unsigned int size);

/**
 * @brief Função para gerar a posição na tabela hash.
 * @param code, size
 * @return id
 */
int hashFunction(unsigned int code, unsigned int size);

/**
 * @brief Função para inserir na tabela hash.
 * @param t[], code, *status, size
 * @return (void)
 */
void insertIntoHashTable(ListHash t[], unsigned int code, char *status, unsigned int size);

/**
 * @brief Função para atualizar o status de uma sala na tabela hash.
 * @param t[], code, *status, size
 * @return (void)
 */
void updateStatusIntoHashTable(ListHash t[], unsigned int code, char *newStatus, unsigned int size);

/**
 * @brief Função para buscar o status de uma sala dentro da tabela hash.
 * @param t[], code, size
 * @return *status
 */
char *searchStatusIntoHashTable(ListHash t[], unsigned int code, unsigned int size);

/**
 * @brief Função para imprimir a tabela hash.
 * @param t[], size
 * @return (void)
 */
void printHashTable(ListHash t[], const unsigned int size);

#endif
