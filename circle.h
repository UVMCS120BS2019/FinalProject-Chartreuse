//
// Created by Mary Woolley on 2019-04-21.
//

#ifndef FINALPROJECT_CHARTREUSE_CIRCLE_H
#define FINALPROJECT_CHARTREUSE_CIRCLE_H

#include <cmath>

#include "shape.h"

const double pi = 3.1415926;

class Circle : public Shape {
private:
    double radius;
public:
    //constructors
    Circle();
    Circle(color col, point cent, double radius);

    //getters and setters
    double getRadius();
    void setRadius(double radius);

    //virtual methods
    virtual void draw() const override;
};


#endif //FINALPROJECT_CHARTREUSE_CIRCLE_H
