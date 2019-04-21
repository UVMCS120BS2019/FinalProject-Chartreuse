//
// Created by Mary Woolley on 2019-04-18.
//

#ifndef FINALPROJECT_CHARTREUSE_BUTTON_H
#define FINALPROJECT_CHARTREUSE_BUTTON_H

#include <string>
#include <functional>
#include "longSquare.h"

using std::string;

class Button {
private:
    //make a rectangle for the button
    LongSquare ls;
    //make a label
    std::string label;
    //button fill (color will be from our rectangle)
    color fill;

public:
    //constructors
    Button();
    Button(LongSquare ls, string label);

    //other methods
    bool isOverlapping(int x, int y) const;
    void hover();

    //virtual methods
    virtual void draw();
    //virtual void click(std::function<void()> callback);
    virtual ~Button();
};


#endif //FINALPROJECT_CHARTREUSE_BUTTON_H
