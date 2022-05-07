//
//  RetailItem.h
//  RetailItemClass
//
//  Created by MacBook Air on 01.05.2022.
//

#ifndef RetailItem_h
#define RetailItem_h
#include <iostream>
#include <string>

using namespace std;

class RetailItem
{
private:
    
    string description;
    int unitsOnHand;
    double price;
    
public:
    RetailItem(string, int, double);
    
    //setter
    void set_description(string);
    void set_unitsOnHand(int);
    void set_price(double);
    
    //getter
    string get_description() const;
    int get_unitsOnHand() const;
    double get_price() const;
    
    void show() const;
};

#endif /* RetailItem_h */
