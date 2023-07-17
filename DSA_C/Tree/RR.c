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

// Function to represent an AVL tree using inorder traversal
void representAVL(struct AVLNode *root)
{
    if (root != NULL)
    {
        representAVL(root->left);
        printf("%d ", root->data);
        representAVL(root->right);
    }
}

int main()
{
    struct AVLNode *root = NULL;

    // Perform R-R Rotation
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    printf("AVL Tree after R-R Rotation: ");
    representAVL(root);
    printf("\n");

    return 0;
}
