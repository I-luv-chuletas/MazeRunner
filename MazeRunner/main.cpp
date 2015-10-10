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
    while (!mazeRunner->reachEnd(maze->getGoal())) {
        
        //Las direcciones con las que se suma la posicion del maze runner, asi obtenemos su nueva posicion.
        
        // Sacamos las direcciones
        char *direc = maze->getAdjacentTiles(mazeRunner->getPosition()); // Aqui hay un array local
        
        std::cout << "Izq " << direc[0] << " Derecha " << direc[1] << " up " << direc[2] << " down " << direc[3] << std::endl;
        
        /* LEYENDA DE DIRECCIONES:
            direc[0] == Izquierda
            direc[1] == derecha
            direc[2] == up
            direc[3] == down */
        
        mazeRunner->checkXAxis(direc[0], direc[1]);
        
        // Despues de hacer el movimiento, aplicamos el movimiento en el Grid. Sacamos nuevamente los espacios adyacentes.
        direc = maze->getAdjacentTiles(mazeRunner->getPosition()); // Redundante que vuelva a recibir los valores de las direcciones?
        
        
        // Verificamos el eje de Y
        mazeRunner->checkYAxis(direc[2], direc[3]);
    
        // Volvemos y ajustamos el maze
        
        
        // Verificamos si hay que retroceder
        if (!mazeRunner->getMovementFlagX() && !mazeRunner->getMovementFlagY()) { // Si ambos movimientos son nulos
            std::cout << "\nRetrocediendo\n";
            mazeRunner->retreatPosition();
        }
        
        
        maze->markGridPosition(mazeRunner->getPosition(), mazeRunner->getSymbol());
        maze->outputGrid();
        

        std::cin >> temp;
        
        
        
        
        
        
    }
    
    
    return 0;
}
