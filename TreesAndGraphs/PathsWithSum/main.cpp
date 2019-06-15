#include <iostream>
#include <map>
#include <algorithm>

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

// approach 2: hash table
// runtime: O(N), O(log(N)) for balanced tree

void incrementHashTable(map<int, int> &table, int key, int delta){
    int val = 0;
    if (table.find(key) != table.end()) {
        val = table.find(key)->second + delta;
    } else {
        val += delta;
    }

    if(val == 0) {
        table.erase(key);
    } else {
        table[key] = val;
    }

}

int countPathWithSumNEW(TreeNode * node, int targetSum,
                        int runningSum, map<int, int> &pathCount) {
    if (node == NULL){
        return 0;
    }

    runningSum += node->data;
    int sum = runningSum - targetSum;
    int totalPaths;
    if (pathCount.find(sum) != pathCount.end()) {
        totalPaths = pathCount.find(sum)->second;
    } else {
        totalPaths = 0;
    }

    if (runningSum == targetSum) {
        totalPaths++;
    }

    incrementHashTable(pathCount, runningSum, 1);
    totalPaths += countPathWithSumNEW(node->left, targetSum, runningSum, pathCount);
    totalPaths += countPathWithSumNEW(node->right, targetSum, runningSum, pathCount);
    incrementHashTable(pathCount, runningSum, -1);

    return totalPaths;
}

int countPathWithSumWrapper(TreeNode * node, int targetSum) {
    map<int, int> x;
    return countPathWithSumNEW(node, targetSum, 0, x);
}


int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode * node = minimalTree(arr, 0, n - 1);
    preorder(node);

    int result = countPathswithSum(node,5);
    int result_2 = countPathWithSumWrapper(node,5);


    cout << endl;
    cout << "Paths with Sum 5: " << result << endl;
    cout << "Paths with Sum 5: " << result_2 << endl;
    return 0;
}
