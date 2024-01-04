#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Data structure to store a binary tree node along
// with its level and parent information
struct NodeInfo {
    Node* node;
    int level;
    Node* parent;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Perform inorder traversal on a given binary tree and update 'x' and 'y'
void updateLevelandParent(Node* root, Node* parent, int level, NodeInfo &x, NodeInfo &y){
// base case: tree is empty
    if (root == nullptr){
        return; 
    }
// traverse left subtree
    updateLevelandParent(root->left, root, level + 1, x, y);
// if the first element is found, save its level and parent node
    if (root == x.node) {
        x.level = level;
        x.parent = parent;
    }
// if the second element is found, save its level and parent node
    if (root == y.node) {
        y.level = level;
        y.parent = parent;
    }
// traverse right subtree
    updateLevelandParent(root->right, root, level + 1, x, y);
}

// Function to determine if two given nodes are cousins of each other
bool checkCousins(Node* root, Node* node1, Node* node2){
// return if the tree is empty
    if (root == nullptr){
        return false;
    }

    int level = 1;                  //level of the root is 1
    Node* parent = nullptr;         // parent of the root is null

    NodeInfo x = {node1, level, parent};
    NodeInfo y = {node2, level, parent};
// perform inorder traversal on the array and update 'x' and 'y'
    updateLevelandParent(root, nullptr, 1, x, y);
// return true if 'x' and 'y' are at the same level, but different parent
    return x.level == y.level && x.parent != y.parent;
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
    
    if (checkCousins(root, root->right, root->left)){
        cout << "The two nodes are cousins";
    }
    else 
    cout << "The two nodes are not cousisns";
    
    return 0;
}