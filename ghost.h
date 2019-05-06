//
// Created by vgwse on 4/23/2019.
//

#ifndef FINALPROJECT_CHARTREUSE_GHOST_H
#define FINALPROJECT_CHARTREUSE_GHOST_H

#include "circle.h"
#include "longSquare.h"
#include "character.h"
#include "shape.h"
#include <vector>
#include <chrono>
#include <cmath>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Ghost {

private:

    //Variables and vectors
    int x;
    int y;
    Circle head;
    LongSquare leg1;
    Circle halfCircleLeg;
    Circle halfCircleLeg2;
    Circle halfCircleLeg3;
    Circle eye1;
    Circle eye2;
    Circle mouth;
    vector<Shape*> ghost;
    LongSquare collisionSquare;


public:

    //Constructors
    Ghost();
    Ghost(int x, int y);

    //Create ghost skeleton
    void createGhostSkele(int x, int y);

    //Push ghost to the vector in a specific order
    void addGhost();

    //Construct the Ghost
    void drawGhost();

    //Create a method to move the ghost
    void  ghostMove(double x, double y);
    void track(point start, point end);

    bool checkGhost(Character &meghan);





};


#endif //FINALPROJECT_CHARTREUSE_GHOST_H
