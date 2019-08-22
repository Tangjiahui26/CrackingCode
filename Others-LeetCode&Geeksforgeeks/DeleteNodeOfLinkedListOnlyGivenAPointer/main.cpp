#include <iostream>

using namespace std;

// Problem description:
/*
 * Given only a pointer to a node
 * to be deleted in a singly linked
 *  list, how do you delete it?
 */

// The idea is simple:
// Copying the data from the next node
// to the node to be deleted and delete
// the next node.

class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();

    new_node->data = new_data;
    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteNode(Node *node_ptr){
    Node* temp = node_ptr->next;
    node_ptr->data = temp->data;
    node_ptr->next = temp->next;
    free(temp);
}

int main()
{
    Node* head = NULL;

    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);

    cout << "Before deleting \n";
    printList(head);

    deleteNode(head);
    cout << "\nAfter detelting \n";
    printList(head);
    return 0;
}
