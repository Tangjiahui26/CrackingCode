#include <iostream>

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

TreeNode * successor(TreeNode * node){
    if (node == NULL) {
        return NULL;
    }

    if(node->right){
        node = node->right;
        while(node->left){
            node = node->left;
        }
        return node;
    } else {
        TreeNode * q = node;
        TreeNode * x = node->parent;
        while(x != NULL && x->left != q){
            q = x;
            x = x->parent;
        }
        return x;
    }
}

void printSuccessors(TreeNode * node){
    if (node == NULL){
        return;
    }
    TreeNode * _successor = successor(node);
    int res = _successor ? _successor->data : -1;
    cout << "Successor of " << node->data << " is " << res << endl;
    printSuccessors(node->left);
    printSuccessors(node->right);
}

int main()
{
    int arr[] = {-1,1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode * node = minimalTree(arr, 0, n - 1);
    inorder(node);
    printSuccessors(node);
    return 0;
}
