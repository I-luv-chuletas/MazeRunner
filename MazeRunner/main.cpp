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
        
        
        
       // mazeRunner->checkMovement(direc[0], direc[1], direc[2], direc[3]); // Innecesario ahora que encontramos el problema.
        // ENCONTRADO EL PROBLEMA: NO ESTA ACTUALIZANDO EL ADJACENT TILES CUANDO SE MUEVE INTERNAMENTE EN EL CHECK MOVEMENT
        // SOLUCION: SEPARA CHECK MOVEMENTS Y PONLO EN EL MAIN LOOP.
        mazeRunner->checkXAxis(direc[0], direc[1]);
        
        
        if (mazeRunner->getMovementDirectionX() != 0) { // Si en el eje de x hay movimiento
            mazeRunner->makeMovement(); // Haz el movimiento
        }
        
        // Despues de hacer el movimiento, aplicamos el movimiento en el Grid. Sacamos nuevamente los espacios adyacentes.
        maze->getAdjacentTiles(mazeRunner->getPosition());
        
        // Verificamos el eje de Y
        mazeRunner->checkYAxis(direc[2], direc[3]);
    
        if (mazeRunner->getMovementDirectionY() != 0) { // Si en el eje de x hay movimiento
            mazeRunner->makeMovement(); // Haz el movimiento
        }
        
        // Verificamos si hay que retroceder
        if (mazeRunner->getMovementDirectionX() == 0 && mazeRunner->getMovementDirectionY() == 0 ) { // Si ambos movimientos son nulos
            mazeRunner->retreatPosition();
        }
        
        
        maze->markGridPosition(mazeRunner->getPosition(), mazeRunner->getSymbol());
        maze->outputGrid();
        

        std::cin >> temp;
        
        
        
        
        
        
    }
    
    
    return 0;
}
