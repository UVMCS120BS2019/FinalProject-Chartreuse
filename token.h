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
    Circle tokenCircle;
    Circle tokenLayer;
    vector<Shape*> token;


    //Create the token skeleton
    void createTokenSkele();

    //Push token to the vector in a specific order
    void addToken();

    //Construct token
    void drawToken();

public:

    //Place the completed token together
    void completedToken(Token token1);

    //STILL THINKING ABOUT
    //Getters
    //Get the location of the ghost
    //int getLocation(int x, int y);


    //Setters
    //Set the location of the ghost
    //int setLocation(int x, int y);

    //Create a method to move the ghost
    //void  ghostMove();

    //Create a method for the color of the ghost to change
    //void ghostColor();

};


#endif //FINALPROJECT_CHARTREUSE_TOKEN_H
