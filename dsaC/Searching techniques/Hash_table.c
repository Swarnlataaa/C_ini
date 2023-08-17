#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct KeyValue
{
    char key[50];
    int value;
    struct KeyValue *next;
} KeyValue;

typedef struct HashTable
{
    KeyValue *table[TABLE_SIZE];
} HashTable;

unsigned int hash(const char *key)
{
    unsigned int hash_value = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        hash_value = hash_value * 31 + key[i];
    }
    return hash_value % TABLE_SIZE;
}

HashTable *createHashTable()
{
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void insert(HashTable *hashTable, const char *key, int value)
{
    unsigned int index = hash(key);

    KeyValue *newEntry = (KeyValue *)malloc(sizeof(KeyValue));
    strcpy(newEntry->key, key);
    newEntry->value = value;
    newEntry->next = NULL;

    if (hashTable->table[index] == NULL)
    {
        hashTable->table[index] = newEntry;
    }
    else
    {
        KeyValue *current = hashTable->table[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newEntry;
    }
}

int search(HashTable *hashTable, const char *key)
{
    unsigned int index = hash(key);

    KeyValue *current = hashTable->table[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value;
        }
        current = current->next;
    }

    return -1; // Key not found
}

int main()
{
    HashTable *hashTable = createHashTable();

    insert(hashTable, "apple", 5);
    insert(hashTable, "banana", 8);
    insert(hashTable, "orange", 12);

    printf("Value for 'apple': %d\n", search(hashTable, "apple"));
    printf("Value for 'banana': %d\n", search(hashTable, "banana"));
    printf("Value for 'orange': %d\n", search(hashTable, "orange"));
    printf("Value for 'grape': %d\n", search(hashTable, "grape"));

    return 0;
}
