#include <stdio.h>
#include <stdlib.h>

// Structure for a binary search tree node
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

// Function to insert a node into a binary search tree
struct TreeNode *insert(struct TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else
    {
        if (data <= root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

// Function to represent a binary search tree
void representBST(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    representBST(root->left);
    printf("%d ", root->data);
    representBST(root->right);
}

int main()
{
    struct TreeNode *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    representBST(root);
    printf("\n");

    return 0;
}
