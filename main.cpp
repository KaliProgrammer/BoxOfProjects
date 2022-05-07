//
//  main.cpp
//  ShipBattle
//
//  Created by MacBook Air on 10.04.2022.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <unistd.h>


using namespace std;

//создаем два двухмерных массива
//выводим поле и радар
//заполняем символами
//выводим пользовательское меню
//создаём 4 типа короблей
//распологаем корабли
//выводим поле
//начало игры
//ход игрока
//игра продолжается до тех пор пока полностью не потоплены все корабли одного из противников
//объявление победителя
//предложить сиграть снова

//Запрашиваем координату игрока
//Игрок вводит координату
//Отмечаем координату на радаре(если не попал - точка, если попал - крестик)
//Если попал (то есть координата поля компьютера содержит корабль), то делаем дикремент -> следующий ход а если не попал то ход передаётся противнику



void showFieldBattle();
void userMenu();
void inputValidation(char&, int&);
void displayPC();
void inputValidationPC(int& , int&);
void PCMenu();
void showRadar();



const int Size = 10;
string fieldBattle [Size][Size] = { "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□"};

string radar [Size][Size] ={ "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                             "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                             "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                             "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                             "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                             "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                             "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                             "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                             "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                             "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□"};

string pcField [Size][Size] =      { "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□",
                                    "□" , "□", "□", "□", "□", "□", "□", "□", "□", "□"};



    
int main(int argc, const char * argv[]) {
    int numbersOfShipsOfPlayer = 20;
    int numbersOfShipsOfPC = 20;
    bool hit = false;
    char l = ' ';
    int l1 = 0;
    int num = 0;
 
    
    cout << endl;
    cout << endl;
    showFieldBattle();
    userMenu();
    
    cout << "Теперь компьютер располагает корабли! Ожидайте!" << endl;
    
    for (int k = 0; k < 4; k++)
    {
        cout << ".";
        sleep(1);
    }
    cout << endl;
    PCMenu();
    
    system("cls");
    cout << "Корабли расположены! Игра началась! Fight!" << endl;
    
    do{
        
        do {
            system("cls");
            if (numbersOfShipsOfPC == 0)
            {
            break;
            }
            showRadar();
            cout << "Введите координату корабля: " << endl;
            cout << "Буква: " << endl;
            cin >> l;
            while (toupper(l) != 'A' && toupper(l) != 'B' && toupper(l) != 'C' && toupper(l) != 'D' && toupper(l) != 'E' && toupper(l) != 'F' && toupper(l) != 'G' && toupper(l) != 'H' && toupper(l) != 'I' && toupper(l) != 'J')

            {
                cout << "Неправильный ввод! Введите снова: "; cin >> l;
            }

            switch (l)
            {
                case 'A':
                case 'a':
                    l1 = 0;
                    break;
                case 'B':
                case 'b':
                    l1 = 1;
                    break;
                case 'C':
                case 'c':
                    l1 = 2;
                    break;
                case 'D':
                case 'd':
                    l1 = 3;
                    break;
                case 'E':
                case 'e':
                    l1 = 4;
                    break;
                case 'F':
                case 'f':
                    l1 = 5;
                    break;
                case 'G':
                case 'g':
                    l1 = 6;
                    break;
                case 'H':
                case 'h':
                    l1 = 7;
                    break;
                case 'I':
                case 'i':
                    l1 = 8;
                    break;
                case 'J':
                case 'j':
                    l1 = 9;
                    break;
            }
            cout << "Цифра: " << endl;
            cin >> num;
            while (num < 1 || num > 10)
            {
                cout << "Неправильный ввод! Введите цифру от 1 до 10: "; cin >> num;
            }
            if ( pcField[l1][num-1] == "▀")
            {
                sleep(2);
                cout << "Вы попали в корабль противника!" << endl;
                
                radar[l1][num-1] = "X";
                showRadar();
                numbersOfShipsOfPC--;
                if (numbersOfShipsOfPC == 0)
                {

                break;
                }
                hit = true;

            }
            else
            {
                sleep(2);
                cout << "Вы не попали в корабль противника!" << endl;
                radar[l1][num-1] = ".";
                showRadar();
                hit = false;
               
            }

           } while (hit == true);
        
    if (numbersOfShipsOfPC == 0)
    {
    break;
    }
        
        do{
            
            if (numbersOfShipsOfPlayer == 0)
            {
                break;
            }
//            showFieldBattle();
            
            cout << "Ходит компьютер!" << endl;
            for (int j = 0; j < 3; j++)
            {
                cout << ".";
                sleep(1);
            }
            cout << endl;
            
        l1 = rand()%9;
        num = rand()%9;
            
            if (fieldBattle[l1][num] == "▀")
            {
                
                cout << "Компьютер попал в ваш корабль!" << endl;
                fieldBattle[l1][num] = "X";
                showFieldBattle();
                numbersOfShipsOfPlayer--;
                if (numbersOfShipsOfPlayer == 0)
                {
                    break;
                }
                hit = true;
                
            }
            else
            {
                cout <<"Компьютер не попал в ваш корабль!" << endl;
                hit = false;
                sleep(2);

            }
        }while(hit == true);
        if (numbersOfShipsOfPlayer == 0)
        {
            break;
        }
        
        
    } while (numbersOfShipsOfPC != 0 || numbersOfShipsOfPlayer != 0);
    
  
    if (numbersOfShipsOfPC == 0)
    {
        cout << "Вы победили!" << endl;
    }
    else if (numbersOfShipsOfPlayer == 0)
    {
        cout << "Вы проиграли!" << endl;
    }

    return 0;
}

void showFieldBattle()
{
    cout << "    1   2   3   4   5   6   7   8   9   10  " << endl;
    cout << "--------------------------------------------\n";
    for (int i = 0; i < Size; i++)
    {
        if (i == 0)
            cout << "A";
        if (i == 1)
            cout << "B";
        if (i == 2)
            cout << "C";
        if (i == 3)
            cout << "D";
        if (i == 4)
            cout << "E";
        if (i == 5)
            cout << "F";
        if (i == 6)
            cout << "G";
        if (i == 7)
            cout << "H";
        if (i == 8)
            cout << "I";
        if (i == 9)
            cout << "J";
        cout << "| ";
   
        for (int j = 0; j < Size; j++)
        {
            cout << " " << fieldBattle[i][j] << "  " ;
            if (j == 9)
            {
                cout << "|";
            }
        }
        cout << endl;
        cout << endl;

    }
    
}
void userMenu()
{
    int odnopalub = 4;
    int dvuhpalub = 3;
    int trehpalub = 2;
    int chetarehpalub = 1;
    
    char x = ' ';
    int y = 0;
    int userChoice1;
    int z = 0;

    
    do{
        cout << "Расположите однопалубные корабли ( 4 штуки): " << endl;
            cout << "Назовите координаты однопалубного корабля: ";

        do {
            cout << "\nБуква:\n";
            cin >> x;
            while (toupper(x) != 'A' && toupper(x) != 'B' && toupper(x) != 'C' && toupper(x) != 'D' && toupper(x) != 'E' && toupper(x) != 'F' && toupper(x) != 'G' && toupper(x) != 'H' && toupper(x) != 'I' && toupper(x) != 'J')

            {
                cout << "Неправильный ввод! Введите снова: "; cin >> x;
            }

            switch (x)
            {
                case 'A':
                case 'a':
                    z = 0;
                    break;
                case 'B':
                case 'b':
                    z = 1;
                    break;
                case 'C':
                case 'c':
                    z = 2;
                    break;
                case 'D':
                case 'd':
                    z = 3;
                    break;
                case 'E':
                case 'e':
                    z = 4;
                    break;
                case 'F':
                case 'f':
                    z = 5;
                    break;
                case 'G':
                case 'g':
                    z = 6;
                    break;
                case 'H':
                case 'h':
                    z = 7;
                    break;
                case 'I':
                case 'i':
                    z = 8;
                    break;
                case 'J':
                case 'j':
                    z = 9;
                    break;
            }

            cout << "\nЦифра:\n";
            cin >> y;
            while (y < 1 || y > 10)
            {
                cout << "Неправильный ввод! Введите цифру от 1 до 10: "; cin >> y;
            }
            while (fieldBattle[z][y-1] == "▀" )
            {
                cout << "Эта клетка уже занята!";
                inputValidation(x, y);
            }
            while (fieldBattle[z][y-1] == ".")
            {
                cout << "Вы не можете так близко распологать корабли!";
                inputValidation(x, y);
            }

                fieldBattle[z][y-1] = "▀";


            if (y == 1 && z == 0)
            {
                fieldBattle[z][y] = ".";
                fieldBattle[z+1][y-1] = ".";
                fieldBattle[z+1][y] = ".";
            }
            if (y == 10 && z == 0)
            {
                fieldBattle[z+1][y-1] = ".";
                fieldBattle[z][y-2] = ".";
                fieldBattle[z+1][y-2] = ".";
            }
            if (y > 1 && y < 10 && z == 0)
            {
                fieldBattle[z][y-2] = ".";
                fieldBattle[z+1][y-2] = ".";
                fieldBattle[z+1][y-1] = ".";
                fieldBattle[z+1][y] = ".";
                fieldBattle[z][y] = ".";
            }


            if (y == 1 && z == 9)
            {
                fieldBattle[z-1][y] = ".";
                fieldBattle[z-1][y-1] = ".";
                fieldBattle[z][y] = ".";
            }
            if (y == 10 && z == 9)
            {
                fieldBattle[z-1][y-2] = ".";
                fieldBattle[z-1][y-1] = ".";
                fieldBattle[z][y-2] = ".";
            }
            if (y > 1 && y < 10 && z == 9)
            {
                fieldBattle[z][y-2] = ".";
                fieldBattle[z-1][y-2] = ".";
                fieldBattle[z-1][y-1] = ".";
                fieldBattle[z-1][y] = ".";
                fieldBattle[z][y] = ".";
            }
            if (y == 1 && z > 0 && z < 9)
            {
                fieldBattle[z][y] = ".";
                fieldBattle[z-1][y] = ".";
                fieldBattle[z+1][y] = ".";
                fieldBattle[z-1][y-1] = ".";
                fieldBattle[z+1][y-1] = ".";
            }
            if (y == 10 && z > 0 && z < 9)
            {
                fieldBattle[z][y-2] = ".";
                fieldBattle[z-1][y-2] = ".";
                fieldBattle[z+1][y-2] = ".";
                fieldBattle[z-1][y-1] = ".";
                fieldBattle[z+1][y-1] = ".";
            }
            if(z != 0 && z != 9 && y != 1 && y != 10 )
            {
            fieldBattle[z-1][y-1] = ".";
            fieldBattle[z-1][y-2] = ".";
            fieldBattle[z][y-2] = ".";
            fieldBattle[z+1][y-2] = ".";
            fieldBattle[z+1][y-1] = ".";
            fieldBattle[z+1][y] = ".";
            fieldBattle[z][y] = ".";
            fieldBattle[z-1][y] = ".";
            }
            showFieldBattle();
            odnopalub--;

        } while (odnopalub != 0);
        
    
    
    cout << "Расположите двухпалубные корабли (3 штуки): " << endl;
        cout << "Назовите координаты двухпалубного корабля: ";
    do{
    cout << "\nБуква:\n";
    cin >> x;
    while (toupper(x) != 'A' && toupper(x) != 'B' && toupper(x) != 'C' && toupper(x) != 'D' && toupper(x) != 'E' && toupper(x) != 'F' && toupper(x) != 'G' && toupper(x) != 'H' && toupper(x) != 'I' && toupper(x) != 'J')

    {
        cout << "Неправильный ввод! Введите снова: "; cin >> x;
    }
        switch (x)
        {
            case 'A':
            case 'a':
                z = 0;
                break;
            case 'B':
            case 'b':
                z = 1;
                break;
            case 'C':
            case 'c':
                z = 2;
                break;
            case 'D':
            case 'd':
                z = 3;
                break;
            case 'E':
            case 'e':
                z = 4;
                break;
            case 'F':
            case 'f':
                z = 5;
                break;
            case 'G':
            case 'g':
                z = 6;
                break;
            case 'H':
            case 'h':
                z = 7;
                break;
            case 'I':
            case 'i':
                z = 8;
                break;
            case 'J':
            case 'j':
                z = 9;
                break;
        }

        cout << "\nЦифра:\n";
        cin >> y;
        while (y < 1 || y > 10)
        {
            cout << "Неправильный ввод! Введите цифру от 1 до 10: "; cin >> y;
        }
        while (fieldBattle[z][y-1] == "▀" )
        {
            cout << "Эта клетка уже занята!";
            inputValidation(x, y);
        }
        while (fieldBattle[z][y-1] == ".")
        {
            cout << "Вы не можете так близко распологать корабли!";
            inputValidation(x, y);
        }

            fieldBattle[z][y-1] = "▀";
            showFieldBattle();
        do{
        cout << R"(
                               Как желаете расположить двухпалубный корабль?

                                1. □ □ - ( → ) - горизонтально в правую сторону

                                2. □ □ - ( ← ) - горизонтально в левую сторону

                                3. □ - ( ↓ ) - вертикально вниз
                                   □

                                    □
                                4.  □ - ( ↑ ) - вертикально вверх
                                )";

                                cin >> userChoice1;

        } while (userChoice1 < 1 || userChoice1 > 4);

        switch (userChoice1) {
            case 1:
                if (y == 10)
               {
                   cout << "В данном случае в правую сторону распологать корабль нельзя!\n";
                   fieldBattle[z][y-1] = "□";
                   break;
               }

                if ((fieldBattle[z][y] != "▀") && (fieldBattle[z][y] != "."))
                {
                    fieldBattle[z][y] = "▀";
                }
                else
               {
                cout << "Недостаточно места для манёвра." << endl;
                fieldBattle[z][y-1] = "□";
                break;
                }




                if (y == 1 && z == 0)
               {
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y+1] = ".";
                    fieldBattle[z][y+1] = ".";
               }
                if (y == 9 && z == 0)
               {
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y-2] = ".";
                    fieldBattle[z][y-2] = ".";
               }


                 if  (z > 0 && z < 9 && y >1  && y < 10 && y < 9)
                {
                fieldBattle[z][y-2] = ".";
                fieldBattle[z-1][y-2] = ".";
                fieldBattle[z-1][y] = ".";
                fieldBattle[z-1][y-1] = ".";
                fieldBattle[z-1][y+1] = ".";
                fieldBattle[z][y+1] = ".";
                fieldBattle[z+1][y] = ".";
                fieldBattle[z+1][y+1] = ".";
                fieldBattle[z+1][y-1] = ".";
                fieldBattle[z+1][y-2] = ".";
                }

                 if (z > 0 && z < 9 && y == 1)
                {
                fieldBattle[z-1][y-1] = ".";
                fieldBattle[z-1][y] = ".";
                fieldBattle[z-1][y+1] = ".";
                fieldBattle[z][y+1] = ".";
                fieldBattle[z+1][y+1] = ".";
                fieldBattle[z+1][y] = ".";
                fieldBattle[z+1][y-1] = ".";
                }
                 if ( z == 0 && y > 1 && y < 9)
               {
                fieldBattle[z+1][y-1] = ".";
                fieldBattle[z][y+1] = ".";
                fieldBattle[z+1][y+1] = ".";
                fieldBattle[z+1][y] = ".";
                fieldBattle[z][y-2] = ".";
                fieldBattle[z+1][y-2] = ".";
                }
                 if (z > 0 && z < 9 && y == 9)
                {
                fieldBattle[z-1][y-2] = ".";
                fieldBattle[z-1][y-1] = ".";
                fieldBattle[z-1][y] = ".";
                fieldBattle[z][y-2] = ".";
                fieldBattle[z+1][y-2] = ".";
                fieldBattle[z+1][y] = ".";
                fieldBattle[z+1][y-1] = ".";
                }
                if (y == 1 && z == 9)
               {
                    fieldBattle[z-1][y-1] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z-1][y+1] = ".";
                    fieldBattle[z][y+1] = ".";
               }
                if (y == 9 && z == 9)
               {
                    fieldBattle[z][y-2] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z-1][y-1] = ".";
                    fieldBattle[z-1][y] = ".";
               }
                if ( z == 9 && y > 1 && y < 9)
              {
               fieldBattle[z][y-2] = ".";
               fieldBattle[z-1][y-2] = ".";
               fieldBattle[z-1][y-1] = ".";
               fieldBattle[z-1][y] = ".";
               fieldBattle[z-1][y+1] = ".";
               fieldBattle[z][y+1] = ".";
               }

                showFieldBattle();
                dvuhpalub--;
                break;

            case 2:

            if (y == 1)
            {
            cout << "Так нельзя располагать корабль!\n";
            fieldBattle[z][y-1] = "□";
            break;
            }
                if ((fieldBattle[z][y-2] != "▀") && (fieldBattle[z][y-2] != "."))
                {
                    fieldBattle[z][y-2] = "▀";
                }
                else
               {
                cout << "Недостаточно места для манёвра." << endl;
                fieldBattle[z][y-1] = "□";
                break;
               }

            if (y == 10 && z > 0 && z < 9)
            {
                fieldBattle[z+1][y-1] = ".";
                fieldBattle[z-1][y-1] = ".";
                fieldBattle[z-1][y-2] = ".";
                fieldBattle[z+1][y-2] = ".";
                fieldBattle[z-1][y-3] = ".";
                fieldBattle[z][y-3] = ".";
                fieldBattle[z+1][y-3] = ".";
            }
            else if (y == 10 && z == 0)
            {
            fieldBattle[z+1][y-1] = ".";
            fieldBattle[z+1][y-2] = ".";
            fieldBattle[z+1][y-3] = ".";
            fieldBattle[z][y-3] = ".";
            }

            else if (y == 10 && z == 9)
            {
            fieldBattle[z-1][y-1] = ".";
            fieldBattle[z-1][y-2] = ".";
            fieldBattle[z-1][y-3] = ".";
            fieldBattle[z][y-3] = ".";
            }

            else if (y > 1 && y < 10 && z ==9)
            {
                fieldBattle[z][y] = ".";
                fieldBattle[z-1][y] = ".";
                fieldBattle[z-1][y-1] = ".";
                fieldBattle[z-1][y-2] = ".";
                fieldBattle[z-1][y-3] = ".";
                fieldBattle[z][y-3] = ".";

            }
               else  if (y == 2 && z == 9)
                {
                    fieldBattle[z-1][y-1] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z][y] = ".";

                }
             else   if (y == 2 && z > 0 && z < 9)
                {
                    fieldBattle[z][y] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z-1][y-1] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y-2] = ".";
                }
               else  if (y == 2 && z == 0)
                {
                    fieldBattle[z][y] = ".";
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y-2] = ".";
                }
               else  if (z == 0 && y > 1 && y < 10)
                {
                    fieldBattle[z][y] = ".";
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y-2] = ".";
                    fieldBattle[z+1][y-3] = ".";
                    fieldBattle[z][y-3] = ".";

                }
                else
                {
                    fieldBattle[z][y] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z-1][y-1] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z-1][y-3] = ".";
                    fieldBattle[z][y-3] = ".";
                    fieldBattle[z+1][y-3] = ".";
                    fieldBattle[z+1][y-2] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y] = ".";
                }
            showFieldBattle();
            dvuhpalub--;
            break;

            case 3:
                if (z == 9)
                {
                cout << "Так нельзя располагать корабль!\n";
                fieldBattle[z][y-1] = "□";
                break;
                }
                    if ((fieldBattle[z+1][y-1] != "▥") && (fieldBattle[z+1][y-1] != "."))
                    {
                        fieldBattle[z+1][y-1] = "▀";
                    }
                    else
                   {
                    cout << "Недостаточно места для манёвра." << endl;
                    fieldBattle[z][y-1] = "□";
                    break;
                   }

                if (y == 10 && z > 0 && z < 8)
                {
                    fieldBattle[z-1][y-1] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z][y-2] = ".";
                    fieldBattle[z+1][y-2] = ".";
                    fieldBattle[z+2][y-2] = ".";
                    fieldBattle[z+2][y-1] = ".";
                }
                else if (y == 10 && z == 0)
                {
                fieldBattle[z][y-2] = ".";
                fieldBattle[z+1][y-2] = ".";
                fieldBattle[z+2][y-2] = ".";
                fieldBattle[z+2][y-1] = ".";
                }

               else  if (y == 10 && z == 8)
                {
                fieldBattle[z-1][y-1] = ".";
                fieldBattle[z-1][y-2] = ".";
                fieldBattle[z][y-2] = ".";
                fieldBattle[z+1][y-2] = ".";
                }

                else  if (y > 1 && y < 10 && z == 8)
                {
                    fieldBattle[z][y] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z-1][y-1] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z][y-2] = ".";
                    fieldBattle[z+1][y-2] = ".";
                }
                   else  if (y == 1 && z == 8)
                    {
                        fieldBattle[z-1][y-1] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z][y] = ".";
                        fieldBattle[z+1][y] = ".";
                    }
                   else  if (y == 1 && z > 0 && z < 8)
                    {
                        fieldBattle[z-1][y-1] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z][y] = ".";
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z+2][y] = ".";
                        fieldBattle[z+2][y-1] = ".";
                    }
                    else if (y == 1 && z == 0)
                    {
                        fieldBattle[z][y] = ".";
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z+2][y] = ".";
                        fieldBattle[z+2][y-1] = ".";
                    }
                   else  if (z == 0 && y > 1 && y < 10)
                    {
                        fieldBattle[z][y] = ".";
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z+2][y] = ".";
                        fieldBattle[z+2][y-1] = ".";
                        fieldBattle[z+2][y-2] = ".";
                        fieldBattle[z+1][y-2] = ".";
                        fieldBattle[z][y-2] = ".";

                    }

                    else
                    {
                        fieldBattle[z-1][y-2] = ".";
                        fieldBattle[z][y-2] = ".";
                        fieldBattle[z+1][y-2] = ".";
                        fieldBattle[z+2][y-2] = ".";
                        fieldBattle[z+2][y-1] = ".";
                        fieldBattle[z+2][y] = ".";
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z][y] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z-1][y-1] = ".";
                    }
                showFieldBattle();
                dvuhpalub--;
                break;

            case 4:
                if (z == 0)
                            {
                                cout << "Так нельзя располагать корабль! Попробуйте ещё:" << endl;
                                fieldBattle[z][y-1] = "□";
                                break;
                            }

                            if (fieldBattle[z-1][y-1] != "▀" && fieldBattle[z-1][y-1] != ".")
                            {
                                fieldBattle[z-1][y-1] = "▀";
                            }
                            else
                            {
                                    cout << "Нет места для манёвра! Попробуйте другой вариант:" << endl;
                                    fieldBattle[z][y-1] = "□";
                                    break;
                            }

                            if (z == 1 && y == 1)
                            {
                                fieldBattle[z+1][y-1] = ".";
                                fieldBattle[z+1][y] = ".";
                                fieldBattle[z-1][y] = ".";
                                fieldBattle[z][y] = ".";

                            }
                            else if (z == 9 && y == 1)
                            {
                                fieldBattle[z-2][y-1] = ".";
                                fieldBattle[z-2][y] = ".";
                                fieldBattle[z-1][y] = ".";
                                fieldBattle[z][y] = ".";
                            }
                            else if (z > 1 && z < 9 && y == 1)
                            {

                                fieldBattle[z-2][y-1] = ".";
                                fieldBattle[z-2][y] = ".";
                                fieldBattle[z-1][y] = ".";
                                fieldBattle[z][y] = ".";
                                fieldBattle[z+1][y-1] = ".";
                                fieldBattle[z+1][y] = ".";

                            }

                            else if (z == 1 && y == 10)
                            {
                                fieldBattle[z+1][y-1] = ".";
                                fieldBattle[z+1][y-2] = ".";
                                fieldBattle[z-1][y-2] = ".";
                                fieldBattle[z][y-2] = ".";

                            }
                            else if (z == 9 && y == 10)
                            {
                                fieldBattle[z-2][y-1] = ".";
                                fieldBattle[z-2][y-2] = ".";
                                fieldBattle[z-1][y-2] = ".";
                                fieldBattle[z][y-2] = ".";
                            }
                            else if (z > 1 && z < 9 && y == 10)
                            {

                                fieldBattle[z-2][y-1] = ".";
                                fieldBattle[z-2][y-2] = ".";
                                fieldBattle[z-1][y-2] = ".";
                                fieldBattle[z][y-2] = ".";
                                fieldBattle[z+1][y-1] = ".";
                                fieldBattle[z+1][y-2] = ".";
                            }

                            else if (y > 1 && y < 10 && z == 9)
                            {
                                fieldBattle[z-2][y] = ".";
                                fieldBattle[z-2][y-1] = ".";
                                fieldBattle[z-2][y-2] = ".";
                                fieldBattle[z-1][y-2] = ".";
                                fieldBattle[z-1][y] = ".";
                                fieldBattle[z][y] = ".";
                                fieldBattle[z][y-2] = ".";
                            }
                            else if (y > 1 && y < 10 && z == 1)
                            {
                                fieldBattle[z-1][y-2] = ".";
                                fieldBattle[z-1][y] = ".";
                                fieldBattle[z][y-2] = ".";
                                fieldBattle[z][y] = ".";
                                fieldBattle[z+1][y-2] = ".";
                                fieldBattle[z+1][y-1] = ".";
                                fieldBattle[z+1][y] = ".";
                            }

                            else
                            {
                                pcField[z-2][y] = ".";
                                pcField[z-2][y-1] = ".";
                                pcField[z-2][y-2] = ".";
                                pcField[z-1][y-2] = ".";
                                pcField[z-1][y] = ".";
                                pcField[z][y] = ".";
                                pcField[z][y-2] = ".";
                                pcField[z+1][y-2] = ".";
                                pcField[z+1][y-1] = ".";
                                pcField[z+1][y] = ".";
                            }

                            showFieldBattle();
                            dvuhpalub--;
                            break;
        }



