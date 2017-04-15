/*
 ItemToPurchase.cpp
 lab 8 - Online Shopping Cart
 
 
 Created by Micheal Erickson on 1/30/2017
 Copyright © 2017 Micheal Erickson. All rights reserved.
 micheal.erickson3.14@gmail.com section 007
 */

#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0;
    itemQuantity = 0;
    return;
}

ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
    return;
}

void ItemToPurchase::SetName(string newName) {
    itemName = newName;
    return;
}

string ItemToPurchase::GetName() {
    return itemName;
}

void ItemToPurchase::SetPrice(int newPrice) {
    itemPrice = newPrice;
    return;
}

int ItemToPurchase::GetPrice() {
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int newQuantity) {
    itemQuantity = newQuantity;
    return;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}

void ItemToPurchase::SetDescription(string newDescription) {
    itemDescription = newDescription;
    return;
}

string ItemToPurchase::GetDescription() {
    return itemDescription;
}

void ItemToPurchase::PrintItemCost() {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}

void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ": " << itemDescription << endl;
}
