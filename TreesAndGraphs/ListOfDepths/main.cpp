#include <iostream>
#include <list>
#include <vector>

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

void createLevelLinkedList(TreeNode * node, unsigned int depth, vector<list<int>> & lists) {
    if (node == NULL) {
        return;
    }

    if (lists.size() == depth) {
        lists.push_back(list<int>());
    }

    list<int> & l = lists[depth];
    l.push_back(node->data);

    createLevelLinkedList(node->right, depth + 1, lists);
    createLevelLinkedList(node->left, depth + 1, lists);
}

void printLists(vector<list<int>> & lists) {
    int depth = 0;
    for (list<int> l : lists) {
        cout << "\nDepth " << depth << ": ";
        for (int val : l) {
            cout << " " << val;
        }
        cout << endl;
        depth++;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode * node = minimalTree(arr, 0, n - 1);
    preorder(node);

    vector<list<int>> lists;
    createLevelLinkedList(node, 0, lists);
    printLists(lists);
    return 0;
}
