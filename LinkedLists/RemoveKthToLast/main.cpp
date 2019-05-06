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

// approach1: running pointers (two pointers)
struct Node * returnKthToLast(struct Node * head, int k) {
    Node *first = head;
    Node *second = head;

    for (int i = 0; i < k; ++i) {
        if (first == NULL){
            return NULL;
        }
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return second;
}

//approach2: recursive

struct Node * kthToLast(struct Node * head, int k, int& i) {
    if(head == NULL){
        return NULL;
    }

    Node * nd = kthToLast(head->next, k, i);
    i = i + 1;
    if (i == k) {
        return head;
    }
    return nd;
}

struct Node * kthToLast(struct Node * head, int k){
    int i = 0;
    return kthToLast(head, k, i);
}

int main()
{
    /* The constructed linked list is:
         10->12->11->11->12->11->10*/
    struct Node *start = pushNode(10);
    start->next = pushNode(12);
    start->next->next = pushNode(11);
    start->next->next->next = pushNode(11);
    start->next->next->next->next = pushNode(12);
    start->next->next->next->next->next =
                                    pushNode(11);
    start->next->next->next->next->next->next =
                                    pushNode(10);

    int k = 6;
    struct Node *returnNode = kthToLast(start, k);
    cout << k << "th to last is " << returnNode->data << endl;
    return 0;
}
