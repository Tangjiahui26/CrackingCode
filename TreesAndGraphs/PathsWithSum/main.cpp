#include <iostream>

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

// approach1: brute-force
// runtime: O(n log(n) ) for balanced tree
// runtime: O(n^2) for unbalanced tree

int countPathsWithSumFromNode(TreeNode* node, int sum, int currentSum) {
    if (node == NULL) {
        return 0;
    }
    currentSum += node->data;

    int totalpaths = 0;
    if (currentSum == sum) {
        totalpaths++;
    }

    totalpaths += countPathsWithSumFromNode(node->left, sum, currentSum);
    totalpaths += countPathsWithSumFromNode(node->right, sum, currentSum);
    return totalpaths;
}

int countPathswithSum(TreeNode * node, int sum) {
    if (node == NULL) {
        return 0;
    }

    int pathsFromRoot = countPathsWithSumFromNode(node, sum, 0);

    int pathsOnLeft = countPathswithSum(node->left, sum);
    int pathsOnRight = countPathswithSum(node->right, sum);

    return pathsFromRoot + pathsOnLeft + pathsOnRight;
}


int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode * node = minimalTree(arr, 0, n - 1);
    preorder(node);

    int result = countPathswithSum(node,5);

    cout << endl;
    cout << "Paths with Sum 5: " << result << endl;
    return 0;
}
