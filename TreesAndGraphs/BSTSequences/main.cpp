#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

typedef list<int> int_list;
typedef vector<int_list*> list_vector;

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

void preorder(TreeNode* root){
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void weaveLists(int_list * first, int_list * second, list_vector* results, int_list * prefix){
    if (first->size() == 0 || second->size() == 0) {
        auto result = new int_list(*prefix);
        for (auto val : *first) {
            result->push_back(val);
        }

        for (auto val : *second) {
            result->push_back(val);
        }
        results->push_back(result);
        return;
    }

    // damaging and then restoring the list
    int headFirst = first->front();
    first->pop_front();
    prefix->push_back(headFirst);
    weaveLists(first, second, results, prefix);
    prefix->pop_back();
    first->push_back(headFirst);

    // same for second
    int headSecond = second->front();
    second->pop_front();
    prefix->push_back(headSecond);
    weaveLists(first, second, results, prefix);
    prefix->pop_back();
    second->push_back(headSecond);
}

list_vector* BSTSequences(TreeNode* node){
    auto result = new list_vector;

    if(node == NULL) {
        result->push_back(new int_list);
        return result;
    }

    auto prefix = new int_list;
    prefix->push_back(node->data);

    auto left_seq = BSTSequences(node->left);
    auto right_seq = BSTSequences(node->right);

    for (auto left : *left_seq) {
        for (auto right: *right_seq) {
            auto weaved = new list_vector;
            weaveLists(left, right, weaved, prefix);
            for (auto val : *weaved) {
                result->push_back(val);
            }
        }
    }
    return result;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode * node = minimalTree(arr, 0, n - 1);
    cout << "PREORDER: ";
    preorder(node);
    cout << endl;

    for (auto seq : *BSTSequences(node)) {
        for (auto val : *seq) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
