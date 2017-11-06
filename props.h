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

void glutSolidCylinder(double BASE_INNER,double TOP_INNER,double BASE_OUTER,double TOP_OUTER,double HEIGHT,int SLICES,int STACKS)
{
    GLUquadric* cylinder = gluNewQuadric();
    GLUquadric* base = gluNewQuadric();
    GLUquadric* top = gluNewQuadric();
    gluCylinder(cylinder, BASE_OUTER, TOP_OUTER, HEIGHT, SLICES, STACKS);
    glRotated(180, 1, 0, 0);
    gluDisk(base, BASE_INNER, BASE_OUTER, SLICES, 1);
    glRotated(180, 1, 0, 0);
    glTranslated(0.0, 0.0, HEIGHT);
    gluDisk(top, TOP_INNER, TOP_OUTER, SLICES, 1);
    glTranslated(0.0, 0.0, -HEIGHT);
}

void glutWireCylinder(double BASE,double TOP,double HEIGHT,int SLICES,int STACKS)
{
    GLUquadric* cylinder = gluNewQuadric();
    GLUquadric* base = gluNewQuadric();
    GLUquadric* top = gluNewQuadric();
    glColor3d(0,0,0);
    gluCylinder(cylinder, BASE, TOP, HEIGHT, SLICES, STACKS);
    glRotated(180, 1, 0, 0);
    gluDisk(base, BASE, BASE+0.01, SLICES, 1);
    glRotated(180, 1, 0, 0);
    glTranslated(0.0, 0.0, HEIGHT);
    gluDisk(top, TOP, TOP+0.01, SLICES, 1);
    glTranslated(0.0, 0.0, -HEIGHT);
}

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

class MerryGoRound
{
    public:
        MerryGoRound()
        {
            //Solid Shapes
            //Base
            glColor3d(86.0/255.0, 49.0/255.0, 168.0/255.0);
            glPushMatrix();
            glRotated(90,1,0,0);
            glutSolidCylinder(0,0,0.5,0.5,0.1,32,32);
            glPopMatrix();
            glPushMatrix();
            glColor3d(255.0/255.0, 255.0/255.0, 255.0/255.0);
            glRotated(90,1,0,0);
            glutSolidCylinder(0.5,0.5,0.55,0.55,0.01,32,32);
            glPopMatrix();

            //Bars
            glColor3d(0.0/255.0, 0.0/255.0, 0.0/255.0);
            //Central bar
            glPushMatrix();
            glTranslated(0,0.14,0);
            glScaled(0.01,0.3,0.01);
            glutSolidCube(1);
            glPopMatrix();
            //Horizontal and vertical bars
            for(int i=0;i<6;i++)
            {
                glColor3d(111.0/255.0, 124.0/255.0, 122.0/255.0);
                glPushMatrix();
                glRotated(i*60,0,1,0);
                glTranslated(0.2,0.285,0);
                glScaled(0.4,0.01,0.01);
                glutSolidCube(1);
                glPopMatrix();
                glPushMatrix();
                glRotated(i*60,0,1,0);
                glTranslated(0.4,0.14,0);
                glScaled(0.01,0.3,0.01);
                glutSolidCube(1);
                glPopMatrix();
            }
        }
};

class Ground
{
    public:
        Ground()
        {
            glColor3d(139.0/255.0,69.0/255.0,19.0/255.0);
            glPushMatrix();
            glTranslated(0,-0.87,0);
            glScaled(2,0.2,2);
            glutSolidCube(5);
            glPopMatrix();

        }
};
#endif //SCENERY_PROPS_H
