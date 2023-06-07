#include <iostream>
#include <stack>
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

int heightRecursive(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + max(heightRecursive(root->left), heightRecursive(root->right));
}
/*int height(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    list<Node*> queue;
    queue.push_back(root);

    Node* front = nullptr;
    int height = 0;

    while(!queue.empty()){
        int size = queue.size();

        while(size--) {
            front = queue.front();
            queue.pop_front();

            if (front->left) {
                queue.push_back(front->left);
            }
        
            if (front->right) {
                queue.push_back(front->right);
            }
        }
        height++; 
    }
    return height;
}*/

int main() {

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->left = createNode(5);
    root->right->right = createNode(6);
    root->right->left->left = createNode(7);
    root->right->left->right = createNode(8);

    cout << "The height of the tree is: " << heightRecursive(root);
    
    return 0;
}