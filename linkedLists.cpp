#include <iostream>
using namespace std;

class Node {
public: 
    int Value;
    Node* Next;
    };

    void printList(Node* n) {
        
        while (n != NULL) {
            cout << n->Value << endl;
            n = n->Next;
        }

    }

    void insertAtFront(Node** head, int newValue) { //Value is passed by reference so must recieve pointer to a pointer hence Node**
        //Prepare a newNode
        Node* newNode = new Node();
        newNode->Value = newValue;
        //Put it in front of current head
        newNode->Next = *head;
        //Move head of the list to point to the newNode
        *head = newNode;
    }

    void insertAtEnd(Node** head, int newValue) {
        // Prepare a newNode
        Node* newNode = new Node();
        newNode->Value = newValue;
        newNode->Next = NULL;
        // Check if linked list is empty, if empty newNode will be a head node
        if(*head == NULL) {
            *head = newNode;
            return;
        }
        // Find last node
        Node* last = *head;
        while (last->Next != NULL) {
            last = last->Next;
        }
        // Insert newNode aftr last node
        last->Next = newNode;
    }

    void insertAfter(Node* previous, int newValue) {
        // Check if previous node is Null
        if (previous == NULL) {
            cout << "Previous cannot be NULL" ;
            return;
        }
        // Prepare new Node
        Node* newNode = new Node();
        newNode->Value = newValue;
        //insert newNode after previous
        newNode->Next = previous->Next;
        previous->Next = newNode;

    }
int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->Value = 1;
    head->Next = second;

    second->Value = 2;
    second->Next = third;

    third->Value = 3;
    third->Next = NULL;

    insertAtFront(&head, -1);
    insertAtFront(&head, -2);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAfter(head, 8);
    insertAfter(second, 24);
    printList(head);
    return 0;
}