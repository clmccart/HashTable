/* 
 * File:   GameBoard.h
 * Author: Claire McCarthy
 * 
 * Created on November 18, 2014, 7:24 PM
 * 
 * GAMEBOARD.H
 * GameBoard.h - contains the function prototypes and variables for the 
 * GameBoard class. 
 * FUNCTIONAL DESCRIPTION
 * Contains the function prototypes and private and public variables for the 
 * GameBoard class including in-line functions size and elementAt.
 * 
 * NOTICE
 * Copyright (C) 2014 Claire McCarthy All Rights Reserved.
 */

#ifndef GAMEBOARD_H
#define	GAMEBOARD_H

#include <cstdlib>  
#include <iostream>
#include <vector>

using namespace std;

class GameBoard {
    
public:
    GameBoard();
    GameBoard(int negOne);
    void print();
    void setElementAt(int x, int y, int value);
    int size() { return DIMENSION; }
    int elementAt(int x, int y) {return board[x][y]; }
    bool equals(GameBoard board);
    int hashCode(GameBoard key);


private:
    static const int DIMENSION = 8;
    int board[DIMENSION][DIMENSION];

};

#endif	/* GAMEBOARD_H */