//        if (y == 1 && z == 0)
//        {
//            fieldBattle[z][y] = ".";
//            fieldBattle[z+1][y-1] = ".";
//            fieldBattle[z+1][y] = ".";
//        }
//        if (y == 10 && z == 0)
//        {
//            fieldBattle[z+1][y-1] = ".";
//            fieldBattle[z][y-2] = ".";
//            fieldBattle[z+1][y-2] = ".";
//        }
//        if (y > 1 && y < 10 && z == 0)
//        {
//            fieldBattle[z][y-2] = ".";
//            fieldBattle[z+1][y-2] = ".";
//            fieldBattle[z+1][y-1] = ".";
//            fieldBattle[z+1][y] = ".";
//            fieldBattle[z][y] = ".";
//        }
//
//
//        if (y == 1 && z == 9)
//        {
//            fieldBattle[z-1][y] = ".";
//            fieldBattle[z-1][y-1] = ".";
//            fieldBattle[z][y] = ".";
//        }
//        if (y == 10 && z == 9)
//        {
//            fieldBattle[z-1][y-2] = ".";
//            fieldBattle[z-1][y-1] = ".";
//            fieldBattle[z][y-2] = ".";
//        }
//        if (y > 1 && y < 10 && z == 9)
//        {
//            fieldBattle[z][y-2] = ".";
//            fieldBattle[z-1][y-2] = ".";
//            fieldBattle[z-1][y-1] = ".";
//            fieldBattle[z-1][y] = ".";
//            fieldBattle[z][y] = ".";
//        }
//        if (y == 1 && z > 0 && z < 9)
//        {
//            fieldBattle[z][y] = ".";
//            fieldBattle[z-1][y] = ".";
//            fieldBattle[z+1][y] = ".";
//            fieldBattle[z-1][y-1] = ".";
//            fieldBattle[z+1][y-1] = ".";
//        }
//        if (y == 10 && z > 0 && z < 9)
//        {
//            fieldBattle[z][y-2] = ".";
//            fieldBattle[z-1][y-2] = ".";
//            fieldBattle[z+1][y-2] = ".";
//            fieldBattle[z-1][y-1] = ".";
//            fieldBattle[z+1][y-1] = ".";
//        }
//        if(z > 0 && z < 9 && y > 0 && y < 10 )
//        {
//        fieldBattle[z-1][y-1] = ".";
//        fieldBattle[z-1][y-2] = ".";
//        fieldBattle[z][y-2] = ".";
//        fieldBattle[z+1][y-2] = ".";
//        fieldBattle[z+1][y-1] = ".";
//        fieldBattle[z+1][y] = ".";
//        fieldBattle[z][y] = ".";
//        fieldBattle[z-1][y] = ".";
//        }

