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
void Key::createKeySkele() {
    keyCircle.setColor(1,.8,0);
    keyCircle.setCenter(500,300);
    keyCircle.setRadius(15);
    keyOpening.setColor(0,0,0);
    keyOpening.setCenter(500,300);
    keyOpening.setRadius(10);
    base=LongSquare({1,.8,0},{500,320},50, 10);
    topKey=LongSquare({1,.8,0},{510,325},6, 10);
    bottomKey=LongSquare({1,.8,0},{510,338},6, 10);
}


//This method adds the parts of the key to the vector
void Key::addKey() {
    key.push_back(new Circle(keyCircle));
    key.push_back(new LongSquare(base));
    key.push_back(new LongSquare(topKey));
    key.push_back(new LongSquare(bottomKey));
    key.push_back(new Circle(keyOpening));

}

//This method draws the key
void Key::drawKey()  {
    for (Shape* &ky: key){
        ky->draw();
    }
}

//Define Public method
//Uses all the private methods to make the key
void Key::completedKey(Key key1) {
    key1.createKeySkele();
    key1.addKey();
    key1.drawKey();
}