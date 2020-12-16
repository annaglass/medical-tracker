#ifndef HASHQUAD_HPP
#define HASHQUAD_HPP

using namespace std;

class HashTable {
    private:
        int insertCollisions; // number of collisions during an insert
        int searchCollisions; // number of collisions during a search
        int tableSize; // max size of table
        int *table; // pointer to table array
    
    public:
        HashTable(int size);  // constructor
        int getLocation(int key); // finds location for new ID by quadratic probing
        bool insert(int key); // inserts a key into hash table
        unsigned int hashFunction(int key); // hash function to map values to key
        void printTable(); // prints all IDs in table
        void setNumCollisions(); // sets collisions to zero
        int getNumCollisions(string choice); // returns the number of collisions (insert or search)
        int search(int key); // returns index of a key using quadratic probing
};

#endif