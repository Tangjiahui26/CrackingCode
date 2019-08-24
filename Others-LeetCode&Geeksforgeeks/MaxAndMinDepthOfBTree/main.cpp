#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node *newNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* The minimum depth is the number
 * of nodes along the shortest path
 * from the root node down to the
 * nearest leaf node.
 */

int minDepth(Node *root){
    if (root == NULL){
        return 0;
    }

    if (root->left == NULL && root->right == NULL){
        return 1;
    }

    if (!root->left){
        return minDepth(root->right) + 1;
    }

    if (!root->right){
        return minDepth(root->left) + 1;
    }

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

// get the maximum depth

int maxDepth(Node* node){
    if (node == NULL){
        return 0;
    } else {
        int leftD = maxDepth(node->left);
        int rightD = maxDepth(node->right);

        if (leftD > rightD){
            return (leftD + 1);
        } else {
            return (rightD + 1);
        }
    }

}

int main()
{
    Node *root     = newNode(1);
    root->left     = newNode(2);
    root->right     = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    cout <<"The minimum depth of binary tree is : "<< minDepth(root) << endl;
    cout <<"The maximum depth of binary tree is : "<< maxDepth(root);
    return 0;
}
