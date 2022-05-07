//
//  main.cpp
//  SecondClass
//
//  Created by MacBook Air on 30.04.2022.
//

#include <iostream>
#include "Student.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    int Size = 0;
    cout << "Enter the num of students in group: " << endl;
    cin >> Size;
    Student* BV112 = new Student[Size]; //constructor by default
    for (int i = 0; i < Size; i++)
    {
        cout << "Enter the name of student: " <<  i + 1 << endl;
        BV112[i].Set_Console_Input();
    }
    for (int i = 0; i < Size; i++)
    {
        BV112[i].Show();
        BV112[i].Save("BV112.txt");
        cout << endl;
    }
    cout << "The num of students now: " << Student::Get_Count() << endl;
    
    delete[] BV112;
    cout << "The num of students now: " << Student::Get_Count() << endl;
    
    Student Bobrov{"Bobrov", "Bobr", "Bobrovich", 5};
    Bobrov.Set_Grade();
    cout << "The num of students now: " << Student::Get_Count() << endl;
    Bobrov.Show();
    Bobrov.Save("BV112.txt");
 
    
    
    
    return 0;
}
