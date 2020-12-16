#include "bubblesort.cpp"
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
        // create temparr of type bubblesort
        BubbleSort temparr((i+1)*100);
        
        // copying data to array     
        for (int j = 0; j < ((i+1)*100); j++)
            temparr.insert(testData[j]);
            //temparr.insert(testData[j]);
            
        // sort the array
        start = clock();
        temparr.sort();
        sortTime = clock() - start;
        sort[i] = float(sortTime) / CLOCKS_PER_SEC;
    }

    // writing to file for graphing
    ofstream out_file("insert_search_performance_bubbleSort_dataSetA.csv");
    
    // writing sort performance
    for (int i = 0; i < 100; i++)
        out_file << sort[i] << " ";
    
    // closing file
    out_file.close();
}