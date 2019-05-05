//
// Created by vgwse on 4/23/2019.
//

#ifndef FINALPROJECT_CHARTREUSE_TOKEN_H
#define FINALPROJECT_CHARTREUSE_TOKEN_H


#include "circle.h"
#include "longSquare.h"
#include "shape.h"
#include <vector>
using std::vector;


class Token {

private:
    //Variables and vectors
    LongSquare collisionCheck;
    Circle tokenCircle;
    Circle tokenLayer;
    vector<Shape*> token;
    bool hidden;


    //Create the token skeleton
    void createTokenSkele(int x, int y);

    //Push token to the vector in a specific order



public:
    //Construct token
    void drawToken();

    //Place the completed token together

    //TODO::Character collisions with the tokens and wracking up a score

    //Getters
    //Get the location of the token
    //int getLocation(int x, int y);

    //is there a collision with the character?
    bool tokenCollision(int x);

    //Setters
    //Set the location of the token
    void setLocation(int x, int y);

    //Create a method for the color of the token to change
    void seeThru();

    bool isHidden() const;

    ~Token();

};


#endif //FINALPROJECT_CHARTREUSE_TOKEN_H
