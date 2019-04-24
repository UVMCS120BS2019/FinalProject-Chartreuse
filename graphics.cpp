//
// Created by Mary Woolley on 2019-04-18.
//


#include <iostream>
#include <vector>
#include <iomanip>

#include "graphics.h"
#include "button.h"
#include "circle.h"
#include "character.h"
#include "ghost.h"

using namespace std;


Circle trialCircle;


//setting the window size
const int WIDTH = 800, HEIGHT = 600;
GLdouble width= WIDTH, height= HEIGHT;
int wd;

//play button
LongSquare gameButton({0,0,0}, {WIDTH/2, HEIGHT/3}, 120, 50);
Button playGame(gameButton, "Play");
//help button
LongSquare helpButton({0,0,0}, {WIDTH/2, HEIGHT/2}, 120, 50);
Button helpGame(helpButton, "Get Help");
//return to menu button
LongSquare returnButton({0,0,0}, {WIDTH/5, HEIGHT/5}, 120, 50);
Button returnToMenu(returnButton, " <- Back to menu");

//make a character
Character meghan;

// Enum for the different screen
enum Screen {start, help, game, results};
Screen window;

void init() {
    // Set the window to the welcome page
    window = start;
}

void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            meghan.move(x, y);
            break;
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_UP:
            break;
    }

    glutPostRedisplay();
}

void display() {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //switching screens
    switch(window) {
        case start: displayStart();
            break;
        case help: displayHelp();
            break;
        case game: displayGame();
            break;
        case results: displayResults();
            break;
    }

    glFlush();
}

void displayStart() {
    Ghost one;
    one.completedGhost(one);
    Circle key;
    LongSquare base;
    LongSquare topKey;
    LongSquare bottomKey;
    key.setColor(1,.8,0);
    key.setCenter(500,300);
    key.setRadius(15);
    base=LongSquare({1,.8,0},{500,320},50, 10);
    topKey=LongSquare({1,.8,0},{510,325},6, 10);
    bottomKey=LongSquare({1,.8,0},{510,338},6, 10);
    key.draw();
    base.draw();
    topKey.draw();
    bottomKey.draw();
    playGame.draw();
    helpGame.draw();

}
void displayHelp(){
    string helpMsg1 = "Having trouble?";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2i(WIDTH/2-120, HEIGHT/2);
    for (char &letter : helpMsg1) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }
    string helpMsg2 = "Using your arrow keys to navigate the maze.";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2i(WIDTH/2-120, HEIGHT/2 + 50 );
    for (char &letter : helpMsg2) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, letter);
    }
    string helpMsg3 = "Avoid colliding with the ghosts!";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2i(WIDTH/2-120, HEIGHT/2 + 80 );
    for (char &letter : helpMsg3) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, letter);
    }

    returnToMenu.draw();

}

void displayGame() {
    string game1 = "You found the game screen!";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2i(WIDTH/2-120, HEIGHT/2 + 110 );
    for (char &letter : game1) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }

    meghan.draw();

}
void displayResults() {

}

//make the cursor work on the window
void cursor(int x, int y) {
    glutPostRedisplay();
}

//key functions
void kbd(unsigned char key, int x, int y){
    if (key == 'h') {
        window = help;
    }
    else if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    glutPostRedisplay();
}

void timer(int dummy) {

}

//mouse clicking on stuff
void mouse(int button, int state, int x, int y) {
    if(window == start) {
        if (playGame.isOverlapping(x, y) and button == GLUT_LEFT_BUTTON){
            window = game;
            if (playGame.isOverlapping(x,y)) {
                if(button == GLUT_LEFT_BUTTON) {
                    window = game;
                }
            }
        }
        else if (helpGame.isOverlapping(x, y) and button == GLUT_LEFT_BUTTON){
            window = help;
            if (helpGame.isOverlapping(x,y)) {
                if(button == GLUT_LEFT_BUTTON) {
                    window = help;
                }
            }
        }
    }
    if (window == help) {
        if (returnToMenu.isOverlapping(x,y) and button == GLUT_LEFT_BUTTON) {
            window = start;
            if (returnToMenu.isOverlapping(x,y)) {
                if (button ==GLUT_LEFT_BUTTON) {
                    window = start;
                }
            }
        }
    }

}


int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(-200,-100); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Escape Dungeon" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();

    return 0;
}