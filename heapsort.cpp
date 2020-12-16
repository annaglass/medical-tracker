#include <iostream>
#include "heapsort.hpp"

using namespace std;

// constructor, creates a new array and initializes private variables
MinHeap::MinHeap(int size) {
    numElements = 0;
    maxSize = size;
    heaparr = new int[size];
}

// swaps two elements for use in insert and heapify functions
void swap(int *ptr1, int *ptr2) {  
    int temp = *ptr1;  
    *ptr1 = *ptr2;  
    *ptr2 = temp;  
} 

// recursive function compares children to parent, utilizes swap function to maintain min heap property
void MinHeap::heapify(int index) {
    
    // finding left and right children of given index
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int min = index;
    
    // check left and right children to find new minimum
    if (left < numElements && heaparr[left] < heaparr[index])
        min = left;
    if (right < numElements && heaparr[right] < heaparr[index])
        min = right;
    
    // if a change is necessary, call swap function and recursively call heapify
    if (min != index) {
        swap(heaparr[index], heaparr[min]);
        heapify(min);
    }
}

// inserts a new ID into heap
void MinHeap::insert(int ID) {
    
    // cout error and return if the array is full
    if (maxSize == numElements) { 
        cout << "ID could not be inserted" << endl; 
        return; 
    } 

    // increment number of elements and insert into array
    numElements++;
    int index = numElements - 1; 
    heaparr[index] = ID; 
  
    // this checks min heap for errors by comparing parent to child
    while (index != 0 && heaparr[(index-1)/2] > heaparr[index]) { 
       // if min heap is violated, call the swap function
       swap(heaparr[index], heaparr[(index-1)/2]); 
       // move index to parent
       index = (index-1)/2; 
    } 
}

// returns index of ID we are looking for
int MinHeap::search(int ID) {

    for (int i = 0; i < numElements; i++) {
        if (heaparr[i] == ID)
            return i;
    }
    cout << "ID could not be found." << endl;
    return -1;
}

// displays the patient IDs
void MinHeap::display() {
    for (int i = 0; i < 10000; i++)  
        cout << heaparr[i] << " ";  
    cout << endl; 
}