//        showFieldBattle();
//        odnopalub--;
//



    }while (dvuhpalub != 0);
        
    
    cout << "Расположите трёхпалубные корабли (2 штуки): " << endl;
        cout << "Назовите координаты трёхпалубного корабля: ";
    do{
        cout << "\nБуква:\n";
        cin >> x;
        while (toupper(x) != 'A' && toupper(x) != 'B' && toupper(x) != 'C' && toupper(x) != 'D' && toupper(x) != 'E' && toupper(x) != 'F' && toupper(x) != 'G' && toupper(x) != 'H' && toupper(x) != 'I' && toupper(x) != 'J')

        {
            cout << "Неправильный ввод! Введите снова: "; cin >> x;
        }
        switch (x)
        {
            case 'A':
            case 'a':
                z = 0;
                break;
            case 'B':
            case 'b':
                z = 1;
                break;
            case 'C':
            case 'c':
                z = 2;
                break;
            case 'D':
            case 'd':
                z = 3;
                break;
            case 'E':
            case 'e':
                z = 4;
                break;
            case 'F':
            case 'f':
                z = 5;
                break;
            case 'G':
            case 'g':
                z = 6;
                break;
            case 'H':
            case 'h':
                z = 7;
                break;
            case 'I':
            case 'i':
                z = 8;
                break;
            case 'J':
            case 'j':
                z = 9;
                break;
        }

        cout << "\nЦифра:\n";
        cin >> y;
        while (y < 1 || y > 10)
        {
            cout << "Неправильный ввод! Введите цифру от 1 до 10: "; cin >> y;
        }
        while (fieldBattle[z][y-1] == "▀" )
        {
            cout << "Эта клетка уже занята!";
            inputValidation(x, y);
        }
        while (fieldBattle[z][y-1] == ".")
        {
            cout << "Вы не можете так близко распологать корабли!";
            inputValidation(x, y);
        }

            fieldBattle[z][y-1] = "▀";
            showFieldBattle();
        do{
        cout << R"(
                               Как желаете расположить двухпалубный корабль?

                                1. □ □ □ - ( → ) - горизонтально в правую сторону

                                2. □ □ □ - ( ← ) - горизонтально в левую сторону

                                3. □ - ( ↓ ) - вертикально вниз
                                   □
                                   □

                                    □
                                    □
                                4.  □ - ( ↑ ) - вертикально вверх
                                )";

                                cin >> userChoice1;

        } while (userChoice1 < 1 || userChoice1 > 4);

        switch (userChoice1) {
            case 1:

                if (y > 8)
                {
                    cout << "Так нельзя распологать корабли!" << endl;
                    fieldBattle[z][y-1] = "□";
                    break;
                }
                if ((fieldBattle[z][y] != "▀" && fieldBattle[z][y+1] != "▀") && (fieldBattle[z][y] != "." && fieldBattle[z][y+1] != "."))
                {
                    fieldBattle[z][y] = "▀";
                    fieldBattle[z][y+1] = "▀";
                }
                else
                    {
                    cout << "Недостаточно места для манёвра." << endl;
                    fieldBattle[z][y-1] = "□";
                    break;
                    }

                if (z == 0 && y == 1)
                {
                    fieldBattle[z][y+2] = ".";
                    fieldBattle[z+1][y+2] = ".";
                    fieldBattle[z+1][y+1] = ".";
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y-1] = ".";
                }
                else if (z == 9 && y == 1)
                {
                    fieldBattle[z][y+2] = ".";
                    fieldBattle[z-1][y+2] = ".";
                    fieldBattle[z-1][y+1] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z-1][y-1] = ".";

                }

               else if (z > 0 && z < 9 && y == 1)
                {
                    fieldBattle[z][y+2] = ".";
                    fieldBattle[z-1][y+2] = ".";
                    fieldBattle[z-1][y+1] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z-1][y-1] = ".";
                    fieldBattle[z+1][y+2] = ".";
                    fieldBattle[z+1][y+1] = ".";
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y-1] = ".";
                }
                else if (z > 0 && z < 9 && y == 8)
                {
                    fieldBattle[z][y-2] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z-1][y-1] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z-1][y+1] = ".";
                    fieldBattle[z+1][y-2] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y+1] = ".";
                }

               else if (z == 0 && y == 8)
                {
                    fieldBattle[z+1][y-2] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y+1] = ".";
                    fieldBattle[z][y-2] = ".";

                }
               else if (z == 9 && y == 8)
                {
                    fieldBattle[z][y-2] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z-1][y-1] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z-1][y+1] = ".";
                }


                else if (z == 0 && y > 1 && y < 8)
                {
                    fieldBattle[z][y+2] = ".";
                    fieldBattle[z+1][y+2] = ".";
                    fieldBattle[z+1][y+1] = ".";
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z][y-2] = ".";
                    fieldBattle[z+1][y-2] = ".";
                }

               else if (z == 9 && y > 1 && y < 9)
                {
                    fieldBattle[z][y+2] = ".";
                    fieldBattle[z-1][y+2] = ".";
                    fieldBattle[z-1][y+1] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z-1][y-1] = ".";
                    fieldBattle[z][y-2] = ".";
                    fieldBattle[z-1][y-2] = ".";
                }

                else
                {
                    fieldBattle[z][y+2] = ".";
                    fieldBattle[z-1][y+2] = ".";
                    fieldBattle[z-1][y+1] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z-1][y-1] = ".";
                    fieldBattle[z+1][y+2] = ".";
                    fieldBattle[z+1][y+1] = ".";
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z][y-2] = ".";
                    fieldBattle[z+1][y-2] = ".";

                }
                showFieldBattle();
                trehpalub--;
                break;

            case 2:

                if (y < 3)
                  {
                      cout << "Так нельзя распологать корабли!" << endl;
                      fieldBattle[z][y-1] = "□";
                         break;
                   }

                   if ((fieldBattle[z][y-2] != "▀" && fieldBattle[z][y-3] != "▀") && (fieldBattle[z][y-2] != "." && fieldBattle[z][y-3] != "."))
                     {
                         fieldBattle[z][y-2] = "▀";
                         fieldBattle[z][y-3] = "▀";
                    }
                         else
                {
                    cout << "Недостаточно места для манёвра." << endl;
                    pcField[z][y-1] = "□";
                  break;
                }

                          if (y == 10 && z > 0 && z < 9)
                          {
                              fieldBattle[z+1][y-1] = ".";
                              fieldBattle[z+1][y-2] = ".";
                              fieldBattle[z+1][y-3] = ".";
                              fieldBattle[z+1][y-4] = ".";
                              fieldBattle[z][y-4] = ".";
                              fieldBattle[z-1][y-1] = ".";
                              fieldBattle[z-1][y-2] = ".";
                              fieldBattle[z-1][y-3] = ".";
                              fieldBattle[z-1][y-4] = ".";
                          }
                          else if (y == 10 && z == 0)
                          {
                              fieldBattle[z+1][y-1] = ".";
                              fieldBattle[z+1][y-2] = ".";
                              fieldBattle[z+1][y-3] = ".";
                              fieldBattle[z+1][y-4] = ".";
                              fieldBattle[z][y-4] = ".";
                          }

                          else if (y == 10 && z == 9)
                          {
                              fieldBattle[z-1][y-1] = ".";
                              fieldBattle[z-1][y-2] = ".";
                              fieldBattle[z-1][y-3] = ".";
                              fieldBattle[z-1][y-4] = ".";
                              fieldBattle[z][y-4] = ".";
                          }

                          else if (y > 3 && y < 10 && z == 9)
                          {
                              fieldBattle[z][y] = ".";
                              fieldBattle[z-1][y] = ".";
                              fieldBattle[z-1][y-1] = ".";
                              fieldBattle[z-1][y-2] = ".";
                              fieldBattle[z-1][y-3] = ".";
                              fieldBattle[z-1][y-4] = ".";
                              fieldBattle[z][y-4] = ".";

                          }
                              else if (y == 3 && z == 9)
                              {
                                  fieldBattle[z-1][y-1] = ".";
                                  fieldBattle[z-1][y-2] = ".";
                                  fieldBattle[z-1][y-3] = ".";
                                  fieldBattle[z-1][y] = ".";
                                  fieldBattle[z][y] = ".";

                              }
                              else if (y == 3 && z > 0 && z < 9)
                              {
                                  fieldBattle[z][y] = ".";
                                  fieldBattle[z-1][y] = ".";
                                  fieldBattle[z-1][y-1] = ".";
                                  fieldBattle[z-1][y-2] = ".";
                                  fieldBattle[z-1][y-3] = ".";
                                  fieldBattle[z+1][y] = ".";
                                  fieldBattle[z+1][y-1] = ".";
                                  fieldBattle[z+1][y-2] = ".";
                                  fieldBattle[z+1][y-3] = ".";
                              }
                              else if (y == 3 && z == 0)
                              {
                                  fieldBattle[z+1][y-1] = ".";
                                  fieldBattle[z+1][y-2] = ".";
                                  fieldBattle[z+1][y-3] = ".";
                                  fieldBattle[z+1][y] = ".";
                                  fieldBattle[z][y] = ".";
                              }
                              else if (z == 0 && y > 3 && y < 10)
                              {
                                  fieldBattle[z][y] = ".";
                                  fieldBattle[z+1][y] = ".";
                                  fieldBattle[z+1][y-1] = ".";
                                  fieldBattle[z+1][y-2] = ".";
                                  fieldBattle[z+1][y-3] = ".";
                                  fieldBattle[z+1][y-4] = ".";
                                  fieldBattle[z][y-4] = ".";

                              }
                              else
                              {
                                  fieldBattle[z][y] = ".";
                                  fieldBattle[z-1][y] = ".";
                                  fieldBattle[z-1][y-1] = ".";
                                  fieldBattle[z-1][y-2] = ".";
                                  fieldBattle[z-1][y-3] = ".";
                                  fieldBattle[z-1][y-4] = ".";
                                  fieldBattle[z][y-4] = ".";
                                  fieldBattle[z+1][y-4] = ".";
                                  fieldBattle[z+1][y-3] = ".";
                                  fieldBattle[z+1][y-2] = ".";
                                  fieldBattle[z+1][y-1] = ".";
                                  fieldBattle[z+1][y] = ".";
                              }
                showFieldBattle();
                trehpalub--;
                break;

            case 3:

                if (z > 7)
                    {
                        cout << "Так нельзя распологать корабли!" << endl;
                        pcField[z][y-1] = "□";
                      break;
                    }

                if ((fieldBattle[z+1][y-1] != "▀" && fieldBattle[z+2][y-1] != "▀") && (fieldBattle[z+1][y-1] != "." && fieldBattle[z+2][y-1] != "."))
               {
                   fieldBattle[z+1][y-1] = "▀";
                   fieldBattle[z+2][y-1] = "▀";
               }
               else
              {
                  cout << "Недостаточно места для манёвра." << endl;
                  fieldBattle[z][y-1] = "□";
               break;
              }



                               if (y == 10 && z > 0 && z < 7)
                               {
                                   fieldBattle[z+3][y-1] = ".";
                                   fieldBattle[z+3][y-2] = ".";
                                   fieldBattle[z+2][y-2] = ".";
                                   fieldBattle[z+1][y-2] = ".";
                                   fieldBattle[z][y-2] = ".";
                                   fieldBattle[z-1][y-1] = ".";
                                   fieldBattle[z-1][y-2] = ".";

                               }
                               else if (y == 10 && z == 0)
                               {
                                   fieldBattle[z+3][y-1] = ".";
                                   fieldBattle[z+3][y-2] = ".";
                                   fieldBattle[z+2][y-2] = ".";
                                   fieldBattle[z+1][y-2] = ".";
                                   fieldBattle[z][y-2] = ".";
                               }

                              else  if (y == 10 && z == 7)
                               {
                                   fieldBattle[z-1][y-1] = ".";
                                   fieldBattle[z-1][y-2] = ".";
                                   fieldBattle[z][y-2] = ".";
                                   fieldBattle[z+1][y-2] = ".";
                                   fieldBattle[z+2][y-2] = ".";
                               }



                               else if (y > 1 && y < 10 && z == 7)
                               {
                                   fieldBattle[z][y] = ".";
                                   fieldBattle[z-1][y] = ".";
                                   fieldBattle[z-1][y-1] = ".";
                                   fieldBattle[z-1][y-2] = ".";
                                   fieldBattle[z+1][y] = ".";
                                   fieldBattle[z+2][y] = ".";
                                   fieldBattle[z][y-2] = ".";
                                   fieldBattle[z+1][y-2] = ".";
                                   fieldBattle[z+2][y-2] = ".";
                               }



                                  else  if (y == 1 && z == 7)
                                   {
                                       fieldBattle[z-1][y-1] = ".";
                                       fieldBattle[z-1][y] = ".";
                                       fieldBattle[z][y] = ".";
                                       fieldBattle[z+1][y] = ".";
                                       fieldBattle[z+2][y] = ".";
                                   }


                                  else if (y == 1 && z > 0 && z < 7)
                                   {
                                       fieldBattle[z-1][y-1] = ".";
                                       fieldBattle[z-1][y] = ".";
                                       fieldBattle[z][y] = ".";
                                       fieldBattle[z+1][y] = ".";
                                       fieldBattle[z+2][y] = ".";
                                       fieldBattle[z+3][y] = ".";
                                       fieldBattle[z+3][y-1] = ".";
                                   }
                                   else if (y == 1 && z == 0)
                                   {
                                       fieldBattle[z+3][y-1] = ".";
                                       fieldBattle[z+3][y] = ".";
                                       fieldBattle[z+2][y] = ".";
                                       fieldBattle[z+1][y] = ".";
                                       fieldBattle[z][y] = ".";
                                   }



                                  else  if (z == 0 && y > 1 && y < 10)
                                   {
                                       fieldBattle[z][y] = ".";
                                       fieldBattle[z+1][y] = ".";
                                       fieldBattle[z+2][y] = ".";
                                       fieldBattle[z+3][y] = ".";
                                       fieldBattle[z+3][y-1] = ".";
                                       fieldBattle[z+3][y-2] = ".";
                                       fieldBattle[z+2][y-2] = ".";
                                       fieldBattle[z+1][y-2] = ".";
                                       fieldBattle[z][y-2] = ".";

                                   }

                                   else
                                   {
                                       fieldBattle[z][y] = ".";
                                       fieldBattle[z+1][y] = ".";
                                       fieldBattle[z+2][y] = ".";
                                       fieldBattle[z+3][y] = ".";
                                       fieldBattle[z+3][y-1] = ".";
                                       fieldBattle[z+3][y-2] = ".";
                                       fieldBattle[z+2][y-2] = ".";
                                       fieldBattle[z+1][y-2] = ".";
                                       fieldBattle[z][y-2] = ".";
                                       fieldBattle[z-1][y] = ".";
                                       fieldBattle[z-1][y-1] = ".";
                                       fieldBattle[z-1][y-2] = ".";
                                   }

                showFieldBattle();
                trehpalub--;
                break;


            case 4:

                if (z < 2)
                {
                    cout << "Так нельзя распологать корабли!" << endl;
                    fieldBattle[z][y-1] = "□";
                    break;
                }

                if ((fieldBattle[z-1][y-1] != "▀" && fieldBattle[z-2][y-1] != "▀") && (fieldBattle[z-1][y-1] != "." && fieldBattle[z-2][y-1] != "."))
                   {
                       fieldBattle[z-1][y-1] = "▀";
                       fieldBattle[z-2][y-1] = "▀";

                   }
                else
                    {
                        cout << "Недостаточно места для манёвра." << endl;
                        fieldBattle[z][y-1] = "□";
                     break;
                    }

                if (z == 2 && y == 1)
                {
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z-2][y] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z][y] = ".";
                }

                else if (z == 9 && y == 1)
                {
                    fieldBattle[z-3][y-1] = ".";
                    fieldBattle[z-3][y] = ".";
                    fieldBattle[z-2][y] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z][y] = ".";
                }
                else if (z > 2 && z < 9 && y == 1)
                {

                    fieldBattle[z-3][y-1] = ".";
                    fieldBattle[z-3][y] = ".";
                    fieldBattle[z-2][y] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z][y] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y] = ".";
                }

                else if (z == 2 && y == 10)
                {
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y-2] = ".";
                    fieldBattle[z-2][y-2] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z][y-2] = ".";

                }
                else if (z == 9 && y == 10)
                {
                    fieldBattle[z-3][y-1] = ".";
                    fieldBattle[z-3][y-2] = ".";
                    fieldBattle[z-2][y-2] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z][y-2] = ".";
                }
                else if (z > 2 && z < 9 && y == 10)
                {
                    fieldBattle[z-3][y-1] = ".";
                    fieldBattle[z-3][y-2] = ".";
                    fieldBattle[z-2][y-2] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z][y-2] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y-2] = ".";
                }

                else if (y > 1 && y < 10 && z == 9)
                {
                    fieldBattle[z-3][y-1] = ".";
                    fieldBattle[z-3][y] = ".";
                    fieldBattle[z-2][y] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z][y] = ".";
                    fieldBattle[z-3][y-2] = ".";
                    fieldBattle[z-2][y-2] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z][y-2] = ".";
                }
                else if (y > 1 && y < 10 && z == 2)
                {
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y-2] = ".";

                    fieldBattle[z][y] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z-2][y] = ".";
                    fieldBattle[z][y-2] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z-2][y-2] = ".";
                }

                else
                {
                    fieldBattle[z+1][y] = ".";
                    fieldBattle[z+1][y-1] = ".";
                    fieldBattle[z+1][y-2] = ".";

                    fieldBattle[z][y] = ".";
                    fieldBattle[z-1][y] = ".";
                    fieldBattle[z-2][y] = ".";
                    fieldBattle[z][y-2] = ".";
                    fieldBattle[z-1][y-2] = ".";
                    fieldBattle[z-2][y-2] = ".";

                    fieldBattle[z-3][y] = ".";
                    fieldBattle[z-3][y-1] = ".";
                    fieldBattle[z-3][y-2] = ".";
                }
                showFieldBattle();
                trehpalub--;
                break;


        }

    }while (trehpalub != 0);

        
   
    cout << "Расположите четырёхпалубные корабли (1 штука): " << endl;
        cout << "Назовите координаты четырёхпалубного корабля: ";
        do
        {
            cout << "\nБуква:\n";
            cin >> x;
            while (toupper(x) != 'A' && toupper(x) != 'B' && toupper(x) != 'C' && toupper(x) != 'D' && toupper(x) != 'E' && toupper(x) != 'F' && toupper(x) != 'G' && toupper(x) != 'H' && toupper(x) != 'I' && toupper(x) != 'J')
          
            {
                cout << "Неправильный ввод! Введите снова: "; cin >> x;
            }
            switch (x)
            {
                case 'A':
                case 'a':
                    z = 0;
                    break;
                case 'B':
                case 'b':
                    z = 1;
                    break;
                case 'C':
                case 'c':
                    z = 2;
                    break;
                case 'D':
                case 'd':
                    z = 3;
                    break;
                case 'E':
                case 'e':
                    z = 4;
                    break;
                case 'F':
                case 'f':
                    z = 5;
                    break;
                case 'G':
                case 'g':
                    z = 6;
                    break;
                case 'H':
                case 'h':
                    z = 7;
                    break;
                case 'I':
                case 'i':
                    z = 8;
                    break;
                case 'J':
                case 'j':
                    z = 9;
                    break;
            }
            
            cout << "\nЦифра:\n";
            cin >> y;
            while (y < 1 || y > 10)
            {
                cout << "Неправильный ввод! Введите цифру от 1 до 10: "; cin >> y;
            }
            while (fieldBattle[z][y-1] == "▀" )
            {
                cout << "Эта клетка уже занята!";
                inputValidation(x, y);
            }
            while (fieldBattle[z][y-1] == ".")
            {
                cout << "Вы не можете так близко распологать корабли!";
                inputValidation(x, y);
            }
            
                fieldBattle[z][y-1] = "▀";
                showFieldBattle();
            do{
            cout << R"(
                                   Как желаете расположить двухпалубный корабль?
            
                                    1. □ □ □ - ( → ) - горизонтально в правую сторону
            
                                    2. □ □ □ - ( ← ) - горизонтально в левую сторону
            
                                    3. □ - ( ↓ ) - вертикально вниз
                                       □
                                       □
            
                                        □
                                        □
                                    4.  □ - ( ↑ ) - вертикально вверх
                                    )";
            
                                    cin >> userChoice1;
                
            } while (userChoice1 < 1 || userChoice1 > 4);
            switch (userChoice1)
            {
                case 1:
                    if (y > 7)
                    {
                        cout << "Так нельзя распологать корабли!" << endl;
                        fieldBattle[z][y-1] = "□";
                        break;
                    }
                    if ((fieldBattle[z][y] != "▀" && fieldBattle[z][y+1] != "▀" && fieldBattle[z][y+2] != "▀") && (fieldBattle[z][y] != "." && pcField[z][y+1] != "." && pcField[z][y+2] != "."))
                    {
                        fieldBattle[z][y] = "▀";
                        fieldBattle[z][y+1] = "▀";
                        fieldBattle[z][y+2] = "▀";

                    }
                    else
                        {
                        cout << "Недостаточно места для манёвра." << endl;
                            fieldBattle[z][y-1] = "□";
                        break;
                        }
                    
                    if (z == 0 && y == 1)
                    {
                        fieldBattle[z][y+3] = ".";
                        fieldBattle[z+1][y+3] = ".";
                        fieldBattle[z+1][y+2] = ".";
                        fieldBattle[z+1][y+1] = ".";
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z+1][y-1] = ".";
                    }
                    else if (z == 9 && y == 1)
                    {
                        fieldBattle[z][y+3] = ".";
                        fieldBattle[z-1][y+3] = ".";
                        fieldBattle[z-1][y+2] = ".";
                        fieldBattle[z-1][y+1] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z-1][y-1] = ".";
                        
                    }
                
                   else if (z > 0 && z < 9 && y == 1)
                    {
                        fieldBattle[z][y+3] = ".";
                        fieldBattle[z-1][y+3] = ".";
                        fieldBattle[z-1][y+2] = ".";
                        fieldBattle[z-1][y+1] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z-1][y-1] = ".";
                        fieldBattle[z+1][y+3] = ".";
                        fieldBattle[z+1][y+2] = ".";
                        fieldBattle[z+1][y+1] = ".";
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z+1][y-1] = ".";
                    }
                    else if (z > 0 && z < 9 && y == 7)
                    {
                        fieldBattle[z][y-2] = ".";
                        fieldBattle[z-1][y-2] = ".";
                        fieldBattle[z-1][y-1] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z-1][y+1] = ".";
                        fieldBattle[z-1][y+2] = ".";
                        fieldBattle[z+1][y-2] = ".";
                        fieldBattle[z+1][y-1] = ".";
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z+1][y+1] = ".";
                        fieldBattle[z+1][y+2] = ".";
                    }
                    
                   else if (z == 0 && y == 7)
                    {
                        fieldBattle[z+1][y-2] = ".";
                        fieldBattle[z+1][y-1] = ".";
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z+1][y+1] = ".";
                        fieldBattle[z+1][y+2] = ".";
                        fieldBattle[z][y-2] = ".";
                       
                    }
                   else if (z == 9 && y == 7)
                    {
                        fieldBattle[z][y-2] = ".";
                        fieldBattle[z-1][y-2] = ".";
                        fieldBattle[z-1][y-1] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z-1][y+1] = ".";
                        fieldBattle[z-1][y+2] = ".";
                    }
            
                    else if (z == 0 && y > 1 && y < 8)
                    {
                        fieldBattle[z][y+3] = ".";
                        fieldBattle[z+1][y+3] = ".";
                        fieldBattle[z+1][y+2] = ".";
                        fieldBattle[z+1][y+1] = ".";
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z+1][y-1] = ".";
                        fieldBattle[z][y-2] = ".";
                        fieldBattle[z+1][y-2] = ".";
                    }
                  
                   else if (z == 9 && y > 1 && y < 9)
                    {
                        fieldBattle[z][y+3] = ".";
                        fieldBattle[z-1][y+3] = ".";
                        fieldBattle[z-1][y+2] = ".";
                        fieldBattle[z-1][y+1] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z-1][y-1] = ".";
                        fieldBattle[z][y-2] = ".";
                        fieldBattle[z-1][y-2] = ".";
                    }
                    
                    else
                    {
                        fieldBattle[z][y+3] = ".";
                        fieldBattle[z-1][y+2] = ".";
                        fieldBattle[z-1][y+3] = ".";
                        fieldBattle[z-1][y+1] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z-1][y-1] = ".";
                        fieldBattle[z-1][y-2] = ".";
                        fieldBattle[z][y-2] = ".";
                        fieldBattle[z+1][y+3] = ".";
                        fieldBattle[z+1][y+2] = ".";
                        fieldBattle[z+1][y+1] = ".";
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z+1][y-1] = ".";
                        fieldBattle[z+1][y-2] = ".";
                        
                    }
                    showFieldBattle();
                    chetarehpalub--;
                    break;
                    
                case 2:
                    if (y < 4)
                      {
                          cout << "Так нельзя распологать корабли!" << endl;
                          fieldBattle[z][y-1] = "□";
                             break;
                       }
                   
                       if ((fieldBattle[z][y-2] != "▀" && fieldBattle[z][y-3] != "▀" && fieldBattle[z][y-4] != "▀") && (fieldBattle[z][y-2] != "." && pcField[z][y-3] != "." && pcField[z][y-4] != "."))
                         {
                             fieldBattle[z][y-2] = "▀";
                             fieldBattle[z][y-3] = "▀";
                             fieldBattle[z][y-4] = "▀";
                        }
                             else
                    {
                        cout << "Недостаточно места для манёвра." << endl;
                        fieldBattle[z][y-1] = "□";
                      break;
                    }
                    
                              if (y == 10 && z > 0 && z < 9)
                              {
                                  fieldBattle[z+1][y-1] = ".";
                                  fieldBattle[z+1][y-2] = ".";
                                  fieldBattle[z+1][y-3] = ".";
                                  fieldBattle[z+1][y-4] = ".";
                                  fieldBattle[z+1][y-5] = ".";
                                  fieldBattle[z][y-5] = ".";
                                  fieldBattle[z-1][y-1] = ".";
                                  fieldBattle[z-1][y-2] = ".";
                                  fieldBattle[z-1][y-3] = ".";
                                  fieldBattle[z-1][y-4] = ".";
                                  fieldBattle[z-1][y-5] = ".";
                              }
                              else if (y == 10 && z == 0)
                              {
                                  fieldBattle[z+1][y-1] = ".";
                                  fieldBattle[z+1][y-2] = ".";
                                  fieldBattle[z+1][y-3] = ".";
                                  fieldBattle[z+1][y-4] = ".";
                                  fieldBattle[z+1][y-4] = ".";
                                  fieldBattle[z][y-5] = ".";
                              }
                                  
                              else if (y == 10 && z == 9)
                              {
                                  fieldBattle[z-1][y-1] = ".";
                                  fieldBattle[z-1][y-2] = ".";
                                  fieldBattle[z-1][y-3] = ".";
                                  fieldBattle[z-1][y-4] = ".";
                                  fieldBattle[z-1][y-5] = ".";
                                  fieldBattle[z][y-5] = ".";
                              }

                              else if (y > 4 && y < 10 && z == 9)
                              {
                                  fieldBattle[z][y] = ".";
                                  fieldBattle[z-1][y] = ".";
                                  fieldBattle[z-1][y-1] = ".";
                                  fieldBattle[z-1][y-2] = ".";
                                  fieldBattle[z-1][y-3] = ".";
                                  fieldBattle[z-1][y-4] = ".";
                                  fieldBattle[z-1][y-5] = ".";
                                  fieldBattle[z][y-5] = ".";
                              }
                                  else if (y == 4 && z == 9)
                                  {
                                      fieldBattle[z-1][y-1] = ".";
                                      fieldBattle[z-1][y-2] = ".";
                                      fieldBattle[z-1][y-3] = ".";
                                      fieldBattle[z-1][y-4] = ".";
                                      fieldBattle[z-1][y] = ".";
                                      fieldBattle[z][y] = ".";
                                  }
                                  else if (y == 4 && z > 0 && z < 9)
                                  {
                                      fieldBattle[z][y] = ".";
                                      fieldBattle[z-1][y] = ".";
                                      fieldBattle[z-1][y-1] = ".";
                                      fieldBattle[z-1][y-2] = ".";
                                      fieldBattle[z-1][y-3] = ".";
                                      fieldBattle[z-1][y-4] = ".";
                                      fieldBattle[z+1][y] = ".";
                                      fieldBattle[z+1][y-1] = ".";
                                      fieldBattle[z+1][y-2] = ".";
                                      fieldBattle[z+1][y-3] = ".";
                                      fieldBattle[z+1][y-4] = ".";
                                  }
                                  else if (y == 4 && z == 0)
                                  {
                                      fieldBattle[z+1][y-1] = ".";
                                      fieldBattle[z+1][y-2] = ".";
                                      fieldBattle[z+1][y-3] = ".";
                                      fieldBattle[z+1][y-4] = ".";
                                      fieldBattle[z+1][y] = ".";
                                      fieldBattle[z][y] = ".";
                                  }
                                  else if (z == 0 && y > 4 && y < 10)
                                  {
                                      fieldBattle[z][y] = ".";
                                      fieldBattle[z+1][y] = ".";
                                      fieldBattle[z+1][y-1] = ".";
                                      fieldBattle[z+1][y-2] = ".";
                                      fieldBattle[z+1][y-3] = ".";
                                      fieldBattle[z+1][y-4] = ".";
                                      fieldBattle[z+1][y-5] = ".";
                                      fieldBattle[z][y-5] = ".";
                                  }
                                  else
                                  {
                                      fieldBattle[z][y] = ".";
                                      fieldBattle[z-1][y] = ".";
                                      fieldBattle[z+1][y] = ".";
                                      fieldBattle[z-1][y-1] = ".";
                                      fieldBattle[z-1][y-2] = ".";
                                      fieldBattle[z-1][y-3] = ".";
                                      fieldBattle[z-1][y-4] = ".";
                                      fieldBattle[z-1][y-5] = ".";
                                      fieldBattle[z][y-5] = ".";
                                      fieldBattle[z+1][y-5] = ".";
                                      fieldBattle[z+1][y-4] = ".";
                                      fieldBattle[z+1][y-3] = ".";
                                      fieldBattle[z+1][y-2] = ".";
                                      fieldBattle[z+1][y-1] = ".";
                                  }
                    
                    showFieldBattle();
                    chetarehpalub--;
                    break;
                    
                case 3:
                    
                    if (z > 6)
                        {
                            cout << "Так нельзя распологать корабли!" << endl;
                            fieldBattle[z][y-1] = "□";
                          break;
                        }
                            
                    if ((fieldBattle[z+1][y-1] != "▀" && fieldBattle[z+2][y-1] != "▀" && fieldBattle[z+3][y-1] != "▀") && (fieldBattle[z+1][y-1] != "." && pcField[z+2][y-1] != "." && fieldBattle[z+3][y-1] != "."))
                   {
                       fieldBattle[z+1][y-1] = "▀";
                       fieldBattle[z+2][y-1] = "▀";
                       fieldBattle[z+3][y-1] = "▀";
                   }
                   else
                  {
                      cout << "Недостаточно места для манёвра." << endl;
                      fieldBattle[z][y-1] = "□";
                   break;
                  }

                                   if (y == 10 && z > 0 && z < 6)
                                   {
                                       fieldBattle[z+4][y-1] = ".";
                                       fieldBattle[z+3][y-2] = ".";
                                       fieldBattle[z+4][y-2] = ".";
                                       fieldBattle[z+2][y-2] = ".";
                                       fieldBattle[z+1][y-2] = ".";
                                       fieldBattle[z][y-2] = ".";
                                       fieldBattle[z-1][y-1] = ".";
                                       fieldBattle[z-1][y-2] = ".";
                                   }
                                   else if (y == 10 && z == 0)
                                   {
                                       fieldBattle[z+4][y-1] = ".";
                                       fieldBattle[z+4][y-2] = ".";
                                       fieldBattle[z+3][y-2] = ".";
                                       fieldBattle[z+2][y-2] = ".";
                                       fieldBattle[z+1][y-2] = ".";
                                       fieldBattle[z][y-2] = ".";
                                   }
                                       
                                  else  if (y == 10 && z == 6)
                                   {
                                       fieldBattle[z-1][y-1] = ".";
                                       fieldBattle[z-1][y-2] = ".";
                                       fieldBattle[z][y-2] = ".";
                                       fieldBattle[z+1][y-2] = ".";
                                       fieldBattle[z+2][y-2] = ".";
                                       fieldBattle[z+3][y-2] = ".";
                                   }
                    
                                   else if (y > 1 && y < 10 && z == 6)
                                   {
                                       fieldBattle[z][y] = ".";
                                       fieldBattle[z-1][y] = ".";
                                       fieldBattle[z+1][y] = ".";
                                       fieldBattle[z+2][y] = ".";
                                       fieldBattle[z+3][y] = ".";
                                       fieldBattle[z-1][y-1] = ".";
                                       fieldBattle[z-1][y-2] = ".";
                                       fieldBattle[z][y-2] = ".";
                                       fieldBattle[z+1][y-2] = ".";
                                       fieldBattle[z+2][y-2] = ".";
                                       fieldBattle[z+3][y-2] = ".";
                                   }
                    
                                      else  if (y == 1 && z == 6)
                                       {
                                           fieldBattle[z-1][y-1] = ".";
                                           fieldBattle[z-1][y] = ".";
                                           fieldBattle[z][y] = ".";
                                           fieldBattle[z+1][y] = ".";
                                           fieldBattle[z+2][y] = ".";
                                           fieldBattle[z+3][y] = ".";
                                       }
                    
                                      else if (y == 1 && z > 0 && z < 6)
                                       {
                                           fieldBattle[z-1][y-1] = ".";
                                           fieldBattle[z-1][y] = ".";
                                           fieldBattle[z][y] = ".";
                                           fieldBattle[z+1][y] = ".";
                                           fieldBattle[z+2][y] = ".";
                                           fieldBattle[z+3][y] = ".";
                                           fieldBattle[z+4][y] = ".";
                                           fieldBattle[z+4][y-1] = ".";
                                       }
                                       else if (y == 1 && z == 0)
                                       {
                                           fieldBattle[z+4][y-1] = ".";
                                           fieldBattle[z+3][y] = ".";
                                           fieldBattle[z+4][y] = ".";
                                           fieldBattle[z+2][y] = ".";
                                           fieldBattle[z+1][y] = ".";
                                           fieldBattle[z][y] = ".";
                                       }
                    
                                      else  if (z == 0 && y > 1 && y < 10)
                                       {
                                           fieldBattle[z][y] = ".";
                                           fieldBattle[z+1][y] = ".";
                                           fieldBattle[z+2][y] = ".";
                                           fieldBattle[z+3][y] = ".";
                                           fieldBattle[z+4][y] = ".";
                                           fieldBattle[z+4][y-1] = ".";
                                           fieldBattle[z+4][y-2] = ".";
                                           fieldBattle[z+3][y-2] = ".";
                                           fieldBattle[z+2][y-2] = ".";
                                           fieldBattle[z+1][y-2] = ".";
                                           fieldBattle[z][y-2] = ".";
                                       }
                        
                                       else
                                       {
                                           fieldBattle[z][y] = ".";
                                           fieldBattle[z+1][y] = ".";
                                           fieldBattle[z+2][y] = ".";
                                           fieldBattle[z+3][y] = ".";
                                           fieldBattle[z+4][y] = ".";
                                           fieldBattle[z+4][y-1] = ".";
                                           fieldBattle[z+4][y-2] = ".";
                                           fieldBattle[z+2][y-2] = ".";
                                           fieldBattle[z+3][y-2] = ".";
                                           fieldBattle[z+1][y-2] = ".";
                                           fieldBattle[z][y-2] = ".";
                                           fieldBattle[z-1][y] = ".";
                                           fieldBattle[z-1][y-1] = ".";
                                           fieldBattle[z-1][y-2] = ".";
                                       }
                    showFieldBattle();
                    chetarehpalub--;
                    break;
                    
                case 4:
                    
                    if (z < 3)
                    {
                        cout << "Так нельзя распологать корабли!" << endl;
                        fieldBattle[z][y-1] = "□";
                        break;
                    }
                    
                    if ((fieldBattle[z-1][y-1] != "▀" && fieldBattle[z-2][y-1] != "▀" && fieldBattle[z-3][y-1] != "▀") && (fieldBattle[z-1][y-1] != "." && fieldBattle[z-2][y-1] != "." && fieldBattle[z-3][y-1] != "."))
                       {
                           fieldBattle[z-1][y-1] = "▀";
                           fieldBattle[z-2][y-1] = "▀";
                           fieldBattle[z-3][y-1] = "▀";
                       }
                    else
                        {
                            cout << "Недостаточно места для манёвра." << endl;
                            fieldBattle[z][y-1] = "□";
                         break;
                        }
                    
                    if (z == 3 && y == 1)
                    {
                        fieldBattle[z+1][y-1] = ".";
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z-2][y] = ".";
                        fieldBattle[z-3][y] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z][y] = ".";
                    }
                    
                    else if (z == 9 && y == 1)
                    {
                        fieldBattle[z-3][y] = ".";
                        fieldBattle[z-4][y-1] = ".";
                        fieldBattle[z-4][y] = ".";
                        fieldBattle[z-2][y] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z][y] = ".";
                    }
                    else if (z > 3 && z < 9 && y == 1)
                    {
                        
                        fieldBattle[z-4][y-1] = ".";
                        fieldBattle[z-3][y] = ".";
                        fieldBattle[z-4][y] = ".";
                        fieldBattle[z-2][y] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z][y] = ".";
                        fieldBattle[z+1][y-1] = ".";
                        fieldBattle[z+1][y] = ".";
                    }
                    
                    else if (z == 2 && y == 10)
                    {
                        fieldBattle[z+1][y-1] = ".";
                        fieldBattle[z+1][y-2] = ".";
                        fieldBattle[z-2][y-2] = ".";
                        fieldBattle[z-3][y-2] = ".";
                        fieldBattle[z-1][y-2] = ".";
                        fieldBattle[z][y-2] = ".";
                    }
                    else if (z == 9 && y == 10)
                    {
                        fieldBattle[z-4][y-1] = ".";
                        fieldBattle[z-3][y-2] = ".";
                        fieldBattle[z-4][y-2] = ".";
                        fieldBattle[z-2][y-2] = ".";
                        fieldBattle[z-1][y-2] = ".";
                        fieldBattle[z][y-2] = ".";
                    }
                    else if (z > 3 && z < 9 && y == 10)
                    {
                        fieldBattle[z-4][y-1] = ".";
                        fieldBattle[z-4][y-2] = ".";
                        fieldBattle[z-3][y-2] = ".";
                        fieldBattle[z-2][y-2] = ".";
                        fieldBattle[z-1][y-2] = ".";
                        fieldBattle[z][y-2] = ".";
                        fieldBattle[z+1][y-1] = ".";
                        fieldBattle[z+1][y-2] = ".";
                    }
                    
                    else if (y > 1 && y < 10 && z == 9)
                    {
                        fieldBattle[z-4][y-1] = ".";
                        fieldBattle[z-4][y] = ".";
                        fieldBattle[z-3][y] = ".";
                        fieldBattle[z-2][y] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z][y] = ".";
                        fieldBattle[z-4][y-2] = ".";
                        fieldBattle[z-3][y-2] = ".";
                        fieldBattle[z-2][y-2] = ".";
                        fieldBattle[z-1][y-2] = ".";
                        fieldBattle[z][y-2] = ".";
                    }
                    else if (y > 1 && y < 10 && z == 3)
                    {
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z+1][y-1] = ".";
                        fieldBattle[z+1][y-2] = ".";
                        fieldBattle[z][y] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z-2][y] = ".";
                        fieldBattle[z-3][y] = ".";
                        fieldBattle[z][y-2] = ".";
                        fieldBattle[z-1][y-2] = ".";
                        fieldBattle[z-2][y-2] = ".";
                        fieldBattle[z-3][y-2] = ".";
                    }
                    
                    else
                    {
                        fieldBattle[z+1][y] = ".";
                        fieldBattle[z+1][y-1] = ".";
                        fieldBattle[z+1][y-2] = ".";
                        fieldBattle[z][y] = ".";
                        fieldBattle[z-1][y] = ".";
                        fieldBattle[z-2][y] = ".";
                        fieldBattle[z][y-2] = ".";
                        fieldBattle[z-1][y-2] = ".";
                        fieldBattle[z-2][y-2] = ".";
                        fieldBattle[z-3][y] = ".";
                        fieldBattle[z-4][y] = ".";
                        fieldBattle[z-3][y-2] = ".";
                        fieldBattle[z-4][y-1] = ".";
                        fieldBattle[z-4][y-2] = ".";
                    }
                    showFieldBattle();
                    chetarehpalub--;
                    break;
            }
            
        }while (chetarehpalub != 0);
        
    
    } while(odnopalub != 0 && dvuhpalub != 0 && trehpalub != 0 && chetarehpalub != 0);
    
    }
    
    

