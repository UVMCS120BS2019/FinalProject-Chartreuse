//
// Created by vgwse on 4/23/2019.
//

#include "ghost.h"

//Variables and vectors
int x;
int y;
Circle head;
LongSquare leg1;
Circle halfCircleLeg;
Circle halfCircleLeg2;
Circle halfCircleLeg3;
Circle eye1;
Circle eye2;
Circle mouth;
vector<Shape*> ghost;
LongSquare collisionSquare;

//Define Private methods
//This creates all the parts for the ghost and puts them in the right order
void Ghost::createGhostSkele(int x, int y){
    head.setCenter(x-12 ,y);
    collisionSquare = LongSquare({0.4, 0.4, 0.4, 0}, {x,y}, 20,30);
    head.setRadius(24);
    leg1=LongSquare({1,1,1,1},{x - 12 , y + 12 }, 40, 48);
    halfCircleLeg.setCenter(x - 26 ,y+28);
    halfCircleLeg.setRadius(10);
    halfCircleLeg2.setCenter(x-10,y+29);
    halfCircleLeg2.setRadius(10);
    halfCircleLeg3.setCenter(x+2,y+28);
    halfCircleLeg3.setRadius(10);
    eye1.setColor(0,0,0,1);
    eye1.setCenter(x - 20 ,y );
    eye1.setRadius(8.5);
    eye2.setColor(0,0,0,1);
    eye2.setCenter(x  , y );
    eye2.setRadius(8.5);
    mouth.setColor(0,0,0,1);
    mouth.setCenter(x - 10 , y + 15 );
    mouth.setRadius(7.5);

}


//This adds the parts of the ghost to the vector
void Ghost::addGhost(){
    ghost.push_back(new Circle(head));
    ghost.push_back(new LongSquare(leg1));
    ghost.push_back(new Circle(halfCircleLeg));
    ghost.push_back(new Circle(halfCircleLeg2));
    ghost.push_back(new Circle(halfCircleLeg3));
    ghost.push_back(new Circle(eye1));
    ghost.push_back(new Circle (eye2));
    ghost.push_back(new Circle (mouth));

}

Ghost::Ghost() {
    createGhostSkele(100,100);
}

Ghost::Ghost(int x, int y) {
    createGhostSkele(x, y);
}


//This call the draw function for each part of the ghost
void Ghost::drawGhost(){
    for (Shape* &ghoul:ghost){
        ghoul->draw();
    }
}


//Define Public methods
//This calls all the private and public methods and assembles the ghost
void Ghost::completedGhost(Ghost ghoul){
    ghoul.createGhostSkele(100,100);
    ghoul.addGhost();
    ghoul.drawGhost();
}

void Ghost::ghostMove(double x, double y) {
    head.moveCenter(x,y);
    leg1.moveCenter(x,y);
    halfCircleLeg.moveCenter(x,y);
    halfCircleLeg2.moveCenter(x,y);
    halfCircleLeg3.moveCenter(x,y);
    eye1.moveCenter(x,y);
    eye2.moveCenter(x,y);
    mouth.moveCenter(x,y);
}
//
//void Ghost::track(int x) {
//    while (true) {
//        if (x < 800) {
//
//
//        }
//    }
//}