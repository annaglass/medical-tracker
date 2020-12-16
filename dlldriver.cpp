#include "dll.cpp"
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

    // getting random numbers
    int randomNumbers[10000];
    srand(time(NULL));
    int count = 0;
    // i represents units of 100
    for (int i = 0; i < 100; i++) {
        // j represents units of 1
        for (int j = 0; j < 100; j++) {
            // fill up array with random numbers in sets of 100
            randomNumbers[count] = i*100 + rand() % 100;
            count++;
        }
    }

    // variable, object, and data array declarations
    DoublyLinkedList list;
    clock_t start, insertTime, searchTime;
    float insert[100], search[100];
    Node* testNode = NULL;

    // loop performs insert and search in increments of 100
    for (int i = 0; i < 100; i++) {
        // insert value, put time in insert time array
        start = clock();
        for (int j = (i*100); j < ((i+1)*100); j++)
            list.insertNode(testData[j]);
        insertTime = clock() - start;
        insert[i] = float(insertTime) / 100 / CLOCKS_PER_SEC;
        
        // search for value, put time in search time array
        start = clock();
        for (int j = (i*100); j < ((i+1)*100); j++)
            testNode = list.searchList(testData[randomNumbers[j]]);
        searchTime = clock() - start;
        search[i] = float(searchTime) / 100 / CLOCKS_PER_SEC;
    }
    
    // writing to file for graphing
    ofstream out_file("insert_search_performance_dll_dataSetA.csv");
    
    // writing insert performance
    for (int i = 0; i < 100; i++)
        out_file << insert[i] << " ";

    out_file << "\n";
    
    // writing search performance
    for (int i = 0; i < 100; i++) 
        out_file << search[i] << " ";
    
    // closing file
    out_file.close();
}