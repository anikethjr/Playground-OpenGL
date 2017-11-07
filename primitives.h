//
// Created by anikethjr on 6/11/17.
//
#ifndef SCENERY_PRIMITIVES_H
#define SCENERY_PRIMITIVES_H

#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>

using namespace glm;
using namespace std;

class Point;
class Vector;
/**
 * Finds the vector difference between two points
 * @param a First point
 * @param b Second point
 * @return Returns the difference Vector
 */
Vector difference(Point a, Point b);

/**
 * Class to represent a 3D point
 */
class Point
{
public:
    double x,y,z;
    /**
     * Constructor which initializes x,y,z to 0,0,0
     */
    Point();
    /**
     * Constructor which initializes the coordinates to those specified in the arguments
     * @param x x coordinate to be set
     * @param y y coordinate to be set
     * @param z z coordinate to be set
     */
    Point(double x, double y, double z);
    /**
     * Function which sets the coordinates to those specified in the arguments
     * @param x x coordinate to be set
     * @param y y coordinate to be set
     * @param z z coordinate to be set
     */
    void set(double x, double y, double z);
    /**
     * Function which sets the coordinates equal to those of the Point passed
     * @param p Point whose values are to be copied
     */
    void set(Point p);
};

/**
 * Class to represent a 3D vector
 */
class Vector
{
public:
    double x,y,z;
    /**
     * Constructor which initializes x,y,z components to 0,0,0
     */
    Vector();
    /**
     * Constructor which initializes the components to those specified in the arguments
     * @param x x component to be set
     * @param y y component to be set
     * @param z z component to be set
     */
    Vector(double x, double y, double z);
    /**
     * Function which sets the components to those specified in the arguments
     * @param x x component to be set
     * @param y y component to be set
     * @param z z component to be set
     */
    void set(double x, double y, double z);
    /**
     * Function which sets the components equal to those of the Vector passed
     * @param v Vector whose values are to be copied
     */
    void set(Vector v);
    /**
     * Normalizes the vector so that its magnitude is 1
     */
    void normalize();
    /**
     * Finds the dot product of the current Vector with the Vector passed
     * @param v The vector with which the dot product is to be calculated
     * @return Returns the dot product
     */
    double dot(Vector v);
    /**
     * Finds the cross product of the current Vector with the Vector passed
     * @param v The vector with which the cross product is to be calculated
     * @return Returns the cross product
     */
    Vector cross(Vector v);
};

#endif //SCENERY_PRIMITIVES_H
