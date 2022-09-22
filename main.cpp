// Jaonuario set/2022
//fazer em lista os pontos

#include "main.hpp"
#include <GL/gl.h>
#include <cstddef>
#include <iostream>

#define SIZE_X 500 
#define SIZE_Y 500

Rgb pencil = BLACK;
Rgb** matrixPx = NULL;

int main(int argc, char** argv)
{
    if(matrixPx == NULL)
    {
        matrixPx = new Rgb*[500];

        for(int i = 0; i < 500; i++)
        {
            matrixPx[i] = new Rgb[500];
            for(int j = 0; j < 500; j++)
            {
                matrixPx[i][j] = GREEN;
            }
        }
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(430, 130);
    glutCreateWindow("Eventos");

    glutKeyboardFunc(KeyboardManager);
    glutMouseFunc(MouseManager);

    glutDisplayFunc(Draw);
    Inicialize();

    glutMainLoop();
}

void Inicialize()
{
    glClearColor(0.0, 0.5, 0.2, 1.0);
    glPointSize(5.0f);
    gluOrtho2D(0.0, 500.0, 500.0, 0.0);
}

void MouseManager(int button, int state, int x, int y)
{
    //Evento de mudança de estado
    if(button == GLUT_LEFT_BUTTON)
    {
        //evento especifico
        if(state == GLUT_DOWN)
            matrixPx[x][y] = pencil;
    }

    glutPostRedisplay();
}

void KeyboardManager(unsigned char key, int x, int y)
{
    switch (key) {
        case 'C':
        case 'c':
            for(int cordY = 0; cordY < 500; cordY++)
            {
                for(int cordX = 0; cordX < 500; cordX++)
                    matrixPx[cordX][cordY] = GREEN;
            }
            break;

        case 'R':
        case 'r':
            pencil = RED;
            pencil.activia = true;
            break;

        case 'G':
        case 'g':
            pencil = GREEN;
            pencil.activia = true;
            break;

        case 'B':
        case 'b':
            pencil = BLUE;
            pencil.activia = true;
            break;
        
        case 'W':
        case 'w':
            pencil = WHITE;
            pencil.activia = true;
            break;
        
        case 'X':
        case 'x':
            pencil = BLACK;
            pencil.activia = true;
            break;
    }

    glutPostRedisplay();
}

void Draw()
{
    Rgb* aux;

    glViewport(0, 0, 500, 500);

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);
    for(int cordY = 0; cordY < 500; cordY++)
    {
        for(int cordX = 0; cordX < 500; cordX++)
        {
            aux = &matrixPx[cordX][cordY];
            if(aux->activia)
            {
                //pinta a tela
                glColor3f(aux->red, aux->green, aux->blue);
                glVertex2i(cordX, cordY);
            }
        }
    }
    glEnd();
    glFlush();
}