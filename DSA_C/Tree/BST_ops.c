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

// Function to insert a node into the binary search tree
struct TreeNode *insert(struct TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else
    {
        if (data < root->data)
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

// Function to search for a node in the binary search tree
struct TreeNode *search(struct TreeNode *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }

    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

// Function to find the minimum value node in a binary search tree
struct TreeNode *findMinimum(struct TreeNode *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the binary search tree
struct TreeNode *delete(struct TreeNode *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        // Case 1: No child or 1 child
        if (root->left == NULL)
        {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: 2 children
        struct TreeNode *temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }

    return root;
}

// Function to represent a binary search tree using inorder traversal
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

    printf("Binary Search Tree: ");
    representBST(root);
    printf("\n");

    int searchKey = 40;
    struct TreeNode *searchResult = search(root, searchKey);
    if (searchResult != NULL)
    {
        printf("Node with data %d found in the BST\n", searchKey);
    }
    else
    {
        printf("Node with data %d not found in the BST\n", searchKey);
    }

    int deleteKey = 30;
    root = delete (root, deleteKey);
    printf("Binary Search Tree after deleting node with data %d: ", deleteKey);
    representBST(root);
    printf("\n");

    return 0;
}
