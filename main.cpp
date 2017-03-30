/* 
 * File:   main.cpp
 * Author: Claire McCarthy
 * 
 * Created on November 18, 2014, 7:24 PM
 * 
 * MAIN.CPP
 * main.cpp - interacts with the GameBoard, HashTable, and Entry class to 
 * display information to the user.  
 * FUNCTIONAL DESCRIPTION
 * Uses the GameBoard, HashTable, and Entry classes to display
 * info to the user about the hash table. Creates random game boards and 
 * compares them in order to test the has table. 
 * 
 * NOTICE
 * Copyright (C) 2014 Claire McCarthy All Rights Reserved.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "HashTable.h"
#include "GameBoard.h" 

using namespace std;


GameBoard randomBoard();
void initTable(HashTable &table, int numBoards);
bool allDiff(GameBoard boards[4]);



int main(int argc, char** argv) {

    int numBoards = 10000;
    int numSearches = 2500000;
    cout << numBoards << " GameBoards inserted; "
            << numSearches << " searches" << endl << endl;

    
    // OUTPUT: PART 1
    // ------
    //
    // *** create required table of statistics with varying load factors
    int size1 = 5;
    HashTable tablePart1 = HashTable(size1);
    GameBoard boards1[5];
    for (int i = 0; i < size1; ++i) {
        boards1[i] = randomBoard();
    }
    while (allDiff(boards1) == false) {
        for (int i = 0; i < size1; ++i) {
            boards1[i] = randomBoard();
        }
    }
    for (int i = 0; i < size1; ++i) {
        int value = tablePart1.compress(i);
        tablePart1.insert(boards1[i], value);
    }
    int precision = 5;
    int width = 15;
    cout << setiosflags(ios::fixed) << setprecision(precision) << setw(width) 
            << endl;
    for (int i = 0; i < size1; ++i) {
        cout << "Number of Buckets = " << tablePart1.getNumBuckets() << endl;
        cout << "Load Factor = " <<tablePart1.getLoadFactor() << endl;
    }
    
    
    
    
    
    
    // OUTPUT: PART 2
    // ------
    // NOTE: set DIMENSION in GameBoard.h to 4 for this section
    
    
    
    // *** make a hash table of size 100
    
    
    // make an array of 4 GameBoards, all of which are different
    GameBoard boards[4];
    for (int i = 0; i < 4; ++i) {
        boards[i] = randomBoard();
    }
    while (allDiff(boards) == false) {
        for (int i = 0; i < 4; ++i) {
            boards[i] = randomBoard();
        }
    }

    //initTable(HashTable &table, int numBoards)
    // *** insert the first two boards into the hash table with arbitrary values
    int size = 2;
    HashTable table = HashTable(size);
    initTable(table, 2);
    
    

    cout << "———————————————————------------------------————————" << endl << endl;
    cout << "ADDED BOARDS 1 AND 2 TO THE HASH TABLE" << endl << endl;
    cout << "———————————————————------------------------————————" << endl << endl;
    cout << "SEARCHES AFTER INSERTIONS BUT BEFORE REMOVALS" << endl << endl;
    cout << "———————————————————------------------------————————" << endl;


    cout << "Searching for Board 1 (which is in the hash table).  Board 1:" << endl << endl;
    boards[0].print();
    Entry e = table.find(boards[0]);// *** try to find boards[0] in the hash table
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Searching for Board 2 (which is in the hash table).  Board 2:" << endl << endl;
    boards[1].print();
    e = table.find(boards[1]);// *** try to find boards[1] in the hash table
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
    
        
    cout << "Searching for Board 3 (which is NOT in the hash table).  Board 3:" << endl << endl;
    boards[1].print();
    e = table.find(boards[2]);// *** try to find boards[2] in the hash table
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
    
        
    cout << "Searching for Board 4 (which is NOT in the hash table).  Board 4:" << endl << endl;
    boards[1].print();
    e = table.find(boards[3]);// *** try to find boards[3] in the hash table
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
    
    cout << "REMOVALS" << endl << endl;
    cout << "———————————————————------------------------————————" << endl;
    cout << "Removing Board 1 (which is in the hash table):" << endl << endl;
    boards[0].print();
    e =  table.remove(boards[0]);// *** remove boards[0]
    cout << "Here’s what was returned from the remove:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Removing Board 2 (which is in the hash table):" << endl << endl;
    boards[1].print();
    e =  table.remove(boards[1]);// *** remove boards[1]
    cout << "Here’s what was returned from the remove:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Removing Board 3 (which is NOT in the hash table):" << endl << endl;
    boards[2].print();
    e =  table.remove(boards[2]);// *** remove boards[2]
    cout << "Here’s what was returned from the remove:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Removing Board 4 (which is NOT in the hash table):" << endl << endl;
    boards[3].print();
    e =  table.remove(boards[3]);// *** remove boards[3]
    cout << "Here’s what was returned from the remove:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    
    cout << "SEARCHES AFTER REMOVALS" << endl << endl;
    cout << "———————————————————------------------------————————" << endl;
        
    cout << "Searching for Board 1 (no longer in the hash table).  Board 1:" << endl << endl;
    boards[0].print();
    e = table.find(boards[0]);// *** try to find boards[0] in the hash table
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Searching for Board 2 (no longer in the hash table).  Board 2:" << endl << endl;
    boards[1].print();
    e = table.find(boards[1]);// *** try to find boards[1] in the hash table
    cout << "Here’s what was returned from the find:" << endl << endl;
    e.getBoard().print();
    cout << "———————————————————------------------------————————" << endl << endl;
        
    cout << "Call to isEmpty function returns:  " << table.isEmpty() << endl << endl;
    
    cout << "———————————————————------------------------————————" << endl << endl;

    return EXIT_SUCCESS;

}



//
// Inputs: None.
//
// Output: A random gameboard.
//
// Creates and returns a GameBoard containing random
// integers
//

GameBoard randomBoard() {

    GameBoard board;
    for (int y = 0; y < board.size(); y++) {
        for (int x = 0; x < board.size(); x++) {
            double fval = rand() * 17;
            int value = (int) fval;
            board.setElementAt(x, y, value);
        }
    }
    return board;

}



//
// Inputs: A HashTable and an integer specifiying the
//         number of random Gameboards to be inserted
//         into the table.
//
// Output: None.
//
// The specified number of GameBoards is created and
// inserted into the HashTable. The value associated
// with each board is just the value of the for-loop
// control variable, since, for this lab, this value
// does not matter.
//

void initTable(HashTable &table, int numBoards) {
    for (int i = 0; i < numBoards; i++) {
        table.insert(randomBoard(), i);
    }
}


//
// Inputs: An array of 4 GameBoards.
//
// Output: A Boolean value:
//           - true if all 4 boards are different
//           - false, otherwise
//

bool allDiff(GameBoard boards[4]) {

    return
    !boards[0].equals(boards[1]) &&
            !boards[0].equals(boards[2]) &&
            !boards[0].equals(boards[3]) &&
            !boards[1].equals(boards[2]) &&
            !boards[1].equals(boards[3]) &&
            !boards[2].equals(boards[3]);


}


