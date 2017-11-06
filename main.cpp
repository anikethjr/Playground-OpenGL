#include <bits/stdc++.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include "primitives.h"
#include "camera.h"

using namespace glm;
using namespace std;

Camera cam;

void renderScene(void)
{
    //Clear screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective


    glBegin(GL_QUADS);
    glVertex3d(0,0,0);
    glVertex3d(0.5,0,0);
    glVertex3d(0.5,0.5,0);
    glVertex3d(0,0.5,0);

    glEnd();

    glutSwapBuffers();
}

void idle()
{
    glutPostRedisplay();
}

void keyPress(unsigned char key,int x,int y)
{
    switch(key)
    {

        case 'f':    cam.slide(0,0, 0.2); break; // slide camera forward
        case 'F': cam.slide(0,0,-0.2); break; //slide camera back
            // add up/down and left/right controls
        case 'p':      cam.pitch(-1.0); break;
        case 'P': cam.pitch( 1.0); break;
            // add yaw controls
        case 'y':      cam.yaw(-1.0); break;
        case 'Y': cam.yaw( 1.0); break;
            // add roll controls
        case 'r':      cam.roll(1.0); break;
        case 'R': cam.roll(-1.0); break;
        default: return;
    }
    glutPostRedisplay();
}

void Special_Keys (int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_RIGHT :  cam.slide(.2, 0, 0); break;
        case GLUT_KEY_LEFT:  cam.slide(-0.2, 0, 0); break;
        case GLUT_KEY_UP   :  cam.slide(0, .2, 0); break;
        case GLUT_KEY_DOWN :  cam.slide(0, -0.2, 0); break;
    }

    glutPostRedisplay();
}

int main()
{
    // init GLUT and create Window
    int x = 0;
    glutInit(&x, NULL);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Scenery");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL); //Enables color


    // register callbacks
    glutDisplayFunc(renderScene);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyPress);
    glutSpecialFunc  (Special_Keys);

    // setup camera
    glClearColor (1, 1, 1, 1.0);
    cam.set(Point(3,2,0),Point(-3,2,0),Vector(0,1,0));
    cam.setShape(45,800.00/600.00,1.0, 50.0);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}

