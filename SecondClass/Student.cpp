//
//  Student.cpp
//  SecondClass
//
//  Created by MacBook Air on 30.04.2022.
//

#include "Student.hpp"

int Student::Count = 0;
int Student::Count_ID = 0;
Student::Student(string LN, string N, string MN, int CG = 0): Last_Name{LN}, Name{N}, Middle_Name{MN}, Count_Grades{CG}, Average_Ball{0.0F}
{
    Count++;
    Count_ID++;
    ID = Count_ID;
    if(Count_Grades)Grades = new int[Count_Grades] {};
    else Grades = nullptr;
}

Student::Student(): Student{"", "", ""}{}

Student::~Student()
{
    cout << "Destructor for ID: " << ID << endl;
    Count--;
    Save();
    if (Grades) delete Grades;
    Grades = nullptr;
}
//сеттеры
void Student::Set_Last_Name(string LN)
{
    Last_Name = LN;
}

void Student::Set_Name(string N)
{
    Name = N;
}
void Student::Set_Middle_Name(string MN)
{
    Middle_Name = MN;
}

void Student::Set_Grade()
{
    Average_Ball = 0.0F;
    cout << "Student " << Last_Name << " " << Name << " " << Middle_Name << " " << Count_Grades << " grades." << endl;
    if(!Count_Grades)
    {
        cout << "Enter the num of grades of " << Last_Name << " " << Name << " " << Middle_Name << ": ";
        cin >> Count_Grades;
        Grades = new int[Count_Grades] {};
    }
    for (int i = 0; i < Count_Grades; i++)
    {
        cout << "Enter grade " << i + 1 << ": "; cin >> Grades[i];
        Average_Ball += Grades[i];
    }
    Average_Ball /= (float) Count_Grades;
}
void Student::Set_Console_Input()
{
    cout << "Enter full name with space: ";
    cin >> Last_Name >> Name >> Middle_Name;
    cin.ignore();
    Set_Grade();
}

//геттеры
string Student::Get_Last_Name() const
{
    return  Last_Name;
}
string Student::Get_Name() const
{
    return  Name;;
}
string Student::Get_Middle_Name() const
{
    return Middle_Name;
}

int Student::Get_ID()const
{
    return ID;
}

int Student::Get_Count()
{
    return Count;
}

const int* Student::Get_Grade() const
{
    return Grades;
}

float Student::Get_Average_Ball() const
{
    return Average_Ball;
}

void Student::Show() const
{
    cout << "Name: " << Last_Name << " " << Name << " " << Middle_Name << endl;
    cout << "Student's ID: " << ID << endl;
    if (!Count_Grades)
    {
        cout << "There are no grades yet!" << endl;
    }
    else
    {
        cout << "Grades: ";
        for (int i = 0; i < Count_Grades; i++)
            cout << Grades[i] << " ";
        cout << "\n Average score: " << Average_Ball << endl;
    }
    
}

void Student::Save(string n) const
{
    ofstream F_Out(n, ios::app);
    F_Out << "Name: " << Last_Name << " " << Name << " " << Middle_Name << "\t";
    F_Out << "Student's ID: " << ID << "\t";
    
    if(!Count_Grades)F_Out<< "There are no grades yet!" << endl;
    else
    {
        F_Out << "Grades: ";
        for (int i = 0; i < Count_Grades; i++)
            F_Out << Grades[i] << " ";
        F_Out << "\tAverage score: " << Average_Ball << endl;
    }
    F_Out.close();
}



