//
// Created by Mary Woolley on 2019-04-21.
//

#ifndef FINALPROJECT_CHARTREUSE_CHARACTER_H
#define FINALPROJECT_CHARTREUSE_CHARACTER_H

#include <vector>
#include "ghost.h"
#include "longSquare.h"
#include "circle.h"

using namespace std;

class Character {
private:
    //vector of body parts
    vector<Shape*> body;
    Circle torso1, torso2, leg1, leg2, head, nose, tail;
    LongSquare collisionSquare;
    int cSquareRightX;
    int cSquareLeftX;
    int cSquareTopY;
    int cSquareBottomY;
    //getting cSqaure shit
//    int cSquareLeftX();
//    int cSquareRightY();
    int cSquareLeftY();
//    int cSqaureTopX();
//    int cSquareBottomX();


    // vector of tiles for the background maze
    // character only allowed to move within tiles
    vector<LongSquare> backgroundMaze;

public:
    //constructors
    Character();
    int collisionSquareGetRightX();
    int collisionSquareGetLeftX();
    int collsionSquareGetTopY();
    int collisionSquareGetbottomY();
    int collisionSquareGetLeftY();

    // setter
    void setBackground(vector<LongSquare> background);
    void setGhostCheck(Ghost ghost);


    //other methods
    void draw();
    void move(double x, double y);
    void resetPosition();

    // boundary testing functions
    void testBounds();
    bool testRightBounds();
    bool testLeftBounds();
    bool testUpperBounds();
    bool testLowerBounds();





    //getters and setters
    int getBottomY();
    int getCentY();


};


#endif //FINALPROJECT_CHARTREUSE_CHARACTER_H
