//
// Created by anikethjr on 6/11/17.
//
#ifndef SCENERY_CAMERA_H
#define SCENERY_CAMERA_H

#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#include "primitives.h"
#define PI 3.14159265

class Camera
{
    private:
        Point eye, look, up;
        Vector u, v, n;
        double viewAngle, aspect, nearDist, farDist;
        void setModelviewMatrix();

    public:
        Camera();
        void set(Point eye, Point look, Vector up);
        void roll(double angle);
        void pitch(double angle);
        void yaw(double angle);
        void slide(double delU, double delV, double delN);
        void setShape(double vAng, double asp, double nearD, double farD);
};

Camera:: Camera(void)
{
    setShape(45.0f, 640/(double)480, 0.1f, 200.0f);

    Point eyePoint = Point( 10.0, 0.0, 0.0 );
    Point lookPoint = Point( 0.0, 0.0, 0.0 );
    Vector upVector = Vector( 0, 1, 0 );

    set( eyePoint, lookPoint, upVector );
}


void Camera :: setShape(double vAngle, double asp, double nr, double fr)
{
    viewAngle = vAngle;
    aspect = asp;
    nearDist = nr;
    farDist = fr;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(viewAngle, aspect, nearDist, farDist);
    glMatrixMode(GL_MODELVIEW);
}

void Camera :: setModelviewMatrix(void)
{
    double m[16];
    Vector eVec(eye.x, eye.y, eye.z);
    m[0]=u.x;
    m[1]=v.x;
    m[2]=n.x;
    m[3]=0;
    m[4]=u.y;
    m[5]=v.y;
    m[6]=n.y;
    m[7]=0;
    m[8]=u.z;
    m[9]=v.z;
    m[10]=n.z;
    m[11]=0;
    m[12]=-eVec.dot(u);
    m[13]=-eVec.dot(v);
    m[14]=-eVec.dot(n);
    m[15]=1.0;
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixd(m);
}

void Camera:: set(Point Eye, Point look, Vector up)
{
    eye.set(Eye);
    n.set(eye.x - look.x, eye.y - look.y, eye.z - look.z);
    u.set(up.cross(n));

    v.set(n.cross(u));
    n.normalize();
    u.normalize();
    v.normalize();
    setModelviewMatrix();
}

void Camera:: slide(double delU, double delV, double delN)
{
    eye.x += delU * u.x + delV * v.x + delN * n.x;
    eye.y += delU * u.y + delV * v.y + delN * n.y;
    eye.z += delU * u.z + delV * v.z + delN * n.z;

    look.x += delU * u.x + delV * v.x + delN * n.x;
    look.y += delU * u.y + delV * v.y + delN * n.y;
    look.z += delU * u.z + delV * v.z + delN * n.z;
    setModelviewMatrix();
}

void Camera:: roll(double angle)
{
    double cs= cos(PI/180 * angle);
    double sn= sin(PI/180 * angle);
    Vector t(u);
    u.set(cs* t.x - sn*v.x,cs*t.y - sn*v.y, cs*t.z - sn*v.z);
    v.set(cs* v.x + sn*t.x,cs*v.y + sn*t.y, cs*v.z + sn*t.z);
    setModelviewMatrix();
}

void Camera:: pitch(double angle)
{
    double cs= cos(PI/180 * angle);
    double sn= sin(PI/180 * angle);
    Vector t(v);
    v.set(cs * t.x - sn * n.x,cs * t.y - sn * n.y, cs * t.z - sn * n.z);
    n.set(cs * n.x + sn * v.x, cs * n.y + sn * v.y, cs * n.z + sn * v.z);
    setModelviewMatrix();
}

void Camera:: yaw(double angle)
{
    double cs= cos(PI/180 * angle);
    double sn= sin(PI/180 * angle);
    Vector t(u);
    u.set(cs* t.x + sn * n.x, cs* t.y + sn * n.y, cs* t.z + sn * n.z);
    n.set(cs* n.x - sn* u.x, cs* n.y - sn* u.y, cs* n.z - sn* u.z);
    setModelviewMatrix();
}

#endif //SCENERY_CAMERA_H