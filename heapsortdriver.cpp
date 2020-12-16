#include "heapsort.cpp"
#include <fstream>
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main() {
    // create and open ifstream file
    ifstream in_file("dataSetA.csv");
    
    int testData[10000];
    string line;
    int numData = 0;

    // read into testData array
    while (getline(in_file, line, ',') && !in_file.eof())
        testData[numData++] = stoi(line);
    testData[numData] = stoi(line);

    clock_t start, sortTime;
    float sort[100];

    for (int i = 0; i < 100; i++) {
        // create temp of type minHeap
        MinHeap tempheap((i+1)*100);
        
        // inserting data into heap    
        for (int j = 0; j < ((i+1)*100); j++)
            tempheap.insert(testData[j]);
            
        // heap sort from root, time and record results 
        start = clock();
        tempheap.heapify(0);
        sortTime = clock() - start;
        sort[i] = float(sortTime) / CLOCKS_PER_SEC;
    }

    // writing to file for graphing
    ofstream out_file("insert_search_performance_heapSort_dataSetA.csv");
    
    // writing sort performance
    for (int i = 0; i < 100; i++)
        out_file << sort[i] << " ";
    
    // closing file
    out_file.close();
}