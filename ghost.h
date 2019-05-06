//
// Created by vgwse on 4/23/2019.
//

#ifndef FINALPROJECT_CHARTREUSE_GHOST_H
#define FINALPROJECT_CHARTREUSE_GHOST_H

#include "circle.h"
#include "longSquare.h"
#include "shape.h"
#include <vector>
#include <chrono>
#include <cmath>
#include <thread>

using std::vector;

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

    //clear ghost shape vector
    void deleteGhost();

    //Construct the Ghost
    void drawGhost();

    // get collision square center
    point getCollisionSquareCenter();

    //place the complete ghost together;
    //
    //void completedGhost(Ghost ghoul);


    //Create a method to move the ghost
    void  ghostMove(double x, double y);
    void track(int deltaX);

    //Create a method for the color of the ghost to change
    //void ghostColor();







};


#endif //FINALPROJECT_CHARTREUSE_GHOST_H
