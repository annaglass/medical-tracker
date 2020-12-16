#define DLL_HPP

#include <iostream>
using namespace std;

// doubly linked list node struct
struct Node {
    int key;
    Node *next;
    Node *prev;
};

// class definitions
class DoublyLinkedList {
    // doubly linked list utilizes head and tail
    private:
        Node* head;
        Node* tail;
    
    public:
        DoublyLinkedList(); // constructor
        void insertNode(int newKey); // inserts node at the end
        Node* searchList(int); // finds a node in the list using key
        void displayList(); // print the list
};