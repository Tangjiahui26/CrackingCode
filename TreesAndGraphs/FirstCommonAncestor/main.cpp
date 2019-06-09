#include <iostream>
#include <cmath>

using namespace std;

class TreeNode{
  public:
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

TreeNode * newNode(int data) {
    TreeNode * node = new TreeNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

TreeNode * minimalTree(int arr[], int start, int end, TreeNode * parent = NULL) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    TreeNode * root = newNode(arr[mid]);

    root->parent = parent;
    root->left = minimalTree(arr, start, mid - 1, root);
    root->right = minimalTree(arr, mid + 1, end, root);

    return root;
}

void inorder(TreeNode* root){
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


// similar to intersection of linked-lists

int getDepth(TreeNode * node){
    int depth = 0;
    while(node != NULL){
        node = node->parent;
        depth++;
    }
    return depth;
}

TreeNode * firstCommonAncestor(TreeNode * p, TreeNode * q){
    int delta = getDepth(p) - getDepth(q);
    TreeNode *first = delta > 0 ? q : p;
    TreeNode *second = delta > 0 ? p : q;

    while (abs(delta) > 0 && second != NULL) {
        second = second->parent;
        delta--;
    }

    while(first != second && first != NULL && second != NULL){
        first = first->parent;
        second = second->parent;
    }

    return (first == NULL || second == NULL) ? NULL : first;
}

int main()
{
    int arr[] = {-1,1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode * node = minimalTree(arr, 0, n - 1);
    inorder(node);
    TreeNode * node1 = node->left->left;
    TreeNode * node2 = node->right->right;
    TreeNode * ancestor = firstCommonAncestor(node1, node2);
    cout << "\nFirst Common Ancestor of Node " << node1->data << " and Node " << node2->data
         << " is " << ancestor->data << endl;
    return 0;
}
