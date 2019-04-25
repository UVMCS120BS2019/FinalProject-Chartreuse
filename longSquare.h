//
// Created by Mary Woolley on 2019-04-18.
//

#ifndef FINALPROJECT_CHARTREUSE_LONGSQUARE_H
#define FINALPROJECT_CHARTREUSE_LONGSQUARE_H

#include "shape.h"

class LongSquare : public Shape {
private:
    color fill;
    point cent;
    unsigned int width;
    unsigned int height;
    double opacity;

public:
    //constructors
    LongSquare();
    LongSquare(color fill, point cent, unsigned int height, unsigned int width);

    //getters
    int getCentX() const;
    int getLeftX() const;
    int getRightX() const;
    int getCentY() const;
    int getTopY() const;
    int getBottomY() const;
    point getCent() const;

    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    double getOpacity() const;
    color getFill() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    void setWidth(unsigned int width);
    void setHeight(unsigned int height);

    void setColor(double red, double green, double blue, double opacity);
    void setColor(color fill);
    void move(int deltaX, int deltaY);
    void resize(unsigned int height, unsigned int width);
    void setCent(int x, int y);

    virtual void draw() const override;
    //void draw() const;
};


#endif //FINALPROJECT_CHARTREUSE_LONGSQUARE_H
