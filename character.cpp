//
// Created by Mary Woolley on 2019-04-21.
//

#include <string>
#include "character.h"

using namespace std;

Character::Character() {
    collisionSquare = LongSquare({0,0,1,0}, {35, 105}, 32,37);
    torso1 = Circle({1,1,1}, {30, 110}, 10);
    torso2 = Circle({1,1,1}, {35, 110}, 10);
    leg1 = Circle({0,0,0}, {42, 120}, 3);
    leg2 = Circle({0,0,0}, {23, 120}, 3);
    head = Circle({1,1,1}, {43, 97}, 8);
    nose = Circle({0,0,0}, {51, 97}, 3);
    tail = Circle({0,0,0}, {20, 100}, 3);

    body.emplace_back(&collisionSquare);
    body.emplace_back(&torso1);
    body.emplace_back(&torso2);
    body.emplace_back(&leg1);
    body.emplace_back(&leg2);
    body.emplace_back(&head);
    body.emplace_back(&nose);
    body.emplace_back(&tail);

}

void Character::draw() {
    for(Shape *shape: body) {
        shape-> draw();
    }
}



void Character::move(double x, double y) {
    torso1.moveCenter(x,y);
    torso2.moveCenter(x,y);
    leg1.moveCenter(x,y);
    leg2.moveCenter(x,y);
    head.moveCenter(x,y);
    nose.moveCenter(x,y);
    tail.moveCenter(x,y);
    collisionSquare.move(x,y);
}

//void Character::resetPosition() {
//    torso.move(30,100);
//    arms.move(30,100);
//    legs.move(30,100);
//    head.moveCenter(30,100);
//}

//int Character::getBottomY() {
//
//}
//
//int Character::getCentY() {
//
//}