#include "camera.h"
#include "props.h"
#include "Parser.h"

using namespace std;
using namespace glm;

Camera cam;
double slide_inclination = 45.0;
double merryGoRound_rotate = 0;
Model* modcu;

/**
 * Function which assembles the various objects and creates the scene
 */
void renderScene()
{
    //Clear screen
    glClear  (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Draw the ground
    Ground g;

    // Place the surrounding walls of the park
    glPushMatrix();
    Wall w;
    w.create();
    glPopMatrix();

    //Place the path within the park
    glPushMatrix();
    Path p;
    p.create();
    glPopMatrix();

    //Place and scale merry-go-round
    glPushMatrix();
    glTranslated(-2.5,-0.25,3.5);
    glRotated(merryGoRound_rotate,0,1,0);
    MerryGoRound m;
    glPopMatrix();

    //Place and scale swing
    glPushMatrix();
    glTranslated(1,-0.014,-1);
    glRotated(90,0,1,0);
    glScaled(1.5,1.5,1.5);
    Swing s;
    glPopMatrix();

    // Place slide
    glPushMatrix();
    glTranslated(2,0,-1);
    glRotatef(75, 0, 1, 0);
    Slide slide;
    slide.create(slide_inclination);
    glPopMatrix();

    // Place and scale monkey bar
    glPushMatrix();
    glTranslatef(-1.3, 0.5121, -0.91);
    glRotatef(-75, 0, 1, 0);
    glScaled(1.5,1.5,1.5);
    MonkeyBar mb;
    mb.create();
    glPopMatrix();

    //Place and scale bench
    glPushMatrix();
    glTranslatef(1.7, -0.21, 1.2);
    glRotatef(0, 0, 1, 0);
    Bench bench;
    bench.create();
    glPopMatrix();

    //Drawing the Blender model
    glPushMatrix();
    glTranslatef(0.0, -0.3, 3.0);
    modcu->draw();
    glPopMatrix();

    glEnd();

    glutSwapBuffers();
}

/**
 * Updates the variables in every frame
 */
void idle()
{
    merryGoRound_rotate = merryGoRound_rotate + 0.001;
    glutPostRedisplay();
}

/**
 * Handles key presses
 * @param key the keyboard input given by the user
 * @param x x coordinate of the input
 * @param y y coordinate of the input
 */
void keyPress(unsigned char key,int x,int y)
{
    switch(key)
    {
        //Move forward
        case 'w':
            cam.move(dvec3(0,0,-0.2));
            break;
        //Move back
        case 's':
            cam.move(dvec3(0,0,0.2));
            break;
        //Move left
        case 'a':
            cam.move(dvec3(-0.2,0,0));
            break;
        //Move right
        case 'd':
            cam.move(dvec3(0.2,0,0));
            break;
        //Move up
        case 'r':
            cam.move(dvec3(0,0.2,0));
            break;
        //Move down
        case 'f':
            cam.move(dvec3(0,-0.2,0));
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
            cam.setupPosition(dvec3(-1,0,5),dvec3(-1,0,0),dvec3(0,1,0));
            return;
        //Right view
        case 'h':
            cam.setupPosition(dvec3(5,0,0),dvec3(0,0,0),dvec3(0,1,0));
            return;
        //Top view
        case 't':
            cam.setupPosition(dvec3(0,5,0),dvec3(0,0,0),dvec3(0,0,-1));
            return;
        //Back view
        case 'b':
            cam.setupPosition(dvec3(-1,0,-5),dvec3(-1,0,0),dvec3(0,1,0));
            return;
        default:
            return;
    }
    glutPostRedisplay();
}

/**
 * Adds lighting to the scene
 */
void light()
{
	GLfloat mat_specular[] = {0.1, 0.2, 0.1, 1.0};
   	GLfloat mat_emission[] = {0.1, 0.2, 0.1, 1.0};
   	GLfloat light_position[] = {1.0, 2.0, 1.0, 1.0};
	GLfloat light_ambient[] = {0.8, 0.8, 0.8, 1.0};
	GLfloat light_diffuse[] = {0.2, 0.1, 0.3, 1.0};
	GLfloat light_specular[] = {0.2, 0.2, 0.2, 1.0};
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
   	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);	
   	glEnable(GL_LIGHTING);
   	glEnable(GL_LIGHT0);
}

int main()
{
    // init GLUT and create Window
    int x = 0;
    glutInit(&x, nullptr);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(928,696);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Scenery");
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_SMOOTH);
    modcu = new Model("FerrisWheel.obj", "FerrisWheel.mtl");
    // register callbacks
    glutDisplayFunc(renderScene);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyPress);
    //light the scene
    light();
    // setup camera
    glClearColor(135.0/255.0,206.0/255.0,250.0/255.0,1.0);
    cam.setupPosition(dvec3(-1,0,5),dvec3(-1,0,0),dvec3(0,1,0));
    cam.setupProperties(45,928.00/696.00,0.1, 50.0);
    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}

