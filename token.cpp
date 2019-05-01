//
// Created by vgwse on 4/23/2019.
//

#include "token.h"

//Variables and vectors
Circle tokenCircle;
Circle tokenLayer;
vector<Shape*> token;

//Define private methods
//This method sets up the skeleton for the token 
void Token::createTokenSkele(int x, int y)  {
    tokenCircle.setCenter(x,y);
    tokenCircle.setRadius(30);
    tokenCircle.setColor(1,.6,0,1);
    tokenLayer.setCenter(x,y);
    tokenLayer.setRadius(20);
    tokenLayer.setColor(1,.9,0,1);

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