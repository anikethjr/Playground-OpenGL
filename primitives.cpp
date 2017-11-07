//
// Created by anikethjr on 7/11/17.
//
#include "primitives.h"

Point::Point()
{
    x=y=z=0;
}

Point::Point(double x, double y, double z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}

void Point::set(double x, double y, double z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}

void Point::set(Point p)
{
x=p.x;
y=p.y;
z=p.z;
}

Vector::Vector()
{
    x=y=z=0;
}
Vector::Vector(double x, double y, double z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}
void Vector::set(double x, double y, double z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}
void Vector::set(Vector v)
{
    x=v.x;
    y=v.y;
    z=v.z;
}
void Vector::normalize()
{
    x=(double(x))/sqrt(x*x + y*y + z*z);
    y=(double(y))/sqrt(x*x + y*y + z*z);
    z=(double(z))/sqrt(x*x + y*y + z*z);
}
double Vector::dot(Vector v)
{
    return x*v.x + y *v.y + z*v.z;
}
Vector Vector::cross(Vector v)
{
    return Vector(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

Vector difference(Point a, Point b) {
    return Vector(a.x-b.x,a.y-b.y,a.z-b.z);
}