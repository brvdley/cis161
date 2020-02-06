/*
 * textSouls.cpp
 *
 *  Created on: Feb 6, 2020
 *      Author: bradl
 */

#include <iostream> //libraries
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

int health; //initialize variables
int maxHealth;
int level;
const char* achievements[] = {"Beat Boss 1", "Beat Boss 2", "Beat Boss 3", "Beat Boss 4", "Beat Boss 5"};

bool achievement1 = false; //initialize to false
bool achievement2 = false;
bool achievement3 = false;
bool achievement4 = false;
bool achievement5 = false;

void menu(); //initialize functions
void newGame();
int continueGame();
void viewAchievements();

int main() {
	menu(); //run game
}

void menu() {
	const char* menuItems[] = {"New Game", "Load Game", "View Achievements", "Exit"}; //create menu array
	int sentinel = 0;
	int menuSize = 4;
	while (sentinel != 4) { //exit strategy
		sentinel = 0; //reset sentinel
		cout << "Welcome to Text Souls! Choose an option..." << endl;
		for(int i = 0; i < menuSize; i++) { //display system user menu and receive input
			cout << (i + 1) << ". " << menuItems[i]<< endl;
		}
		cin >> sentinel;
		if (sentinel == 1) { //create game if they choose new game
			newGame();
		}
		else if (sentinel == 2) { //Load save
			continueGame();
		}
		else if (sentinel == 3) { //View Achievements
			viewAchievements();
		}
	}
}

void newGame() { //create new game
	cout << "Test" << endl;
}

int continueGame() { //load file to continue
	string line; //single line of the file
	vector <string> saveData; //save data vector to store data
	ifstream saveFile ("saveData.txt"); //file we are retrieving from
	if (saveFile.is_open()) { //if we open this file
		while (getline(saveFile, line)) { //while there are new lines to be grabbed, push back each line into the vector
			saveData.push_back(line);
		}
	saveFile.close(); } //close save file
	else {
		cout << "Unable to open file"; //no file found.
	}
	level = stoi(saveData[0]); //store data into each variable and convert from string to int
	health = stoi(saveData[1]);
	maxHealth = stoi(saveData[2]);
	cout << "Current Level: " << level << " Current Health: " <<  health << " Current Max Health: " << maxHealth << endl; //output player data
	return level; //return each variable for use in game
	return health;
	return maxHealth;
}

void viewAchievements() {
	int achievementSize = 5;
	string line; //single line of the file
	vector <string> saveData; //save data vector to store data
	ifstream saveFile ("playerAchievements.txt"); //file we are retrieving from
		if (saveFile.is_open()) { //if we open this file
			while (getline(saveFile, line)) { //while there are new lines to be grabbed, push back each line into the vector
				saveData.push_back(line);
			}
		saveFile.close(); } //close save file
		else {
			cout << "Unable to open file"; //no file found.
		}
		istringstream(saveData[0]) >> achievement1; //store data into each variable and convert from string to bool
		istringstream(saveData[1]) >> achievement2;
		istringstream(saveData[2]) >> achievement3;
		istringstream(saveData[3]) >> achievement4;
		istringstream(saveData[4]) >> achievement5;
		for(int i = 0; i < achievementSize; i++) { //display system user menu and receive input
			cout << "Achievement " << (i + 1) << ". " << achievements[i] << ": " << saveData[i] << endl;
		}
}
