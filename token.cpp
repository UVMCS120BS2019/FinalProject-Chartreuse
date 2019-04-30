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
void Token::createTokenSkele()  {
    tokenCircle.setCenter(200,200);
    tokenCircle.setRadius(30);
    tokenCircle.setColor(1,.6,0,1);
    tokenLayer.setCenter(200,200);
    tokenLayer.setRadius(20);
    tokenLayer.setColor(1,.9,0,1);
}


//This method adds the parts of the token to the vector
void Token::addToken()  {
    token.push_back(new Circle(tokenCircle));
    token.push_back(new Circle(tokenLayer));

}

//This method draws the token
void Token::drawToken()  {
    for (Shape* &tk: token){
        tk->draw();
    }
}

//Define Public method
//Uses all the private methods to make the token
void Token::completedToken(Token token1) {
    token1.createTokenSkele();
    token1.addToken();
    token1.drawToken();
}