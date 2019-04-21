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
    LongSquare torso, arms, legs;
    Circle head;

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
