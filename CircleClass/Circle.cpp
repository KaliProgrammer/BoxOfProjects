//
//  Circle.cpp
//  CircleClass
//
//  Created by MacBook Air on 01.05.2022.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include "Circle.h"
#include <iomanip>
#include <cmath>


using namespace std;

Circle::Circle()         //by default
{
    radius = 0;
    pi = 3.14159;
}

//Circle::Circle(double r)
//{
//    radius = r;
//}

void Circle::setRadius(double r)
{
    radius = r;
}

double Circle::getRadius() const
{
    return radius;
}
double Circle::getArea() const
{
    return (pi * radius * radius);
}
double Circle::getDiameter() const
{
    return (radius * 2);
}
double Circle::getCircumference() const
{
    return (2 * pi * radius);
}
void Circle::show() const
{
    cout << "What would you like to calculate:\n"
         << "1. Area (Area = pi * radius * radius)\n"
         << "2. Diameter (Diameter = radius * 2)\n"
         << "3. Circumference (Circumference = 2 * pi * radius)\n" << endl;
}
