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

class ResultNode {
public:
    int size;
    Node * tail;
    ResultNode(Node* tail, int size) {
        this->size = size;
        this->tail = tail;
    }
};

ResultNode* getSizeAndTail(Node * head) {
    if (head == NULL) {
        return NULL;
    }

    int size = 1;
    Node * cur = head;
    while (cur->next != NULL) {
        size++;
        cur = cur->next;
    }
    return new ResultNode(cur, size);
}

Node * getKthNode(Node* head, int k) {
    Node* cur = head;
    while (k > 0 && cur != NULL) {
        cur = cur->next;
        k--;
    }
    return cur;
}

Node * findIntersection(Node* list1, Node* list2) {
    ResultNode* list1Result = getSizeAndTail(list1);
    ResultNode* list2Result = getSizeAndTail(list2);

    if (list1Result->tail != list2Result->tail) {
        return NULL;
    }

    Node* shorter = list1Result->size < list2Result->size ? list1 : list2;
    Node* longer = list2Result->size < list2Result->size ? list2 : list1;

    longer = getKthNode(longer, abs(list1Result->size - list2Result->size));

    while (shorter != longer) {
        shorter = shorter->next;
        longer = longer->next;
    }
    return longer;
}

int main()
{
    struct Node *list1 = pushNode(1);
    list1->next = pushNode(2);
    list1->next->next = pushNode(6);
    list1->next->next->next = pushNode(2);
    list1->next->next->next->next = pushNode(1);

    struct Node *list2 = pushNode(2);
    list2->next = pushNode(8);
    list2->next->next = list1->next->next->next;

    struct Node* returnIntersectionNode = findIntersection(list1, list2);
    printLinkedList(returnIntersectionNode);
    return 0;
}
