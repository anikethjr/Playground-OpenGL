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

/**
 * Class for creating a slide
 */
class Slide
{
public:

    /**
     * Function to create the slide
     * @param inclination defines the inclination of the slide
     */
    void create(double inclination) {
        base(inclination);
        stairs();
        bars();
        frame();
        line(inclination);

    }

    /**
     * Function that defines the base of the slide
     * @param inclination defines the inclination of the slide
     */
    void base(double inclination) {
        // right edge
        glColor3d(255.0 / 255, 0, 0);
        glPushMatrix();
        glTranslated(0, 0, 0);
        glRotatef(inclination, 0, 0, 1);
        glScaled(1, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // right base edge
        glColor3d(255.0 / 255, 0, 0);
        glPushMatrix();
        glTranslated(-0.707 + 0.246, -0.351, 0);
        glScaled(0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // right top edge
        glColor3d(255.0 / 255, 0, 0);
        glPushMatrix();
        glTranslated(0.46, 0.35, 0);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // slide part
        glColor3d(5.0 / 255, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(0, 0, -0.1);
        glRotatef(inclination, 0, 0, 1);
        glScaled(1, 0.001, -0.2);
        glutSolidCube(1);
        glPopMatrix();

        // slide base part
        glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(-0.707 + 0.246, -0.351, -0.1);
        glScaled(0.23, 0.001, -0.2);
        glutSolidCube(1);
        glPopMatrix();

        // slide top part
        glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(0.46, 0.35, -0.1);
        glScaled(0.23, 0.001, -0.2);
        glutSolidCube(1);
        glPopMatrix();

        // left edge
        glColor3d(255 / 255.0, 0, 0);
        glPushMatrix();
        glTranslated(0, 0, -0.2);
        glRotatef(inclination, 0, 0, 1);
        glScaled(1, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // left base edge
        glColor3d(255 / 255.0, 0, 0);
        glPushMatrix();
        glTranslated(-0.707 + 0.246, -0.351, -0.2);
        glScaled(0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // left top edge
        glColor3d(255.0 / 255, 0, 0);
        glPushMatrix();
        glTranslated(0.46, 0.35, -0.2);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();
    }

    /**
     * Function that defines the stairs/steps of the slide
     */
    void stairs() {
        // right stairs edge
        glColor3d(255.0 / 255, 0, 0);
        glPushMatrix();
        glTranslated(0.56, -0.01, 0);
        glScaled(0.03, 0.71, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // left stairs edge
        glColor3d(255.0 / 255, 0, 0);
        glPushMatrix();
        glTranslated(0.56, -0.01, -0.2);
        glScaled(0.03, 0.71, 0.01);
        glutSolidCube(1);
        glPopMatrix();
    }

    /**
     * Function that defines the bars for the stairs/steps of the slide
     */
    void bars() {
        // bars
        // bar 1
        glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(0.56, 0.18, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();

        // bar 2
        glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(0.56, 0.03, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();

        // bar 3
        glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(0.56, -0.12, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();

        // bar 4
        glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(0.56, -0.27, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();
    }

    /**
     * Function that defines the frame at the top of the slide
     */
    void frame() {

        // frame
        // frame right side
        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.36, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.41, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.46, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.51, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.56, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // frame left side
        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.36, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.41, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.46, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.51, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.56, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // frame top
        // frame top right
        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.46, 0.55, 0);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // frame top left
        // frame top right
        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.46, 0.55, -0.2);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();
    }

    /**
     * Function to create the borders of the slide
     * @param inclination defines the inclination of the slide
     */
    void line(double inclination) {
        glColor3d(0,0,0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // right edge
        glPushMatrix();
        glTranslated(0,0,0);
        glRotatef(inclination, 0, 0, 1);
        glScaled(1,0.03,0.01);
        glutSolidCube(1);
        glPopMatrix();

        // right base edge
        glPushMatrix();
        glTranslated(-0.707+0.246, -0.351, 0);
        glScaled(0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // right top edge
        glPushMatrix();
        glTranslated(0.46, 0.35, 0);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // slide part
        glPushMatrix();
        glTranslated(0, 0, -0.1);
        glRotatef(inclination, 0, 0, 1);
        glScaled(0.2,0.001,-0.2);
        glutSolidCube(1);
        glPopMatrix();

        // slide base part
        glPushMatrix();
        glTranslated(-0.707+0.246, -0.351, -0.1);
        glScaled(0.23,0.001,-0.2);
        glutSolidCube(1);
        glPopMatrix();

        // slide base part
        glPushMatrix();
        glTranslated(-0.707+0.246, -0.351, -0.1);
        glScaled(0.23,0.001,-0.2);
        glutSolidCube(1);
        glPopMatrix();

        // left edge
        glPushMatrix();
        glTranslated(0,0,-0.2);
        glRotatef(inclination, 0, 0, 1);
        glScaled(1,0.03,0.01);
        glutSolidCube(1);
        glPopMatrix();

        // left base edge
        glPushMatrix();
        glTranslated(-0.707+0.246, -0.351, -0.2);
        glScaled(0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // left top edge
        glPushMatrix();
        glTranslated(0.46, 0.35, -0.2);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // right stairs edge
        glPushMatrix();
        glTranslated(0.56, -0.01, 0);
        glScaled(0.03, 0.71, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // left stairs edge
        glPushMatrix();
        glTranslated(0.56, -0.01, -0.2);
        glScaled(0.03, 0.71, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // bars
        glPushMatrix();
        glTranslated(0.56, 0.18, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.56, 0.03, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.56, -0.12, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();


        // frame
        // frame right side
        glPushMatrix();
        glTranslated(0.36, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.41, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.46, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.51, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.56, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // frame left side
        glPushMatrix();
        glTranslated(0.36, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.41, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.46, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.51, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.56, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // frame top
        // frame top right
        glPushMatrix();
        glTranslated(0.46, 0.55, 0);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // frame top left
        // frame top right
        glPushMatrix();
        glTranslated(0.46, 0.55, -0.2);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
};

/**
 * Class for creating a monkey bar
 */
class MonkeyBar
{
public:

    /**
     * Function to create the monkey bar
     */
    void create() {
        frame();
        bars();
        line();
    }

    /**
     * Function that defines the frame of the monkey bar
     */
    void frame() {
        // frame
        // frame right edge
        glColor3d(9/255.0, 71/255.0, 42/255.0);
        glPushMatrix();
        glTranslated(0, 0, 0);
        glScaled(1, 0.03, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // frame left edge
        glColor3d(9/255.0, 71/255.0, 42/255.0);
        glPushMatrix();
        glTranslated(0, 0, -0.35);
        glScaled(1, 0.03, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // frame right legs
        glColor3d(9/255.0, 71/255.0, 42/255.0);
        glPushMatrix();
        glTranslated(-0.485, -0.287, 0);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(9/255.0, 71/255.0, 42/255.0);
        glPushMatrix();
        glTranslated(0.485, -0.287, 0);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // frame left legs
        glColor3d(9/255.0, 71/255.0, 42/255.0);
        glPushMatrix();
        glTranslated(-0.485, -0.287, -0.35);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(9/255.0, 71/255.0, 42/255.0);
        glPushMatrix();
        glTranslated(0.485, -0.287, -0.35);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();




    }

    /**
     * Function to add the bars in the frame
     */
    void bars() {
        // bars
        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(0, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(0.15, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(-0.15, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(0.3, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(-0.3, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(-0.45, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(0.45, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();
    }

    /**
     * Function to create the borders of the monkey bar
     */
    void line() {
        glColor3d(0,0,0);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // frame
        // frame right edge
        glPushMatrix();
        glTranslated(0, 0, 0);
        glScaled(1, 0.03, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // frame left edge
        glPushMatrix();
        glTranslated(0, 0, -0.35);
        glScaled(1, 0.03, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // frame right legs
        glPushMatrix();
        glTranslated(-0.485, -0.287, 0);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.485, -0.287, 0);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // frame left legs
        glPushMatrix();
        glTranslated(-0.485, -0.287, -0.35);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.485, -0.287, -0.35);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // bars
        glPushMatrix();
        glTranslated(0, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.15, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0.15, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.3, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0.3, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0.45, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.45, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();


        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    }

};

/**
 * Class for creating a wooden bench
 */
class Bench
{
public:

    /**
     * Function to create the wooden bench
     */
    void create() {
        base();
        line();
    }

    /**
     * Function that defines the base and the seat of the bench
     */
    void base() {
        // base right legs
        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0, 0, 0);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();


        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0.5, 0, 0);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // right joiner
        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0.25, 0.175, 0);
        glScaled(0.55, 0.05, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // base left legs
        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0, 0, -1);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();


        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0.5, 0, -1);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // left joiner
        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0.25, 0.175, -1);
        glScaled(0.55, 0.05, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // seat
        glColor3d(124/255.0, 90/255.0, 4/255.0);
        glPushMatrix();
        glTranslated(0.05, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.12, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.19, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.26, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.33, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.4, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.47, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

    }

    /**
     * Function to create the borders of the bench
     */
    void line() {
        glColor3d(0,0,0);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // base right legs
        glPushMatrix();
        glTranslated(0, 0, 0);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();


        glPushMatrix();
        glTranslated(0.5, 0, 0);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // right joiner
        glPushMatrix();
        glTranslated(0.25, 0.175, 0);
        glScaled(0.55, 0.05, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // base left legs
        glPushMatrix();
        glTranslated(0, 0, -1);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();


        glPushMatrix();
        glTranslated(0.5, 0, -1);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // left joiner
        glPushMatrix();
        glTranslated(0.25, 0.175, -1);
        glScaled(0.55, 0.05, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // seat
        glPushMatrix();
        glTranslated(0.05, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.12, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.19, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.26, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.33, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.4, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.47, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();





        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

};


#endif //SCENERY_PROPS_H
