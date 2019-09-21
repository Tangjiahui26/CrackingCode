#include <iostream>

using namespace std;

// Given a linked list where every node represents a linked list
// and contains two pointers of its type:
// (1) pointer to next node in the main lust ("right" pointer)
// (2) pointer to a linked list where this node is head ("down" pointer)

// write a function flatten() to flatten the lists into a single linked list
// The flattened linked list should also be sorted.

// solution: using Merge() to merge lists one by one - C implementation

struct Node{
    int data;
    struct Node *right;
    struct Node *down;
};

void push(Node** head_ref, int new_data){
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->right = NULL;

    new_node->data = new_data;

    new_node->down = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node* node){
    while (node != NULL){
        printf("%d ", node->data);
        node = node->down;
    }
}

// function to merge two sorted linked lists

Node* merge(Node* a, Node* b){
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node* result;
    if (a->data < b->data){
        result = a;
        result->down = merge(a->down, b);
    } else {
        result = b;
        result->down = merge(a, b->down);
    }
    return result;
}

Node* flatten(Node* root){
    if (root == NULL || root->right == NULL) {
        return root;
    }

    // merge this list with the list on right side
    return merge(root, flatten(root->right));
}

int main()
{
    // test code
    Node* root = NULL;
    push(&root, 30);
    push(&root, 8);
    push(&root, 7);
    push(&root, 5);

    push(&(root->right), 20);
    push(&(root->right), 10);

    push(&(root->right->right), 50);
    push(&(root->right->right), 22);
    push(&(root->right->right), 19);

    push(&(root->right->right->right), 45);
    push(&(root->right->right->right), 40);
    push(&(root->right->right->right), 35);
    push(&(root->right->right->right), 20);

    root = flatten(root);

    printList(root);
    return 0;
}
