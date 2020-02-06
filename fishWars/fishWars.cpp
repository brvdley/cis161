/*
 * fishWars.cpp
 *
 *  Created on: Feb 6, 2020
 *      Author: bradl
 */

#include <iostream>
using namespace std;

void menu();
void fight();

int main() {
	menu();
}

void menu() {
	const char* menuItems[] = {"Start Game", "See Rules", "Exit"};
	int sentinel = 0;
	int menuSize = 3;
	while (sentinel != 3) {
		sentinel = 0;
		cout << "Welcome to Fish Wars! Choose an option..." << endl;
		for(int i = 0; i < menuSize; i++) { //display system user menu and receive input
						cout << (i + 1) << ". " << menuItems[i]<< endl;
					}
		cin >> sentinel;
		if (sentinel == 1) {
			fight();
		}
		else if (sentinel == 2) {
			cout << "Fish Wars is a card game where two players get 13 cards each. \nThe cards have face values of 1-10 plus one shark card and two peace cards. The game is played in 13 rounds. \nEach round, the players each play one card face down and then flip them up at the same time. The player with the higher number (plus any battle bonus) wins. No one wins on a tie. \nA round winner gets one point added to their score plus one battle bonus point. Play continues until all thirteen rounds are complete and the highest final score wins. \nPlay exception: If you play a shark card then you always win unless the opponent plays a peace card then it is a tie and no one wins. \nIf you play a point card or a shark card against a peace card then it is a draw plus the player who did not play the peace card has their battle bonus reduced to zero. \nIf two peace cards are played then it is just a tie." << endl;
		}
	}
}

void fight() {
	cout << "Test" << endl;
}
