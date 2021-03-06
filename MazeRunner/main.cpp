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
        char *direc = maze->getAdjacentTiles(mazeRunner->getPosition()); // Se devuelven lo que este en el grid en 4 posiciones
        
        std::cout << "Izq " << direc[0] << " Derecha " << direc[1] << " up " << direc[2] << " down " << direc[3] << std::endl;
        
        /* LEYENDA DE DIRECCIONES:
            direc[0] == Izquierda
            direc[1] == derecha
            direc[2] == up
            direc[3] == down */
        
        // Verificamos movimiento en el eje de X
        mazeRunner->checkXAxis(direc[0], direc[1]);
        
        // Verificamos si hubo movimiento, para aplicar la nueva posicion al stack
        if (mazeRunner->getMovementFlagX()) {
            std::cout<< "\nMoviendo X\n";
            mazeRunner->updatePositionStack(); // Si se movio en X, aplica el movimiento al stack
        }

        maze->markGridPosition(mazeRunner->getPosition(), mazeRunner->getSymbol());
        
        // Despues de hacer el movimiento, aplicamos el movimiento en el Grid. Sacamos nuevamente los espacios adyacentes.
        direc = maze->getAdjacentTiles(mazeRunner->getPosition()); // Redundante que vuelva a recibir los valores de las direcciones?
        
        
        // Verificamos el eje de Y
        mazeRunner->checkYAxis(direc[2], direc[3]);
        
        // Verificamos el flag para aplicar movimiento al stack
        if (mazeRunner->getMovementFlagY()) {
            std::cout<< "\nMoviendo Y\n";
            mazeRunner->updatePositionStack(); // Si se movio en Y, aplica el movimiento al stack
        }
    
        // Volvemos y ajustamos el maze
        
        
        // Verificamos si hay que retroceder
        if (!mazeRunner->getMovementFlagX() && !mazeRunner->getMovementFlagY()) { // Si no hubo movimiento en ninguno de los ejes
            
            maze->markGridPosition(mazeRunner->getPosition(), mazeRunner->_nonViableSymbol);
            mazeRunner->retreatPosition();
            
        }else
            //mazeRunner->updatePositionStack();
        
        maze->markGridPosition(mazeRunner->getPosition(), mazeRunner->getSymbol());
        maze->outputGrid();
        
        // Debugging purposes
        std::cin >> temp;
        
    }
    
    
    return 0;
}
