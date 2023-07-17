#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the Binary Tree
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else
    {
        if (data <= root->data)
        {
            root->left = insertNode(root->left, data);
        }
        else
        {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// Function to search for a key in the Binary Tree
struct Node *searchKey(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return searchKey(root->left, key);
    }
    else
    {
        return searchKey(root->right, key);
    }
}

// Function to count the number of nodes in the Binary Tree
int countNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to calculate the height of the Binary Tree
int calculateHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Function for inorder traversal of the Binary Tree
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function for preorder traversal of the Binary Tree
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function for postorder traversal of the Binary Tree
void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *root = NULL;

    // Insert nodes into the Binary Tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Search for a key in the Binary Tree
    int searchKey = 30;
    struct Node *searchResult = searchKey(root, searchKey);
    if (searchResult != NULL)
    {
        printf("Key %d found in the Binary Tree\n", searchKey);
    }
    else
    {
        printf("Key %d not found in the Binary Tree\n", searchKey);
    }

    // Count the number of nodes in the Binary Tree
    int numNodes = countNodes(root);
    printf("Number of nodes in the Binary Tree: %d\n", numNodes);

    // Calculate the height of the Binary Tree
    int height = calculateHeight(root);
    printf("Height of the Binary Tree: %d\n", height);

    // Perform inorder traversal of the Binary Tree
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Perform preorder traversal of the Binary Tree
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Perform postorder traversal of the Binary Tree
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
