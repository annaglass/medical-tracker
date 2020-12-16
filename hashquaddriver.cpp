#include "hashquad.cpp"
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

    HashTable hashtable(40009);
    clock_t start, insertTime, searchTime;
    float insert[100], search[100];
    int found = 0;
    int insertCollisions[100], searchCollisions[100];

    // loop performs insert and search in increments of 100
    for (int i = 0; i < 100; i++) {
        hashtable.setNumCollisions();
        // insert value, put time in insert time array
        start = clock();
        for (int j = (i*100); j < ((i+1)*100); j++)
            hashtable.insert(testData[j]);
        insertTime = clock() - start;
        insert[i] = float(insertTime) / 100 / CLOCKS_PER_SEC;
        
        // search for value, put time in search time array
        start = clock();
        for (int j = (i*100); j < ((i+1)*100); j++) {
            found = hashtable.search(testData[randomNumbers[j]]);
        }
        searchTime = clock() - start;
        search[i] = float(searchTime) / 100 / CLOCKS_PER_SEC;
        insertCollisions[i] = hashtable.getNumCollisions("insert");
        searchCollisions[i] = hashtable.getNumCollisions("search");
    }

    // writing data to out file
    ofstream out_file("insert_search_performance_hashQuad_dataSetA.csv");

    // insert time
    for (int i = 0; i < 100; i++) 
        out_file << insert[i] << " ";

    out_file << "\n";

    // search time
    for (int i = 0; i < 100; i++) 
        out_file << search[i] << " ";
    
    out_file << "\n";

    // insert collisions number
    for (int i = 0; i < 100; i++) 
        out_file << insertCollisions[i] << " ";

    out_file << "\n";

    // search collisions number
    for (int i = 0; i < 100; i++) 
        out_file << searchCollisions[i] << " ";

    out_file.close();
}