#include "Player.h"


Player::Player() {}

Player::~Player() {
	for (auto spell : spellList) {
		delete spell;
	}
}

bool Player::FindSpell(String& spell) {
	int upper = spellList.size() - 1;
	int lower = 0;
	int target;
	String temp;
	while (lower <= upper) {
		target = lower + (upper - lower) / 2;
		temp = spellList[target]->GetName();
		temp.ToLower();
		if (temp == spell) return true;
		else if (temp < spell) lower = target + 1;
		else upper = target;
	}
	return false;
}

Spell* Player::CastSpell(String& spell)
{
	int upper = spellList.size() - 1;
	int lower = 0;
	int target;
	String temp;
	while (lower <= upper) {
		target = lower + (upper - lower) / 2;
		temp = spellList[target]->GetName();
		temp.ToLower();
		if (temp == spell) return spellList[target];
		else if (temp < spell) lower = target + 1;
		else upper = target;
	}
	return nullptr;
}

std::vector<Spell*> Player::GetSpellList() {
	return this->spellList;
}

void Player::SpellList(){
	for (int i = 0; i < spellList.size(); i++) {
		std::cout << "\t\t" << spellList[i]->GetName() << "\n";
	}
}

void Player::AddSpell(Spell* spell) {
	spellList.push_back(spell);
	if (spellList.size() >= 2) std::sort(spellList.begin(), spellList.end(), Spell::Compare);
}