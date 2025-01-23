#ifndef H_HASH
#define H_HASH

typedef struct _node NodeHash;

typedef struct _listhash {
    NodeHash *start;
    unsigned int tam;
} ListHash;

/**
 * @brief Function to initialize the list of each element in the hash table.
 * @param *list
 * @return (void)
 */
void initializeList(ListHash *list);

/**
 * @brief Function to insert into the list of a specific position in the hash table.
 * @param *list, code, *status
 * @return (void)
 */
void insertIntoList(ListHash *list, unsigned int code, const char *status);

/**
 * @brief Function to update the status of a room within a list of a specific position in the hash table.
 * @param *list, code, *newStatus
 * @return (void)
 */
void updateRoomStatus(ListHash *list, unsigned int code, const char *newStatus);

/**
 * @brief Function to search for the status of a room within a list of a specific position in the hash table.
 * @param *list, code
 * @return status
 */
char *searchList(ListHash *list, unsigned int code);

/**
 * @brief Function to print the list of a specific position in the hash table.
 * @param *list
 * @return (void)
 */
void printList(ListHash *list);

/**
 * @brief Function to initialize the hash table.
 * @param t[], size
 * @return (void)
 */
void initializeHashTable(ListHash *t, unsigned int size);

/**
 * @brief Function to generate the position in the hash table.
 * @param code, size
 * @return id
 */
int hashFunction(unsigned int code, unsigned int size);

/**
 * @brief Function to insert into the hash table.
 * @param t[], code, *status, size
 * @return (void)
 */
void insertIntoHashTable(ListHash *t, unsigned int code, const char *status, unsigned int size);

/**
 * @brief Function to update the status of a room in the hash table.
 * @param t[], code, *newStatus, size
 * @return (void)
 */
void updateStatusIntoHashTable(ListHash *t, unsigned int code, const char *newStatus, unsigned int size);

/**
 * @brief Function to search for the status of a room within the hash table.
 * @param t[], code, size
 * @return *status
 */
char *searchStatusIntoHashTable(ListHash *t, unsigned int code, unsigned int size);

/**
 * @brief Function to print the hash table.
 * @param t[], size
 * @return (void)
 */
void printHashTable(ListHash *t, const unsigned int size);

void freeList(ListHash *list);

void freeHashTable(ListHash *t, unsigned int size);

#endif
