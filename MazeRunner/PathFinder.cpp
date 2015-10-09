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


//void PathFinder::checkMovement(char left, char right, char up, char down){
//    // Este metodo verifica la direccion que sea posible moverse
//    
//    
//    int direction[2]; // Aqui guardamos los valores de movimiento que vamos a tener
//    direction[0] = 0;
//    direction[1] = 0;
//    //int* point;
//    
//    // *****Cambia el scope del array, se esta perdiendo el valor *******
//    checkXAxis(left, right); // Verificamos que direccion se debe coger
//    std::cout<< "\nDirection : " << direction[1] << std::endl;
//
//    if (direction[0] != 0) {
//        std::cout<< "\nDirection x: " << direction[0] << std::endl;
//        makeMovement(direction);
//        direction[0] = 0;
//    }
//    
//    std::cout << "\n----------------------------------------------------------------------";
//    std::cout << "\n CHECK MOVEMENT\n";
//    std::cout << "\nEstando en: " << _currentPosition[1] << " , " << _currentPosition[0];
//    std::cout << "\nA mis alrededores estan:\n";
//    std::cout << "Up: " << up << "\nDown " << down << "\nLeft: " << left << "\nRight: "<< right <<"\n\n";
//    std::cout << "----------------------------------------------------------------------\n";
//    
//    
//    //checkYAxis(up, down, left, right);
//    
//    std::cout << "\nLas direcciones son: " << direction[1] << " , " << direction[0] << std::endl;
//    
//    
//    if (direction[0] == 0 && direction[1] == 0) { // Si no hay movimiento en ninguno de los dos.
//        
//        retreatPosition();
//        
//    }else {
//        
//        makeMovement(direction);
//        
//    }
//    
//    std::cout<<"Soy Chucky "<<direction[1]<<" "<<direction[0]<<std::endl;
//    
//}


void PathFinder::checkXAxis(char left, char right){
    // Aqui verificamos unicamente el eje de x para saber el movimiento que va a tener
    
    std::cout<< "Verificando X.\n A la izquierda hay: " << left << "\nA la derecha hay: " << right;
    // Nuestro _movementDirection es nuestra direccion hacia la meta. Por ende esa direccion es la que tiene presedencia
    if (_defaultMovementDirection[0] == 1) { // Si nuestra direcion por default es a la derecha...
        if (right == '1' || right == _nonViableSymbol || right == _movementSymbol) { // Si a la derecha hay una pared o ya se recorrio
            
            if (left == '1' || left == _nonViableSymbol || left == _movementSymbol) { // Si a la izquierda hay una pared o ya se recorrio
                _movementDirection[0] = 0; // Entonces no hay movimiento en x
                
            }else {
                _movementDirection[0] = -1; // Si puedes moverte a la izquierda, esa es tu nueva direccion.
            }
            
        }else {
            _movementDirection[0] = 1; // Si puedes moverte a la derecha, esa es tu nueva direccion.
            std::cout<< "\nYou're taking a right turn, NIGGGUH\n" << std::endl;
        }
    }
    
    else if (_defaultMovementDirection[0] == -1) { // Si nuestro movimiento por default es para arriba...
         std::cout<< "\n naaaaah  other way nigguuuuuh\n";
        if (left == '1' || left == 'n') { // Miramos a nuestra izquierda, si no podemos coger para alla:
            
            if (right == '1' || right == _nonViableSymbol || right == _movementSymbol) { // Si tampoco me puedo mover a la derecha:
                _movementDirection[0] = 0;

            }else {
                _movementDirection[0] = 1;
            }
            
        }else {
            _movementDirection[0] = -1;
        }
    }
    
}


void PathFinder::checkYAxis(char up, char down){
    
    std::cout << "Up: " << up << "\nDown: " << down << std::endl;
    std::cout << "Mi POSITion actual: " << "(" << _currentPosition[1] << " , " << _currentPosition[0] << std::endl;
    std::cout << "direccion: " << _movementDirection[1] << " " << _movementDirection[0] << std::endl;
    
//    std::cout << "\n----------------------------------------------------------------------";
//    std::cout << "\nEstando en: " << _currentPosition[1] << " , " << _currentPosition[0];
//    std::cout << "\nA mis alrededores estan:\n";
//    std::cout << "Up: " << up << "\nDown " << down << "\nLeft: " << left << "\nRight: "<< right <<"\n\n";
//    std::cout << "----------------------------------------------------------------------\n";
    
    // Nuestro _movementDirection es nuestra direccion hacia la meta. Por ende esa direccion es la que tiene presedencia
    if (_defaultMovementDirection[1] == 1) {
        if (down == '1' || down == _nonViableSymbol || down == _movementSymbol) { // Si a la derecha hay una pared o ya se recorrio
            
            if (up == '1' || up == _nonViableSymbol || up == _movementSymbol) { // Si a la izquierda hay una pared o ya se recorrio
                _movementDirection[1] = 0; // Entonces no hay movimiento en x
                
            }else {
                _movementDirection[1] = -1; // Si puedes moverte a la izquierda, esa es tu nueva direccion.
            }
            
        }else {
            std::cout << std::endl << "Lo tienes invertido guevon: " << up << std::endl;
            _movementDirection[1] = 1; // Si puedes moverte a la derecha, esa es tu nueva direccion.
            std::cout << std::endl << "#OMG like, te estas moviendo parriba, oseaaa" << std::endl;
        }
    }
    
    else if (_defaultMovementDirection[1] == -1) { // El inverso de todo lo que hice arriba
        if (up == '1' || up == _nonViableSymbol || up == _movementSymbol ) {
            
            if (down == '1' || down == _nonViableSymbol || down == _movementSymbol) {
                _movementDirection[1] = 0;
                
            }else {
                _movementDirection[1] = 1;
            }
            
        }else {
            _movementDirection[1] = -1;
        }
    }
    
    std::cout << "La direccion es: " << _movementDirection[1] << " ,  " << _movementDirection[0];
    
}


void PathFinder::makeMovement() {
    
    //std::cout<< "\nDirection y: " << direction[1] << std::endl;
    _currentPosition[0] += _movementDirection[0]; // Aplica movimiento en X
    _currentPosition[1] += _movementDirection[1]; // Aplica movimiento en Y
    
    std::cout << "\n\nMi posicion actualizada: (" << _currentPosition[1] << " , " << _currentPosition[0] << ")\n" << std::endl;
    
    // Actualiza el stack de posiciones
    _positionStack->push(_currentPosition);
    
    // Debugging: Verificando donde envia el movimiento.
    std::cout << "Posicion en filas:" << _currentPosition[1] << "Posicion en columnas: " << _currentPosition[0] << std::endl;
    
    // Reseteamos la direccion de movimiento
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
    std::cout<< "vaamos pa: "  << finalPosition[0] << " , " << finalPosition[1] << std::endl;
    
    // Ponemos en el stack de posiciones la primera posicion, la cual es la inicial.
    _positionStack->push(startPosition);
    temp = _positionStack->getTop();
    
    _currentPosition[0] = temp[0];
    _currentPosition[1] = temp[1];
    
    
    if (finalPosition[0] > startPosition[0]) { // Si la posicion del goal esta a la derecha de donde empiezo..
        
        _defaultMovementDirection[0] = 1;
        
    }else {
        
        _defaultMovementDirection[0] = -1;
        
    }
    
    if (finalPosition[1] > startPosition[1]) {
        
        _defaultMovementDirection[1] = 1;
        
    }else {
        
        _defaultMovementDirection[1] = -1;
        
    }
    
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




