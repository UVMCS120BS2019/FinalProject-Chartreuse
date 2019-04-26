//
// Created by Mary Woolley on 2019-04-21.
//
#include "graphics.h"
#include "circle.h"
#define _USE_MATH_DEFINES

using namespace std;

Circle::Circle() {
    radius = 10;
}

Circle::Circle(color col, point cent, double radius) : Shape (col, cent) {
    setRadius(radius);
}

double Circle::getRadius() {
    return radius;
}

void Circle::setRadius(double radius) {
    if (radius > 0) {
        this->radius = radius;
    } else {
        radius = 10;
    }
}

void Circle::draw() const {
    glBegin(GL_TRIANGLE_FAN);
    float radius = this->radius;
    float xGen, yGen;

    glColor3f(fill.red, fill.green, fill.blue);
    //for all 360 degrees, use sin and cos to determine x and y
    for(int angle = 0; angle <= 360; angle++){
        xGen = cent.x + float(cos(angle*(pi/180)) * radius);
        yGen = cent.y + float(sin(angle*(pi/180)) * radius);

        //create a vertex for the given angle
        glVertex2i(xGen, yGen);
    }
    glEnd();

}