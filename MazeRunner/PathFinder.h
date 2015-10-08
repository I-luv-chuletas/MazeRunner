//
//  PathFinder.h
//  MazeRunner
//
//  Created by Alexander Rivera on 9/29/15.
//  Copyright (c) 2015 Alexander Rivera. All rights reserved.
//

#ifndef __MazeRunner__PathFinder__
#define __MazeRunner__PathFinder__

#include <stdio.h>
#include <string>
#include "PositionStack.h"

class PathFinder {

private:
    int _defaultMovement[2];
    int _currentPosition[2];    // Es redundante por ahora ya que tenemos el tope del stack, pero hey. You never know.
    int _movementDirection[2];  // Este array automaticamente nos dice la direccion a la cual se tiene que mover el personaje.
    int _movesCounter;          // Contador para saber cuantos pasos ha tomado el runner.
    char _movementSymbol;       // Simbolo que marca por donde el runner ha pasado.
    char _nonViableSymbol;      // Simbolo para marcar los caminos no viables.
    char _characterSymbol;      // Simbolo que representa nuestro personaje.
    bool _reachEnd;             // Flag que nos deja saber si llegamos al final o no
    
    // Aqui en adelante estarian los dos stacks.
    PositionStack* _positionStack   = new PositionStack();
    PositionStack* _nonViableStack  = new PositionStack();
    
    // Metodos para verificar el moviminto por separado
    void checkXAxis(char left, char right, int direction[]);
    void checkYAxis(char up, char down, char left, char right, int direction[]);
    
public:
    PathFinder();
    void checkMovement(char left, char right, char up, char down);
    
    void adjustDefaultMovement(int startPosition[], int finalPosition[]);
    void retreatPosition(); // Coger una pasada posicion del stack.
    void makeMovement(int direction[]);
    
    
    bool reachEnd(int endPosition[]);
    int* getPosition();
    char* getSymbol(){
        return &_characterSymbol;
    }
};


#endif /* defined(__MazeRunner__PathFinder__) */
