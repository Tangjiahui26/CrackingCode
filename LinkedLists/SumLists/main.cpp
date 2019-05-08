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
    struct Node *first = pushNode(9);
    first->next = pushNode(5);
    first->next->next = pushNode(9);
    first->next->next->next = pushNode(1);

    struct Node *second = pushNode(3);
    second->next = pushNode(5);
    second->next->next = pushNode(3);

    Node* result = sumLists(first, second, 0);
    printLinkedList(result);
    return 0;
}
