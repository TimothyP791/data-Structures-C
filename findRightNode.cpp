#include <iostream>

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

// Function to find the next node for a given node in the same level in a binary tree
// by using preorder traversal
Node* findRightNode(Node* root, Node* node, int level, int &node_level){
    if (root == nullptr) {
        return nullptr;
    }
// If desired node is found set node level to current level
    if (root == node){
        node_level = level;
        return nullptr;
    }
// If nodelevel is already set then the current node is the next right node
    else if (node_level && level == node_level) {
        return root;
    }
    // recur for left subtree and increase level by 1
    Node* left = findRightNode(root->left, node, level + 1, node_level);
    // If the node is found in the left subtree return it
    if (left) {
        return left;
    }
    //recur for right subtree and increase level by 1
    return findRightNode(root->right, node, level + 1, node_level);
}

// Function to find the next node of a given node in the same level
// in a given binary tree
Node* findRightNode(Node* root, Node* node) {
    int node_level = 0;
    return findRightNode(root, node, 1, node_level);
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

    Node* right = findRightNode(root, root->right->left->right);

    if (right) {
        cout << "The right node is " << right->data << endl;
    }
    else 
    cout << "The right node does not exist" << endl;
    
    
    return 0;
}