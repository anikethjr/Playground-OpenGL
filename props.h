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

class Slide
{
public:
//        GLUquadricObj *quadratic, *quadratic2;;
//        quadratic = gluNewQuadric();
//        quadratic2 = gluNewQuadric();

    void create(double inclination) {
        base(inclination);
        stairs();
        bars();
        frame();
        line(inclination);

    }

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

    void line(double inclination) {
        glColor3d(0,0,0);
//        GLUquadricObj *quadratic, *quadratic2;
//        quadratic = gluNewQuadric();
//        quadratic2 = gluNewQuadric();
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

class MonkeyBar
{
public:
    void create()
    {
        frame();
        bars();
        line();
    }

    void frame()
    {
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

    void bars()
    {
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

    void line()
    {
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
