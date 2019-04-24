//
// Created by vgwse on 4/23/2019.
//

#ifndef FINALPROJECT_CHARTREUSE_GHOST_H
#define FINALPROJECT_CHARTREUSE_GHOST_H

#include "circle.h"
#include "longSquare.h"
#include "shape.h"
#include <vector>
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

    //Push ghost to the vector in a specific order
    void addGhost();

    //Construct the Ghost
    void drawGhost();

public:

    //Create ghost skeleton
    void createGhostSkele();


    //place the complete ghost together;
    void completedGhost(Ghost ghoul);

    //STILL THINKING ABOUT
    //Getters
    //Get the location of the ghost
    //int getLocation(int x, int y);


    //Setters
    //Set the location of the ghost
    //int setLocation(int x, int y);

    //Create a method to move the ghost
    //void  ghostMove();

    //Create a method for the color of the ghost to change
    //void ghostColor();







};


#endif //FINALPROJECT_CHARTREUSE_GHOST_H
