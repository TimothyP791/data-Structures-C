#include <iostream>
#include <stack>
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

void IterativePostOrder(Node* root) { // left, right, data
    stack<Node*> s;

    Node* curr = root;

    if(root == nullptr) {
        return;
    }

    s.push(curr);
    //create new stack to store postorder traversal
    stack<int> out;
    //pop a node from the stack and push it into the output stack
    while(!s.empty()) {
        curr = s.top();
        s.pop();

        out.push(curr->data);
        //Push left and right child of popped node into the stack
        if (curr->left) {
        s.push(curr->left);
        }
        if (curr->right) {
            s.push(curr->right);
        }
    }
    //print out postorder traversal
    while (!out.empty()) {
        cout << out.top() << " ";
        out.pop();
    }
}

void IterativePreorder(Node* root) { //data, left, right
    // Create empty stack 
    stack<Node*> stack;
    //Start from the root node (Set current node to root)
    Node* curr = root;
    //return if tree is empty
    if (root == nullptr) {
        return;
    }
    //push root node to stack
    stack.push(curr);
    
    while (!stack.empty()) {
        curr = stack.top();
        stack.pop();
        
        cout << curr->data << " ";
        // push right child of current node onto the stack
        if(curr->right) {
            stack.push(curr->right);
        }
        // push left child of current node onto the stack
        if(curr->left) {
            stack.push(curr->left);
        }
        //Note right child must be pushed first in due to LIFO algorithm of stack
        
    }
}

void IterativeInorder(Node* root) { // left, data, right
    // Create empty stack 
    stack<Node*> stack;
    //Start from the root node (Set current node to root)
    Node* curr = root;
    //if the current node is null and the stack is also empty we are done
    while (!stack.empty() || curr != nullptr) {
        //if the current node exists push it to the stack 
        //and move to its left child
        if (curr != nullptr) {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            //Otherwise, if the current node is null, pop an element from the stack,
            //print it, and finally set the node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";

            curr = curr->right;
        }
    }
}

void preOrderTraversal(Node* root) { //preorder algorithm (data,left,right) 
    //Base case
    if (root == nullptr) return;
    //First print out data
    cout << root->data << " ";
    //Use recursive function call to check left and right child
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root) { //inorder algorithm (left,data,right)  
    //Base case
    if (root == nullptr) return;
    //Check Left using recursive call
    inOrderTraversal(root->left);
    //Print data in second stage of the algorithm
    cout << root->data << " ";
    //Check right using recursive call
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) { //postorder algorithm (left, right, data)
    //Base case
    if (root == nullptr) return;
    //Check Left using recursive call
    postOrderTraversal(root->left);
    //Check right using recursive call
    postOrderTraversal(root->right);
    //Print data in third stage of the algorithm
    cout << root->data << " ";
}
//Used for level order traversal fucntion
bool printlevel(Node* root, int level){
    if (root == nullptr) {
        return false;
    }
    if (level == 1) {
        cout << root->data << " ";
    return true;
    }
    

    printlevel(root->left, level - 1);
    printlevel(root->right, level -1);
    

    return left || right;
}
//level order traversal
void levelOrderTraversal(Node* root) {
    int level = 1;

    while (printlevel(root, level)){
        level++;
    }
    
}

int main () {
    //level 1
    Node* root = createNode(1);
    //level 2
    root->left = createNode(2);
    root->right = createNode(3);
    //level 3
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    //level 4
    root->left->right->left = createNode(9);
    root->right->right->left = createNode(15);

    //levelOrderTraversal(root);
    //preOrderTraversal(root);
    inOrderTraversal(root);
    //postOrderTraversal(root);
    //IterativeInorder(root);
    //IterativePreorder(root);
    //IterativePostOrder(root);
    return 0;
}