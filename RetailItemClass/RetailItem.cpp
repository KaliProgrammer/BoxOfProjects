//
//  RetailItem.cpp
//  RetailItemClass
//
//  Created by MacBook Air on 01.05.2022.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include "RetailItem.h"

RetailItem::RetailItem(string desc, int unOnHands, double pr)
{
    description = desc;
    unitsOnHand = unOnHands;
    price = pr;
}
//setter
void RetailItem::set_description(string desc)
{
    description = desc;
}
void RetailItem::set_unitsOnHand(int unOnHands)
{
    unitsOnHand = unOnHands;
}
void RetailItem::set_price(double pr)
{
    price = pr;
}

//getter
string RetailItem::get_description() const
{
    return description;
}
int RetailItem::get_unitsOnHand() const
{
    return unitsOnHand;
}
double RetailItem::get_price() const
{
    return price;
}

void RetailItem::show() const
{
    cout << "Description: " << get_description() << "\n"
         << "Units on Hand: " << get_unitsOnHand() << "\n"
         << "Price: " << get_price() << endl;
}

