//
// Created by anikethjr on 7/11/17.
//
#include "camera.h"

Camera::Camera()
{
    eye = dvec3(0.0,0.0,5.0);
    look = dvec3(0.0,0.0,0.0);
    up = dvec3(0,1,0);

    setupPosition(eye,look,up);
    setupProperties(45.0f,928.00/696.00,0.1,50.0);
}

void Camera :: setupProperties(double viewAngle, double aspect, double nearDist, double farDist)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(viewAngle, aspect, nearDist, farDist);
    glMatrixMode(GL_MODELVIEW);
}

void Camera :: setModelViewMatrix()
{
    double m[16];
    dvec3 eVec(eye.x, eye.y, eye.z);
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
    m[12]=-dot(eVec,u);
    m[13]=-dot(eVec,v);
    m[14]=-dot(eVec,n);
    m[15]=1.0;
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixd(m);
}

void Camera::setupPosition(dvec3 Eye, dvec3 Look, dvec3 Up)
{
    eye = Eye;
    look = Look;
    up = Up;
    n = eye-look;
    u = cross(up,n);
    v = cross(n,u);
    n = normalize(n);
    u = normalize(u);
    v = normalize(v);
    setModelViewMatrix();
}

void Camera::move(dvec3 displacement)
{
    eye.x += displacement.x * u.x + displacement.y * v.x + displacement.z * n.x;
    eye.y += displacement.x * u.y + displacement.y * v.y + displacement.z * n.y;
    eye.z += displacement.x * u.z + displacement.y * v.z + displacement.z * n.z;
    look.x += displacement.x * u.x + displacement.y * v.x + displacement.z * n.x;
    look.y += displacement.x * u.y + displacement.y * v.y + displacement.z * n.y;
    look.z += displacement.x * u.z + displacement.y * v.z + displacement.z * n.z;
    setModelViewMatrix();
}

void Camera:: roll(double angle)
{
    double cs= cos(PI/180 * angle);
    double sn= sin(PI/180 * angle);
    dvec3 t = u;
    u = dvec3(cs*t.x - sn*v.x,cs*t.y - sn*v.y, cs*t.z - sn*v.z);
    v = dvec3(cs* v.x + sn*t.x,cs*v.y + sn*t.y, cs*v.z + sn*t.z);
    setModelViewMatrix();
}

void Camera:: pitch(double angle)
{
    double cs= cos(PI/180 * angle);
    double sn= sin(PI/180 * angle);
    dvec3 t = v;
    v = dvec3(cs * t.x - sn * n.x,cs * t.y - sn * n.y, cs * t.z - sn * n.z);
    n = dvec3(cs * n.x + sn * v.x, cs * n.y + sn * v.y, cs * n.z + sn * v.z);
    setModelViewMatrix();
}

void Camera:: yaw(double angle)
{
    double cs= cos(PI/180 * angle);
    double sn= sin(PI/180 * angle);
    dvec3 t = u;
    u = dvec3(cs* t.x + sn * n.x, cs* t.y + sn * n.y, cs* t.z + sn * n.z);
    n = dvec3(cs* n.x - sn* u.x, cs* n.y - sn* u.y, cs* n.z - sn* u.z);
    setModelViewMatrix();
}