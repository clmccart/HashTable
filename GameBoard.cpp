/* 
 * File:   GameBoard.cpp
 * Author: Claire McCarthy
 * 
 * Created on November 18, 2014, 7:24 PM
 * 
 * GAMEBOARD.CPP
 * GameBoard.cpp - contains the functions for the GameBoard class.
 * FUNCTIONAL DESCRIPTION
 * Contains the functions for theGameBoard class including two different 
 * constructors, functions that access elements, an equals function, the hash
 * code functions, etc. 
 * NOTICE
 * Copyright (C) 2014 Claire McCarthy All Rights Reserved.
 */

#include "GameBoard.h"



GameBoard::GameBoard() {
}

GameBoard::GameBoard(int negOne) {
    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            board[r][c] = -1;
        }
    }
}

void GameBoard::setElementAt(int x, int y, int value) {
    board[x][y] = value % 3;
    if (board[x][y] < 0) {
        board[x][y] = board[x][y] + 3;
    }
}



bool GameBoard::equals(GameBoard board) {

    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            if (this->board[r][c] != board.elementAt(r, c))
                return false;
        }
    }

    return true;
}



int GameBoard::hashCode(GameBoard key) {

    int hashVal = 0;

    for (int r = 0; r < key.size(); ++r) {
        for (int c = 0; c < key.size(); ++c) {
            hashVal = ((127*hashVal) + key.elementAt(r, c)) % 16908799;
        }            
    }
   
    
    return hashVal;
}

void GameBoard::print() {
    for (int r = 0; r < DIMENSION; r++) {
        cout << "\n"; 
        for (int c = 0; c < DIMENSION; c++) {
            int number = board[r][c];
            cout << number << " ";
            
        }  
    }
    cout << "\n" << endl;
}