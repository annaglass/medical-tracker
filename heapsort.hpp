#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

using namespace std;

class MinHeap {
    
    private:
        int *heaparr; // pointer to heap array
        int maxSize; // max size of heap array
        int numElements; // number of elements currently in heap
    
    public:
        MinHeap(int maxSize); // constructor
        void heapify(int index); // heap sort from root
        void insert(int ID); // insert an ID into heap
        int search(int ID); // returns index of given ID
        void display(); // displays IDs in heap
};

#endif