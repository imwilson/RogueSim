#include "RogueSim.h"
#include "RogueSim_imports.h"
#include "GearChoice.h"
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

void ask_gear() {
	cout << "Please enter a number for the slot you wish to add: " << endl;
	int equip_in = 0;
	while (cin >> equip_in) {
		cout << "1: Helm, 2: Neck, 3: Shoulder, 4: Shirt, 5: Chest, 6: Belt, 7: Legs, 8: Feet, 9: Wrist, 10: Hands" << endl;
		cout << "11: Ring1, 12: Ring2, 13: Trinket1, 14: Trinket2, 15: Back, 16: Mainhand Weapon, 17: Offhand Weapon, 18: Ranged" << endl;
		cout << "Enter 0 to return to Main Menu" << endl;
		switch(equip_in)
		{
			case 0:
				return;
				break;
			case 1:
				ask_helm();
				break;
			case 2:
				ask_neck();
				break;
			case 3:
				ask_shoulder();
				break;
			case 4:
				ask_shirt();
				break;
			case 5:
				ask_chest();
				break;
			case 6:
				ask_belt();
				break;
			case 7:
				ask_legs();
				break;
			case 8:
				ask_feet();
				break;
			case 9:
				ask_wrist();
				break;
			case 10:
				ask_hands();
				break;
			case 11:
				ask_ring1();
				break;
			case 12:
				ask_ring2();
				break;
			case 13:
				ask_trink1();
				break;
			case 14:
				ask_trink2();
				break;
			case 15:
				ask_belt();
				break;
			case 16:
				ask_mhwep();
				break;
			case 17:
				ask_ohwep();
				break;
			case 18:
				ask_ranged();
				break;
			default:
				cout << "Something went wrong, please try again" << endl;
		}
	}
}
