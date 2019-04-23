//
// Created by Mary Woolley on 2019-04-18.
//


#include <iostream>
#include <vector>
#include <iomanip>

#include "graphics.h"
#include "button.h"

using namespace std;

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

// Enum for the different screen
enum Screen {start, help, game, results};
Screen window;

// vector for longsquare background
vector<LongSquare> tiles;

void init() {
    // Set the window to the welcome page
    window = start;

    for (int i = 10; i <= 331; i += 40) {
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {i, 110}, 20, 20));
        tiles.push_back(LongSquare({0.5, 0.5, 0.5}, {i, 130}, 20, 20));
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {i, 150}, 20, 20));
    }
}

void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
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

    playGame.draw();
    helpGame.draw();

}
void displayHelp(){
    string helpMsg1 = "Having trouble?";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2i(WIDTH/2-120, HEIGHT/2 + 150 );
    for (char &letter : helpMsg1) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }
    string helpMsg2 = "Using your arrow keys to navigate the maze.";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2i(WIDTH/2-120, HEIGHT/2 + 170 );
    for (char &letter : helpMsg2) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, letter);
    }
    string helpMsg3 = "Avoid colliding with the ghosts!";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2i(WIDTH/2-120, HEIGHT/2 + 190 );
    for (char &letter : helpMsg3) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, letter);
    }
}

void displayGame() {

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