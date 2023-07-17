#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node with the given data
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to represent a binary tree
void representBinaryTree(struct TreeNode *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    representBinaryTree(root->right, level + 1);

    for (int i = 0; i < level; i++)
    {
        printf("    ");
    }
    printf("%d\n", root->data);

    representBinaryTree(root->left, level + 1);
}

int main()
{
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    representBinaryTree(root, 0);

    return 0;
}
