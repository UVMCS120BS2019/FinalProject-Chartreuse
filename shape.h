//
// Created by Mary Woolley on 2019-04-18.
//

#ifndef FINALPROJECT_CHARTREUSE_SHAPES_H
#define FINALPROJECT_CHARTREUSE_SHAPES_H

#include "graphics.h"

//make points
struct point {
    int x;
    int y;
};
//make a color
struct color {
    double red;
    double green;
    double blue;
};

class Shape {
protected:
    point cent;
    color fill;

public:
    //constructors
    Shape();
    Shape(color col, point cent);
    //getters and setters
    point getCenter();
    color getColor();

    void setCenter(int chooseX, int chooseY);
    void setColor(double newRed, double newGreen, double newBlue);
    //other and virtual methods
    void moveCenter(int changeX, int changeY);

    virtual void draw() const = 0;

    virtual ~Shape();

};


#endif //FINALPROJECT_CHARTREUSE_SHAPES_H
