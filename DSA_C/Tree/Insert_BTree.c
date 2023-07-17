#include <stdio.h>
#include <stdlib.h>
#define MAX_KEYS 3

// Structure for a B-tree node
struct BTreeNode
{
    int keys[MAX_KEYS];
    struct BTreeNode *child[MAX_KEYS + 1];
    int numKeys;
    int leaf;
};

// Function to create a new B-tree node
struct BTreeNode *createNode(int leaf)
{
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    newNode->numKeys = 0;
    newNode->leaf = leaf;
    for (int i = 0; i < MAX_KEYS + 1; i++)
    {
        newNode->child[i] = NULL;
    }
    return newNode;
}

// Function to search a key in the B-tree
struct BTreeNode *searchKey(struct BTreeNode *root, int key)
{
    int i = 0;
    while (i < root->numKeys && key > root->keys[i])
    {
        i++;
    }
    if (root->keys[i] == key)
    {
        return root;
    }
    if (root->leaf)
    {
        return NULL;
    }
    return searchKey(root->child[i], key);
}

// Function to split a child node of the B-tree
void splitChild(struct BTreeNode *parent, int index, struct BTreeNode *child)
{
    struct BTreeNode *newNode = createNode(child->leaf);
    newNode->numKeys = MAX_KEYS - 1;

    for (int j = 0; j < MAX_KEYS - 1; j++)
    {
        newNode->keys[j] = child->keys[j + MAX_KEYS];
    }

    if (!child->leaf)
    {
        for (int j = 0; j < MAX_KEYS; j++)
        {
            newNode->child[j] = child->child[j + MAX_KEYS];
        }
    }

    child->numKeys = MAX_KEYS - 1;

    for (int j = parent->numKeys; j > index; j--)
    {
        parent->child[j + 1] = parent->child[j];
    }
    parent->child[index + 1] = newNode;

    for (int j = parent->numKeys - 1; j >= index; j--)
    {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[index] = child->keys[MAX_KEYS - 1];
    parent->numKeys++;
}

// Function to insert a key into the B-tree
void insertKey(struct BTreeNode *root, int key)
{
    if (root->numKeys == MAX_KEYS - 1)
    {
        struct BTreeNode *newNode = createNode(0);
        newNode->child[0] = root;
        root = newNode;
        splitChild(newNode, 0, root);
    }
    int i = root->numKeys - 1;
    if (root->leaf)
    {
        while (i >= 0 && key < root->keys[i])
        {
            root->keys[i + 1] = root->keys[i];
            i--;
        }
        root->keys[i + 1] = key;
        root->numKeys++;
    }
    else
    {
        while (i >= 0 && key < root->keys[i])
        {
            i--;
        }
        i++;
        if (root->child[i]->numKeys == MAX_KEYS)
        {
            splitChild(root, i, root->child[i]);
            if (key > root->keys[i])
            {
                i++;
            }
        }
        insertKey(root->child[i], key);
    }
}

// Function to represent a B-tree in inorder traversal
void inorderTraversal(struct BTreeNode *root)
{
    if (root != NULL)
    {
        int i;
        for (i = 0; i < root->numKeys; i++)
        {
            if (!root->leaf)
            {
                inorderTraversal(root->child[i]);
            }
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf)
        {
            inorderTraversal(root->child[i]);
        }
    }
}

int main()
{
    struct BTreeNode *root = createNode(1);
    root->keys[0] = 10;
    root->numKeys++;

    // Inserting keys in the B-tree
    insertKey(root, 20);
    insertKey(root, 30);
    insertKey(root, 40);
    insertKey(root, 50);

    printf("B-Tree after insertions: ");
    inorderTraversal(root);
    printf("\n");

    int searchKey = 30;
    struct BTreeNode *searchResult = searchKey(root, searchKey);
    if (searchResult != NULL)
    {
        printf("Key %d found in the B-Tree\n", searchKey);
    }
    else
    {
        printf("Key %d not found in the B-Tree\n", searchKey);
    }

    return 0;
}
