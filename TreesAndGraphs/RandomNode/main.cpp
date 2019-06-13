#include <iostream>
#include <random>

using namespace std;

class TreeNode{
private:
    int size = 0;
  public:
    int data;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int d) {
        left = NULL;
        right = NULL;
        data = d;
        size = 1;
    }

    int getSize() {
        return size;
    }

    int getData() {
        return data;
    }

    TreeNode *getRandomNode();
    void insertInOrder(int d);
    TreeNode *find(int d);
};

TreeNode *TreeNode::find(int d){
    if (d == data) {
        return this;
    } else if (d <= data) {
        return left != NULL ? left->find(d) : NULL;
    } else if (d > data) {
        return right != NULL ? right->find(d) : NULL;
    }
    return NULL;
}

void TreeNode::insertInOrder(int d) {
    if ( d <= data) {
        if (left == NULL) {
            left = new TreeNode(d);
        } else {
            left->insertInOrder(d);
        }
    } else {
        if (right == NULL) {
            right = new TreeNode(d);
        } else {
            right->insertInOrder(d);
        }
    }
    size++;
}

TreeNode *TreeNode::getRandomNode(){
    int leftsize = left == NULL ? 0 : left->size;

    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(0,size -1); // guaranteed unbiased

    int random = uni(rng);
    if (random < leftsize) {
        return left->getRandomNode();
    } else if (random == leftsize) {
        return this;
    } else {
        return right->getRandomNode();
    }
}

int main()
{
    TreeNode * root = new TreeNode(2);
    root->insertInOrder(1);
    root->insertInOrder(3);
    root->insertInOrder(4);

    TreeNode * result = root->getRandomNode();
    cout << "GET RANDOM NODE: " << result->data << endl;

    return 0;
}
