#include <iostream>
#include "hashquad.hpp"

using namespace std;

// constructor
HashTable::HashTable(int size) {
    insertCollisions = 0;
    searchCollisions = 0;
    tableSize = size;
    table = new int[size];
}

// calls hash function and utilizes quadratic probing to get location for new patient ID, updates numCollisions during loop
int HashTable::getLocation(int key) {
    // find location by calling hashfunction
    unsigned int loc = hashFunction(key);
    
    // if there is nothing at the location, return this location
    if (table[loc] == 0)
        return loc;

    // loop uses quadratic probing to find a location
    for (int i = 1; i < tableSize; i++) {
        // increment collisions
        insertCollisions++;

        // quadratic probing formula finds a new potential location
        loc = (hashFunction(key) + (i*i)) % tableSize;

        // if an empty location is found, return it
        if (table[loc] == 0)
            return loc;
    }

    // if the hashtable is full, return -1
    return -1;
}

// inserts a key into hash table
bool HashTable::insert(int key) {
    // find location for key
    int loc = getLocation(key);
    
    // return false if the table is full
    if (loc == -1)
        return false;
	
    // insert key at location
	table[loc] = key;
    return true;
}

// returns h(x) = key % tablesize for patient ID
unsigned int HashTable::hashFunction(int key) {
    return key % tableSize;
}

// goes through array and prints patient IDs
void HashTable::printTable() {
    for (int i = 0; i < tableSize; i++)
        if (table[i] != 0) 
            cout << table[i] << ", ";
    cout << endl;
}

// initializer for numcollisions for use in driver throughout testing
void HashTable::setNumCollisions() {
    insertCollisions = 0;
    searchCollisions = 0;
}


// returns collisions, updated by getlocation and search function
int HashTable::getNumCollisions(string choice) {
    if (choice == "insert")
        return insertCollisions;
    else
        return searchCollisions;
}


int HashTable::search(int key) {
    // find initial 
    unsigned int loc = hashFunction(key);
    if (table[loc] == key)
        return loc;
     
    // use quadratic probing to find location
    for (int i = 1; i < tableSize; i++) {
        searchCollisions++;
        // quadratic probing formula finds a new potential location
        loc = (hashFunction(key) + (i*i)) % tableSize;
        // if an empty location is found, return it
        if (table[loc] == key)
            return loc;
    }
    
    // if key isn't found, return -1
    return -1;
}