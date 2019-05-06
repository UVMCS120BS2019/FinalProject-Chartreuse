//
// Created by vgwse on 4/23/2019.
//

#include "ghost.h"
#include <iostream>


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
bool hit;
vector<Shape*> ghost;
LongSquare collisionSquare;

int i = 0;


//Define Private methods
//This creates all the parts for the ghost and puts them in the right order
void Ghost::createGhostSkele(int x, int y){
    deleteGhost();
    head.setCenter(x-12 ,y);
    collisionSquare = LongSquare({0.4, 0.4, 0.4, 0}, {x,y}, 45,50);
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
    addGhost();
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

void Ghost::deleteGhost() {
    ghost.clear();
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

point Ghost::getCollisionSquareCenter() {
    return collisionSquare.getCenter();
}


bool Ghost::checkGhost(Character &meghan) {
    std::cout << meghan.getCollisionSquare().getBottomY() << std::endl;
    std::cout << collisionSquare.getTopY() << std::endl;
    //std::cout = meghan.getCollisionSquare().getCentX();
//    if (collisionSquare.getLeftX() - collisionSquare.getRightX() < meghan.getCollisionSquare().getLeftX() + meghan.getCollisionSquare().getRightX()) {
//        //check the Y axis
//
//        if (abs(this->collisionSquare.getTopY() - this->collisionSquare.getBottomY()) < meghan.getCollisionSquare().getTopY() + meghan.getCollisionSquare().getBottomY()) {
//            hit = true;
//        }
//    }
//    if ((meghan.getCollisionSquare().getRightX()>= collisionSquare.getLeftX()) &&
//        meghan.getCollisionSquare().getBottomY()<= collisionSquare.getBottomY()){
//        std::cout<<"You hit the ghost, that's pretty fucking RUDE!"<<std::endl;
//    }
//    else if((collisionSquare.getLeftX() >= meghan.getCollisionSquare().getRightX()) &&
//              collisionSquare.getBottomY()<=meghan.getCollisionSquare().getBottomY() ){
//        std::cout<<"case 2!"<<std::endl;
//
//    }
//    return hit;
//}




    if ((this->collisionSquare.getLeftX() <= meghan.getCollisionSquare().getCentX() &&
         (meghan.getCollisionSquare().getCentX() <= this->collisionSquare.getRightX())) &&
        ((this->collisionSquare.getTopY() <= meghan.getCollisionSquare().getTopY()) &&
         (meghan.getCollisionSquare().getTopY() < this->collisionSquare.getBottomY()))) {
        hit = true;
        std::cout << "You hit the ghost, that's pretty fucking RUDE!" << std::endl;
    }
    else if()

    return hit;
}



void Ghost::ghostMove(double x, double y) {
    collisionSquare.move(x, y);
    collisionSquare.moveCenter(x, y);
    head.moveCenter(x,y);
    leg1.move(x,y);
    halfCircleLeg.moveCenter(x,y);
    halfCircleLeg2.moveCenter(x,y);
    halfCircleLeg3.moveCenter(x,y);
    eye1.moveCenter(x,y);
    eye2.moveCenter(x,y);
    mouth.moveCenter(x,y);
}

void Ghost::track(int deltaX) {
    deleteGhost();
    if (i < deltaX) {
        ghostMove(5, 0);
        std::cout << collisionSquare.getCenter().x << std::endl;
        std::this_thread::sleep_for(std::chrono::nanoseconds(250000000));
    } else if (i >= deltaX) {
        ghostMove(-5, 0);
        std::cout << collisionSquare.getCenter().x << std::endl;
        std::this_thread::sleep_for(std::chrono::nanoseconds(250000000));
    }
    std::cout << i << std::endl;
    i += 5;
    if (i == (2 * deltaX)) {
        i = 0;
    }

}