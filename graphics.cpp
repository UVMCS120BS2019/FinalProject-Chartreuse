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
#include "token.h"
#include "key.h"

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
//return to menu button
LongSquare returnButton({0,0,0}, {WIDTH/5, HEIGHT/5}, 120, 50);
Button returnToMenu(returnButton, " <- Back to menu");
// play again button
LongSquare playAgainBox({0,0,0}, {WIDTH/2, HEIGHT/2}, 120, 50);
Button playAgainButton(playAgainBox, "Play Again");
// play again button
LongSquare backToMenuBox({0,0,0}, {WIDTH/2, HEIGHT/2 + 70}, 120, 50);
Button backToMenuButton(backToMenuBox, "Back to Menu");

//make a character
Character meghan;
Ghost one;
Key key1(650, 210);
Token token1;

//make ghost
Ghost ghosty;

// bool for if game won
bool gameWon = false;

// Enum for the different screen
enum Screen {start, help, game, results};
Screen window;

// vector of longsquares for background tiles
vector<LongSquare> tiles;

void init() {
    // Set the window to the welcome page
    window = start;

    // add squares for background maze to tile vector
    for (int i = 10; i <= 310; i += 40) {
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {i, 90}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {i, 110}, 20, 20));
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {i, 130}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {i + 20, 90}, 20, 20));
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {i + 20, 110}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {i + 20, 130}, 20, 20));
    }

    for (int i = 150; i <= 430; i += 40) {
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {270, i}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {290, i}, 20, 20));
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {310, i}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {270, i + 20}, 20, 20));
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {290, i + 20}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {310, i + 20}, 20, 20));
    }

    for (int i = 330; i < 800; i += 40) {
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {i, 410}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {i, 430}, 20, 20));
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {i, 450}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {i + 20, 410}, 20, 20));
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {i + 20, 430}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {i + 20, 450}, 20, 20));
    }

    for (int i = 190; i <= 390; i += 40) {
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {510, i}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {530, i}, 20, 20));
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {550, i}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {510, i + 20}, 20, 20));
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {530, i + 20}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {550, i + 20}, 20, 20));
    }

    for (int i = 570; i <= 650; i += 40) {
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {i, 190}, 20, 20));
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {i, 210}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {i, 230}, 20, 20));
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {i + 20, 190}, 20, 20));
        tiles.push_back(LongSquare({0.4, 0.4, 0.4}, {i + 20, 210}, 20, 20));
        tiles.push_back(LongSquare({0.2, 0.2, 0.2}, {i + 20, 230}, 20, 20));
    }
    // end adding squares to tile vector

    meghan.setBackground(tiles);
}

void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            meghan.move(0, 5);
            meghan.testBounds();
            break;
        case GLUT_KEY_LEFT:
            meghan.move(-5, 0);
            meghan.testBounds();
            break;
        case GLUT_KEY_RIGHT:
            meghan.move(5, 0);
            meghan.testBounds();
            break;
        case GLUT_KEY_UP:
            meghan.move(0, -5);
            meghan.testBounds();
            break;
    }
    key1.checkKey(meghan);
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
    /* string game1 = "You found the game screen!";
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2i(WIDTH/2-120, HEIGHT/2 + 110 );
    for (char &letter : game1) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    } */
    for (LongSquare i : tiles) {
        i.draw();
    }

    meghan.draw();
    ghosty.completedGhost(ghosty);


    one.completedGhost(one);
    key1.drawKey();
    token1.setLocation(200,200);
    token1.drawToken();

}
void displayResults() {
    string resultsMessage;
    if (gameWon == false) {
        resultsMessage = "You Died";
        glColor3f(1.0f, 1.0f, 1.0f);
        glRasterPos2i(WIDTH/2 - 48, HEIGHT/2 - 100);
        for (char &letter : resultsMessage) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
        }
    } else {
        resultsMessage = "You Won !";
        glColor3f(1.0f, 1.0f, 1.0f);
        glRasterPos2i(WIDTH/2 - 48, HEIGHT/2 - 100);
        for (char &letter : resultsMessage) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
        }
    }

    playAgainButton.draw();
    backToMenuButton.draw();
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

    if (window == results) {
        if (playAgainButton.isOverlapping(x,y) and button == GLUT_LEFT_BUTTON) {
            window = game;
            gameWon = false;
            meghan.resetPosition();
            if (playAgainButton.isOverlapping(x,y)) {
                if(button == GLUT_LEFT_BUTTON) {
                    window = game;
                    gameWon = false;
                    meghan.resetPosition();
                }
            }
        } else if (backToMenuButton.isOverlapping(x,y) and button == GLUT_LEFT_BUTTON) {
            window = start;
            gameWon = false;
            meghan.resetPosition();
            if (backToMenuButton.isOverlapping(x,y)) {
                if(button == GLUT_LEFT_BUTTON) {
                    window = start;
                    gameWon = false;
                    meghan.resetPosition();
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