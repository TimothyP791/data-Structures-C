#include <iostream>
#include <list>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

bool isComplete(Node* root){
    // Return if the tree is empty
    if (root == nullptr) {
        return true;
    }
    //create empty queue and enqueue root node
    list<Node*> queue;
    queue.push_back(root);
    //pointer to track current node
    Node* front = queue.front();

    //flag to mark the end of full nodes
    bool flag = false;

    //Loop until queue is empty
    while(!queue.empty()){
        front = queue.front();
        queue.pop_front();

        // if we have encountered a non-full node before and the current node
        // is not a leaf, a tree cannot be complete
        if (flag && (front->left || front->right)){
            return false;
        }
        // if the left child is empty and the right child exists,
        // a tree cannot be complete
        if (front->left == nullptr && front->right){
            return false;
        }
        // if the left child exists, enqueue it
        if (front->left) {
            queue.push_back(front->left);
        }
        // if the current node is a non-full node, set the flag to true
        else {
            flag = true;
        }
        // if the right child exists, enqueue it
        if (front->right) {
            queue.push_back(front->right);
        }
        // if the current node is a non-full node, set the flag to true
        else {
            flag = true;
        }
    }
    return true;
}

int main() {

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->left = createNode(5);
    root->right->right = createNode(6);
    root->right->left->left = createNode(7);
    root->right->left->right = createNode(8);
    //root->left->right = createNode(9);

    if (isComplete(root)){
        cout << "The tree is complete";
    }
    else {
        cout << "The tree is not complete";
    }
    
    
    return 0;
}