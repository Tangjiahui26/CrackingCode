#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node * next;
};

struct Node * pushNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printLinkedList(struct Node * head){

    while(head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL"<< endl;
}

bool deleteMiddleNode(struct Node * node) {
    if(node == NULL || node->next == NULL) {
        return false;
    }
    node->data = node->next->data;
    node->next = node->next->next;
    return true;
}

int main()
{
    struct Node *start = pushNode(10);
    start->next = pushNode(11);
    start->next->next = pushNode(12);
    start->next->next->next = pushNode(13);
    start->next->next->next->next = pushNode(14);
    start->next->next->next->next->next =
                                    pushNode(15);
    start->next->next->next->next->next->next =
                                    pushNode(16);

    printf("Linked list before deletion ");
    printLinkedList(start);

    deleteMiddleNode(start->next->next);

    printf("Linked list after deletion ");
    printLinkedList(start);

    return 0;
}
