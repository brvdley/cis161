/*
 * foodTruckOwens.cpp
 *
 *  Created on: Jan 27, 2020
 *      Author: Bradley Owens
 *      Email: BradleyOwens126@gmail.com
 *
 */
#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

vector <string> foodItems = {"Hamburger", "Hot Dogs", "Chili (12 Oz.)", "Fry Basket", "Chili on Hamburger, Hot Dog, or Fries", "Soda"};
double initialInventory[] = {200, 200, 75, 75, 500, 75, 200};
const char* menuItems[] = {"Create Order", "Print Previous Receipt", "Remove Item", "See Initial Inventory", "See Current Menu"};
const char* inventoryItems[] = {"Hamburger Patties", "Hot Dogs", "Hamburger Buns", "Hot Dog Buns", "Ounces Of Chili", "Fry Baskets", "Cans Of Soda"};
const int initialSize = 7;
const int menuSize = 5;
const int foodSize = 6;
vector <double> endInventory;
const double foodPrices[] = {5.00, 5.00, 4.00, 7.00, 2.00, 2.00};
const double taxRate = .05;
string initialAnswer;
int choice;
int custChoice;
vector<string> custOrder;
string tempCustOrder;
double tempCustTotal = 0;
double subTotal;
int revisedAmount;
int sentinel = 0;
double total;
double taxAmount;
int tempRemovedItem;
int removedItems;
int tempInv;
double tempPercentage;
vector <double> finalPercentages;

int main () {
	cout << "Welcome! Is the initial inventory correct? Y or N" << endl; //display initial inventory and ask if its currently correct
	for(int i = 0; i < initialSize; i++) {
		cout << (i + 1) << ". " << inventoryItems[i] << ": " << initialInventory[i] << endl;
	}
	cin >> initialAnswer;
	while (initialAnswer != "Y") { //if it isn't let them edit the amounts
		while (sentinel != -1) {
			sentinel = 0;
			cout << "Which item would you like to correct? 1 for patties, 2 for dogs, etc." << endl;
			cin >> choice;
			choice--;
			cout << "Please enter an amount." << endl;
			cin >> revisedAmount;
			initialInventory[choice] = revisedAmount;
			cout << "Revised Inventory: " << endl;
			for(int i = 0; i < initialSize; i++) {
				cout << (i + 1) << ". " << inventoryItems[i] << ": " << initialInventory[i] << endl;
			}
			cout << "Enter -1 to exit or any other number to revise another item." << endl;
			cin >> sentinel;
		}
	}
	while (sentinel != -1) {
		sentinel = 0; //set values to initialization amounts
		choice = 0;
		for(int i = 0; i < menuSize; i++) { //display system user menu and receive input
				cout << (i + 1) << ". " << menuItems[i]<< endl;
			}
		cout << "Select a menu item. 1 for Create Order, 2 for Previous Receipt, etc." << endl;
		cin >> choice;
		choice--;
		if (choice == 0) { //Create Order
			custOrder.clear(); //Clear any previous items
			initialAnswer = "";
			while (initialAnswer != "N") {
				cout << "Which item would the customer like?" << endl; //display menu
				for(size_t i = 0; i < foodItems.size(); i++) {
					cout << (i + 1) << ". " << foodItems[i] << endl;
				}
				cin >> custChoice;
				custChoice--;
				tempCustOrder = foodItems[custChoice]; //add items to order vector
				custOrder.push_back(tempCustOrder);
				tempCustTotal += foodPrices[custChoice];
				cout << "Would you like another item? Y or N" << endl;
				cin >> initialAnswer;
			}
			subTotal = tempCustTotal; //create receipt and totals
			taxAmount = tempCustTotal * taxRate;
			total = tempCustTotal + taxAmount;
			cout << "Creating Receipt File..." << endl;
			ofstream outputFile;
			outputFile.open("PreviousReceipt.txt");
			outputFile << "Items: " << endl;
			for(auto itr : custOrder) {
			    outputFile << itr << endl;
			}
			outputFile << "Subtotal: $" << setprecision(4) << subTotal << endl;
			outputFile << "Tax: $" << setprecision(4) << taxAmount << endl;
			outputFile << "Total: $" << setprecision(4) << total << endl;
			outputFile.close();
			cout << "Finished! Receipt can now be printed." << endl;
		}
		else if (choice == 1) { //Recreate receipt with previous information.
			cout << "Creating Receipt File..." << endl;
			ofstream outputFile;
			outputFile.open("PreviousReceipt.txt");
			outputFile << "Items: " << endl;
			for(auto itr : custOrder) {
				outputFile << itr << endl;
			}
			outputFile << "Subtotal: $" << setprecision(4) << subTotal << endl;
			outputFile << "Tax: $" << setprecision(4) << taxAmount << endl;
			outputFile << "Total: $" << setprecision(4) << total << endl;
			outputFile.close();
			cout << "Finished! Receipt can now be printed." << endl;
		}
		else if (choice == 2) { //Remove item from the menu
			initialAnswer = "";
			while (initialAnswer != "N") {
				cout << "Which item would you like to remove?" << endl; //display current menu
				for(int i = 0; i < foodSize; i++) {
					cout << (i + 1) << ". " << foodItems[i] << endl;
				}
				cin >> tempRemovedItem;
				tempRemovedItem--;
				foodItems.erase(foodItems.begin()+tempRemovedItem); //erase choice from menu
				cout << "Item removed. Current Menu: " << endl; //display new menu
				for(size_t i = 0; i < foodItems.size(); i++) {
					cout << (i + 1) << ". " << foodItems[i] << endl;
				}
				cout << "Would you like to remove another item? Y or N" << endl;
				cin >> initialAnswer;
			}
		}
		else if (choice == 3) { //Display Initial Inventory
			for(int i = 0; i < initialSize; i++) {
					cout << (i + 1) << ". " << inventoryItems[i] << ": " << initialInventory[i] << endl;
			}
		}
		else if (choice == 4) { //Display Current Menu
			for(size_t i = 0; i < foodItems.size(); i++) {
				cout << (i + 1) << ". " << foodItems[i] << endl;
			}
		}
		cout << "Enter -1 to enter closing procedures or any other number to continue." << endl; //end program
		cin >> sentinel;
	}
	cout << "Please enter each item's current stock: " << endl; //Capture final inventory and alert if more stock is needed.
	for(int i = 0; i < initialSize; i++) {
		cout << i + 1 << ". " << inventoryItems[i] << endl;
		cin >> tempInv;
		endInventory.push_back(tempInv);
	}
	for(int i = 0; i < initialSize; i++) {
		tempPercentage = (endInventory[i] / initialInventory[i]) * 100;
		finalPercentages.push_back(tempPercentage);
		cout << inventoryItems[i] << ": " << finalPercentages[i] << "%" << endl;
		if (finalPercentages[i] <= 20) {
			cout << inventoryItems[i] << " has stock below 20%! Purchase more for tomorrow." << endl;
		}
		}
		cout << "Creating Inventory File..." << endl; //print out end of day stock and info
		ofstream inventoryFile;
		inventoryFile.open("endStock.txt");
		inventoryFile << "Items: " << endl;
		for(int i = 0; i < initialSize; i++) {
			inventoryFile << inventoryItems[i] << ": " << finalPercentages[i] << "%" << endl;
			if (finalPercentages[i] <= 20) {
				inventoryFile << inventoryItems[i] << " has stock below 20%! Purchase more for tomorrow." << endl;
			}
		}
		inventoryFile.close();
		cout << "Finished! Inventory can now be printed." << endl;
		return 0;
	}



