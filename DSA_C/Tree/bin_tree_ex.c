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

// Function to insert a node into the binary tree based on the conditions
struct TreeNode *insertNode(struct TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to represent a binary tree using inorder traversal
void representBinaryTree(struct TreeNode *root)
{
    if (root != NULL)
    {
        representBinaryTree(root->left);
        printf("%d ", root->data);
        representBinaryTree(root->right);
    }
}

int main()
{
    struct TreeNode *root = NULL;

    // Inserting 43 as the root of the tree
    root = insertNode(root, 43);

    // Inserting the remaining elements
    root = insertNode(root, 10);
    root = insertNode(root, 79);
    root = insertNode(root, 90);
    root = insertNode(root, 12);
    root = insertNode(root, 54);
    root = insertNode(root, 11);
    root = insertNode(root, 9);
    root = insertNode(root, 50);

    printf("Binary Tree: ");
    representBinaryTree(root);
    printf("\n");

    return 0;
}
