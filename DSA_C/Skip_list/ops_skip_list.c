#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_LEVEL 6

// Structure for a skip list node
struct SkipNode
{
    int key;
    int value;
    struct SkipNode **next;
};

// Structure for the skip list
struct SkipList
{
    int level;
    struct SkipNode *header;
};

// Function to create a new skip list node
struct SkipNode *createNode(int key, int value, int level)
{
    struct SkipNode *newNode = (struct SkipNode *)malloc(sizeof(struct SkipNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = (struct SkipNode **)malloc((level + 1) * sizeof(struct SkipNode *));
    return newNode;
}

// Function to create and initialize a skip list
struct SkipList *createSkipList()
{
    struct SkipList *skipList = (struct SkipList *)malloc(sizeof(struct SkipList));
    skipList->level = 0;
    skipList->header = createNode(INT_MIN, 0, MAX_LEVEL);
    for (int i = 0; i <= MAX_LEVEL; i++)
    {
        skipList->header->next[i] = NULL;
    }
    return skipList;
}

// Function to generate a random level for a new node
int randomLevel()
{
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL)
    {
        level++;
    }
    return level;
}

// Function to insert a node into the skip list
void insert(struct SkipList *skipList, int key, int value)
{
    struct SkipNode *update[MAX_LEVEL + 1];
    struct SkipNode *current = skipList->header;

    for (int i = skipList->level; i >= 0; i--)
    {
        while (current->next[i] != NULL && current->next[i]->key < key)
        {
            current = current->next[i];
        }
        update[i] = current;
    }

    current = current->next[0];

    if (current == NULL || current->key != key)
    {
        int newLevel = randomLevel();
        if (newLevel > skipList->level)
        {
            for (int i = skipList->level + 1; i <= newLevel; i++)
            {
                update[i] = skipList->header;
            }
            skipList->level = newLevel;
        }

        struct SkipNode *newNode = createNode(key, value, newLevel);

        for (int i = 0; i <= newLevel; i++)
        {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }
}

// Function to search for a node in the skip list
bool search(struct SkipList *skipList, int key)
{
    struct SkipNode *current = skipList->header;

    for (int i = skipList->level; i >= 0; i--)
    {
        while (current->next[i] != NULL && current->next[i]->key < key)
        {
            current = current->next[i];
        }
    }

    current = current->next[0];

    return (current != NULL && current->key == key);
}

// Function to print the elements of the skip list
void printSkipList(struct SkipList *skipList)
{
    printf("Skip List:\n");
    for (int i = skipList->level; i >= 0; i--)
    {
        struct SkipNode *current = skipList->header->next[i];
        printf("Level %d: ", i);
        while (current != NULL)
        {
            printf("(%d, %d) ", current->key, current->value);
            current = current->next[i];
        }
        printf("\n");
    }
}

int main()
{
    // Create a skip list
    struct SkipList *skipList = createSkipList();

    // Insert nodes into the skip list
    insert(skipList, 3, 30);
    insert(skipList, 6, 60);
    insert(skipList, 2, 20);
    insert(skipList, 5, 50);
    insert(skipList, 1, 10);

    // Print the skip list
    printSkipList(skipList);

    // Search for nodes in the skip list
    printf("Search 4: %s\n", search(skipList, 4) ? "Found" : "Not Found");
    printf("Search 5: %s\n", search(skipList, 5) ? "Found" : "Not Found");

    // Free the memory allocated for the skip list
    struct SkipNode *current = skipList->header;
    struct SkipNode *temp;
    while (current != NULL)
    {
        temp = current;
        current = current->next[0];
        free(temp->next);
        free(temp);
    }
    free(skipList);

    return 0;
}
