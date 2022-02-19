//
//  main.cpp
//  Equation
//
//  Created by MacBook Air on 18.02.2022.
//

#include <iostream>
#include <math.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int equation( double b, double c, double a=0)
{
    double x1=0.0, x2=0.0, D=0.0;
    if(a==0)
    {
        x1=-c/b;
        cout<<"x= "<<x1<<endl;
        return 1;
    }
    else
    {
        D=(b*b)-4*a*c;
        if(D<0)
        {
            cout<<"No real roots"<<endl;
            return 0;
        }
        else if (D==0)
        {
            x1=(-b)/(2*a);
            cout<<"x1=x2= "<<x1<<endl;
            return 2;
        }
        else
        {
            x1=((-b)-sqrt(D))/(2*a);
            x2=((-b)+sqrt(D))/(2*a);
            cout<<"x1= "<<x1<<"\nx2= "<<x2<<endl;
            return 2;
        }
    }
}

inline double equation1(double k, double b)
{
    
    return -b/k;
}
int equation1( double a, double b, double c)
{
    double x1 = 0.0, x2 = 0.0, D = 0.0;
    D = (b * b) - 4 * a * c;
    if (D < 0)
    {
        cout << "Нет действительных корней!" << endl;
        return 0;
    }
    else
        if (D == 0)
        {
            x1 = (-b) / (2 * a);
            cout << "x1=x2= " << x1 << endl;
            return 1; //
        }
        else
        {
            x1 = ((-b) - sqrt(D)) / (2 * a);
            x2 = ((-b) + sqrt(D)) / (2 * a);
            cout << "x1= " << x1 << "\nx2= " << x2 << endl;
            return 2;
        }
}

int main()
{
    int choice = 0;
    double a=0.0, b=0.0, c=0.0;

    do
    {
        cout<<R"(---This program solves equations---)
1-linear equation (kx+b=0)
2-square equation (ax^2+bx+c=0)
0-quit
)";
        do
        {
            cout<<"Choose the type of equation: ";cin>>choice;
            if(choice<0||choice>2)
                cout<<"Wrong type! Try again: "<<endl;
        } while (choice<0||choice>2);
        if(choice==0)break;
        switch(choice)
        {
            case 1:
                cout<<"Enter coefficient k:  ";cin>>b;
                cout<<"Enter coefficient b:  ";cin>>c;
                
                equation1(b,c);
                break;
            case 2:
                cout<<"Enter coefficient a:  ";cin>>a;
                cout<<"Enter coefficient b:  ";cin>>b;
                cout<<"Enter coefficient c:  ";cin>>c;
               
                equation1(a,b,c);
                break;
        }

        system("pause");
        system("cls");
        
    } while (choice!=0);
    cout<<"Quit..."<<endl;
    sleep(2);
    
    return 0;
}
