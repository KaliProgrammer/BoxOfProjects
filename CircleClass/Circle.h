//
//  Circle.h
//  CircleClass
//
//  Created by MacBook Air on 01.05.2022.
//

#ifndef Circle_h
#define Circle_h
#include <iostream>
#include <cmath>

using namespace std;
class Circle
{
private:
    double radius;
    double pi;
    
public:
    
    Circle(); //by default
    
    Circle(double);
    
    void setRadius(double);
    
    double getRadius() const;
    double getArea() const;
    double getDiameter() const;
    double getCircumference() const;
    void show() const;
 
};

#endif /* Circle_h */
