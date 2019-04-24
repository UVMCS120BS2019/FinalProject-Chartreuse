//
// Created by Mary Woolley on 2019-04-21.
//

#include <string>
#include "character.h"

using namespace std;

Character::Character() {
    torso = LongSquare({1,1,1}, {30,110}, 20,20);
    arms = LongSquare({1,1,1}, {30,100}, 20, 20);
    legs = LongSquare({1,1,1}, {30,100}, 20, 20);
    head = Circle({1,1,1}, {30,100}, 10);

    body.emplace_back(&torso);
    body.emplace_back(&arms);
    body.emplace_back(&legs);
    body.emplace_back(&head);
}

void Character::draw() {
    for(Shape *shape: body) {
        shape-> draw();
    }
}

void Character::move(double x, double y) {
    torso.move(x,y);
    arms.move(x,y);
    legs.move(x,y);
    head.moveCenter(x,y);
}

void Character::resetPosition() {

}

//int Character::getBottomY() {
//
//}
//
//int Character::getCentY() {
//
//}