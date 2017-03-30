/* 
 * File:   HashTable.h
 * Author: Claire McCarthy
 * 
 * Created on November 18, 2014, 7:24 PM
 * 
 * HASHTABLE.H
 * HashTable.h - contains the function prototypes and variables for the 
 * HashTable class. 
 * FUNCTIONAL DESCRIPTION
 * Contains the function prototypes and private and public variables for the 
 * HashTable class including the vector of Entry's used as the hashTable. 
 * 
 * NOTICE
 * Copyright (C) 2014 Claire McCarthy All Rights Reserved.
 */

#ifndef HASHTABLE_H
#define	HASHTABLE_H

#include "Entry.h"
#include "GameBoard.h"
#include <vector>

class HashTable {
public:
    HashTable(int size);
    virtual ~HashTable();
    Entry insert(GameBoard key, int value);
    Entry remove(GameBoard key);
    Entry find(GameBoard key);
    int compress(int value);
    int calcVariance();
    bool isEmpty();
    void makeEmpty();
    int getLoadFactor();
    int getNumItems();
    int getNumBuckets();
    void printListSizes();
    
private:
    //may need a * here?
    vector<Entry> hashTable;
};

#endif	/* HASHTABLE_H */

