//
//  main.cpp
//  PayrollClass
//
//  Created by MacBook Air on 05.05.2022.
//

#include <iostream>


using namespace std;

class Payroll
{
    double hourlyPR;
    double numberHW;
    double totalPayForTheWeek;
    
public:
    //setter
    void set_hourlyPR(double h)
    {
        hourlyPR = h;
    }
    void set_numberHW(double n)
    {
        numberHW = n;
    }
    void set_totalPayForTheWeek(double t)
    {
        totalPayForTheWeek = t;
    }
    
    //getter
    double get_hourlyPR() const
    {
        return hourlyPR;
    }
    double get_numberHW() const
    {
        return numberHW;
    }
    double get_totalPayForTheWeek() const
    {
        return hourlyPR*numberHW;
    }
    
    
};

int main(int argc, const char * argv[])
{
    const int Size = 2;
    double hourlyPR;
    double numberHW;
    //double totalPayForTheWeek;
    
    Payroll *employee;
    employee = new Payroll[Size];
    for (int i = 0; i < Size; i++)
    {
        cout << "How many hours employee has worked duirng the week?\n";
        cin >> numberHW;
        employee[i].set_numberHW(numberHW);
        cout << "What is the employee's hourly pay rate: \n";
        cin >> hourlyPR;
        employee[i].set_hourlyPR(hourlyPR);
        cout << "Total: $" << employee[i].get_totalPayForTheWeek() << "\n";
    }

    delete [] employee;
    employee = nullptr;
    
    return 0;
}
