#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node * next;
};

struct Node * pushNode(int data) {
    Node * temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printLinkedListNode(struct Node * node) {
    if (node != NULL) {
        cout << node->data << endl;
    } else {
        cout << "NULL" << endl;
    }
}

Node* loopDetection(Node* head) {
    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            break;
        }
    }

    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }

    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{
    struct Node *list1 = pushNode(1);
    list1->next = pushNode(2);
    list1->next->next = pushNode(6);
    list1->next->next->next = pushNode(2);
    list1->next->next->next->next = pushNode(1);
//    list1->next->next->next->next  = list1->next;
    Node* loopEntry = loopDetection(list1);
    printLinkedListNode(loopEntry);
    return 0;
}
