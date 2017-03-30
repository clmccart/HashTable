/* 
 * File:   Entry.h
 * Author: Claire McCarthy - clmccart
//
// ENTRY.H.
// Entry.h – Header file for the Entry class used in for CSCI2101 Assignment 7. //
// FUNCTIONAL DESCRIPTION.
 * Stores the data associated with a hash table entry. 
 * Defines public functions ad private variables.
// NOTICE.
// Copyright (C) 2014 Claire McCarthy All Rights Reserved.
 *
 * Created on November 18, 2014, 7:38 PM
 */

#ifndef ENTRY_H
#define	ENTRY_H

#include "GameBoard.h"
#include "Entry.h"

class Entry {
    
public:
    Entry();
    Entry(GameBoard board, int value);
    GameBoard getBoard() { return board; }
    int getValue() { return value; } 
    
    
private:
    GameBoard board;
    int value;
    
    
};

#endif	/* ENTRY_H */

