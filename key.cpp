//
// Created by vgwse on 4/23/2019.
//

#include "key.h"

//Variables and vectors
Circle keyCircle;
Circle keyOpening;
LongSquare base;
LongSquare topKey;
LongSquare bottomKey;
vector<Shape*> key;

//Define private methods
//This method sets up the skeleton for the key 
void Key::createKeySkele(int x, int y) {
    clearKey();
    keySpace = LongSquare({0.4, 0.4, 0.4}, {x, y}, 60, 30);
    keyCircle.setColor(1,.8,0);
    keyCircle.setCenter(x, y - 15);
    keyCircle.setRadius(15);
    keyOpening.setColor(0,0,0);
    keyOpening.setCenter(x, y - 15);
    keyOpening.setRadius(10);
    base=LongSquare({1,.8,0},{x, y + 5},50, 10);
    topKey=LongSquare({1,.8,0},{x + 10, y + 10},6, 10);
    bottomKey=LongSquare({1,.8,0},{x + 10, y + 23},6, 10);
    addKey();
}


//This method adds the parts of the key to the vector
void Key::addKey() {
    key.push_back(new LongSquare(keySpace));
    key.push_back(new Circle(keyCircle));
    key.push_back(new LongSquare(base));
    key.push_back(new LongSquare(topKey));
    key.push_back(new LongSquare(bottomKey));
    key.push_back(new Circle(keyOpening));
}

// clears key vector
void Key::clearKey() {
    key.clear();
}

Key::Key() {
    createKeySkele(500, 315);
}

Key::Key(int x, int y) {
    createKeySkele(x, y);
}

// changes location of key based on center (x,y)
void Key::setLocation(int x, int y) {
    createKeySkele(x, y);
}

//This method draws the key
void Key::drawKey()  {
    for (Shape* &ky: key){
        ky->draw();
    }
}

