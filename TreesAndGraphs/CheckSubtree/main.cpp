#include <iostream>
#include <string>

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

// approach1: pre-order with NULL marks
// time complexity: O(n + m)
// space complexity: O(n + m)
// n, m is the number of nodes in T1 and T2

void getOrderString(TreeNode *node, string &s) {
    if (node == NULL) {
        s.append("X");
        return;
    }

    string val = to_string(node->data);
    s.append(val);
    getOrderString(node->left, s);
    getOrderString(node->right, s);
}

bool checkSubtree(TreeNode *t1, TreeNode *t2) {
    string s1;
    string s2;

    getOrderString(t1, s1);
    getOrderString(t2, s2);

    size_t found = s1.find(s2.c_str());
    return found != string::npos;
}

// approach2: matchTree
// time complexity: O(nm) - worst case; O(n + km) k is the number of occurrences of T2's root in T1
// space complexity: O(log(n) + log(m))

bool matchTree(TreeNode * n1, TreeNode * n2){
    if (n1 == NULL && n2 == NULL) {
        return true;
    } else if (n1 == NULL || n2 == NULL) {
        return false;
    } else if (n1->data != n2->data) {
        return false;
    } else {
        return matchTree(n1->right, n2->right) && matchTree(n1->left, n2->left);
    }
}

bool subTree(TreeNode * n1, TreeNode * n2){
    if (n1 == NULL){
        return false;
    } else if (n1->data == n2->data && matchTree(n1, n2)){
        return true;
    }
    return subTree(n1->left, n2) || subTree(n1->right, n2);
}

bool checkSubtreeBySearch(TreeNode * n1, TreeNode * n2) {
    if (n2 == NULL) {
        return true;
    }
    return subTree(n1, n2);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode * node = minimalTree(arr, 0, n - 1);
    preorder(node);

    int arr1[] = {1,2,3,4,5,6,7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    TreeNode * node1 = minimalTree(arr1, 0, n1 - 1);
    cout << endl;
    preorder(node1);

    cout << endl;
    string result = checkSubtree(node, node1) ? "YES" : "NO";
    cout << "CheckSubtree: " << result << endl;

    string result_1 = checkSubtreeBySearch(node, node1) ? "YES" : "NO";
    cout << "CheckSubtreeBySearch: " << result_1 << endl;
    return 0;
}
