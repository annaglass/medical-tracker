#include <iostream>
#include "bubblesort.hpp"

using namespace std;

// constructor sets max array size and creates array
BubbleSort::BubbleSort(int size) {
    maxSize = size;
    bubblearr = new int[maxSize];
    numElements = 0;
}

// deconstructor deallocates memory
BubbleSort::~BubbleSort() {
    delete bubblearr;
}

// inserts an ID into array using numelements
void BubbleSort::insert(int ID) {
    bubblearr[++numElements] = ID;
}

// swaps two elements for use in bubble sort function
void swap(int *ptr1, int *ptr2) {  
    int temp = *ptr1;  
    *ptr1 = *ptr2;  
    *ptr2 = temp;  
}  

// sort function compares values and utilizes swap if a change is needed
void BubbleSort::sort() {   
    for (int i = 0; i < maxSize - 1; i++)
        for (int j = 0; j < maxSize - 1 - i; j++)
            // if a value before another is larger, we need to swap
            if (bubblearr[j] > bubblearr[j+1])  
                swap(&bubblearr[j], &bubblearr[j+1]);  
}  
  
// search function returns the index of the ID
int BubbleSort::search(int ID) {
    for (int i = 0; i < maxSize; i++)
        // if the ID is found return the index
        if (bubblearr[i] == ID)
            return i;
    return -1;
}

// diplays the array
void BubbleSort::display() {  
    for (int i = 0; i < maxSize; i++)  
        cout << bubblearr[i] << " ";  
    cout << endl;  
}  