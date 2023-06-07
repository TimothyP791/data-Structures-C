#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;
};

void printForward(Node* head) {
    Node* traverse = head;
    while (traverse != nullptr) {
        cout << traverse->value << endl;
        traverse = traverse->next;
    }
}

void printBackward(Node* tail) {
    Node* traverse = tail;
    while (traverse != nullptr) {
        cout << traverse->value << endl;
        traverse = traverse->prev;
    }
}

int main() {
    Node* head;
    Node* tail;
    //add first node
    //prepare new node
    Node* node = new Node();
    //set node value
    node->value = 4;
    //set next and prev to NULL
    node->next = nullptr;
    node->prev = nullptr;
    //Make first node both head and tail
    head = node;
    tail = node;

    //Add second node
    //create new node
    node = new Node();
    //set node value
    node->value = 5;
    //set next to null because it is new tail
    node->next = nullptr;
    //set prev to tail which is still previous node
    node->prev = tail;
    //have tail next which is first node point to new node
    tail->next = node;
    //lastly set tail equal to newly added node
    tail = node;
    
    //add 3rd node
    node = new Node();
    node->value = 6;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;

    //add 4rd node
    node = new Node();
    node->value = 7;
    node->next = nullptr;
    node->prev = tail;
    tail->next = node;
    tail = node;

    printForward(head);
    printBackward(tail);

    return 0;
}