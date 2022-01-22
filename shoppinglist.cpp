/* Code written by: Tianna DeSpain*/

// set up enviroment
#include <map>
#include <string>
#include <list>
#include <iostream>
#include <iomanip>
using namespace std;

// Create class item to store each shopping list item's information
class Item
{
    // Attributes for Item class- name, location, price, quantity
private:
    string name;
    string location;

public:
    float price;
    int quantity;

    // Methoods for the Items Class

    /* The following methood inputs infomration about the new item to be added
    to the list, and assigns it accordingly to the right class attributes*/
    void readlines()
    {
        // Ask the user for the name of the item to be added
        cout << endl
             << "What item would you like to add? ";
        // Assign the input as the name of the new item
        cin >> name;

        // Ask the user for the location of the item to be added
        cout << endl
             << "Where is this item located in the store? (e.g. Produce) ";
        // Assign the input as the location of the new item
        cin >> location;

        // Ask the user for the how many they need to buy
        cout << endl
             << "Enter the quantity:";
        // Assign the input as the quantity of the new item
        cin >> quantity;

        // Ask for the price per item
        cout << endl
             << "Enter the price: (ex: 5.40)";
        // Assign the input as the price per item
        cin >> price;
    }

    /* The following methood formatts the output of each of the class 
    attributes so that they output nicely when the methood is called*/
    void printitems()
    {
        // Set the width for each output, and then print the attribute
        cout << setw(15) << name;
        cout << setw(10) << quantity;
        cout << setw(10) << location;
        cout << setw(10) << price << endl;
    }
};

int main()
{
    // A varriable for whether the user wants to enter another item
    string more = "y";

    // A list of the objects "Items" named shopping list
    list<Item> shoppingList;

    // A counter for each item that will be added to the list
    int counter;

    // A loop to allow the user to enter as many items to the list as they want
    while (more == "y")
    {
        // Conditional for when to stop the loop
        if (more == "n")
        {
            break; // This will exit the loop if they user enters "n" when prompted
        }

        // Initalize new item
        Item item;

        // Call methood to prompt user for infomation about item
        item.readlines();

        // Append new item to the shopping list
        shoppingList.push_back(item);

        // Adds to counter
        counter += 1;

        // Prompts user if they would like to add more items
        cout << "Would you like to add another item? y/n ";
        // Assigns the input to the more varriable that conditions the loop
        cin >> more;
    }

    // New empty shopping list as an array instead of a list
    Item nShoppingList[counter];

    // Creates a total price varraible to use later
    float totalPrice = 0;

    // A loop to add each item from list to array and calculate total price
    for (int i = 0; i < counter; i++)
    {
        // A temporary Item holding the front object of the list
        Item temp = shoppingList.front();

        // Adds the current items price to the total price
        totalPrice += (temp.price * temp.quantity);

        // Adds the temporary item to the new array
        nShoppingList[i] = {temp};

        // Removes the temporary item from the list
        shoppingList.pop_front();
    }

    // Prints and formats the shopping list
    cout << setw(30) << "Shopping List" << endl;
    cout << setw(15) << "Item Name" << setw(10) << "Quantity" << setw(10) << "Location" << setw(10) << "price" << endl;

    for (int i = 0; i < counter; i++)
    {
        nShoppingList[i].printitems();
    }

    // Prints and formats the total price of the entire list
    cout << setw(28) << "Total Price" << endl;
    cout << setw(25) << totalPrice << endl;

    // Prints and formats the number of items on the list
    cout << setw(35) << "Number of List Items" << endl;
    cout << setw(25) << counter << endl;
    return 0;
}