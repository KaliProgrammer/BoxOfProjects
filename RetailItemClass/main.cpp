//
//  main.cpp
//  RetailItemClass
//
//  Created by MacBook Air on 01.05.2022.
//

#include <iomanip>
#include <iostream>
#include <iostream>
#include <string>
#include "RetailItem.h"

using namespace std;

using namespace std;

void displayInfo(const RetailItem*, const int);

int main(int argc, const char * argv[]) {

    const int SIZE = 3;
    
    RetailItem info[SIZE] = {  {"Jacket", 12, 59.95},
                               {"Jeans", 40, 34.95},
                               {"Shirt", 20, 24.95}};
    displayInfo(info, SIZE);

    cin.ignore();
    return 0;
}
void displayInfo(const RetailItem *info, const int SIZE)
{
    cout << "---------------Welcome to our Retail Store!---------------\n\n";
    cout << "\t\t\tInventory Item\t\tUnits on Hand \t\tCost\n";
    cout << "============================================================\n";
 
    cout << fixed << showpoint << setprecision(2);
    
    for (int i = 0; i < SIZE; i++)
    {
        cout << "ITEM # " << i+1 << "\t\t" << info[i].get_description() << "\t\t\t\t" << info[i].get_unitsOnHand() << "\t\t\t\t" << info[i].get_price() << endl;
    }
}
