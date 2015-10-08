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
        char *direc = maze->getAdjacentTiles(mazeRunner->getPosition()); // Aqui hay un array local
        
        std::cout << "Izq " << direc[0] << " Derecha " << direc[1] << " up " << direc[2] << " down " << direc[3] << std::endl;
        
        // Printing de Debugging (para ver que el detecta en la posicion (3,2))
//        int tempArray[] = { 2, 3};
//        char* prueba = maze->getAdjacentTiles(tempArray);
//        std::cout << "Izq " << prueba[0] << " Derecha " << prueba[1] << " up " << prueba[2] << " down " << prueba[3] << std::endl;
//
        
        
        mazeRunner->checkMovement(direc[0], direc[1], direc[2], direc[3]);
        // ENCONTRADO EL PROBLEMA: NO ESTA ACTUALIZANDO EL ADJACENT TILES CUANDO SE MUEVE INTERNAMENTE EN EL CHECK MOVEMENT
        // SOLUCION: SEPARA CHECK MOVEMENTS Y PONLO EN EL MAIN LOOP.
        // check X axis
        // make movement
        // check Y axis
        // make movement
        
        maze->markGridPosition(mazeRunner->getPosition(), mazeRunner->getSymbol());
        maze->outputGrid();
        

        std::cin >> temp;
        
        
        
        
        
        
    }
    
    
    return 0;
}
