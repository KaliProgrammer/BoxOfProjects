//
//  main.cpp
//  CircleClass
//
//  Created by MacBook Air on 01.05.2022.
//

#include <iostream>
#include <iomanip>
#include "Circle.h"
#include <cmath>

using namespace std;


void consoleInput(Circle &);
void getRadius(Circle &);

int main(int argc, const char * argv[])
{
    
    Circle Calculation;
    Calculation.show();
    consoleInput(Calculation);
    
    
    return 0;
}

void consoleInput(Circle &Calculation)
{
    int choice = 0;
    
    do{
        cin >> choice;
        cout << endl;
    switch (choice) {
        case 1:
        {
            getRadius(Calculation);
            cout << "The Area is: ";
            cout << fixed << showpoint << setprecision(2);
            cout << Calculation.getArea() << endl;
        }
            break;
            
        case 2:
        {
            getRadius(Calculation);
            cout << " The diameter is: ";
            cout << fixed << showpoint << setprecision(2);
            cout << Calculation.getDiameter();
        }

            break;
            
        case 3:
        {
            getRadius(Calculation);

            cout << " The circumference is: ";
            cout << fixed << showpoint << setprecision(2);
            cout << Calculation.getCircumference();
        }

            break;
    }
    }while(choice < 1 || choice > 3);
    
    
}

void getRadius(Circle &Calculation)
{
    double radius;
    cout << "Enter radius:\n";
    cin >> radius;
    while (radius < 0.0)
    {
        cout << "Enter radius greater than 0.0, please: " << endl;
        cin >> radius;
    }
    Calculation.setRadius(radius);
}
