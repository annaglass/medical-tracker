#include "dll.hpp"

using namespace std;

// constructor sets head to null
DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
}

// insert node at the end
void DoublyLinkedList::insertNode(int newKey) {
    Node* newNode = new Node;
    newNode->key = newKey;
    
    // case of empty list
    if (!head) {
        head = newNode;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
        return;
    }

    // if head and tail are the same
    if (head == tail) {
        tail = newNode;
        tail->prev = head;
        head->next = tail;
        return;
    }
    
    // else insert it at the end
    newNode->next = NULL;
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// find a node in the list using key
Node* DoublyLinkedList::searchList(int key) {
    Node* start = head;
    Node* end = tail;
    
    // go through list until found and return node
    while (start) {
        if (start->key == key)
            return start;
        if (end->key == key)
            return end;
        start = start->next;
        end = end->prev;
    }
    
    // if data isn't found, print error and return null
    cout << "Data not found." << endl;
    return NULL;
}

// print the list
void DoublyLinkedList::displayList() {
    Node* curr = head;
    
    // go through list and print out key
    while (curr->next) {
        cout << curr->key << " -> ";
        curr = curr->next;
    }
    
    // catches end key
    cout << curr->key << endl;
}