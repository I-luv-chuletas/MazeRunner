//
//  GameGrid.h
//  MazeRunner
//
//  Created by Alexander Rivera on 9/30/15.
//  Copyright (c) 2015 Alexander Rivera. All rights reserved.
//

#ifndef __MazeRunner__GameGrid__
#define __MazeRunner__GameGrid__

#include <stdio.h>
#include <string>

class GameGrid {

private:
    int _startPosition[2];
    int _goalPosition[2];
    int** _grid;
    std::string _fileName;
    
    char _array[4]; // Aqui estaran mis 4 direcciones
    char _startSymbol;
    char _goalSymbol;
    char _nonViableSymbol;
    char _walls;
    char _labyrinth[10][15] = {
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
        {'1','S','1','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','0','1','0','1','1','0','1','1','1','0','1','1','1','1'},
        {'1','0','0','0','1','0','0','1','1','1','0','0','0','0','1'},
        {'1','0','1','1','1','0','1','0','0','1','1','1','1','0','1'},
        {'1','0','1','1','1','0','0','0','1','1','0','0','0','0','1'},
        {'1','0','0','0','1','0','1','1','1','1','0','1','1','0','1'},
        {'1','1','1','0','1','0','0','0','0','1','0','0','1','0','1'},
        {'1','0','0','0','1','0','1','1','1','1','1','0','1','*','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};
     
public:
    GameGrid();
    void findKeyPositions();
    void markGridPosition(int position[], char symbol);
    void createGrid();
    void outputGrid();
    
    int* getStart();
    int* getGoal();
    char* getAdjacentTiles(int position[]);
    
};

#endif /* defined(__MazeRunner__GameGrid__) */
