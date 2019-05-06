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

void printLinkedList(struct Node * node) {
    while (node != NULL) {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}

struct Node* partition(struct Node* head, int i) {
    struct Node* firstStart = NULL;
    struct Node* firstEnd = NULL;
    struct Node* secondStart = NULL;
    struct Node* secondEnd = NULL;

    while(head != NULL) {
        // save the value of head->next
        struct Node * next = head->next;
        // set head->next to NULL so it will be a signle node
        head->next = NULL;
        if (head->data < i) {
            if (firstStart == NULL) {
                firstStart = head;
                firstEnd = firstStart;
            } else {
                firstEnd->next = head;
                firstEnd = firstEnd->next;
            }
        } else {
            if (secondEnd == NULL) {
                secondStart = head;
                secondEnd = secondStart;
            } else {
                secondEnd->next = head;
                secondEnd = secondEnd->next;
            }
        }
        head = next;
    }

    if(firstStart == NULL) {
        return secondStart;
    }

    firstEnd->next = secondStart;
    return firstStart;
}

int main()
{
    struct Node *start = pushNode(3);
    start->next = pushNode(5);
    start->next->next = pushNode(8);
    start->next->next->next = pushNode(5);
    start->next->next->next->next = pushNode(10);
    start->next->next->next->next->next =
                                    pushNode(2);
    start->next->next->next->next->next->next =
                                    pushNode(1);

    printf("Linked list before Partition ");
    printLinkedList(start);

    struct Node *after = partition(start, 5);

    printf("Linked list after Partition ");
    printLinkedList(after);

    return 0;
}
