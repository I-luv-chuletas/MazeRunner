//
//  PositionStack.h
//  MazeRunner
//
//  Created by Alexander Rivera on 9/29/15.
//  Copyright (c) 2015 Alexander Rivera. All rights reserved.
//

#ifndef __MazeRunner__PositionStack__
#define __MazeRunner__PositionStack__

#include <stdio.h>
#include <vector>

class PositionStack {

private:
    std::vector<int> _positionX;
    std::vector<int> _positionY;
    
    int _position[2] = {0, 0};
    int _top;
    int _amount;
    int _positionNode; // Donde puedes virar a mas de una direccion
    
public:
    PositionStack();
    int* getTop();
    int getAmount();
    
    void push(int position[]);
    void pop();
    
};

#endif /* defined(__MazeRunner__PositionStack__) */
