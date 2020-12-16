#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

using namespace std;

class BubbleSort {
    
    private:
        int maxSize; // max size of array
        int *bubblearr; // pointer to the array
        int numElements; // current num elements for efficient insert function
    
    public:
        BubbleSort(int size); // constructor
        ~BubbleSort(); // deconstructor
        void insert(int ID); // inserts given ID into array
        void sort(); // sorts array by bubble sort method
        int search(int ID); // returns index of ID given
        void display(); // displays array

};

#endif