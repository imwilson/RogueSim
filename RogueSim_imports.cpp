#include "RogueSim_imports.h"
#include <iostream>

using namespace std;

void welcome() {
	cout << "Hello and welcome to my sim for Rouges in World of Warcraft Classic!" << endl;
	cout << "It is very much a work in progress, but I hope you can find it useful." << endl;
	cout << "To navigate the sim, enter the number you want on the menu and press Enter" << endl;
	cout << "You can also enter a string separated by spaces if you already know what you want" << endl;
	cout << "Options: " << endl;
	cout << "Enter 1 to set race (default Human)" << endl;
	cout << "Enter 2 to set gear" << endl;
	cout << "Enter 3 to set buffs" << endl;
	cout << "Enter 4 to set combat duration and number of trials" << endl;
	cout << "Enter 5 to run sim" << endl;
	cout << "Enter 6 to see credits" << endl;
}

int ask_race() {
	cout << "Please enter your race by number and press Enter: " << endl;
	cout << "Human:0, Gnome:1, Dwarf:2, NightElf:3, Orc:4, Undead:5, Troll:6" << endl;
	int user_in = 0;
	cin >> user_in;
	return user_in;    // Bad, breaks on bad input
}

