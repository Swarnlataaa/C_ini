#include <stdio.h>
#include <stdlib.h>

// Structure for an AVL tree node
struct AVLNode
{
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

// Function to create a new node with the given data
struct AVLNode *createNode(int data)
{
    struct AVLNode *newNode = (struct AVLNode *)malloc(sizeof(struct AVLNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Function to get the height of a node
int getHeight(struct AVLNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// Function to get the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to update the height of a node
void updateHeight(struct AVLNode *node)
{
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Function to perform a right rotation
struct AVLNode *rightRotate(struct AVLNode *y)
{
    struct AVLNode *x = y->left;
    struct AVLNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Function to perform a left rotation
struct AVLNode *leftRotate(struct AVLNode *x)
{
    struct AVLNode *y = x->right;
    struct AVLNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Function to balance the AVL tree
struct AVLNode *balance(struct AVLNode *node, int data)
{
    // Update the height of the current node
    updateHeight(node);

    // Check the balance factor
    int balanceFactor = getHeight(node->left) - getHeight(node->right);

    // Perform rotation if the tree is unbalanced

    // Left Left Case
    if (balanceFactor > 1 && data < node->left->data)
    {
        return rightRotate(node);
    }

    // Right Right Case
    if (balanceFactor < -1 && data > node->right->data)
    {
        return leftRotate(node);
    }

    // Left Right Case
    if (balanceFactor > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balanceFactor < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Function to insert a node into an AVL tree
struct AVLNode *insert(struct AVLNode *node, int data)
{
    if (node == NULL)
    {
        return createNode(data);
    }
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }
    else
    {
        return node; // Duplicate keys are not allowed
    }

    return balance(node, data);
}

// Function to find the minimum value node in an AVL tree
struct AVLNode *findMinimum(struct AVLNode *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

// Function to delete a node from an AVL tree
struct AVLNode *delete(struct AVLNode *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->data)
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
            struct AVLNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct AVLNode *temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: 2 children
        struct AVLNode *temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }

    return balance(root, data);
}

// Function to perform an inorder traversal of an AVL tree
void inorderTraversal(struct AVLNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct AVLNode *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("AVL Tree after insertions: ");
    inorderTraversal(root);
    printf("\n");

    int deleteKey = 30;
    root = delete (root, deleteKey);

    printf("AVL Tree after deletion of node with data %d: ", deleteKey);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
