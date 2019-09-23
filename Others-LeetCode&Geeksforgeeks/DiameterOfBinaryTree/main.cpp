#include <iostream>

using namespace std;

// The diameter of a tree (sometimes called the width) is the number of
// nodes on the longest path between two end nodes.

// recursive solution

struct Node{
    int data;
    struct Node* left, * right;
};

struct Node* newNode(int data){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int height(struct Node* node){
    if (node == NULL){
        return 0;
    }
    return 1 + max(height(node->left), height(node->right));
}

int diameter(struct Node * tree){
    if (tree == NULL){
        return 0;
    }

    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);

    int leftDiameter = diameter(tree->left);
    int rightDiameter = diameter(tree->right);

    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);

    printf("Diameter is %d", diameter(root));
    return 0;
}
