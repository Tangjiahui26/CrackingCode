#include <iostream>

using namespace std;

// convert a binary tree to doubly linked-list in-pkace

class BiNode{
public:
    int data;
    BiNode* left;
    BiNode* right;
};

BiNode* newNode(int data){
    BiNode* new_node = new BiNode();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printList(BiNode* node){
    while (node!= NULL){
        cout << node->data << " ";
        node = node->right;
    }
}

// method1 - simple recursive
// this function returns the middle node (the root node in bitree)
BiNode* bintreeToListUtil(BiNode* root){
    if (root == NULL){
        return root;
    }

    if (root->left != NULL){
        BiNode* left = bintreeToListUtil(root->left);

        for (; left->right != NULL; left = left->right);

        // concat
        left->right = root;
        root->left = left;
    }

    if (root->right != NULL){
        BiNode* right = bintreeToListUtil(root->right);

        for (; right->left != NULL; right = right->left);

        right->left = root;
        root->right = right;
    }
    return root;
}

BiNode* bintreeToList(BiNode* root){
    if (root == NULL){
        return root;
    }
    root = bintreeToListUtil(root);

    // find the leftmost node
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

// method2 - in order
void bintreeToListInOrder(BiNode* root, BiNode** head){
    if (root == NULL){
        return;
    }
    // static for all recursive calls
    static BiNode* prev = NULL;

    bintreeToListInOrder(root->left, head);

    // convert this node
    if (prev == NULL) {
        *head = root;
    }else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    bintreeToListInOrder(root->right, head);
}

// follow-up: convert bitree to a circular DLL

BiNode* concatenate(BiNode *leftList, BiNode* rightList){
    if (leftList == NULL){
        return rightList;
    }
    if (rightList == NULL){
        return leftList;
    }
    BiNode* leftLast = leftList->left;
    BiNode* rightLast = rightList->left;

    leftLast->right = rightList;
    rightList->left = leftLast;

    leftList->left = rightLast;
    rightLast->right = leftList;
    return leftList;
}

BiNode* bintreeToCList(BiNode* root){
    if (root == NULL){
        return NULL;
    }

    // recursively convert left and right subtrees
    BiNode* left = bintreeToCList(root->left);
    BiNode* right = bintreeToCList(root->right);

    // make a circular linked list of single node (or root)
    root->left = root->right = root;

    return concatenate(concatenate(left, root), right);
}

void displayCList(BiNode* head){
    if (head == NULL){
        return;
    }
    cout << "Circular Linked list is \n";
    BiNode* itr = head;

    do{
        cout << itr->data << " ";
        itr =itr->right;
    }while (head != itr);
    cout << endl;
}

int main()
{
    BiNode *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    BiNode* head = bintreeToList(root);
    printList(head);

    cout << endl;

    BiNode *root2= newNode(10);
    root2->left = newNode(12);
    root2->right = newNode(15);
    root2->left->left = newNode(25);
    root2->left->right = newNode(30);
    root2->right->left = newNode(36);
    BiNode* h = NULL;
    bintreeToListInOrder(root2, &h);
    printList(h);

    cout << endl;

    BiNode *root3= newNode(10);
    root3->left = newNode(12);
    root3->right = newNode(15);
    root3->left->left = newNode(25);
    root3->left->right = newNode(30);
    root3->right->left = newNode(36);

    BiNode* h3 = bintreeToCList(root3);
    displayCList(h3);
    return 0;
}
