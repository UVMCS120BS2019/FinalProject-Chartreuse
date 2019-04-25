//
// Created by Mary Woolley on 2019-04-18.
//

#include "shape.h"

Shape::Shape() {
    cent = {0,0};
    fill = {1,1,1,1};
}

Shape::Shape(color col, point cent) {
    this->cent = cent;
    fill = col;
}

point Shape::getCenter() {
    return cent;
}

color Shape::getColor() {
    return fill;
}

void Shape::setCenter(int chooseX, int chooseY) {
    cent.x = chooseX;
    cent.y = chooseY;
}

void Shape::setColor(double newRed, double newGreen, double newBlue, double newOpacity) {
    fill.red = newRed;
    fill.green = newGreen;
    fill.blue = newBlue;
    fill.opacity = newOpacity;
}

void Shape::moveCenter(int changeX, int changeY) {
    cent.x+= changeX;
    cent.y+= changeY;
}

Shape::~Shape() {

}