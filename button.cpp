//
// Created by Mary Woolley on 2019-04-18.
//

#include "button.h"
#include "graphics.h"

using namespace std;

//constructors
Button::Button() {
    fill = {0, 0, 0};

}

Button::Button(LongSquare ls, string label){
    this->ls = ls;
    this->label = label;
    fill = ls.getFill();
}
//draw the rectangle
void Button::draw() {
     ls.draw();
     glColor3f(1, 1, 1);
     glRasterPos2i(ls.getCentX()-(4*label.length()), ls.getCentY()+7);
     for (char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, letter);
     }
}

// Change color of the box when the user is hovering over it
void Button::hover() {
    ls.setColor(fill.red + 0.3, fill.green + 0.3, fill.blue + 0.3);
}

bool Button::isOverlapping(int x, int y) const {
    if (x > ls.getLeftX() && x < ls.getRightX() && y > ls.getTopY() && y < ls.getBottomY()) {
        return true;
    }
    else {
        return false; // Placeholder for compilation
    }
}


Button::~Button() {

}