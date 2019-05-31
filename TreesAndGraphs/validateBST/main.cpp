#include <iostream>
#include <list>

using namespace std;

class TreeNode{
  public:
    int data;
    TreeNode * left;
    TreeNode * right;
};

TreeNode * newNode(int data) {
    TreeNode * node = new TreeNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

TreeNode * minimalTree(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    TreeNode * root = newNode(arr[mid]);

    root->left = minimalTree(arr, start, mid - 1);
    root->right = minimalTree(arr, mid + 1, end);

    return root;
}

void preorder(TreeNode* root){
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root){
    if (root == NULL) {
        return;
    }
    preorder(root->left);
    cout << root->data << " ";
    preorder(root->right);
}

// Method 1: In-order traversal
// Cannot deal with duplicates:
// EXAMPLE: inorder: 0 20 20

bool isBST(TreeNode * root, int &pre) {
    if (root == NULL) {
        return true;
    }

    if (!isBST(root->left, pre)){
        return false;
    }

    if (pre != NULL && root->data <= pre) {
        return false;
    }

    pre = root->data;

    if(!isBST(root->right, pre)) {
        return false;
    }
    return true;
}

// Method 2: Min and Max checking
bool checkBST(TreeNode * root, int min, int max){
    if (root == NULL) {
        return true;
    }

    // root->data <= min solves the problem of Method 1
    if ((min != NULL && root->data <= min) || (max != NULL && root->data > max)) {
        return false;
    }

    if (!checkBST(root->left, min, root->data) || !checkBST(root->right, root->data, max)){
        return false;
    }
    return true;
}

bool isBSTByMinAndMax(TreeNode * root) {
    return checkBST(root, NULL, NULL);
}

int main()
{
    // sorted array
    int arr[] = {-100,-1,1,2,3,4,5,6,7,8,9,11,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode * node = minimalTree(arr, 0, n - 1);
    inorder(node);
    int pre = NULL;

    string result_1 = isBST(node, pre) ? "true" : "false";
    string result_2 = isBSTByMinAndMax(node) ? "true" : "false";
    cout << "\nIs BST: " << result_1 << endl;
    cout << "Is BST: " << result_2 << endl;
    return 0;
}
