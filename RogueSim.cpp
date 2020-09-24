#include <string>
#include <vector>
#include <iostream>
#include "RogueSim.h"
#include "RogueSim_imports.h"

using namespace std;

int main() {

	welcome();

	"""TODO:  
	Import Race
	Import Gear
	Calculate Stats
	Import fight stats
	Run Comabat
	Average Results
	"""
	Stats player;
	Equipment gear;
	Buffs buffs;
	CombatInfo combat_info;
	vector<Proc> proc_list;
	vector<Cooldown> cd_list;

	get_race(player, cd_list);
	get_gear(gear, proc_list, cd_list);
	get_buffs(buffs);
	calc_stats(player, gear, buffs);
	get_fight_info(combat_info);

	// Run Combat Sims
	std::vector<unsigned> damage_results;
	std::vector<unsigned double> dps_results;
	for(long unsigned i = 0; i < combat_info.iterations; i++) {
		unsigned new_result  = run_encounter(player, proc_list, cd_list, combat_info);
		damage_results.push(new_result);
		unsigned double new_dps = new_result / combat_info.fight_length;
		dps_results.push(new_dps);
	}

	// Average Results  TODO: Track min/max of each
	// Damage
	unsigned long double total_dam = 0;
	for (unsigned i = 0; i < damage_results.size(); i++) {
		total_dam += damage_results[i];
	}
	unsigned long double avg_dam = total_dam / combat_info.iterations;
	// DPS
	unsigned long double total_dps = 0;
	for (unsigned i = 0; i < dps_results.size(); i++) {
		total_dps += dps_results[i];
	}
	unsigned long double avg_dps = total_dps / combat_info.iterations;

	cout << "Average damage over " << combat_info.iterations << " trials was: " << avg_dam << endl;
	cout << "Average dps over " << combat_info.iterations << " trials was: " << avg_dps << endl;

	return 0;
}

// Currently just driver functions for backend stuff
void get_race(Stats& player, std::vector<Cooldown>& cd_list) {
	int race_in = ask_race();
	switch(race_in)
	{  // Human:0, Gnome:1, Dwarf:2, NightElf:3, Orc:4, Undead:5, Troll:6
		case 0:  // Human
			cout << "You have selected Human" << endl;
			player.strength = 80;
			player.agility = 130;
			player.stamina = 75;
			player.intellect = 35;
			player.spirit = 52;
			break;
		case 1: // Gnome
			cout << "You have selected Gnome" << endl;
			player.strength = 75;
			player.agility = 133;
			player.stamina = 74;
			player.intellect = 40;
			player.spirit = 50;
			break;
		case 2: // Dwarf
			cout << "You have selected Dwarf" << endl;
			player.strength = 82;
			player.agility = 126;
			player.stamina = 78;
			player.intellect = 34;
			player.spirit = 49;
			break;
		case 3: // NightElf
			cout << "You have selected NightElf" << endl;
			player.strength = 77;
			player.agility = 135;
			player.stamina = 74;
			player.intellect = 35;
			player.spirit = 50;
			break;
		case 4: // Orc
			cout << "You have selected Orc" << endl;
			player.strength = 83;
			player.agility = 127;
			player.stamina = 77;
			player.intellect = 32;
			player.spirit = 53;
			Cooldown blood_fury(20572, 1200, 0, 250, true, 150);
			cd_list.push(blood_fury);
			break;
		case 5: // Undead
			cout << "You have selected Undead" << endl;
			player.strength = 79;
			player.agility = 128;
			player.stamina = 76;
			player.intellect = 33;
			player.spirit = 55;
			break;
		case 6: // Troll
			cout << "You have selected Troll" << endl;
			player.strength = 81;
			player.agility = 132;
			player.stamina = 76;
			player.intellect = 31;
			player.spirit = 51;
			Cooldown berserking(20554, 1800, 10.0, 100, false, 150);
			cd_list.push(berserking);

			break;
		default:
			cout << "An error occured, please enter a usable race" << endl;
	}
	return;
}
void get_gear(Equipment& gear, std::vector<Proc>&, std::vector<Cooldown>&) {
	ask_gear(gear);
}
void get_buffs(Buffs& buffs) {
	ask_buffs(buffs);
}
void calc_stats(Stats&, Equipment&, Buffs&) {}
void get_fight_info(CombatInfo&) {}
unsigned run_encounter(Stats&, std::vector<Proc>&, std::vector<Cooldown>&, CombatInfo&) {}