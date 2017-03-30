/* 
 * File:   HashTable.cpp
 * Author: Claire McCarthy
 * 
 * Created on November 18, 2014, 7:24 PM
 * 
 * HASHTABLE.CPP
 * HASHTABLE.CPP - contains the functions for the HashTable class
 * FUNCTIONAL DESCRIPTION
 * Interacts with the GameBoard and Entry class to create a hash table. The 
 * class contains functions that return info about the hash table. Also contains
 * the compress function for the hash table.
 * 
 * NOTICE
 * Copyright (C) 2014 Claire McCarthy All Rights Reserved.
 */

#include "HashTable.h"
#include "GameBoard.h"
#include "Entry.h"
#include <vector> 

/*
 * Function Name: HashTable - constructor for the HashTable class
 * Functional Description: creates an array of vectors of the given size and
 * sets them equal to the hashTable variable.
 * Entry Parameters: int size - the size of the hash table 
 * Return Values: none
 */
HashTable::HashTable(int size) {
    
    vector<Entry> *hashTable = new vector<Entry> (size);
}
/*
 * Function Name: ~HashTable - destructor for the HashTable class
 * Functional Description: deletes the memory allocated for the hash table. 
 * Entry Parameters: none
 * Return Values: none
 */
HashTable::~HashTable() {
    delete [] &hashTable;
}
/*
 * Function Name: insert - inserts an entry into the hash table
 * Functional Description: creates a new Entry with the given parameters and 
 * enters that entry into the hash table vector. Then returns the new entry.
 * Entry Parameters: GameBoard key, int value - information needed to complete
 * the entry
 * Return Values: Entry - the entry that was just created and inserted
 */
Entry HashTable::insert(GameBoard key, int value) {
    Entry newEntry = Entry(key, value);
    hashTable.push_back(newEntry); 
    return newEntry;
} 
/*
 * Function Name: remove - removes an entry from the hash table
 * Functional Description: finds the given GameBoard and removes it from the 
 * hash table. If it doesn't exist, returns a new entry. Return the removed 
 * entry. 
 * Entry Parameters: GameBoard key - the GameBoard that is being removed
 * Return Values: Entry - the entry that was removed
 */
Entry HashTable::remove(GameBoard key) {
    Entry found = this->find(key);
    if (found.getValue() == -99) {
        return found;
    }
    for (int i = 0; i < hashTable.size(); ++i) {
        Entry entry = hashTable.at(i);
        if (key.equals(entry.getBoard())) {
            hashTable.erase(hashTable.begin() + i);
            return entry;
        }    
    }
    
}
/*
 * Function Name: find - finds and returns an entry from the hash table
 * Functional Description: uses the given key to locate the entry in the hash 
 * table. If it does not exist, creates a new entry and returns that. 
 * Entry Parameters: GameBoard key - the GameBoard that is being found
 * Return Values: Entry - the found entry or the newly created entry
 */
Entry HashTable::find(GameBoard key) {
    
    for (int i = 0; i < hashTable.size(); ++i) {
        Entry entry = hashTable.at(i);
        if (key.equals(entry.getBoard())) {
            return entry;
        }    
    }
    GameBoard board = GameBoard(-1);
    Entry entry = Entry(board, -99);
   
    return entry;
}
/*
 * Function Name: compress
 * Functional Description: compresses the value and returns the value that
 * results form the hash function. 
 * Entry Parameters: int value - the value of the entry 
 * Return Values: int - the compressed value
 */
int HashTable::compress(int value) {
    return ((((13*value) + 37) % 16908799) % hashTable.size()); 
}
/*
 * Function Name: isEmpty - checks to see if the hash table is empty
 * Functional Description: uses the vector function size to see if the hash
 * table is empty
 * Entry Parameters: none
 * Return Values: boolean
 */
bool HashTable::isEmpty() {
    if (hashTable.size() == 0) {
        return true;
    }
    return false;
    
}
/*
 * Function Name: makeEmpty
 * Functional Description: uses a while loop to empty the hash table by popping
 * back each entry until the size is 0
 * Entry Parameters: none
 * Return Values: void
 */
void HashTable::makeEmpty() {
    while (hashTable.size() > 0) {
        hashTable.pop_back(); 
    }
    
}
/*
 * Function Name: getLoadFactor
 * Functional Description: computes the load factor of the hash table and 
 * returns it. 
 * Entry Parameters: none
 * Return Values: int - the load factor
 */
int HashTable::getLoadFactor() {
    //load factor = size / bucket count
    int loadFactor = (this->getNumItems() / this->getNumBuckets());
    return loadFactor; 
    
}
/*
 * Function Name: getNumItems
 * Functional Description: goes through the hash table and uses an iterator to 
 * find the number of buckets that are filled.
 * Entry Parameters: none
 * Return Values: int - the number of items in the hash table
 */
int HashTable::getNumItems() {
    int numItems = 0;
    for (int i = 0; i < hashTable.size(); ++i) {  
        Entry entry = hashTable.at(i);
        if (entry.getValue() == -99 || entry.getValue() == 0) {
            ++numItems;
        }
    }
    return numItems;
}
/*
 * Function Name: getNumBuckets-returns the number of buckets in the hash table
 * Functional Description: returns the number of buckets in the hash table by
 * using the size function to check the size of the hashTable vector
 * Entry Parameters: none
 * Return Values: int - the number of buckets
 */
int HashTable::getNumBuckets() {
    return hashTable.size();
}
/*
 * Function Name: printListSizes - prints the sizes of each of the lists
 * Functional Description: uses a for loop to iterate through the hash table
 * and print out the value for each filled bucket.
 * Entry Parameters: none
 * Return Values: void
 */
void HashTable::printListSizes() {
    for (int i = 0; i < hashTable.size(); ++i) {
        cout << "\n" << endl;
        Entry entry = hashTable.at(i);
        int val = entry.getValue();
        cout << " " << val << endl;
    }
}


