// Jaonuario set/2022
/* 
    g++ *.cpp *.hpp -o vai -lglut -lGL -lGLEW -lGLU  
    ./vai &
*/

#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include "rgb.hpp"

int main(int argc, char**argv);
void Draw();
void Inicialize();
void MouseManager(int button, int state, int x, int y);
void KeyboardManager(unsigned char key, int x, int y);
void MouseRace(int x, int y);