#include <iostream>

using namespace std;

// PostOrder to delete a tree
// Before deleting the parent node
// we should delete its children
// nodes first

class node {
public:
    int data;
    node* left;
    node* right;
};

node* newNode(int data){
    node* Node = new node();

    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

void _deleteTree(node* Node){
    if (Node == NULL){
        return;
    }

    // first delete both subtrees
    _deleteTree(Node->left);
    _deleteTree(Node->right);

    // then delete the node
    cout << "Deleting node: "<< Node->data << endl;
    free(Node);
}

// Delete a tree and sets the root as NULL
void deleteTree(node** Node_ref){
    _deleteTree(*Node_ref);
    *Node_ref = NULL;
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // pass the address of root here
    deleteTree(&root);
    cout << "Tree deleted ";
    return 0;
}
