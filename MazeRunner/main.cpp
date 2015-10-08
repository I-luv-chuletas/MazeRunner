//
//  main.cpp
//  MazeRunner
//
//  Created by Alexander Rivera on 9/29/15.
//  Copyright (c) 2015 Alexander Rivera. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "PathFinder.h"
#include "PositionStack.h"
#include "GameGrid.h"


int main(int argc, const char * argv[]) {
    
    int temp;
    // Inicializacion y Setup de variables y objetos
   
    PathFinder* mazeRunner  = new PathFinder();
    //PositionStack* stack    = new PositionStack();
    GameGrid* maze          = new GameGrid();
    
    std::cout << "Tamo aki\n";
    
    // Ajustamos el default movement del pathfinder
    mazeRunner->adjustDefaultMovement(maze->getStart(), maze->getGoal());
    
    std::cout << "\nTamo aki\n\n";
    //std::cout<< mazeRunner->_movementDirection;
    
    maze->outputGrid();
    
    // Main Loop del Programa
    while (!mazeRunner->reachEnd(maze->getGoal())){
        
        // Sacamos las direcciones
        char *direc = maze->getAdjacentTiles(mazeRunner->getPosition());
        
        std::cout << "Izq " << direc[0] << " Derecha " << direc[1] << " up " << direc[2] << " down " << direc[3] << std::endl;
        
        
        mazeRunner->checkMovement(direc[0], direc[1], direc[2], direc[3]);
        maze->markGridPosition(mazeRunner->getPosition(), mazeRunner->getSymbol());
        maze->outputGrid();
        

        std::cin >> temp;
        
        
        
        
        
        
    }
    
    
    return 0;
}
