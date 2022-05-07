//
//  Student.hpp
//  SecondClass
//
//  Created by MacBook Air on 30.04.2022.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student
{
    string Last_Name;
    string Name;
    string Middle_Name;
    int Count_Grades;
    int* Grades;
    float Average_Ball;
    int ID;
    static int Count;
    static int Count_ID;
public:
    Student(string, string, string, int);
    Student();
    ~Student();
    
    //сеттеры
    void Set_Last_Name(string);
    void Set_Name(string);
    void Set_Middle_Name(string);
    void Set_Grade();
    void Set_Console_Input();
    
    //геттеры
    string Get_Last_Name() const;
    string Get_Name() const;
    string Get_Middle_Name() const;
    int Get_ID()const;
    static int Get_Count();
    const int* Get_Grade() const;
    float Get_Average_Ball() const;
    void Show() const;
    void Save(string = "backup.txt") const;

};
#endif /* Student_hpp */
