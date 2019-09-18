#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

// given a linked list, write a function to reverse every k nodes (where k is an input to the function)

// method 1: recursive

class Node{
public:
    int data;
    Node* next;
};

Node * reverse(Node* head, int k){
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;

    while(current != NULL && count < k){
        // reverse
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL){
        head->next = reverse(next, k);
    }
    return prev;
}

void push(Node** head_ref, int newData){
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

void printList(Node* node){
    while(node!= NULL){
        cout << node->data << " ";
        node = node->next;
    }
}

// method 2: stack

Node* reverseUsingStack(Node* head, int k){
    stack<Node*> mystack;
    Node* current = head;
    Node* prev = NULL;

    while(current != NULL){
        int count = 0;

        while(current != NULL && count < k){
            mystack.push(current);
            current = current->next;
            count++;
        }

        while (mystack.size() > 0){
            if (prev == NULL){
                prev = mystack.top();
                head = prev;
                mystack.pop();
            } else {
                prev->next = mystack.top();
                prev = prev->next;
                mystack.pop();
            }
        }
    }

    prev->next = NULL;
    return head;
}

// similar question: reverse even elements in a linked list
// reversing the contiguous even elements will not take place when:
// 1. the node's value is odd;
// 2. the node's value is even but adjacent values are odd.

Node* reverseEven(Node* head, Node* prev){
    if (head == NULL){
        return NULL;
    }

    Node* temp;
    Node* curr;
    curr = head;

    // Reversing nodes until curr node's value
    // turn odd or Linked List is fully traversed
    while(curr != NULL && curr->data%2 == 0){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    // if elements were reversed then head pointer needs to be changed
    if(curr != head){
        head->next = curr;
        curr = reverseEven(curr, NULL);
        return prev;
    } else
    // simply just iterate over the odd value nodes
    {
        head->next = reverseEven(head->next, head);
        return head;
    }
}

int main()
{
    Node* head = NULL;
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Given linked List \n";
    printList(head);
//    head = reverse(head, 3);
    head = reverseUsingStack(head, 3);

    cout << "\nReversed Linked List \n";
    printList(head);


    Node* head2 = NULL;
    push(&head2, 5);
    push(&head2, 8);
    push(&head2, 6);
    push(&head2, 4);
    push(&head2, 3);
    push(&head2, 3);
    push(&head2, 2);
    push(&head2, 1);
    cout << "\nGiven linked List \n";
    printList(head2);
    head = reverseEven(head2, NULL);

    cout << "\nReversed Linked List \n";
    printList(head2);
    return 0;
}
