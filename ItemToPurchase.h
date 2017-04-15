/*
 ItemToPurchase.h
 lab 8 - Online Shopping Cart
 
 
 Created by Micheal Erickson on 1/30/2017
 Copyright © 2017 Micheal Erickson. All rights reserved.
 micheal.erickson3.14@gmail.com section 007
 */

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(string name = "none", string description = "none", int price = 0, int quantity = 0);
    
    void SetName(string newName);
    string GetName();
    
    void SetPrice(int newPrice);
    int GetPrice();
    
    void SetQuantity(int newQuantity);
    int GetQuantity();
    
    void SetDescription(string newDescription);
    string GetDescription();
    
    void PrintItemCost();
    void PrintItemDescription();
private:
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
};

#endif
