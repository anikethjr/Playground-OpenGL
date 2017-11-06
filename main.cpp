#include "primitives.h"
#include "camera.h"
#include "props.h"

using namespace glm;
using namespace std;

Camera cam;
double left_swing_angle=0, right_swing_angle=0, inclination = 45.0;

void renderScene(void)
{
    //Clear screen
    glClear  (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_DEPTH_TEST);
    glDisable (GL_LIGHTING);


//    glPushMatrix();
//    glRotatef(75, 0, 1, 0);
//    Slide slide;
//    slide.create(inclination);
//    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0); // change this later accordingly
    glRotatef(75, 0, 1, 0);
    MonkeyBar mb;
    mb.create();
    glPopMatrix();

    glEnd();

    glutSwapBuffers();
}

void idle()
{
//    double left_swing_angle_increment, right_swing_angle_increment;
//    if(left_swing_angle>=0 && left_swing_angle<=45)
//        left_swing_angle_increment = 0.1;
//    else if(left_swing_angle<0 && left_swing_angle>=-45)
//        left_swing_angle_increment = -0.1;
//    else if(left_swing_angle)
//        left_swing_angle_increment = -0.1;

    left_swing_angle = (left_swing_angle + 0.2);
    right_swing_angle = (right_swing_angle - 0.2);
    glutPostRedisplay();
}

void keyPress(unsigned char key,int x,int y)
{
    switch(key)
    {
        //Move forward
        case 'w':
            cam.slide(0,0,-0.2);
            break;
        //Move back
        case 's':
            cam.slide(0,0,0.2);
            break;
        //Move left
        case 'a':
            cam.slide(-0.2,0,0);
            break;
        //Move right
        case 'd':
            cam.slide(0.2,0,0);
            break;
        //Move up
        case 'r':
            cam.slide(0,0.2,0);
            break;
        //Move down
        case 'f':
            cam.slide(0,-0.2,0);
            break;
        //Look up
        case 'i':
            cam.pitch(-1.0);
            break;
        //Look down
        case 'k':
            cam.pitch(1.0);
            break;
        //Look left
        case 'l':
            cam.yaw(1.0);
            break;
        //Look right
        case 'j':
            cam.yaw(-1.0);
            break;
        //Roll anticlockwise
        case 'z':
            cam.roll(-1.0);
            break;
        //Roll clockwise
        case 'x':
            cam.roll(1.0);
            break;
        //Front view
        case 'g':
            cam.set(Point(0,0,2),Point(0,0,0),Vector(0,1,0));
            return;
        //Right view
        case 'h':
            cam.set(Point(2,0,0),Point(0,0,0),Vector(0,1,0));
            return;
        //Top view
        case 't':
            cam.set(Point(0,2,0),Point(0,0,0),Vector(0,0,1));
            return;
        //Back View
        case 'b':
            cam.set(Point(0,0,-2),Point(0,0,0),Vector(0,1,0));
            return;
        default:
            return;
    }
    glutPostRedisplay();
}

int main()
{
    // init GLUT and create Window
    int x = 0;
    glutInit(&x, nullptr);
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

    // setup camera
    glClearColor (135.0/255.0,206.0/255.0,250.0/255.0, 1.0);
    cam.set(Point(2,0,0),Point(0,0,0),Vector(0,1,0));
    cam.setShape(45,800.00/600.00,1.0, 50.0);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}

