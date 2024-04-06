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
		target = (upper + lower) / 2;
		temp = spellList[target]->GetName();
		temp.ToLower();
		if (temp == spell) return true;
		if (temp < spell) lower = target + 1;
		if (temp > spell) upper = target - 1;
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
		target = (upper + lower) / 2;
		temp = spellList[target]->GetName();
		temp.ToLower();
		if (temp == spell) return spellList[target];
		if (temp < spell) lower = target + 1;
		if (temp > spell) upper = target - 1;
	}
	return nullptr;
}

std::vector<Spell*> Player::GetSpellList() {
	return this->spellList;
}

void Player::SpellList(){
	for (int i = 0; i < spellList.size(); i++) {
		std::cout << "\t\t" << spellList[i]->GetName() << " | " << spellList[i]->GetDamage() << " damage" << "\n";
	}
}

void Player::AddSpell(Spell* spell) {
	spellList.push_back(spell);
	if (spellList.size() >= 2) std::sort(spellList.begin(), spellList.end(), Spell::Compare);
}

void Player::SetPos(Vec2 pos) {
	playerPos.x = pos.x;
	playerPos.y = pos.y;
}

Vec2 Player::GetPos() const {
	return playerPos;
}