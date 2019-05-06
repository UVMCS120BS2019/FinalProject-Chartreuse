//
// Created by vgwse on 4/23/2019.
//

#ifndef FINALPROJECT_CHARTREUSE_GHOST_H
#define FINALPROJECT_CHARTREUSE_GHOST_H

#include "circle.h"
#include "ghost.h"

#include "longSquare.h"
#include "shape.h"
#include <vector>
#include <chrono>
#include <cmath>

using std::vector;

class Ghost {

private:

    //Variables and vectors
    int x;
    int y;
    bool  hit;
    Circle head;
    LongSquare leg1;
    Circle halfCircleLeg;
    Circle halfCircleLeg2;
    Circle halfCircleLeg3;
    Circle eye1;
    Circle eye2;
    Circle mouth;
    vector<Shape*> ghost;
    LongSquare collisionSquareGhost;

    int getCenterX() const;
    int getLeftX() const;
    int getRightX() const;
    int getCenterY() const;
    int getTopY() const;
    int getBottomY() const;
    bool collide();
    point getCenter() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;


public:

    //Constructors
    Ghost();
    Ghost(int x, int y);
    bool setHit(bool hit);
    bool getHit();
    //Create ghost skeleton
    void createGhostSkele(int x, int y);

    //Push ghost to the vector in a specific order
    void addGhost();

    //Construct the Ghost
    void drawGhost();


public:
//    Ghost();
    unsigned int height;
    unsigned int width;
    point center;

    //Create ghost skeleton
    void createGhostSkele();



    //place the complete ghost together;
    //
    //void completedGhost(Ghost ghoul);


    //Create a method to move the ghost
    void  ghostMove(double x, double y);

    void track(int x);
//    bool hit(bool collide);
    bool collisionCheck(int left, int right , int bottom, int top);

    void track(point start, point end);

    //Create a method for the color of the ghost to change
    //void ghostColor();







};


#endif //FINALPROJECT_CHARTREUSE_GHOST_H
