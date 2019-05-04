//
// Created by Mary Woolley on 2019-04-21.
//

#include <string>
#include "character.h"

using namespace std;

Character::Character() {
    collisionSquare = LongSquare({0.4,0.4,0.4,0.0}, {35, 105}, 32,37);
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

    setBackground({});
}

void Character::setBackground(vector<LongSquare> background) {
    backgroundMaze = background;
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

// boundary testing functions
void Character::testBounds() {
    while (!testRightBounds()) {
        move(-1, 0);
    }

    while (!testLeftBounds()) {
        move(1, 0);
    }

    while (!testUpperBounds()) {
        move(0, 1);
    }

    while (!testLowerBounds()) {
        move(0, -1);
    }
}

bool Character::testRightBounds() {
    point topRightPoint = {collisionSquare.getRightX(), collisionSquare.getTopY()};
    point bottomRightPoint = {collisionSquare.getRightX(), collisionSquare.getBottomY()};
    for (LongSquare i : backgroundMaze) {
        if (i.inSquare(topRightPoint) || i.inSquare(bottomRightPoint)) {
            return true;
        }
    }
    return false;
}

bool Character::testLeftBounds() {
    point topLeftPoint = {collisionSquare.getLeftX(), collisionSquare.getTopY()};
    point bottomLeftPoint = {collisionSquare.getLeftX(), collisionSquare.getBottomY()};
    for (LongSquare i : backgroundMaze) {
        if (i.inSquare(topLeftPoint) || i.inSquare(bottomLeftPoint)) {
            return true;
        }
    }
    return false;
}

bool Character::testUpperBounds() {
    point topRightPoint = {collisionSquare.getRightX(), collisionSquare.getTopY()};
    point topLeftPoint = {collisionSquare.getLeftX(), collisionSquare.getTopY()};
    for (LongSquare i : backgroundMaze) {
        if (i.inSquare(topRightPoint) || i.inSquare(topLeftPoint)) {
            return true;
        }
    }
    return false;
}

bool Character::testLowerBounds() {
    point bottomRightPoint = {collisionSquare.getRightX(), collisionSquare.getBottomY()};
    point bottomLeftPoint = {collisionSquare.getLeftX(), collisionSquare.getBottomY()};
    for (LongSquare i : backgroundMaze) {
        if (i.inSquare(bottomRightPoint) || i.inSquare(bottomLeftPoint)) {
            return true;
        }
    }
    return false;
}

LongSquare Character::getCollisionSquare() {
    return collisionSquare;
}