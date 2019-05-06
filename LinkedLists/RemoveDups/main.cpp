#include <iostream>
#include <unordered_set>

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

//approach1: Brute-force with etra buffer, otherwise we do not need to use dup pointer.

void removeDupsBruteForce(struct Node * node) {
    struct Node * first = node;
    struct Node * dup;

    while (first != NULL && first->next != NULL) {
        struct Node * second = first;
        while (second->next != NULL) {
            if (first->data == second->next->data) {
                dup = second->next;
                second->next = second->next->next;
                delete(dup);
            } else {
                second = second->next;
            }
        }
        first = first->next;
    }
}

//approach2: Hash table

void removeDupsHashTable(struct Node * node) {
    unordered_set<int> table;

    struct Node * curr = node;
    struct Node * prev = NULL;

    while (curr != NULL) {
        if (table.find(curr->data) != table.end()) {
            prev->next = curr->next;
            delete(curr);
        } else {
            table.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
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

        printf("Linked list before removing duplicates ");
        printLinkedList(start);

        removeDupsHashTable(start);

        printf("\nLinked list after removing duplicates ");
        printLinkedList(start);

        return 0;
}
