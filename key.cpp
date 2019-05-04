//
// Created by vgwse on 4/23/2019.
//

#include "key.h"
#include <iostream>

Circle keyCircle;
Circle keyOpening;
LongSquare base;
LongSquare topKey;
LongSquare bottomKey;
bool hidden;
vector<Shape*> key;


void Key::createKeySkele(int x, int y) {
    deleteKey();
    keySpace = LongSquare({0.4, 0.4, 0.4}, {x, y}, 60, 30);
    keyCircle.setColor(1,.8,0,1);
    keyCircle.setCenter(x, y - 15);
    keyCircle.setRadius(15);
    keyOpening.setColor(1,0,1,1);
    keyOpening.setCenter(x, y - 15);
    keyOpening.setRadius(10);
    base=LongSquare({1,.8,0},{x, y + 5},50, 10);
    topKey=LongSquare({1,.8,0},{x + 10, y + 10},6, 10);
    bottomKey=LongSquare({1,.8,0},{x + 10, y + 23},6, 10);
    addKey();
    hidden = false;
}


void Key::addKey() {
    key.push_back(new LongSquare(keySpace));
    key.push_back(new Circle(keyCircle));
    key.push_back(new LongSquare(base));
    key.push_back(new LongSquare(topKey));
    key.push_back(new LongSquare(bottomKey));
    key.push_back(new Circle(keyOpening));
}



void Key::deleteKey() {
    key.clear();
}

Key::Key() {
    createKeySkele(670, 180);
}

Key::Key(int x, int y) {
    createKeySkele(x, y);
}


void Key::drawKey()  {
    if (!hidden) {
        for (Shape *&ky: key) {
            ky->draw();
        }
    }
}

LongSquare Key::getKeySpace() {
    return keySpace;
}


void Key::checkKey(Character &meghan) {
    std::cout<<keySpace.getLeftX()<<std::endl;
    std::cout<<meghan.getCollisionSquare().getRightX()<<std::endl;
    if ((meghan.getCollisionSquare().getRightX()>=keySpace.getLeftX()) &&
        meghan.getCollisionSquare().getBottomY()<=keySpace.getBottomY()){
            deleteKey();
            hidden = true;
        }
    }

bool Key::isHidden() const {
    return hidden;
}

void Key::hide() {
    hidden = true;
}