//
//  GameGrid.cpp
//  MazeRunner
//
//  Created by Alexander Rivera on 9/30/15.
//  Copyright (c) 2015 Alexander Rivera. All rights reserved.
//

#include "GameGrid.h"
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>

GameGrid::GameGrid(){
    // Inicializando todos los campos
//    int rowSize;
//    int colSize;
//    
    std::string mazeLine;
    
    //_fileName = fileName;
    _startSymbol       = 'S';
    _goalSymbol        = '^';
    _nonViableSymbol   = '%';
    _walls             = '1';
    
    findKeyPositions();
}


void GameGrid::findKeyPositions() {
    for (int i=0; i<10; i++)
    {
        //columnas
        for (int j=0; j<15; j++)
        {
            if (_labyrinth[i][j] == 's' || _labyrinth[i][j] == 'S') // Buscamos la posicion del principio
            {
                _startPosition[0] = i;
                _startPosition[1] = j;
                
                //cout<<start_coords.at(0)<<" "<<start_coords.at(1)<<endl;
            }
            
            if(_labyrinth[i][j] == '*') // Buscamos la posicion del goal
            {
                _goalPosition[0] = i;
                _goalPosition[1] = j;
                
                //cout<<exit_coords.at(0)<<" "<<exit_coords.at(1)<<endl;
            }
        }
    }

}


void GameGrid::markGridPosition(int position[], char *symbol) {
    // Marca la posicion recibida en el grid con el simbolo del objeto
    _labyrinth[position[1]][position[0]] = *symbol; // <-- Funciona para todo tipo de objeto :)
}

void GameGrid::outputGrid(){
    //filas
    int i;
    int j;
    //int temp;
    
    for (i=0; i<10; i++)
    {
        //columnas
        for (j=0; j<15; j++)
        {
            std::cout << _labyrinth[i][j];
            

        }
        std::cout << std::endl;
        
    }
    std::cout << std::endl;
    
}


char* GameGrid::getAdjacentTiles(int position[]){
    // Verifica las posiciones adyacentes a las coordenadas recibidas, y devuelve los valores dentro del grid.
    
    std::cout << "Estoy verificando alrededor de: (" << position[1] << " , "<<position[0] << ")" << std::endl;
    
    // Colocamos lo que este adyacente de nuestra posicion en un array de caracteres para ser devuelto
    _array[0] = _labyrinth[position[1]][position[0] - 1]; // Miramos la izquierda
    _array[1] = _labyrinth[position[1]][position[0] + 1]; // Miramos la derecha
    _array[2] = _labyrinth[position[1] - 1][position[0]]; // Miramos hacia arriba
    _array[3] = _labyrinth[position[1] + 1][position[0]]; // Miramos hacia abajo
    
    return _array; // Devolvemos las cuatro direcciones
}


// GETTERS ////////////////////////////////////////
int* GameGrid::getStart(){ return _startPosition; }
int* GameGrid::getGoal() { return _goalPosition;  }

//    mazeFile.open(fileName);
//    if (mazeFile.is_open()) {
//
//        mazeFile >> rowSize;
//        mazeFile >> colSize;
//        
//        // Le damos el valor al array de punteros a otros arrays (array 2d dinamico)
//        _grid = new int*[rowSize];
//        for (int i = 0; i < rowSize; i++) {
//            _grid[i] = new int[colSize];
//        }
//        
//        // Ahora nos encargamos de generar el array.
//        for (int i = 0; i < colSize; i++) {
//            // Metes la linea del file al string
//            mazeFile >> mazeLine;
//            
//            // Entra al string, divide cada elemento para añadirlo al grid
//            for (int j = 0; j < rowSize; j++) {
//                _grid[j][i] = mazeLine[j];
//                
//                // Verificamos el simbolo que es
//                if (mazeLine[j] == _startSymbol) {
//                    // _startPosition;
//                }
//                
//            }
//            
//        }
//        
//    }
    

