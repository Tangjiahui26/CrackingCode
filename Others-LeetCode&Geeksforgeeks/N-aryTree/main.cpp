#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// structure of a node of an a-ary tree
struct Node {
    int key;
    vector<Node *> child;
};

Node* newNode(int key){
    Node* temp = new Node;
    temp->key = key;
    return temp;
}

// function 1: return the depth of the tree
int depthOfTree(struct Node *ptr){
    if (!ptr){
        return 0;
    }

    int maxdepth = 0;
    for (vector<Node*>::iterator it = ptr->child.begin(); it != ptr->child.end(); it++){
        maxdepth = max(maxdepth, depthOfTree(*it));
    }

    return maxdepth + 1;
}

int sumOfNodes(Node* root){
    int sum = 0;
    if (root == NULL){
        return 0;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();

        while (n > 0){
            // dequeue an item from queue and
            // add it to sum
            Node* p = q.front();
            q.pop();
            sum += p->key;

            // Enqueue all chirldren of the dequeued item
            for (int i = 0; i< p->child.size(); i++){
                q.push(p->child[i]);
            }
            n--;
        }
    }
    return sum;
}

int factorial(int n){
    if (n == 0){
        return 1;
    }
    return n * factorial(n-1);
}

int calculatetraversalWays(Node* root){
    int ways = 1;
    if (root == NULL){
        return 0;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        Node* p = q.front();
        q.pop();

        ways = ways * (factorial(p->child.size()));

        for (int i = 0; i < p->child.size(); i++){
            q.push(p->child[i]);
        }
    }
    return ways;
}

int main()
{
    Node *root = newNode(20);
   (root->child).push_back(newNode(2));
   (root->child).push_back(newNode(34));
   (root->child).push_back(newNode(50));
   (root->child).push_back(newNode(60));
   (root->child[0]->child).push_back(newNode(70));
   (root->child[0]->child).push_back(newNode(15));
   (root->child[2]->child).push_back(newNode(20));
   (root->child[3]->child).push_back(newNode(30));
   (root->child[3]->child).push_back(newNode(40));
   (root->child[3]->child).push_back(newNode(100));
   (root->child[0]->child[0]->child).push_back(newNode(20));
   (root->child[0]->child[0]->child).push_back(newNode(25));
   (root->child[3]->child[2]->child).push_back(newNode(50));

   cout << depthOfTree(root) << endl;
   cout << sumOfNodes(root) << endl;
   cout << calculatetraversalWays(root) << endl;
   return 0;
}
