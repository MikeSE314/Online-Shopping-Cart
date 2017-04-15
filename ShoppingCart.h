/*
 ShoppingCart.h
 lab 8 - Online Shopping Cart
 
 
 Created by Micheal Erickson on 1/30/2017
 Copyright © 2017 Micheal Erickson. All rights reserved.
 micheal.erickson3.14@gmail.com section 007
 */

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ItemToPurchase.h"

#include <vector>

class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(string customerName, string currentDate);
    
    string GetCustomerName();
    string GetDate();
    void AddItem(ItemToPurchase newItem);
    void RemoveItem(string itemName);
    void UpdateQuantity(string itemName, int itemQuantity);
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();
private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};

#endif
