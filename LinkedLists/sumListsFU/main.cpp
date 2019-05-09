#include <iostream>

using namespace std;

// Follwup of sumLists: The given lists are stored in forward order.

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

// Reverse a LinkedList: iteration
Node * reverseLinkedListInteration(Node* head) {
    Node* cur = head;
    Node* prev = NULL;

    while(cur != NULL) {
        Node * next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

// Reverse a LinkedList: recursive

Node * reverseLinkedListRecursiveHelper(Node* cur, Node* prev) {
    if(cur->next == NULL) {
        cur->next = prev;
        return cur;
    }
    Node * next = cur->next;
    cur->next = prev;
    return reverseLinkedListRecursiveHelper(next, cur);
}

Node * reverseLinkedListRecursive(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    return reverseLinkedListRecursiveHelper(head, NULL);
}



void printLinkedList(struct Node * node) {
    while (node != NULL) {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}

void setNext(Node*& head, Node* newNode){
    if (head == NULL){
        head = newNode;
    } else {
        Node * temp = new Node;
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

struct Node* sumLists(struct Node* list1, struct Node* list2, int carry) {
    if (list1 == NULL && list2 == NULL && carry == 0)
        return NULL;

    Node* result = new Node();
    int value = carry;

    if (list1 != NULL) {
        value += list1->data;
    }

    if (list2 != NULL) {
        value += list2->data;
    }

    result->data = value % 10;

    if (list1 != NULL || list2 != NULL) {
        Node* returnNode =sumLists(list1 == NULL ? NULL : list1->next,
                                   list2 == NULL ? NULL : list2->next,
                                   value >= 10 ? 1: 0);
        setNext(result, returnNode);
    }
    return result;
}

int main()
{
    struct Node *first = pushNode(6);
    first->next = pushNode(1);
    first->next->next = pushNode(7);

    struct Node *second = pushNode(2);
    second->next = pushNode(9);
    second->next->next = pushNode(5);

    first = reverseLinkedListRecursive(first);
    second = reverseLinkedListRecursive(second);

    Node* result = sumLists(first, second, 0);
    result = reverseLinkedListRecursive(result);
    printLinkedList(result);
    return 0;
}
