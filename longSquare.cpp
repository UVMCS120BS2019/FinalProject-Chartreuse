//
// Created by Mary Woolley on 2019-04-18.
//
#include <iostream>
#include <vector>
#include "longSquare.h"
#include "graphics.h"

LongSquare::LongSquare() {
    fill = {0,0,0};
    cent = {0,0};
    height = 30;
    width = 50;
}

LongSquare::LongSquare(color fill, point cent, unsigned int height, unsigned int width) {
    this->fill = fill;
    this->cent = cent;
    this->height = height;
    this->width = width;
}

//get that center point
point LongSquare::getCent() const {
    return cent;
}
int LongSquare::getCentX() const {
    return cent.x;
}
int LongSquare::getCentY() const {
    return cent.y;
}
void LongSquare::setCent(int x, int y) {
    cent = {x, y};
}

//box, like, corner points
int LongSquare::getLeftX() const {
    return cent.x - (width/2);
}
int LongSquare::getRightX() const {
    return cent.x + (width/2);
}
int LongSquare::getTopY() const {
    return cent.y - (height/2);
}
int LongSquare::getBottomY() const {
    return cent.y + (height/2);
}
void LongSquare::move(int moveX, int moveY) {
    cent.x +=moveX;
    cent.y +=moveY;
}
void LongSquare::resize(unsigned int height, unsigned int width){
    this->height = height;
    this->width = width;
}

//make the color
color LongSquare::getFill() const {
    return fill;
}
double LongSquare::getRed() const {
    return fill.red;
}
double LongSquare::getGreen() const {
    return fill.green;
}
double LongSquare::getBlue() const {
    return fill.blue;
}
void LongSquare::setColor(double red, double green, double blue) {
    fill = {red, green, blue};
}
void LongSquare::setColor(color fill) {
    this->fill = fill;
}

//height and width
unsigned int LongSquare::getHeight() const {
    return height;
}
unsigned int LongSquare::getWidth() const {
    return width;
}

//DRAWing
/*void LongSquare::draw() const {

    glColor3f(getRed(), getGreen(), getBlue());
    glBegin(GL_QUADS);

    glVertex2i(getLeftX(), getTopY());
    glVertex2i(getRightX(), getTopY());
    glVertex2i(getRightX(), getBottomY());
    glVertex2i(getLeftX(), getBottomY());

    glEnd();
}*/