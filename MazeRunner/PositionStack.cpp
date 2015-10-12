//
//  PositionStack.cpp
//  MazeRunner
//
//  Created by Alexander Rivera on 9/29/15.
//  Copyright (c) 2015 Alexander Rivera. All rights reserved.
//

#include "PositionStack.h"
PositionStack::PositionStack(){
    _top            = 0;
    _amount         = 0;
    //_positionX[0]    = 0;
    //_positionY[0]    = 0;
}

void PositionStack::push(int position[]){
    // Añadimos un elemento al tope de la lista.
    _positionX.push_back(position[0]);
    _positionY.push_back(position[1]);
}

void PositionStack::pop() {
    // Eliminamos el ultimo elemento en la lista
    _positionX.pop_back();
    _positionY.pop_back();
}

int* PositionStack::getTop() {

   _position[0] = _positionX.back();
   _position[1] = _positionY.back();
    
    return _position;
}

int PositionStack::getAmount(){ return _positionX.size(); }