void inputValidation(char &x, int &y)
{
    cout << "\nБуква:\n";
    cin >> x;
    while (toupper(x) != 'A' && toupper(x) != 'B' && toupper(x) != 'C' && toupper(x) != 'D' && toupper(x) != 'E' && toupper(x) != 'F' && toupper(x) != 'G' && toupper(x) != 'H' && toupper(x) != 'I' && toupper(x) != 'J')
  
    {
        cout << "Неправильный ввод! Введите снова: "; cin >> x;
    }
    cout << "\nЦифра:\n";
    cin >> y;
    while (y < 1 || y > 10)
    {
        cout << "Неправильный ввод! Введите цифру от 1 до 10: "; cin >> y;
    }
}




void PCMenu()
{
    int odnopalub = 4;
    int dvuhpalub = 3;
    int trehpalub = 2;
    int chetarehpalub = 1;
    int z = 0;
    int y = 0;
    int PCinput;
 
    srand(static_cast<unsigned int>(time(0)));


    do {

        z = rand()%9;
        y = rand()%10 + 1;

        while (pcField[z][y-1] == "▀" || pcField[z][y-1] == "." )
        {

            inputValidationPC(z, y);
        }

            pcField[z][y-1] = "▀";


        if (y == 1 && z == 0)
        {
            pcField[z][y] = ".";
            pcField[z+1][y-1] = ".";
            pcField[z+1][y] = ".";
        }
        if (y == 10 && z == 0)
        {
            pcField[z+1][y-1] = ".";
            pcField[z][y-2] = ".";
            pcField[z+1][y-2] = ".";
        }
        if (y > 1 && y < 10 && z == 0)
        {
            pcField[z][y-2] = ".";
            pcField[z+1][y-2] = ".";
            pcField[z+1][y-1] = ".";
            pcField[z+1][y] = ".";
            pcField[z][y] = ".";
        }

        if (y == 1 && z == 9)
        {
            pcField[z-1][y] = ".";
            pcField[z-1][y-1] = ".";
            pcField[z][y] = ".";
        }
        if (y == 10 && z == 9)
        {
            pcField[z-1][y-2] = ".";
            pcField[z-1][y-1] = ".";
            pcField[z][y-2] = ".";
        }
        if (y > 1 && y < 10 && z == 9)
        {
            pcField[z][y-2] = ".";
            pcField[z-1][y-2] = ".";
            pcField[z-1][y-1] = ".";
            pcField[z-1][y] = ".";
            pcField[z][y] = ".";
        }
        if (y == 1 && z > 0 && z < 9)
        {
            pcField[z][y] = ".";
            pcField[z-1][y] = ".";
            pcField[z+1][y] = ".";
            pcField[z-1][y-1] = ".";
            pcField[z+1][y-1] = ".";
        }
        if (y == 10 && z > 0 && z < 9)
        {
            pcField[z][y-2] = ".";
            pcField[z-1][y-2] = ".";
            pcField[z+1][y-2] = ".";
            pcField[z-1][y-1] = ".";
            pcField[z+1][y-1] = ".";
        }
        if(z != 0 && z != 9 && y != 1 && y != 10 )
        {
            pcField[z-1][y-1] = ".";
            pcField[z-1][y-2] = ".";
            pcField[z][y-2] = ".";
            pcField[z+1][y-2] = ".";
            pcField[z+1][y-1] = ".";
            pcField[z+1][y] = ".";
            pcField[z][y] = ".";
            pcField[z-1][y] = ".";
        }
        odnopalub--;



    } while (odnopalub != 0);



    do
    {

        z = rand()%9;
        y = rand()%10 + 1;


        while (y < 1 || y > 10)
        {
            cin >> y;
        }
        while (pcField[z][y-1] == "▀" )
        {
            inputValidationPC(z, y);
        }
        while (pcField[z][y-1] == ".")
        {
            inputValidationPC(z, y);
        }

            pcField[z][y-1] = "▀";

        PCinput = rand()%4+1;

        switch (PCinput) {
            case 1:
                if (y == 10)
                {
                    pcField[z][y-1] = "□";
                    break;
                }
                if (pcField[z][y] != "▀" && pcField[z][y] != ".")
                           {
                               pcField[z][y] = "▀";
                           }
                           else
                           {

                                   pcField[z][y-1] = "□";
                                   break;
                           }
                if (y == 1 && z == 0)
               {
                    pcField[z+1][y-1] = ".";
                   pcField[z+1][y] = ".";
                   pcField[z+1][y+1] = ".";
                   pcField[z][y+1] = ".";
               }
                if (y == 9 && z == 0)
               {
                   pcField[z+1][y] = ".";
                   pcField[z+1][y-1] = ".";
                   pcField[z+1][y-2] = ".";
                   pcField[z][y-2] = ".";
               }


                 if  (z > 0 && z < 9 && y >1  && y < 10 && y < 9)
                {
                    pcField[z][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z][y+1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y-2] = ".";
                }

                 if (z > 0 && z < 9 && y == 1)
                {
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z][y+1] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                }
                 if ( z == 0 && y > 1 && y < 9)
               {
                   pcField[z+1][y-1] = ".";
                   pcField[z][y+1] = ".";
                   pcField[z+1][y+1] = ".";
                   pcField[z+1][y] = ".";
                   pcField[z][y-2] = ".";
                   pcField[z+1][y-2] = ".";
                }
                 if (z > 0 && z < 9 && y == 9)
                {
                    pcField[z-1][y-2] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z+1][y-2] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                }
                if (y == 1 && z == 9)
               {
                   pcField[z-1][y-1] = ".";
                   pcField[z-1][y] = ".";
                   pcField[z-1][y+1] = ".";
                   pcField[z][y+1] = ".";
               }
                if (y == 9 && z == 9)
               {
                   pcField[z][y-2] = ".";
                   pcField[z-1][y-2] = ".";
                   pcField[z-1][y-1] = ".";
                   pcField[z-1][y] = ".";
               }
                if ( z == 9 && y > 1 && y < 9)
              {
                  pcField[z][y-2] = ".";
                  pcField[z-1][y-2] = ".";
                  pcField[z-1][y-1] = ".";
                  pcField[z-1][y] = ".";
                  pcField[z-1][y+1] = ".";
                  pcField[z][y+1] = ".";
               }

                dvuhpalub--;
                break;

            case 2:

                if (y == 1)
                {
                    pcField[z][y-1] = "□";
                break;
                }
                    if ((pcField[z][y-2] != "▀") && (pcField[z][y-2] != "."))
                    {
                        pcField[z][y-2] = "▀";
                    }
                    else
                   {
                       pcField[z][y-1] = "□";
                    break;
                   }

                if (y == 10 && z > 0 && z < 9)
                {
                    pcField[z+1][y-1] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z+1][y-2] = ".";
                    pcField[z-1][y-3] = ".";
                    pcField[z][y-3] = ".";
                    pcField[z+1][y-3] = ".";
                }
                else if (y == 10 && z == 0)
                {
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y-2] = ".";
                    pcField[z+1][y-3] = ".";
                    pcField[z][y-3] = ".";
                }

                else if (y == 10 && z == 9)
                {
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z-1][y-3] = ".";
                    pcField[z][y-3] = ".";
                }

                else if (y > 1 && y < 10 && z ==9)
                {
                    pcField[z][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z-1][y-3] = ".";
                    pcField[z][y-3] = ".";

                }
                   else  if (y == 2 && z == 9)
                    {
                        pcField[z-1][y-1] = ".";
                        pcField[z-1][y-2] = ".";
                        pcField[z-1][y] = ".";
                        pcField[z][y] = ".";

                    }
                 else   if (y == 2 && z > 0 && z < 9)
                    {
                        pcField[z][y] = ".";
                        pcField[z-1][y] = ".";
                        pcField[z-1][y-1] = ".";
                        pcField[z-1][y-2] = ".";
                        pcField[z+1][y] = ".";
                        pcField[z+1][y-1] = ".";
                        pcField[z+1][y-2] = ".";
                    }
                   else  if (y == 2 && z == 0)
                    {
                        pcField[z][y] = ".";
                        pcField[z+1][y] = ".";
                        pcField[z+1][y-1] = ".";
                        pcField[z+1][y-2] = ".";
                    }
                   else  if (z == 0 && y > 1 && y < 10)
                    {
                        pcField[z][y] = ".";
                        pcField[z+1][y] = ".";
                        pcField[z+1][y-1] = ".";
                        pcField[z+1][y-2] = ".";
                        pcField[z+1][y-3] = ".";
                        pcField[z][y-3] = ".";

                    }
                    else
                    {
                        pcField[z][y] = ".";
                        pcField[z-1][y] = ".";
                        pcField[z-1][y-1] = ".";
                        pcField[z-1][y-2] = ".";
                        pcField[z-1][y-3] = ".";
                        pcField[z][y-3] = ".";
                        pcField[z+1][y-3] = ".";
                        pcField[z+1][y-2] = ".";
                        pcField[z+1][y-1] = ".";
                        pcField[z+1][y] = ".";
                    }

                dvuhpalub--;
                break;

            case 3:
                if (z == 9)
                {
                pcField[z][y-1] = "□";
                break;
                }
                    if ((pcField[z+1][y-1] != "▀") && (pcField[z+1][y-1] != "."))
                    {
                        pcField[z+1][y-1] = "▀";
                    }
                    else
                   {
                    pcField[z][y-1] = "□";
                    break;
                   }

                if (y == 10 && z > 0 && z < 8)
                {
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z+1][y-2] = ".";
                    pcField[z+2][y-2] = ".";
                    pcField[z+2][y-1] = ".";
                }
                else if (y == 10 && z == 0)
                {
                    pcField[z][y-2] = ".";
                    pcField[z+1][y-2] = ".";
                    pcField[z+2][y-2] = ".";
                    pcField[z+2][y-1] = ".";
                }

               else  if (y == 10 && z == 8)
                {
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z+1][y-2] = ".";
                }

                else  if (y > 1 && y < 10 && z == 8)
                {
                    pcField[z][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z+1][y-2] = ".";
                }
                   else  if (y == 1 && z == 8)
                    {
                        pcField[z-1][y-1] = ".";
                        pcField[z-1][y] = ".";
                        pcField[z][y] = ".";
                        pcField[z+1][y] = ".";
                    }
                   else  if (y == 1 && z > 0 && z < 8)
                    {
                        pcField[z-1][y-1] = ".";
                        pcField[z-1][y] = ".";
                        pcField[z][y] = ".";
                        pcField[z+1][y] = ".";
                        pcField[z+2][y] = ".";
                        pcField[z+2][y-1] = ".";
                    }
                    else if (y == 1 && z == 0)
                    {
                        pcField[z][y] = ".";
                        pcField[z+1][y] = ".";
                        pcField[z+2][y] = ".";
                        pcField[z+2][y-1] = ".";
                    }
                   else  if (z == 0 && y > 1 && y < 10)
                    {
                        pcField[z][y] = ".";
                        pcField[z+1][y] = ".";
                        pcField[z+2][y] = ".";
                        pcField[z+2][y-1] = ".";
                        pcField[z+2][y-2] = ".";
                        pcField[z+1][y-2] = ".";
                        pcField[z][y-2] = ".";

                    }

                    else
                    {
                        pcField[z-1][y-2] = ".";
                        pcField[z][y-2] = ".";
                        pcField[z+1][y-2] = ".";
                        pcField[z+2][y-2] = ".";
                        pcField[z+2][y-1] = ".";
                        pcField[z+2][y] = ".";
                        pcField[z+1][y] = ".";
                        pcField[z][y] = ".";
                        pcField[z-1][y] = ".";
                        pcField[z-1][y-1] = ".";
                    }
                dvuhpalub--;
                break;


            case 4:
                if (z == 0)
                            {
                                pcField[z][y-1] = "□";
                                break;
                            }

                            if (pcField[z-1][y-1] != "▀" && pcField[z-1][y-1] != ".")
                            {
                                pcField[z-1][y-1] = "▀";
                            }
                            else
                            {
                                pcField[z][y-1] = "□";
                                    break;
                            }

                            if (z == 1 && y == 1)
                            {
                                pcField[z+1][y-1] = ".";
                                pcField[z+1][y] = ".";
                                pcField[z-1][y] = ".";
                                pcField[z][y] = ".";

                            }
                            else if (z == 9 && y == 1)
                            {
                                pcField[z-2][y-1] = ".";
                                pcField[z-2][y] = ".";
                                pcField[z-1][y] = ".";
                                pcField[z][y] = ".";
                            }
                            else if (z > 1 && z < 9 && y == 1)
                            {

                                pcField[z-2][y-1] = ".";
                                pcField[z-2][y] = ".";
                                pcField[z-1][y] = ".";
                                pcField[z][y] = ".";
                                pcField[z+1][y-1] = ".";
                                pcField[z+1][y] = ".";

                            }

                            else if (z == 1 && y == 10)
                            {
                                pcField[z+1][y-1] = ".";
                                pcField[z+1][y-2] = ".";
                                pcField[z-1][y-2] = ".";
                                pcField[z][y-2] = ".";

                            }
                            else if (z == 9 && y == 10)
                            {
                                pcField[z-2][y-1] = ".";
                                pcField[z-2][y-2] = ".";
                                pcField[z-1][y-2] = ".";
                                pcField[z][y-2] = ".";
                            }
                            else if (z > 1 && z < 9 && y == 10)
                            {

                                pcField[z-2][y-1] = ".";
                                pcField[z-2][y-2] = ".";
                                pcField[z-1][y-2] = ".";
                                pcField[z][y-2] = ".";
                                pcField[z+1][y-1] = ".";
                                pcField[z+1][y-2] = ".";
                            }

                            else if (y > 1 && y < 10 && z == 9)
                            {
                                pcField[z-2][y] = ".";
                                pcField[z-2][y-1] = ".";
                                pcField[z-2][y-2] = ".";
                                pcField[z-1][y-2] = ".";
                                pcField[z+1][y] = ".";
                                pcField[z][y] = ".";
                                pcField[z][y-2] = ".";
                            }
                            else if (y > 1 && y < 10 && z == 1)
                            {
                                pcField[z-1][y-2] = ".";
                                pcField[z-1][y] = ".";
                                pcField[z][y-2] = ".";
                                pcField[z][y] = ".";
                                pcField[z+1][y-2] = ".";
                                pcField[z+1][y-1] = ".";
                                pcField[z+1][y] = ".";
                            }

                            else
                            {
                                pcField[z-2][y] = ".";
                                pcField[z-2][y-1] = ".";
                                pcField[z-2][y-2] = ".";
                                pcField[z-1][y-2] = ".";
                                pcField[z-1][y] = ".";
                                pcField[z][y] = ".";
                                pcField[z][y-2] = ".";
                                pcField[z+1][y-2] = ".";
                                pcField[z+1][y-1] = ".";
                                pcField[z+1][y] = ".";
                            }

                            dvuhpalub--;
                            break;

        }
        displayPC();


    } while (dvuhpalub != 0);




    do {

            z = rand() % 9;
            y = rand() % 10 + 1;


        while (pcField[z][y-1] == "▀" || pcField[z][y-1] == ".")
        {

            inputValidationPC(z, y);
        }

        pcField[z][y-1] = "▀";


            PCinput = rand() % 4 + 1;



        switch (PCinput)
        {
            case 1:

                if (y > 8)
                {
                    pcField[z][y-1] = "□";
                    break;
                }
                if ((pcField[z][y] != "▀" && pcField[z][y+1] != "▀") && (pcField[z][y] != "." && pcField[z][y+1] != "."))
                {
                    pcField[z][y] = "▀";
                    pcField[z][y+1] = "▀";
                }
                else
                    {
                    pcField[z][y-1] = "□";
                    break;
                    }

                if (z == 0 && y == 1)
                {
                    pcField[z][y+2] = ".";
                    pcField[z+1][y+2] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                }
                else if (z == 9 && y == 1)
                {
                    pcField[z][y+2] = ".";
                    pcField[z-1][y+2] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y-1] = ".";

                }

               else if (z > 0 && z < 9 && y == 1)
                {
                    pcField[z][y+2] = ".";
                    pcField[z-1][y+2] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z+1][y+2] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                }
                else if (z > 0 && z < 9 && y == 8)
                {
                    pcField[z][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z+1][y-2] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y+1] = ".";
                }

               else if (z == 0 && y == 8)
                {
                    pcField[z+1][y-2] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z][y-2] = ".";

                }
               else if (z == 9 && y == 8)
                {
                    pcField[z][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y+1] = ".";
                }


                else if (z == 0 && y > 1 && y < 8)
                {
                    pcField[z][y+2] = ".";
                    pcField[z+1][y+2] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z+1][y-2] = ".";
                }

               else if (z == 9 && y > 1 && y < 9)
                {
                    pcField[z][y+2] = ".";
                    pcField[z-1][y+2] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                }

                else
                {
                    pcField[z][y+2] = ".";

                    pcField[z-1][y+2] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y-1] = ".";

                    pcField[z+1][y+2] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";

                    pcField[z-1][y-2] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z+1][y-2] = ".";

                }

                trehpalub--;
                break;

            case 2:
                if (y < 3)
                  {
                      pcField[z][y-1] = "□";
                         break;
                   }

                   if ((pcField[z][y-2] != "▀" && pcField[z][y-3] != "▀") && (pcField[z][y-2] != "." && pcField[z][y-3] != "."))
                     {
                         pcField[z][y-2] = "▀";
                         pcField[z][y-3] = "▀";
                    }
                         else
                {
                    pcField[z][y-1] = "□";
                  break;
                }


                          if (y == 10 && z > 0 && z < 9)
                          {
                              pcField[z+1][y-1] = ".";
                              pcField[z+1][y-2] = ".";
                              pcField[z+1][y-3] = ".";
                              pcField[z+1][y-4] = ".";
                              pcField[z][y-4] = ".";
                              pcField[z-1][y-1] = ".";
                              pcField[z-1][y-2] = ".";
                              pcField[z-1][y-3] = ".";
                              pcField[z-1][y-4] = ".";
                          }
                          else if (y == 10 && z == 0)
                          {
                              pcField[z+1][y-1] = ".";
                              pcField[z+1][y-2] = ".";
                              pcField[z+1][y-3] = ".";
                              pcField[z+1][y-4] = ".";
                              pcField[z][y-4] = ".";
                          }

                          else if (y == 10 && z == 9)
                          {
                              pcField[z-1][y-1] = ".";
                              pcField[z-1][y-2] = ".";
                              pcField[z-1][y-3] = ".";
                              pcField[z-1][y-4] = ".";
                              pcField[z][y-4] = ".";
                          }

                          else if (y > 3 && y < 10 && z == 9)
                          {
                              pcField[z][y] = ".";
                              pcField[z-1][y] = ".";
                              pcField[z-1][y-1] = ".";
                              pcField[z-1][y-2] = ".";
                              pcField[z-1][y-3] = ".";
                              pcField[z-1][y-4] = ".";
                              pcField[z][y-4] = ".";

                          }
                              else if (y == 3 && z == 9)
                              {
                                  pcField[z-1][y-1] = ".";
                                  pcField[z-1][y-2] = ".";
                                  pcField[z-1][y-3] = ".";
                                  pcField[z-1][y] = ".";
                                  pcField[z][y] = ".";

                              }
                              else if (y == 3 && z > 0 && z < 9)
                              {
                                  pcField[z][y] = ".";
                                  pcField[z-1][y] = ".";
                                  pcField[z-1][y-1] = ".";
                                  pcField[z-1][y-2] = ".";
                                  pcField[z-1][y-3] = ".";
                                  pcField[z+1][y] = ".";
                                  pcField[z+1][y-1] = ".";
                                  pcField[z+1][y-2] = ".";
                                  pcField[z+1][y-3] = ".";
                              }
                              else if (y == 3 && z == 0)
                              {
                                  pcField[z+1][y-1] = ".";
                                  pcField[z+1][y-2] = ".";
                                  pcField[z+1][y-3] = ".";
                                  pcField[z+1][y] = ".";
                                  pcField[z][y] = ".";
                              }
                              else if (z == 0 && y > 3 && y < 10)
                              {
                                  pcField[z][y] = ".";
                                  pcField[z+1][y] = ".";
                                  pcField[z+1][y-1] = ".";
                                  pcField[z+1][y-2] = ".";
                                  pcField[z+1][y-3] = ".";
                                  pcField[z+1][y-4] = ".";
                                  pcField[z][y-4] = ".";

                              }
                              else
                              {
                                  pcField[z][y] = ".";
                                  pcField[z-1][y] = ".";
                                  pcField[z-1][y-1] = ".";
                                  pcField[z-1][y-2] = ".";
                                  pcField[z-1][y-3] = ".";
                                  pcField[z-1][y-4] = ".";
                                  pcField[z][y-4] = ".";
                                  pcField[z+1][y-4] = ".";
                                  pcField[z+1][y-3] = ".";
                                  pcField[z+1][y-2] = ".";
                                  pcField[z+1][y-1] = ".";
                                  pcField[z+1][y] = ".";
                              }


                trehpalub--;
                break;

            case 3:

                if (z > 7)
                    {

                        pcField[z][y-1] = "□";
                      break;
                    }

                if ((pcField[z+1][y-1] != "▀" && pcField[z+2][y-1] != "▀") && (pcField[z+1][y-1] != "." && pcField[z+2][y-1] != "."))
               {
                   pcField[z+1][y-1] = "▀";
                   pcField[z+2][y-1] = "▀";
               }
               else
              {

                  pcField[z][y-1] = "□";
               break;
              }



                               if (y == 10 && z > 0 && z < 7)
                               {

                                   pcField[z+3][y-1] = ".";
                                   pcField[z+3][y-2] = ".";
                                   pcField[z+2][y-2] = ".";
                                   pcField[z+1][y-2] = ".";
                                   pcField[z][y-2] = ".";
                                   pcField[z-1][y-1] = ".";
                                   pcField[z-1][y-2] = ".";

                               }
                               else if (y == 10 && z == 0)
                               {
                                   pcField[z+3][y-1] = ".";
                                   pcField[z+3][y-2] = ".";
                                   pcField[z+2][y-2] = ".";
                                   pcField[z+1][y-2] = ".";
                                   pcField[z][y-2] = ".";
                               }

                              else  if (y == 10 && z == 7)
                               {
                                   pcField[z-1][y-1] = ".";
                                   pcField[z-1][y-2] = ".";
                                   pcField[z][y-2] = ".";
                                   pcField[z+1][y-2] = ".";
                                   pcField[z+2][y-2] = ".";
                               }



                               else if (y > 1 && y < 10 && z == 7)
                               {
                                   pcField[z][y] = ".";
                                   pcField[z-1][y] = ".";
                                   pcField[z-1][y-1] = ".";
                                   pcField[z-1][y-2] = ".";
                                   pcField[z+1][y] = ".";
                                   pcField[z+2][y] = ".";
                                   pcField[z][y-2] = ".";
                                   pcField[z+1][y-2] = ".";
                                   pcField[z+2][y-2] = ".";
                               }



                                  else  if (y == 1 && z == 7)
                                   {
                                       pcField[z-1][y-1] = ".";
                                       pcField[z-1][y] = ".";
                                       pcField[z][y] = ".";
                                       pcField[z+1][y] = ".";
                                       pcField[z+2][y] = ".";
                                   }


                                  else if (y == 1 && z > 0 && z < 7)
                                   {
                                       pcField[z-1][y-1] = ".";
                                       pcField[z-1][y] = ".";
                                       pcField[z][y] = ".";
                                       pcField[z+1][y] = ".";
                                       pcField[z+2][y] = ".";
                                       pcField[z+3][y] = ".";
                                       pcField[z+3][y-1] = ".";
                                   }
                                   else if (y == 1 && z == 0)
                                   {
                                       pcField[z+3][y-1] = ".";
                                       pcField[z+3][y] = ".";
                                       pcField[z+2][y] = ".";
                                       pcField[z+1][y] = ".";
                                       pcField[z][y] = ".";
                                   }



                                  else  if (z == 0 && y > 1 && y < 10)
                                   {
                                       pcField[z][y] = ".";
                                       pcField[z+1][y] = ".";
                                       pcField[z+2][y] = ".";
                                       pcField[z+3][y] = ".";
                                       pcField[z+3][y-1] = ".";
                                       pcField[z+3][y-2] = ".";
                                       pcField[z+2][y-2] = ".";
                                       pcField[z+1][y-2] = ".";
                                       pcField[z][y-2] = ".";

                                   }

                                   else
                                   {
                                       pcField[z][y] = ".";
                                       pcField[z+1][y] = ".";
                                       pcField[z+2][y] = ".";
                                       pcField[z+3][y] = ".";
                                       pcField[z+3][y-1] = ".";
                                       pcField[z+3][y-2] = ".";
                                       pcField[z+2][y-2] = ".";
                                       pcField[z+1][y-2] = ".";
                                       pcField[z][y-2] = ".";
                                       pcField[z-1][y] = ".";
                                       pcField[z-1][y-1] = ".";
                                       pcField[z-1][y-2] = ".";
                                   }

                trehpalub--;
                break;



            case 4:

                if (z < 2)
                {

                    pcField[z][y-1] = "□";
                    break;
                }

                if ((pcField[z-1][y-1] != "▀" && pcField[z-2][y-1] != "▀") && (pcField[z-1][y-1] != "." && pcField[z-2][y-1] != "."))
                   {
                       pcField[z-1][y-1] = "▀";
                       pcField[z-2][y-1] = "▀";

                   }
                else
                    {
                        pcField[z][y-1] = "□";
                     break;
                    }

                if (z == 2 && y == 1)
                {
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z-2][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z][y] = ".";
                }

                else if (z == 9 && y == 1)
                {
                    pcField[z-3][y-1] = ".";
                    pcField[z-3][y] = ".";
                    pcField[z-2][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z][y] = ".";
                }
                else if (z > 2 && z < 9 && y == 1)
                {

                    pcField[z-3][y-1] = ".";
                    pcField[z-3][y] = ".";
                    pcField[z-2][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z][y] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y] = ".";
                }

                else if (z == 2 && y == 10)
                {
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y-2] = ".";
                    pcField[z-2][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z][y-2] = ".";

                }
                else if (z == 9 && y == 10)
                {
                    pcField[z-3][y-1] = ".";
                    pcField[z-3][y-2] = ".";
                    pcField[z-2][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z][y-2] = ".";
                }
                else if (z > 2 && z < 9 && y == 10)
                {
                    pcField[z-3][y-1] = ".";
                    pcField[z-3][y-2] = ".";
                    pcField[z-2][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y-2] = ".";
                }

                else if (y > 1 && y < 10 && z == 9)
                {
                    pcField[z-3][y-1] = ".";
                    pcField[z-3][y] = ".";
                    pcField[z-2][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z][y] = ".";
                    pcField[z-3][y-2] = ".";
                    pcField[z-2][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z][y-2] = ".";
                }
                else if (y > 1 && y < 10 && z == 2)
                {
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y-2] = ".";

                    pcField[z][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-2][y] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z-2][y-2] = ".";
                }

                else
                {
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y-2] = ".";

                    pcField[z][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-2][y] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z-2][y-2] = ".";

                    pcField[z-3][y] = ".";
                    pcField[z-3][y-1] = ".";
                    pcField[z-3][y-2] = ".";
                }

                trehpalub--;
                break;

        }
        displayPC();


        } while(trehpalub != 0);

    
    
    do
    {
        z = rand() % 9;
        y = rand() % 10 + 1;
 
  
    while (pcField[z][y-1] == "▀" || pcField[z][y-1] == ".")
    {
       
        inputValidationPC(z, y);
    }

    pcField[z][y-1] = "▀";
  
    
        PCinput = rand() % 4 + 1;
        
        switch (PCinput)
        {
            case 1:
                if (y > 7)
                {
                    pcField[z][y-1] = "□";
                    break;
                }
                if ((pcField[z][y] != "▀" && pcField[z][y+1] != "▀" && pcField[z][y+2] != "▀") && (pcField[z][y] != "." && pcField[z][y+1] != "." && pcField[z][y+2] != "."))
                {
                    pcField[z][y] = "▀";
                    pcField[z][y+1] = "▀";
                    pcField[z][y+2] = "▀";

                }
                else
                    {
                    pcField[z][y-1] = "□";
                    break;
                    }
                
                if (z == 0 && y == 1)
                {
                    pcField[z][y+3] = ".";
                    pcField[z+1][y+3] = ".";
                    pcField[z+1][y+2] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                }
                else if (z == 9 && y == 1)
                {
                    pcField[z][y+3] = ".";
                    pcField[z-1][y+3] = ".";
                    pcField[z-1][y+2] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y-1] = ".";
                    
                }
            
               else if (z > 0 && z < 9 && y == 1)
                {
                    pcField[z][y+3] = ".";
                    pcField[z-1][y+3] = ".";
                    pcField[z-1][y+2] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z+1][y+3] = ".";
                    pcField[z+1][y+2] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                }
                else if (z > 0 && z < 9 && y == 7)
                {
                    pcField[z][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z-1][y+2] = ".";
                    pcField[z+1][y-2] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z+1][y+2] = ".";
                }
                
               else if (z == 0 && y == 7)
                {
                    pcField[z+1][y-2] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z+1][y+2] = ".";
                    pcField[z][y-2] = ".";
                   
                }
               else if (z == 9 && y == 7)
                {
                    pcField[z][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z-1][y+2] = ".";
                }
        
                else if (z == 0 && y > 1 && y < 8)
                {
                    pcField[z][y+3] = ".";
                    pcField[z+1][y+3] = ".";
                    pcField[z+1][y+2] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z+1][y-2] = ".";
                }
              
               else if (z == 9 && y > 1 && y < 9)
                {
                    pcField[z][y+3] = ".";
                    pcField[z-1][y+3] = ".";
                    pcField[z-1][y+2] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                }
                
                else
                {
                    pcField[z][y+3] = ".";
                    pcField[z-1][y+2] = ".";
                    pcField[z-1][y+3] = ".";
                    pcField[z-1][y+1] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-1][y-1] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z+1][y+3] = ".";
                    pcField[z+1][y+2] = ".";
                    pcField[z+1][y+1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y-2] = ".";
                    
                }
 
                chetarehpalub--;
                break;
                
            case 2:
                if (y < 4)
                  {
                      pcField[z][y-1] = "□";
                         break;
                   }
               
                   if ((pcField[z][y-2] != "▀" && pcField[z][y-3] != "▀" && pcField[z][y-4] != "▀") && (pcField[z][y-2] != "." && pcField[z][y-3] != "." && pcField[z][y-4] != "."))
                     {
                         pcField[z][y-2] = "▀";
                         pcField[z][y-3] = "▀";
                         pcField[z][y-4] = "▀";
                    }
                         else
                {
                    pcField[z][y-1] = "□";
                  break;
                }
                
                          if (y == 10 && z > 0 && z < 9)
                          {
                              pcField[z+1][y-1] = ".";
                              pcField[z+1][y-2] = ".";
                              pcField[z+1][y-3] = ".";
                              pcField[z+1][y-4] = ".";
                              pcField[z+1][y-5] = ".";
                              pcField[z][y-5] = ".";
                              pcField[z-1][y-1] = ".";
                              pcField[z-1][y-2] = ".";
                              pcField[z-1][y-3] = ".";
                              pcField[z-1][y-4] = ".";
                              pcField[z-1][y-5] = ".";
                          }
                          else if (y == 10 && z == 0)
                          {
                              pcField[z+1][y-1] = ".";
                              pcField[z+1][y-2] = ".";
                              pcField[z+1][y-3] = ".";
                              pcField[z+1][y-4] = ".";
                              pcField[z+1][y-4] = ".";
                              pcField[z][y-5] = ".";
                          }
                              
                          else if (y == 10 && z == 9)
                          {
                              pcField[z-1][y-1] = ".";
                              pcField[z-1][y-2] = ".";
                              pcField[z-1][y-3] = ".";
                              pcField[z-1][y-4] = ".";
                              pcField[z-1][y-5] = ".";
                              pcField[z][y-5] = ".";
                          }

                          else if (y > 4 && y < 10 && z == 9)
                          {
                              pcField[z][y] = ".";
                              pcField[z-1][y] = ".";
                              pcField[z-1][y-1] = ".";
                              pcField[z-1][y-2] = ".";
                              pcField[z-1][y-3] = ".";
                              pcField[z-1][y-4] = ".";
                              pcField[z-1][y-5] = ".";
                              pcField[z][y-5] = ".";
                          }
                              else if (y == 4 && z == 9)
                              {
                                  pcField[z-1][y-1] = ".";
                                  pcField[z-1][y-2] = ".";
                                  pcField[z-1][y-3] = ".";
                                  pcField[z-1][y-4] = ".";
                                  pcField[z-1][y] = ".";
                                  pcField[z][y] = ".";
                              }
                              else if (y == 4 && z > 0 && z < 9)
                              {
                                  pcField[z][y] = ".";
                                  pcField[z-1][y] = ".";
                                  pcField[z-1][y-1] = ".";
                                  pcField[z-1][y-2] = ".";
                                  pcField[z-1][y-3] = ".";
                                  pcField[z-1][y-4] = ".";
                                  pcField[z+1][y] = ".";
                                  pcField[z+1][y-1] = ".";
                                  pcField[z+1][y-2] = ".";
                                  pcField[z+1][y-3] = ".";
                                  pcField[z+1][y-4] = ".";
                              }
                              else if (y == 4 && z == 0)
                              {
                                  pcField[z+1][y-1] = ".";
                                  pcField[z+1][y-2] = ".";
                                  pcField[z+1][y-3] = ".";
                                  pcField[z+1][y-4] = ".";
                                  pcField[z+1][y] = ".";
                                  pcField[z][y] = ".";
                              }
                              else if (z == 0 && y > 4 && y < 10)
                              {
                                  pcField[z][y] = ".";
                                  pcField[z+1][y] = ".";
                                  pcField[z+1][y-1] = ".";
                                  pcField[z+1][y-2] = ".";
                                  pcField[z+1][y-3] = ".";
                                  pcField[z+1][y-4] = ".";
                                  pcField[z+1][y-5] = ".";
                                  pcField[z][y-5] = ".";
                              }
                              else
                              {
                                  pcField[z][y] = ".";
                                  pcField[z-1][y] = ".";
                                  pcField[z+1][y] = ".";
                                  pcField[z-1][y-1] = ".";
                                  pcField[z-1][y-2] = ".";
                                  pcField[z-1][y-3] = ".";
                                  pcField[z-1][y-4] = ".";
                                  pcField[z-1][y-5] = ".";
                                  pcField[z][y-5] = ".";
                                  pcField[z+1][y-5] = ".";
                                  pcField[z+1][y-4] = ".";
                                  pcField[z+1][y-3] = ".";
                                  pcField[z+1][y-2] = ".";
                                  pcField[z+1][y-1] = ".";
                              }
                
              
                chetarehpalub--;
                break;
                
            case 3:
                
                if (z > 6)
                    {
                        pcField[z][y-1] = "□";
                      break;
                    }
                        
                if ((pcField[z+1][y-1] != "▀" && pcField[z+2][y-1] != "▀" && pcField[z+3][y-1] != "▀") && (pcField[z+1][y-1] != "." && pcField[z+2][y-1] != "." && pcField[z+3][y-1] != "."))
               {
                   pcField[z+1][y-1] = "▀";
                   pcField[z+2][y-1] = "▀";
                   pcField[z+3][y-1] = "▀";
               }
               else
              {
                  pcField[z][y-1] = "□";
               break;
              }

                               if (y == 10 && z > 0 && z < 6)
                               {
                                   pcField[z+4][y-1] = ".";
                                   pcField[z+3][y-2] = ".";
                                   pcField[z+4][y-2] = ".";
                                   pcField[z+2][y-2] = ".";
                                   pcField[z+1][y-2] = ".";
                                   pcField[z][y-2] = ".";
                                   pcField[z-1][y-1] = ".";
                                   pcField[z-1][y-2] = ".";
                               }
                               else if (y == 10 && z == 0)
                               {
                                   pcField[z+4][y-1] = ".";
                                   pcField[z+4][y-2] = ".";
                                   pcField[z+3][y-2] = ".";
                                   pcField[z+2][y-2] = ".";
                                   pcField[z+1][y-2] = ".";
                                   pcField[z][y-2] = ".";
                               }
                                   
                              else  if (y == 10 && z == 6)
                               {
                                   pcField[z-1][y-1] = ".";
                                   pcField[z-1][y-2] = ".";
                                   pcField[z][y-2] = ".";
                                   pcField[z+1][y-2] = ".";
                                   pcField[z+2][y-2] = ".";
                                   pcField[z+3][y-2] = ".";
                               }
                
                               else if (y > 1 && y < 10 && z == 6)
                               {
                                   pcField[z][y] = ".";
                                   pcField[z-1][y] = ".";
                                   pcField[z+1][y] = ".";
                                   pcField[z+2][y] = ".";
                                   pcField[z+3][y] = ".";
                                   pcField[z-1][y-1] = ".";
                                   pcField[z-1][y-2] = ".";
                                   pcField[z][y-2] = ".";
                                   pcField[z+1][y-2] = ".";
                                   pcField[z+2][y-2] = ".";
                                   pcField[z+3][y-2] = ".";
                               }
                
                                  else  if (y == 1 && z == 6)
                                   {
                                       pcField[z-1][y-1] = ".";
                                       pcField[z-1][y] = ".";
                                       pcField[z][y] = ".";
                                       pcField[z+1][y] = ".";
                                       pcField[z+2][y] = ".";
                                       pcField[z+3][y] = ".";
                                   }
                
                                  else if (y == 1 && z > 0 && z < 6)
                                   {
                                       pcField[z-1][y-1] = ".";
                                       pcField[z-1][y] = ".";
                                       pcField[z][y] = ".";
                                       pcField[z+1][y] = ".";
                                       pcField[z+2][y] = ".";
                                       pcField[z+3][y] = ".";
                                       pcField[z+4][y] = ".";
                                       pcField[z+4][y-1] = ".";
                                   }
                                   else if (y == 1 && z == 0)
                                   {
                                       pcField[z+4][y-1] = ".";
                                       pcField[z+3][y] = ".";
                                       pcField[z+4][y] = ".";
                                       pcField[z+2][y] = ".";
                                       pcField[z+1][y] = ".";
                                       pcField[z][y] = ".";
                                   }
                
                                  else  if (z == 0 && y > 1 && y < 10)
                                   {
                                       pcField[z][y] = ".";
                                       pcField[z+1][y] = ".";
                                       pcField[z+2][y] = ".";
                                       pcField[z+3][y] = ".";
                                       pcField[z+4][y] = ".";
                                       pcField[z+4][y-1] = ".";
                                       pcField[z+4][y-2] = ".";
                                       pcField[z+3][y-2] = ".";
                                       pcField[z+2][y-2] = ".";
                                       pcField[z+1][y-2] = ".";
                                       pcField[z][y-2] = ".";
                                   }
                    
                                   else
                                   {
                                       pcField[z][y] = ".";
                                       pcField[z+1][y] = ".";
                                       pcField[z+2][y] = ".";
                                       pcField[z+3][y] = ".";
                                       pcField[z+4][y] = ".";
                                       pcField[z+4][y-1] = ".";
                                       pcField[z+4][y-2] = ".";
                                       pcField[z+2][y-2] = ".";
                                       pcField[z+3][y-2] = ".";
                                       pcField[z+1][y-2] = ".";
                                       pcField[z][y-2] = ".";
                                       pcField[z-1][y] = ".";
                                       pcField[z-1][y-1] = ".";
                                       pcField[z-1][y-2] = ".";
                                   }
            
                chetarehpalub--;
                break;
                
            case 4:
                
                if (z < 3)
                {
                    
                    pcField[z][y-1] = "□";
                    break;
                }
                
                if ((pcField[z-1][y-1] != "▀" && pcField[z-2][y-1] != "▀" && pcField[z-3][y-1] != "▀") && (pcField[z-1][y-1] != "." && pcField[z-2][y-1] != "." && pcField[z-3][y-1] != "."))
                   {
                       pcField[z-1][y-1] = "▀";
                       pcField[z-2][y-1] = "▀";
                       pcField[z-3][y-1] = "▀";
                   }
                else
                    {
                        pcField[z][y-1] = "□";
                     break;
                    }
                
                if (z == 3 && y == 1)
                {
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y] = ".";
                    pcField[z-2][y] = ".";
                    pcField[z-3][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z][y] = ".";
                }
                
                else if (z == 9 && y == 1)
                {
                    pcField[z-3][y] = ".";
                    pcField[z-4][y-1] = ".";
                    pcField[z-4][y] = ".";
                    pcField[z-2][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z][y] = ".";
                }
                else if (z > 3 && z < 9 && y == 1)
                {
                    
                    pcField[z-4][y-1] = ".";
                    pcField[z-3][y] = ".";
                    pcField[z-4][y] = ".";
                    pcField[z-2][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z][y] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y] = ".";
                }
                
                else if (z == 2 && y == 10)
                {
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y-2] = ".";
                    pcField[z-2][y-2] = ".";
                    pcField[z-3][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z][y-2] = ".";
                }
                else if (z == 9 && y == 10)
                {
                    pcField[z-4][y-1] = ".";
                    pcField[z-3][y-2] = ".";
                    pcField[z-4][y-2] = ".";
                    pcField[z-2][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z][y-2] = ".";
                }
                else if (z > 3 && z < 9 && y == 10)
                {
                    pcField[z-4][y-1] = ".";
                    pcField[z-4][y-2] = ".";
                    pcField[z-3][y-2] = ".";
                    pcField[z-2][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y-2] = ".";
                }
                
                else if (y > 1 && y < 10 && z == 9)
                {
                    pcField[z-4][y-1] = ".";
                    pcField[z-4][y] = ".";
                    pcField[z-3][y] = ".";
                    pcField[z-2][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z][y] = ".";
                    pcField[z-4][y-2] = ".";
                    pcField[z-3][y-2] = ".";
                    pcField[z-2][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z][y-2] = ".";
                }
                else if (y > 1 && y < 10 && z == 3)
                {
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y-2] = ".";
                    pcField[z][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-2][y] = ".";
                    pcField[z-3][y] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z-2][y-2] = ".";
                    pcField[z-3][y-2] = ".";
                }
                
                else
                {
                    pcField[z+1][y] = ".";
                    pcField[z+1][y-1] = ".";
                    pcField[z+1][y-2] = ".";
                    pcField[z][y] = ".";
                    pcField[z-1][y] = ".";
                    pcField[z-2][y] = ".";
                    pcField[z][y-2] = ".";
                    pcField[z-1][y-2] = ".";
                    pcField[z-2][y-2] = ".";
                    pcField[z-3][y] = ".";
                    pcField[z-4][y] = ".";
                    pcField[z-3][y-2] = ".";
                    pcField[z-4][y-1] = ".";
                    pcField[z-4][y-2] = ".";
                }
  
                chetarehpalub--;
                break;
                
        }
        
        
        
        
        
    } while(chetarehpalub != 0);
    
}

