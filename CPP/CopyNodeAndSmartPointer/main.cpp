#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// Copy Node without testing
typedef map<Node*, Node*> NodeMap;

class Node{
public:
    Node* ptr1;
    Node* ptr2;
};

//Node * newNode(){
//    Node * node = new Node();
//    node->ptr1 = NULL;
//    node->ptr2 = NULL;

//    return node;
//}

Node * copyNodeRecursive(Node * cur, NodeMap & nodeMap){
    if (cur == NULL){
        return NULL;
    }

    // if we can find the node then we copy it
    NodeMap::iterator i = nodeMap.find(cur);
    if (i != nodeMap.end()){
        return i->second;
    }

    Node * node = new Node;
    nodeMap[cur] = node;
    node->ptr1 = copyNodeRecursive(cur->ptr1, nodeMap);
    node->ptr2 = copyNodeRecursive(cur->ptr2, nodeMap);
    return node;
}

Node * copyNode(Node * root){
    NodeMap nodeMap;
    return copyNodeRecursive(root, nodeMap);
}

// smart pointer without testing
template<class T>
class smartPointer {
    T * ref;
    unsigned * refCount;
    void remove(){
        --(*refCount);
        if (*refCount == 0){
            delete ref;
            free(refCount);
            ref = NULL;
            refCount = NULL;
        }
    }
public:
    T getValue(){
        return * ref;
    }

    smartPointer(T * ptr){
        ref = ptr;
        // malloc memory
        refCount = (unsigned*)malloc(sizeof(unsigned));
        // initialize to 1
        *refCount = 1;
    }

    // create a new smart pointer that points to an existing object
    smartPointer(smartPointer<T> & sptr){
        ref = sptr.ref;
        refCount = sptr.refCount;
        ++(*refCount);
    }

    // equal operation override
    smartPointer<T> & operator =(smartPointer<T> & sptr){
        if (this == &sptr) {
            return *this;
        }

        if (*refCount > 0){
            remove();
        }

        ref = sptr.ref;
        refCount = sptr.refCount;
        ++(*refCount);
        return *this;
    }

    ~smartPointer(){
        remove();
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
