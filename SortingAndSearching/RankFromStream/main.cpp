#include <iostream>

using namespace std;

// approach 1: traverse the array and count the number
// Not correct when there are duplicates

//int main(){
//    int a[] = {5, 1, 14, 4, 15, 9, 7, 20, 11, 4};
//    // the number we want to rank
//    int key = 4;
//    int count = 0;
//    for (size_t i = 0; i <= sizeof(a)/sizeof(*a); i++){
//        if(a[i] <= key){
//            count++;
//        }
//    }
//    cout << "Rank of " << key << " in stream is " << count - 1 << endl;
//}

// approach 2: Inplement a new data structure and build a binary search tree

struct Node {
    int data;
    Node *left;
    Node * right;
    int left_size;
};

Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->left_size = 0;
    return temp;
}

Node* insert(Node * root, int data){
    if (!root){
        return newNode(data);
    }

    // insert values recursively
    if (data <= root->data){
        root->left = insert(root->left, data);
        // increment left size
        root->left_size++;
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int getRank(Node* root, int key){
    if (root->data == key){
        return root->left_size;
    }

    if (key < root->data){
        if(!root->left){
            // if cannot find the key in BST
            return -1;
        } else {
            return getRank(root->left, key);
        }
    } else {
        if (!root->right){
            return -1;
        } else {
            int right_size = getRank(root->right, key);
            return root->left_size + 1 + right_size;
        }
    }

}

int main()
{
    int a[] = {5, 1, 4, 4, 5, 9, 9, 7, 13, 3};
    Node *root = NULL;
    for (size_t i = 0; i < sizeof(a)/sizeof(*a); i++){
        root = insert(root, a[i]);
    }

    cout << "Rank of 4 in stream is " << getRank(root, 4) << endl;
    cout << "Rank of 13 in stream is " << getRank(root, 13) << endl;
    return 0;
}