void inputValidationPC(int &z, int &y)
{
    z = rand()%9;
    y = rand()%10 + 1;
}

void displayPC()
{
    cout << "    1   2   3   4   5   6   7   8   9   10  " << endl;
    cout << "--------------------------------------------\n";
    for (int i = 0; i < Size; i++)
    {
        if (i == 0)
            cout << "A";
        if (i == 1)
            cout << "B";
        if (i == 2)
            cout << "C";
        if (i == 3)
            cout << "D";
        if (i == 4)
            cout << "E";
        if (i == 5)
            cout << "F";
        if (i == 6)
            cout << "G";
        if (i == 7)
            cout << "H";
        if (i == 8)
            cout << "I";
        if (i == 9)
            cout << "J";
        cout << "| ";
   
        for (int j = 0; j < Size; j++)
        {
            cout << " " << pcField[i][j] << "  " ;
            if (j == 9)
            {
                cout << "|";
            }
        }
        cout << endl;
        cout << endl;
    }
    
    
}
    
    
void showRadar()
{
    
    
    cout << "    1   2   3   4   5   6   7   8   9   10  " << endl;
    cout << "--------------------------------------------\n";
    for (int i = 0; i < Size; i++)
    {
        if (i == 0)
            cout << "A";
        if (i == 1)
            cout << "B";
        if (i == 2)
            cout << "C";
        if (i == 3)
            cout << "D";
        if (i == 4)
            cout << "E";
        if (i == 5)
            cout << "F";
        if (i == 6)
            cout << "G";
        if (i == 7)
            cout << "H";
        if (i == 8)
            cout << "I";
        if (i == 9)
            cout << "J";
        cout << "| ";
   
        for (int j = 0; j < Size; j++)
        {
            cout << " " << radar[i][j] << "  " ;
            if (j == 9)
            {
                cout << "|";
            }
        }
        cout << endl;
        cout << endl;

    }
    
}
    

