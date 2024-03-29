//
// Created by vgwse on 4/23/2019.
//

#ifndef FINALPROJECT_CHARTREUSE_KEY_H
#define FINALPROJECT_CHARTREUSE_KEY_H

#include "circle.h"
#include "longSquare.h"
#include "character.h"
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
    LongSquare keySpace;
    vector<Shape*> key;




    // clears everything in key vector
    void deleteKey();

public:

    // constructors
    Key();
    Key(int x, int y);

    //Push key to the vector in a specific order
    void addKey();

    //Create the key skeleton using center (x, y)
    void createKeySkele(int x, int y);

    // draw key
    void drawKey();

    void checkKey(Character &meghan);

    bool isHidden()const;

    void hide();
    void unhide();

    LongSquare getKeySpace();

};


#endif //FINALPROJECT_CHARTREUSE_KEY_H
