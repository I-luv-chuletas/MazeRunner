//
//  PathFinder.cpp
//  MazeRunner
//
//  Created by Alexander Rivera on 9/29/15.
//  Copyright (c) 2015 Alexander Rivera. All rights reserved.
//

#include "PathFinder.h"

#include <stdio.h>
#include <string>
#include <iostream>


PathFinder::PathFinder(){
    
    // Inicializamos nuestros campos
    _movesCounter       = 0;
    _characterSymbol    = '@';
    _movementSymbol     = '*';
    _nonViableSymbol    = 'n';
    _reachEnd           = false;
    
}


void PathFinder::checkMovement(char left, char right, char up, char down){
    // Este metodo verifica la direccion que sea posible moverse
    int direction[2]; // Aqui guardamos los valores de movimiento que vamos a tener
    //int* point;
    
    std::cout << "Arriba hay "<< up;
    
    checkXAxis(left, right, direction);
    checkYAxis(up, down, direction);
    
    
    if (direction[0] == 0 && direction[1] == 0) { // Si no hay movimiento en ninguno de los dos.
        
        retreatPosition();
        
    }else {
        
        makeMovement(direction);
        
    }
    
}


void PathFinder::checkXAxis(char left, char right, int direction[]){
    // Aqui verificamos unicamente el eje de x para saber el movimiento que va a tener
    
    std::cout<< "Verificando X.\n A la izquierda hay: " << left << "\nA la derecha hay: " << right;
    // Nuestro _movementDirection es nuestra direccion hacia la meta. Por ende esa direccion es la que tiene presedencia
    if (_movementDirection[0] == 1) {
        if (right == '1' || right == 'n') { // Si a la derecha hay una pared o ya se recorrio
            
            if (left == '1' || left == 'n') { // Si a la izquierda hay una pared o ya se recorrio
                direction[0] = 0; // Entonces no hay movimiento en x
                
            }else {
                direction[0] = -1; // Si puedes moverte a la izquierda, esa es tu nueva direccion.
            }
            
        }else {
            direction[0] = 1; // Si puedes moverte a la derecha, esa es tu nueva direccion.
        }
    }
    
    else if (_movementDirection[0] == -1) {
        if (left == '1' || left == 'n') {
            
            if (right == '1' || right == 'n') {
                direction[0] = 0;

            }else {
                direction[0] = 1;
            }
            
        }else {
            direction[0] = -1;
        }
    }
    
}


void PathFinder::checkYAxis(char up, char down, int direction[]){
    
    std::cout << "Verificando Y\n";
    std::cout << "Up: " << up << "Down: " << down << std::endl;
    
    
    // Nuestro _movementDirection es nuestra direccion hacia la meta. Por ende esa direccion es la que tiene presedencia
    if (_movementDirection[1] == 1) {
        if (down == '1' || down == 'n') { // Si a la derecha hay una pared o ya se recorrio
            
            if (up == '1' || up == 'n') { // Si a la izquierda hay una pared o ya se recorrio
                direction[1] = 0; // Entonces no hay movimiento en x
                
            }else {
                direction[1] = -1; // Si puedes moverte a la izquierda, esa es tu nueva direccion.
            }
            
        }else {
            direction[1] = 1; // Si puedes moverte a la derecha, esa es tu nueva direccion.
        }
    }
    
    else if (_movementDirection[1] == -1) { // El inverso de todo lo que hice arriba
        if (up == '1' || up == 'n') {
            
            if (down == '1' || down == 'n') {
                direction[1] = 0;
                
            }else {
                direction[1] = 1;
            }
            
        }else {
            direction[1] = -1;
        }
    }
    
}


void PathFinder::makeMovement(int direction[]) {
    
    _currentPosition[0] += direction[0]; // Aplica movimiento en X
    _currentPosition[1] += direction[1]; // Aplica movimiento en Y
    
    // Actualiza el stack de posiciones
    _positionStack->push(_currentPosition);
    
    // Actualiza el current pos
    int* pos = _positionStack->getTop();
    _currentPosition[0] = pos[0];
    _currentPosition[1] = pos[1];
    
    // Reseteamos la direccion de movimiento
    _movementDirection[0] = _defaultMovement[0];
    _movementDirection[1] = _defaultMovement[1];
    
    
}


void PathFinder::retreatPosition() {
    
    int* point;
    
    // pinta tu posicion como no viable
    // Añade la posicion al stack de posiciones no viables
    _nonViableStack->push(_currentPosition);
    
    // Hazle pop a la posicion actual
    _positionStack->pop();
    
    // Tu nueva posicion sera la proxima posicion con prioridad en el stack (que tenga otro camino para recorrer)
    point = _positionStack->getTop();
    
    _currentPosition[0] = point[0];
    _currentPosition[1] = point[1];
    
}


void PathFinder::adjustDefaultMovement(int startPosition[], int finalPosition[]) {
    // Aqui ajustamos el movimiento estandar del mazeRunner, siguiendo la salida del laberinto
    
    int* temp; // Variable temporera para recibir la posicion del stack
    
    std::cout<< "Estamos en: " << startPosition[0] << " , " << startPosition[1] << std::endl;
    std::cout<< "vaamos pa: " << finalPosition[0] << " , " << finalPosition[1] << std::endl;
    
    // Ponemos en el stack de posiciones la primera posicion, la cual es la inicial.
    _positionStack->push(startPosition);
    temp = _positionStack->getTop();
    
    _currentPosition[0] = temp[0];
    _currentPosition[1] = temp[1];
    
    
    if (finalPosition[0] > startPosition[0]) { // Si la posicion del goal esta a la derecha de donde empiezo..
        
        _movementDirection[0] = 1;
        
    }else {
        
        _movementDirection[0] = -1;
        
    }
    
    if (finalPosition[1] > startPosition[1]) {
        
        _movementDirection[1] = 1;
        
    }else {
        
        _movementDirection[1] = -1;
        
    }
    
    std::cout<< _movementDirection[0] << " , " << _movementDirection[1] ;
    _defaultMovement[0] = _movementDirection[0];
    _defaultMovement[1] = _movementDirection[1];
    
}


//GETTERS ////////////////////////////////////////////////////
bool PathFinder::reachEnd(int endPosition[]){
    // Verificamos si la posicion actual es la misma que el maze tiene como end position
    if (endPosition == _currentPosition) {
        std::cout << std::endl << "HA LLEGADO AL FINAL!" << std::endl;
        return true;
    }
    
    return false;
}

int* PathFinder:: getPosition() { return _currentPosition; }




