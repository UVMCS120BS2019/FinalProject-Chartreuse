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

//Define Private methods
//This creates all the parts for the ghost and puts them in the right order
void Ghost::createGhostSkele(){
    head.setCenter(300,300);
    head.setRadius(30);
    leg1=LongSquare({1,1,1},{300,320},50, 60);
    halfCircleLeg.setCenter(282,340);
    halfCircleLeg.setRadius(12);
    halfCircleLeg2.setCenter(300,341);
    halfCircleLeg2.setRadius(12);
    halfCircleLeg3.setCenter(318,340);
    halfCircleLeg3.setRadius(12);
    eye1.setColor(0,0,0);
    eye1.setCenter(285,300);
    eye1.setRadius(10);
    eye2.setColor(0,0,0);
    eye2.setCenter(315,300);
    eye2.setRadius(10);
    mouth.setColor(0,0,0);
    mouth.setCenter(300,320);
    mouth.setRadius(9);

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

