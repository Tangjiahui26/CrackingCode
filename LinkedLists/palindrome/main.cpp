#include <iostream>
#include <stack>

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

bool isPalindromeOrNotByStack(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    Node * fast = head;
    Node * slow = head;
    stack<int> values;
    while (fast != NULL && fast->next != NULL) {
        values.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast != NULL) {
        slow = slow->next;
    }

    while (slow != NULL) {
        int popValue = values.top();
        if (popValue != slow->data)
            return false;
        slow = slow->next;
        values.pop();
    }
    return true;
}

int main()
{
    struct Node *test = pushNode(1);
    test->next = pushNode(2);
    test->next->next = pushNode(6);
    test->next->next->next = pushNode(2);
    test->next->next->next->next = pushNode(1);
    cout << "Original Linkedlist: " << endl;
    printLinkedList(test);
    string result = isPalindromeOrNotByStack(test) ? "TRUE" : "FALSE";
    cout << "Is palindrome: " << result << endl;
    return 0;
}
