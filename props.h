//
// Created by anikethjr on 6/11/17.
//
#ifndef SCENERY_PROPS_H
#define SCENERY_PROPS_H

#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>

using namespace glm;
using namespace std;

class Swing
{
    public:
        Swing(double left_swing_angle, double right_swing_angle)
        {
            glColor3d(255.0/255,0,0);

            //Left bars
            glPushMatrix();
            glTranslated(0,0,0);
            glRotated(-20,0,0,1);
            glScaled(0.01,0.5,0.01);
            glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
            glTranslated(0.17,0,0);
            glRotated(20,0,0,1);
            glScaled(0.01,0.5,0.01);
            glutSolidCube(1);
            glPopMatrix();

            //Right bars
            glPushMatrix();
            glTranslated(0,0,-0.75);
            glRotated(-20,0,0,1);
            glScaled(0.01,0.5,0.01);
            glutSolidCube(1);
            glPopMatrix();

            glPushMatrix();
            glTranslated(0.17,0,-0.75);
            glRotated(20,0,0,1);
            glScaled(0.01,0.5,0.01);
            glutSolidCube(1);
            glPopMatrix();

            //Top rod
            glPushMatrix();
            glTranslated(0.09,0.23,-0.375);
            glScaled(0.01,0.01,0.5);
            glutSolidCube(1.5);
            glPopMatrix();

            //Chains
            glColor3d(0,0,0);
            glPushMatrix();
            glTranslated(0.09,0.05,-0.1);
            glScaled(0.01,0.5,0.01);
            glutSolidCube(0.75);
            glPopMatrix();

            glColor3d(0,0,0);
            glPushMatrix();
            glTranslated(0.09,0.05,-0.25);
            glScaled(0.01,0.5,0.01);
            glutSolidCube(0.75);
            glPopMatrix();

            glColor3d(0,0,0);
            glPushMatrix();
            glTranslated(0.09,0.05,-0.5);
            glScaled(0.01,0.5,0.01);
            glutSolidCube(0.75);
            glPopMatrix();

            glColor3d(0,0,0);
            glPushMatrix();
            glTranslated(0.09,0.05,-0.65);
            glScaled(0.01,0.5,0.01);
            glutSolidCube(0.75);
            glPopMatrix();

            //Seats
            glColor3d(255.0/255.0, 255.0/255.0, 17.0/255.0);
            glPushMatrix();
            glTranslated(0.09,-0.14,-0.575);
            glScaled(0.25,0.01,0.33);
            glutSolidCube(0.5);
            glPopMatrix();

            glColor3d(255.0/255.0, 255.0/255.0, 17.0/255.0);
            glPushMatrix();
            glTranslated(0.09,-0.14,-0.175);
            glScaled(0.25,0.01,0.33);
            glutSolidCube(0.5);
            glPopMatrix();


        }
};

void chair()
{
    glColor3d(152.0/255,92.0/255,30.0/255);

    glPushMatrix();
    glTranslatef(4,2.5,0); //RED
    glScalef(0.2,2.5,0.2);
    glutSolidCube(2);
    glPopMatrix();

    //glColor3d(0,1,0);

    glPushMatrix();
    glTranslatef(0.0,2.5,0); //GREEN
    glScalef(0.2,2.5,0.2);
    glutSolidCube(2);
    glPopMatrix();

    //glColor3d(0,0,1);

    glPushMatrix();
    glTranslatef(0,2.5,4); //BLUE
    glScalef(0.2,2.5,0.2);
    glutSolidCube(2);
    glPopMatrix();

    //glColor3d(0,0,0);

    glPushMatrix();
    glTranslatef(4,2.5,4); //BLACK
    glScalef(0.2,2.5,0.2);
    glutSolidCube(2);
    glPopMatrix();

    //glColor3d(0.5,0.5,0.5);
    //glColor3d(30.0/255,40.5/255,40/255);
    glColor3d(255.0/255,165.0/255,79.0/255);
    glPushMatrix();
    glTranslatef(2,5.55,2);
    glScalef(1,0.2,1);
    glutSolidCube(5);
    glPopMatrix();

    //glColor3d(0.5,0.5,0.5);
    glPushMatrix();
    glTranslatef(4.75,7.55,2);
    glScalef(0.05,1,1);
    glutSolidCube(5);
    glPopMatrix();

}

#endif //SCENERY_PROPS_H
