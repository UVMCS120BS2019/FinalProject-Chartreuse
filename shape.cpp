//
// Created by Mary Woolley on 2019-04-18.
//

#include "shape.h"

Shape::Shape() {
    cent = {0,0};
    fill = {1,1,1};
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

void Shape::setColor(double newRed, double newGreen, double newBlue) {
    fill.red = newRed;
    fill.green = newGreen;
    fill.blue = newBlue;
}

Shape::~Shape() {

}