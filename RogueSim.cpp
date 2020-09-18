#include <string>
#include <vector>
#include <iostream>
#include "RogueSim_imports.h"

using namespace std;

class MHwep {
	int type;     // Dagger:0, Sword:1, Mace:2, Fist:3
	int wep_skill;
	double minDam;
	double maxDam;
	double speed;
	double dps;

	// Stats added
	double strength;
	double agility;
	double intellect;
	double spirit;
	double stamina;

	double crit;
	double hit;
	double attackPower;

	bool proc;   // Does the wep have a proc
	MHwep() {
		type = 1;     // Dagger:0, Sword:1, Mace:2, Fist:3
		wep_skill = 300;
		minDam = 1;
		maxDam = 1;
		speed = 1;
		dps = 1;

		// Stats added
		strength = 0;
		agility = 0;
		intellect = 0;
		spirit = 0;
		stamina = 0;

		crit = 0;
		hit = 0;
		attackPower = 0;

		proc = false;   // Does the wep have a proc
	}
}

class OHwep {
	int type;     // Dagger:0, Sword:1, Mace:2, Fist:3
	int wep_skill;
	double minDam;
	double maxDam;
	double speed;
	double dps;

	// Stats added
	double strength;
	double agility;
	double intellect;
	double spirit;
	double stamina;

	double crit;
	double hit;
	double attackPower;

	bool proc;   // Does the wep have a proc

	OHwep() {
		type = 1;     // Dagger:0, Sword:1, Mace:2, Fist:3
		wep_skill = 300;
		minDam = 1;
		maxDam = 1;
		speed = 1;
		dps = 1;

		// Stats added
		strength = 0;
		agility = 0;
		intellect = 0;
		spirit = 0;
		stamina = 0;

		crit = 0;
		hit = 0;
		attackPower = 0;

		proc = false;   // Does the wep have a proc
	}
}

class Stats {
public:
	int race;     // Human:0, Gnome:1, Dwarf:2, NightElf:3, Orc:4, Undead:5, Troll:6
	double strength;
	double agility;
	double intellect;
	double spirit;
	double stamina;

	double crit;
	double hit;
	double attackPower;

	MHwep mh;
	OHwep oh;

	Stats() {
		race  = 0;
		strength = 0;
		agility = 0;
		intellect = 0;
		spirit = 0;
		stamina = 0;

		crit = 0;
		hit = 0;
		attackPower = 0;

		mh = MHwep();
		oh = OHwep();
	}
};

class Equipment {
public:
	double strength;
	double agility;
	double intellect;
	double spirit;
	double stamina;

	double crit;
	double hit;
	double attackPower;

	Equipment() {
		strength = 0;
		agility = 0;
		intellect = 0;
		spirit = 0;
		stamina = 0;

		crit = 0;
		hit = 0;
		attackPower = 0;
	}
}

class CombatInfo {
public:
	long unsigned iterations;
	unsigned double fight_length;
	int boss_level;
	char armor_class;

	CombatInfo() {
		iterations = 1000;
		fight_length = 100;
		boss_level = 63;
		armor_class = 'h';
	}
}
class Buffs {
public:
	// World Buffs
	bool onyhead;
	bool zgheart;
	bool songflower;
	bool fengus;
	bool slipkik;
	bool wcb;
	bool dmf;

	// Raid buffs
	int anni_stacks;
	bool motw;
	bool battle_shout;
	bool trueshot;
	bool lotp;
	bool might;
	bool kings;
	bool stregth_of_earth;
	bool grace_of_air;
	bool gnomish_chicken;
	bool gift_of_arthas;
	bool faerie_fire;
	bool sunder;
	bool curse_of_reck;
	bool imp_ea;

	// Consumes
	bool flask_titans;
	bool flask_sp;
	bool mongoose;
	bool juju_power;
	bool juju_might;
	bool scorpok;
	bool roids;
	bool stam_zanza;
	bool holiday_hit_food;
	bool dumplings;
	bool squid;
	bool dbchili;

	Buffs() {
		// World Buffs
		onyhead = false;
		zgheart = false;
		songflower = false;
		fengus = false;
		slipkik = false;
		wcb = false;
		dmf = false;

		// Raid buffs
		anni_stacks = 0;
		motw = false;
		battle_shout = false;
		trueshot = false;
		lotp = false;
		might = false;
		kings = false;
		stregth_of_earth = false;
		grace_of_air = false;
		gnomish_chicken = false;
		gift_of_arthas = false;
		faerie_fire = false;
		sunder = false;
		curse_of_reck = false;
		imp_ea = false;

		// Consumes
		flask_titans = false;
		flask_sp = false;
		mongoose = false;
		juju_power = false;
		juju_might = false;
		scorpok = false;
		roids = false;
		stam_zanza  = false;
		holiday_hit_food = false;
		dumplings = false;
		squid = false;
		dbchili = false;
	}

}

class Proc {
public:
	int id;
	double chance;
	// Special Flags
	bool mh_active;
	bool oh_active;
	bool autos_only;
	bool gcd_blocked;
Proc() {
	id = -1;
	chance = 0.0;
	mh_active = false;
	oh_active = false;
	autos_only = false;
	gcd_blocked = false;
	}
Proc(int id_in, double chance_in, bool mh_in, bool oh_in, bool auto_in, bool gcd_in) {
	id = id_in;
	chance = chance_in;
	mh_active = mh_in;
	oh_active = oh_in;
	autos_only = auto_in;
	gcd_blocked = gcd_in;
	}
}

class Cooldown {
public:
	int id;
	bool availabe;
	double cd_time;
	double cost;
	double duration
	bool on_gcd;
	double gcd_time;
Cooldown() {
	id = -1;
	availabe = false;
	cd_time = 1.0;
	cost = 0;
	duration = 0;
	on_gcd = false;
	gcd_time = 100;
	}
Cooldown(int a, bool b, double c, double d, double dur, bool e, double f) {
	id = a;
	availabe = b;
	cd_time = c;
	cost = d;
	duration = dur;
	on_gcd = e;
	gcd_time = f;
	}
}

void get_race(Stats&, std::vector<Cooldown>&);
void get_gear(Equipment&, std::vector<Proc>&, std::vector<Cooldown>&);
void get_buffs(Buffs&);
void calc_stats(Stats&, Equipment&, Buffs&);
void get_fight_info(CombatInfo&);
unsigned run_encounter(Stats&, std::vector<Proc>&, std::vector<Cooldown>&, CombatInfo&);

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
	long unsigned iter_count = 0;
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
void get_gear(Equipment&, std::vector<Proc>&, std::vector<Cooldown>&) {}
void get_buffs(Buffs&) {}
void calc_stats(Stats&, Equipment&, Buffs&) {}
void get_fight_info(CombatInfo&) {}
unsigned run_encounter(Stats&, std::vector<Proc>&, std::vector<Cooldown>&, CombatInfo&) {}