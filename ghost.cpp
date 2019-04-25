//
// Created by vgwse on 4/23/2019.
//

#include "ghost.h"

////Variables and vectors
//int x;
//int y;
//Circle head;
//LongSquare leg1;
//Circle halfCircleLeg;
//Circle halfCircleLeg2;
//Circle halfCircleLeg3;
//Circle eye1;
//Circle eye2;
//Circle mouth;
//vector<Shape*> ghost;

//Define Private methods
//This creates all the parts for the ghost and puts them in the right order
void Ghost::createGhostSkele(){
    head.setCenter(300,300);
    head.setRadius(28);
    leg1=LongSquare({1,1,1},{300,320},33, 57);
    halfCircleLeg.setCenter(282,333);
    halfCircleLeg.setRadius(10);
    halfCircleLeg2.setCenter(301,334);
    halfCircleLeg2.setRadius(10);
    halfCircleLeg3.setCenter(318,333);
    halfCircleLeg3.setRadius(10);
    eye1.setColor(0,0,0,1);
    eye1.setCenter(285,300);
    eye1.setRadius(8.5);
    eye2.setColor(0,0,0,1);
    eye2.setCenter(315,300);
    eye2.setRadius(8.5);
    mouth.setColor(0,0,0,1);
    mouth.setCenter(300,320);
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

//This call the draw function for each part of the ghost
void Ghost::drawGhost(){
    for (Shape* &ghoul:ghost){
        ghoul->draw();
    }
}


//Define Public methods
//This calls all the private and public methods and assembles the ghost
void Ghost::completedGhost(Ghost ghoul){
    ghoul.createGhostSkele();
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

void Ghost::track() {
    while (true) {
    }
}