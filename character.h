//
// Created by Mary Woolley on 2019-04-21.
//

#ifndef FINALPROJECT_CHARTREUSE_CHARACTER_H
#define FINALPROJECT_CHARTREUSE_CHARACTER_H

#include <vector>

#include "longSquare.h"
#include "circle.h"

using namespace std;

class Character {
private:
    //vector of body parts
    vector<Shape*> body;
    Circle torso1, torso2, leg1, leg2, head, nose, tail;

public:
    //constructors
    Character();

    //other methods
    void draw();
    void move(double x, double y);
    void resetPosition();

    //getters and setters
    int getBottomY();
    int getCentY();


};


#endif //FINALPROJECT_CHARTREUSE_CHARACTER_H
