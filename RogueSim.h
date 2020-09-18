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
	int helm;
	int neck;
	int shoulder;
	int chest;
	int belt;
	int legs;
	int feet;
	int wrist;
	int hands;
	int ring1;
	int ring2;
	int trink1;
	int trink2;
	int back;
	int mhwep;
	int ohwep;
	int ranged;

	double strength;
	double agility;
	double intellect;
	double spirit;
	double stamina;

	double crit;
	double hit;
	double attackPower;

	Equipment() {
		helm = -1;
		neck = -1;
		shoulder = -1;
		chest = -1;
		belt = -1;
		legs = -1;
		feet = -1;
		wrist = -1;
		hands = -1;
		ring1 = -1;
		ring2 = -1;
		trink1 = -1;
		trink2 = -1;
		back = -1;
		mhwep = -1;
		ohwep = -1;
		ranged = -1;

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