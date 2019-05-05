//
// Created by vgwse on 4/23/2019.
//

#include "token.h"


//Define private methods
//This method sets up the skeleton for the token
Token::Token(int x, int y) {
    createTokenSkele(x, y);
}

void Token::createTokenSkele(int x, int y)  {
    deleteToken();
    tokenCircle.setCenter(x,y);
    tokenCircle.setRadius(15);
    tokenCircle.setColor(1,.6,0,1);
    tokenLayer.setCenter(x,y);
    tokenLayer.setRadius(10);
    tokenLayer.setColor(1,.9,0,1);
    collisionCheck.setCent(x,y);
    collisionCheck.setHeight(15);
    collisionCheck.setWidth(15);
    collisionCheck.setColor(0,0,0,0);

    token.push_back(new LongSquare(collisionCheck));
    token.push_back(new Circle(tokenCircle));
    token.push_back(new Circle(tokenLayer));

    hidden = false;
}



//This method draws the token
void Token::drawToken()  {
    if (!hidden) {
        for (Shape *tk: token) {
            tk->draw();
        }
    }
}

void Token::deleteToken() {
    token.clear();
}


void Token::setLocation(int x, int y) {
    createTokenSkele(x,y);
}

bool Token::tokenCollision(Character &doggo) {

    if(doggo.getCollisionSquare().getRightX() >= collisionCheck.getLeftX() &&
    doggo.getCollisionSquare().getLeftX() <= collisionCheck.getRightX() &&
    doggo.getCollisionSquare().getTopY() >= collisionCheck.getTopY()) {
        deleteToken();
        return true;
    }
    else
        return false;
}

LongSquare Token::getCollisionCheck() {
    return collisionCheck;
}

bool Token::isHidden() const {
    return hidden;
}
void Token::hide() {
    hidden = true;
}

Token::~Token() {

}