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

public:
    virtual void draw() const = 0;

};


#endif //FINALPROJECT_CHARTREUSE_SHAPES_H
