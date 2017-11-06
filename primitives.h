//
// Created by anikethjr on 6/11/17.
//
#ifndef SCENERY_PRIMITIVES_H
#define SCENERY_PRIMITIVES_H

#include<bits/stdc++.h>
#include<GL/glu.h>
#include<GL/glut.h>
using namespace std;

class Point
{
    public:
        double x,y,z;
        Point()
        {
            x=0; y=0; z=0;
        }
        Point(double dx, double dy, double dz)
        {
            x=dx; y=dy; z=dz;
        }
        void set(double dx, double dy, double dz)
        {
            x=dx;
            y=dy;
            z=dz;
        }
        void set(Point p)
        {
            x=p.x;
            y=p.y;
            z=p.z;
        }
};

class Vector
{
    public:
        double x,y,z;
        Vector()
        {
            x=0; y=0; z=0;
        }
        Vector(double dx, double dy, double dz)
        {
            x=dx; y=dy; z=dz;
        }
        void set(double dx, double dy, double dz)
        {
            x=dx;
            y=dy;
            z=dz;
        }
        void set(Vector v)
        {
            x=v.x;
            y=v.y;
            z=v.z;
        }
        void normalize()
        {
            x=(double(x))/sqrt(x*x + y*y + z*z);
            y=(double(y))/sqrt(x*x + y*y + z*z);
            z=(double(z))/sqrt(x*x + y*y + z*z);
        }
        double dot(Vector b)
        {
            double result;
            result= x * b.x + y * b.y + z * b.z;
            return result;
        }
        Vector cross(Vector b)
        {
            Vector result;
            result.x= y* b.z - z * b.y;
            result.y= z * b.x - x * b.z;
            result.z= x * b.y - y * b.x;
            return result;
        }
};

#endif //SCENERY_PRIMITIVES_H
