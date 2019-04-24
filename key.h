//
// Created by vgwse on 4/23/2019.
//

#ifndef FINALPROJECT_CHARTREUSE_KEY_H
#define FINALPROJECT_CHARTREUSE_KEY_H

#include "circle.h"
#include "longSquare.h"
#include "shape.h"
#include <vector>
using std::vector;

class Key {

private:

    //Variables and vectors
    Circle keyCircle;
    Circle keyOpening;
    LongSquare base;
    LongSquare topKey;
    LongSquare bottomKey;
    vector<Shape*> key;

    //Create the key skeleton
    void createKeySkele();

    //Push key to the vector in a specific order
    void addKey();

    //Construct key
    void drawKey();


public:


    //Place the completed key together
    void completedKey(Key key1);


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


#endif //FINALPROJECT_CHARTREUSE_KEY_H
