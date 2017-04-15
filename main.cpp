/*
main.cpp
lab 8 - Online Shopping Cart

Created by Micheal Erickson on 1/30/2017
Copyright © 2017 Micheal Erickson. All rights reserved.
micheal.erickson3.14@gmail.com section 007

Create an online shopping cart, full of objects with individual names,
prices, descriptions, and quantities. The program will interface with
the user to ask for items to buy, their description, price, and
quantity, and be able to show what's in the cart, and what the total
cost is.

If I tell it that my name is Micheal, which it is, and I say I want to
buy Quickdraws, which are orange climbing protection, which cost $20,
and that I want to buy 5, as well as a kayak, which kayak is a blue
kayak and costs $700, output should look like this:

Micheal's Shopping Cart - January 30th, 2017
Number of items: 6

Quickdraws 5 @ $20 = $100
Kayak 1 @ $700 = $700

Total: $800

Or if I want a couple of green laser pointers which shine bright
lights and cost $15 a piece, as well as assorted ballons, the type for
a birthday, and a package costs $4 and I want three packages, and that
I also want a LHC which is very dangerous and costs 13250000000, and a
puppy, the cutest thing ever, and I want 8 of them for a cuddle party,
which cost $1200, and 16 fun-sized bags of M&Ms, filled with chocolate
and covered in candy coating, which cost $1, and 5 lawn chairs,
perfect for watching soccer games and outdoor movies, which cost $70,
and a pineapple grinder for effortless pineapple cutting and costs $8
and a gram of anthrax which is also super deadly and costs $640 per
gram, and an earthquake machine which costs $80000 for its destructive
power, 17 kale strips, super gross, at $d a piece, and a cherry,
perfect for topping your icecream, which also costs $1, and I ask for
the description of all of these things, the output should be:

Micheal's Shopping Cart - January 30th, 2017

Item Descriptions
Green Laser Pointer: Shines bright lights
Assorted Balloons: Birthday vareity, many colors
LHC: Very dangerous
Puppy: The cutest thing ever
M&Ms, Fun-Sized: Filled with chocolate and covered in candy coating
Lawn Chairs: Perfect for watching soccer games and outdoor movies
Pineapple Grinder: Effortless pineapple cutting
Anthrax, 1g Packet: Also super deadly
Earthquake Machine: Destructive power!
Kale Strips: Super gross
Cherry: The perfect topping for icecream

and if I were to ask for the total of these all:

Micheal's Shopping Cart - January 30th, 2017
Number of Items:

Green Laser Pointer 2 @ $15 = $30
Assorted Balloons 3 @ $4 = $12
LHC 1 @ $13250000000 = $13250000000
Puppy 8 @ $1200 = $96000
M&Ms, Fun-Sized 16 @ $1 = $16
Lawn Chairs 5 @ $70 = $350
Pineapple Grinder 1 @ $8 = $8
Anthrax, 1g Packet 1 @ $640 = $640
Earthquake Machine 1 @ $80000 = $80000
Kale Strips 17 @ $2 = $34
Cherry 1 @ $1 = $1

Total: $13250177091

Although for the sake of ease, no price should be above INT_MAX, and
therefore, the user should either seek a discount on the LHC or just
go without it.
*/

#include <string>
#include <iostream>

using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu(ShoppingCart cart);

void PrintOptions();

void CartAdd(ShoppingCart& cart);

void CartRemove(ShoppingCart& cart);

void CartChangeQuantity(ShoppingCart& cart);

void CartPrintDescriptions(ShoppingCart cart);

void CartPrintItems(ShoppingCart cart);

string MakeChoice(string usrInput);

int main() {
    string tmpName = " ";
    string tmpDate = " ";

    cout << "Enter Customer's Name: ";
    getline(cin, tmpName);
    cout << endl;

    cout << "Enter Today's Date: ";
    getline(cin, tmpDate);
    cout << endl;

    ShoppingCart myCart(tmpName, tmpDate);

    cout << "Customer Name: " << myCart.GetCustomerName() << endl;
    cout << "Today's Date: " << myCart.GetDate() << endl;

    PrintMenu(myCart);

    return 0;
}

void PrintOptions() {
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
}

string MakeChoice(string usrInput) {
    while (true) {
        usrInput = " ";
        cout << "Choose an option: ";
        getline(cin, usrInput);
        cout << endl;

        if (usrInput == "q") {
            return "q";
        }
        else if (usrInput == "a") {
            return "a";
        }
        else if (usrInput == "d") {
            return "d";
        }
        else if (usrInput == "c") {
            return "c";
        }
        else if (usrInput == "i") {
            return "i";
        }
        else if (usrInput == "o") {
            return "o";
        }
    }
}

void CartAdd(ShoppingCart& cart) {
    string tmpName = " ";
    string tmpDesc = " ";
    string tmpStrVal = " ";
    int tmpPrice = 0;
    int tmpQty = 0;

    cout << "ADD ITEM TO CART" << endl;

    cout << "Enter the item name: ";
    getline(cin, tmpName);
    cout << endl;

    cout << "Enter the item description: ";
    getline(cin, tmpDesc);
    cout << endl;

    cout << "Enter the item price: ";
    getline(cin, tmpStrVal);
    tmpPrice = stoi(tmpStrVal);
    cout << endl;

    cout << "Enter the item quantity: ";
    getline(cin, tmpStrVal);
    tmpQty = stoi(tmpStrVal);
    cout << endl;

    ItemToPurchase tmpItem(tmpName, tmpDesc, tmpPrice, tmpQty);

    cart.AddItem(tmpItem);

    cout << endl;
    return;
}

void CartRemove(ShoppingCart& cart) {
    string tmpName = " ";

    cout << "REMOVE ITEM FROM CART" << endl;

    cout << "Enter name of item to remove: ";
    getline(cin, tmpName);
    cout << endl;

    cart.RemoveItem(tmpName);

    cout << endl;
    return;
}

void CartChangeQuantity(ShoppingCart& cart) {
    string tmpName = " ";
    string tmpVal = " ";
    int tmpQty = 0;

    cout << "CHANGE ITEM QUANTITY" << endl;

    cout << "Enter the item name: ";
    getline(cin, tmpName);
    cout << endl;

    cout << "Enter the new quantity: ";
    getline(cin, tmpVal);
    tmpQty = stoi(tmpVal);
    cout << endl;

    cart.UpdateQuantity(tmpName, tmpQty);

    cout << endl;
    return;
}

void CartPrintDescriptions(ShoppingCart cart) {
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;

    cart.PrintDescriptions();

    cout << endl;
    return;
}

void CartPrintItems(ShoppingCart cart) {
    cout << "OUTPUT SHOPPING CART" << endl;

    cart.PrintTotal();

    cout << endl;
    return;
}

void PrintMenu(ShoppingCart cart) {
    while (true) {
        PrintOptions();

        string usrInput = " ";

        usrInput = MakeChoice(usrInput);

        if (usrInput == "q") {
            return;
        }
        else if (usrInput == "a") {
            CartAdd(cart);
        }
        else if (usrInput == "d") {
            CartRemove(cart);
        }
        else if (usrInput == "c") {
            CartChangeQuantity(cart);
        }
        else if (usrInput == "i") {
            CartPrintDescriptions(cart);
        }
        else if (usrInput == "o") {
            CartPrintItems(cart);
        }
    }
}
