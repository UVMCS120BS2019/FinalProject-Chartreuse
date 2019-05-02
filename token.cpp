//
// Created by vgwse on 4/23/2019.
//

#include "token.h"


//Define private methods
//This method sets up the skeleton for the token 
void Token::createTokenSkele(int x, int y)  {
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

    token.emplace_back(&collisionCheck);
    token.emplace_back(&tokenCircle);
    token.emplace_back(&tokenLayer);
}



//This method draws the token
void Token::drawToken()  {
    for (Shape *tk: token){
        tk->draw();
    }
}


void Token::setLocation(int x, int y) {
    createTokenSkele(x,y);
}

bool Token::tokenCollision(int x, int y) {

    if(x < collisionCheck.getRightX() && x < collisionCheck.getLeftX()) {
        if(y < collisionCheck.getBottomY() && y > collisionCheck.getTopY()) {
            return true;
        }
    }
    return false;
}

