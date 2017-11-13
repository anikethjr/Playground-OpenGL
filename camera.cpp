//
// Created by anikethjr on 7/11/17.
//
#include "camera.h"

Camera::Camera()
{
    setupPosition(dvec3(0.0,0.0,5.0),dvec3(0.0,0.0,0.0),dvec3(0,1,0));
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
    m[12]=-dot(position,u);
    m[13]=-dot(position,v);
    m[14]=-dot(position,n);
    m[15]=1.0;
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixd(m);
}

void Camera::setupPosition(dvec3 position, dvec3 target, dvec3 up)
{
    this->position = position;
    this->target = target;
    this->up = up;
    n = normalize(position-target);
    u = normalize(cross(up,n));
    v = normalize(cross(n,u));
    setModelViewMatrix();
}

void Camera:: roll(double angle)
{
    dvec3 temp = u;
    u = dvec3(cos(radians(angle))*temp.x - sin(radians(angle))*v.x,cos(radians(angle))*temp.y - sin(radians(angle))*v.y, cos(radians(angle))*temp.z - sin(radians(angle))*v.z);
    v = dvec3(cos(radians(angle))* v.x + sin(radians(angle))*temp.x,cos(radians(angle))*v.y + sin(radians(angle))*temp.y, cos(radians(angle))*v.z + sin(radians(angle))*temp.z);
    setModelViewMatrix();
}

void Camera::move(dvec3 displacement)
{
    position.x += displacement.x * u.x + displacement.y * v.x + displacement.z * n.x;
    position.y += displacement.x * u.y + displacement.y * v.y + displacement.z * n.y;
    position.z += displacement.x * u.z + displacement.y * v.z + displacement.z * n.z;
    target.x += displacement.x * u.x + displacement.y * v.x + displacement.z * n.x;
    target.y += displacement.x * u.y + displacement.y * v.y + displacement.z * n.y;
    target.z += displacement.x * u.z + displacement.y * v.z + displacement.z * n.z;
    setModelViewMatrix();
}

void Camera:: yaw(double angle)
{
    dvec3 t = u;
    u = dvec3(cos(radians(angle))* t.x + sin(radians(angle)) * n.x, cos(radians(angle))* t.y + sin(radians(angle)) * n.y, cos(radians(angle))* t.z + sin(radians(angle)) *n.z);
    n = dvec3(cos(radians(angle))* n.x - sin(radians(angle))* u.x, cos(radians(angle))* n.y - sin(radians(angle))* u.y, cos(radians(angle))* n.z - sin(radians(angle))* u.z);
    setModelViewMatrix();
}

void Camera:: pitch(double angle)
{
    dvec3 temp = v;
    v = dvec3(cos(radians(angle)) * temp.x - sin(radians(angle)) * n.x,cos(radians(angle)) * temp.y - sin(radians(angle)) * n.y, cos(radians(angle)) * temp.z - sin(radians(angle)) * n.z);
    n = dvec3(cos(radians(angle)) * n.x + sin(radians(angle)) * v.x, cos(radians(angle)) * n.y + sin(radians(angle)) * v.y, cos(radians(angle)) * n.z + sin(radians(angle)) * v.z);
    setModelViewMatrix();
}