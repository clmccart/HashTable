/* 
 * File:   Entry.cpp
 * Author: Claire McCarthy
//
// ENTRY.CPP.
// Entry.cpp – Source code for the Entry class for CSCI2101 Assignment 7. //
// FUNCTIONAL DESCRIPTION.
// Contains source code for the Entry code and defines the functions in the 
 * Entry class that are not in-line functions. 
//
// NOTICE.
// Copyright (C) 2014 Claire McCarthy All Rights Reserved.
 * 
 * Created on November 18, 2014, 7:38 PM
 */

#include "Entry.h"


Entry::Entry() {
}



Entry::Entry(GameBoard board, int value) { 
    this->board = board; 
    this->value = value; 
}


