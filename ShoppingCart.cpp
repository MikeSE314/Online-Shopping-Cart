/*
 ShoppingCart.cpp
 lab 8 - Online Shopping Cart
 
 
 Created by Micheal Erickson on 1/30/2017
 Copyright © 2017 Micheal Erickson. All rights reserved.
 micheal.erickson3.14@gmail.com section 007
 */

#include <iostream>

#include <vector>

using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
    return;
}

ShoppingCart::ShoppingCart(string customerName, string currentDate) {
    this->customerName = customerName;
    this->currentDate = currentDate;
    return;
}

string ShoppingCart::GetCustomerName() {
    return customerName;
}

string ShoppingCart::GetDate() {
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase newItem) {
    cartItems.push_back(newItem);
    return;
}

void ShoppingCart::RemoveItem(string itemName) {
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == itemName) {
            cartItems.erase(cartItems.begin() + i);
            return;
        }
    }
    cout << "Item not found in cart. Nothing removed." << endl;
    return;
}

void ShoppingCart::UpdateQuantity(string itemName, int itemQuantity) {
    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == itemName) {
            cartItems.at(i).SetQuantity(itemQuantity);
            return;
        }
    }
    cout << "Item not found in cart. Nothing modified." << endl;
    return;
}

int ShoppingCart::GetNumItemsInCart() {
    int tmpQty = 0;
    for (int i = 0; i < cartItems.size(); i++) {
        tmpQty += cartItems.at(i).GetQuantity();
    }
    return tmpQty;
}

int ShoppingCart::GetCostOfCart() {
    int tmpPrice = 0;
    for (int i = 0; i < cartItems.size(); i++) {
        tmpPrice += cartItems.at(i).GetQuantity() *
                cartItems.at(i).GetPrice();
    }
    return tmpPrice;
}

void ShoppingCart::PrintTotal() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << this->GetNumItemsInCart() << endl;
    cout << endl;
    
    if (cartItems.size() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else {
        for (int i = 0; i < cartItems.size(); i++) {
            cartItems.at(i).PrintItemCost();
        }
    }
    
    cout << endl;
    cout << "Total: $" << this->GetCostOfCart() << endl;
    return;
}

void ShoppingCart::PrintDescriptions() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << endl;
    
    cout << "Item Descriptions" << endl;
    
    if (cartItems.size() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else {
        for (int i = 0; i < cartItems.size(); i++) {
            cartItems.at(i).PrintItemDescription();
        }
    }
    
    cout << endl;
    return;
}
