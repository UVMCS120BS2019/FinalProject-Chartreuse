//
// Created by Mary Woolley on 2019-04-18.
//

#ifndef graphics_h
#define graphics_h

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>

#endif
#include "character.h"

//using GLUT
void init();
void initGL();

//displaying and drawing the fuctions
void display();
void displayStart();
void displayGame();
void displayHelp();
void displayResults();


// Trap and process alphanumeric keyboard events
void kbd(unsigned char key, int x, int y);

// Trap and process special keyboard events
void kbdS(int key, int x, int y);

// Handle "mouse cursor moved" events
void cursor(int x, int y);

// Calls itself after a specified time
void timer(int dummy);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);

//bool collisionCheck(Ghost ghost);

#endif /* graphics_h */

//class graphics {
//
//};