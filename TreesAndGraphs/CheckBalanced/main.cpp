#include <iostream>
#include <algorithm>
#include <limits.h>

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

int checkHeight(TreeNode *root) {
    if (root == NULL) {
        return -1;
    }

    int leftHight = checkHeight(root->left);
    if (leftHight == INT_MIN) {
        return INT_MIN;
    }

    int rightHight = checkHeight(root->right);
    if (rightHight == INT_MIN) {
        return INT_MIN;
    }

    int height_diff = leftHight - rightHight;
    if (abs(height_diff) > 1) {
        return INT_MIN;
    } else {
        return std::max(leftHight, rightHight) + 1;
    }
}

bool isBalanced(TreeNode * root) {
    return checkHeight(root) != INT_MIN;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,100,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode * node = minimalTree(arr, 0, n - 1);
    preorder(node);

    string result = isBalanced(node) ? "YES" : "NO";
    cout << "\nIs Balanced? " << result << endl;

    return 0;
}
