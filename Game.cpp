#include "Animal.h"
#include "Consumable.h"
#include "Game.h"
#include "Spell.h"
#include "Weapon.h"

Game::Game() {
	_player = new Player;
	std::random_device rd;
	std::mt19937 gen(rd());
	MakeRooms(gen);
	for (int i = 0; _player->GetSpellList().size() < INITIAL_SPELL_AMOUNT; i++) {
		Spell* spell = GenerateSpell(gen);
		if (spell != nullptr) {
			String checkSpell = spell->GetName();
			if (!_player->FindSpell(checkSpell.ToLower())) _player->AddSpell(spell);
		}
	}	
}

Game::~Game() {}

//Handles the game.
void Game::Run() {
	int playerPosX = (MAP_WIDTH - 1) / 2;
	int playerPosY = (MAP_HEIGHT - 1) / 2;
	std::cout << "\t\tWELCOME TO THE DUNGEON." << std::endl << std::endl;
	std::cout << "\t\tPress 'Enter' to start.";

	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();

	while (true) {
		system("cls");
		std::cout << "\t\t" << rooms[playerPosY][playerPosX]->GetName() << " | POS: " << playerPosX << "," << playerPosY << "\n\n";
		rooms[playerPosY][playerPosX]->Description();
		std::cout << "\n";
		DisplayValidDirections(playerPosX, playerPosY);
		std::cout << "\t\tEnter 'help' to display avaiable commands\n";
		String input;
		String itemName;
		if (rooms[playerPosY][playerPosX]->GetItem() != nullptr) itemName = rooms[playerPosY][playerPosX]->GetItem()->GetName();
		else itemName = "";

		std::cout << "\n\t\t>> ";
		input.ReadFromConsole().ToLower();

		std::cout << "\n";

		if (input == commands[0] + " " + directions[0] && playerPosY > 0) playerPosY--;
		else if (input == commands[0] + " " + directions[1] && playerPosY < MAP_HEIGHT - 1) playerPosY++;
		else if (input == commands[0] + " " + directions[2] && playerPosX < MAP_WIDTH - 1) playerPosX++;
		else if (input == commands[0] + " " + directions[3] && playerPosX > 0) playerPosX--;
		else if (input == commands[1] + " " + itemName.ToLower() && rooms[playerPosY][playerPosX]->GetItem() != nullptr) {
			system("cls");
			std::cout << "\t\t" << rooms[playerPosY][playerPosX]->GetName() << " | POS: " << playerPosX << "," << playerPosY << "\n";
			rooms[playerPosY][playerPosX]->GetItem()->Use();
		}
		else if (input == commands[2]) {
			system("cls");
			std::cout << "\t\t" << rooms[playerPosY][playerPosX]->GetName() << " | POS: " << playerPosX << "," << playerPosY << "\n";
			if (rooms[playerPosY][playerPosX]->GetItem() == nullptr) std::cout << "\n\t\tYou see nothing of value here.\n";
			else rooms[playerPosY][playerPosX]->GetItem()->Description();
		}
		else if (input == commands[3]) break;
		else if (input == commands[4]) {
			system("cls");
			std::cout << "\t\t[Valid Commands]\n\n"
				<< "\t\tMove <direction>  | Moves towards direction.\n"
				<< "\t\tLook              | Checks room for items.\n"
				<< "\t\tUse <object name> | Uses named object.\n"
				<< "\t\tSpells            | Displays list of known spells.\n"
				<< "\t\tFind Spell        | Checks if spell is known. Asks for spell name.\n"
				<< "\t\tCast              | Casts a spell. Asks for spell name.\n"
				<< "\t\tHelp              | Displays commands.\n"
				<< "\t\tQuit              | Quits game.\n";
		}
		else if (input == commands[5]) {
			system("cls");
			std::cout << "\t\t" << rooms[playerPosY][playerPosX]->GetName() << " | POS: " << playerPosX << "," << playerPosY << "\n";
			std::cout << "\n\t\tEnter the spell you want to find.\n";
			std::cout << "\n\n\n\t\t>> ";
			input.ReadFromConsole().ToLower();
			bool found = _player->FindSpell(input);
			if (found) std::cout << "\n\n\t\tSpell was found.\n";
			else std::cout << "\n\n\t\tYou do not know such a spell.\n";
		}
		else if (input == commands[6]) {
			system("cls");
			std::cout << "\t\t[Spell List]\n\n";
			_player->SpellList();
		}
		else if (input == commands[7]) {
			system("cls");
			std::cout << "\t\t" << rooms[playerPosY][playerPosX]->GetName() << " | POS: " << playerPosX << "," << playerPosY << "\n";
			std::cout << "\n\t\tEnter the spell you want to cast.\n";
			std::cout << "\n\n\n\t\t>> ";
			input.ReadFromConsole().ToLower();
			Spell* spell = _player->CastSpell(input);
			if (spell != nullptr) spell->Cast();
			else std::cout << "\n\t\tYou don't know this spell.\n";
		}
		else {
			system("cls");
			std::cout << "\t\t" << rooms[playerPosY][playerPosX]->GetName() << " | POS: " << playerPosX << "," << playerPosY << "\n\n";
			std::cout << "\t\tInvalid Command!\n";
		} 

		std::cout << "\n\t\tPress 'Enter' to continue.";

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin.get();

	}
}

void Game::DisplayValidDirections(int x, int y) {
	std::cout << "\t\tYou can move: "
		<< ((y > 0) ? "north, " : "")
		<< ((x < MAP_WIDTH - 1) ? "east, " : "")
		<< ((y < MAP_HEIGHT - 1) ? "south, " : "")
		<< ((x > 0) ? "west, " : "") << std::endl;
}

//void Game::Move() {
//
//}
//
//void Game::Look() {
//
//}
//
//void Game::Use() {
//
//}
//
//void Game::Help() {
//
//}
//
//void Game::FindSpell() {
//
//}
//
//void Game::CastSpell() {
//
//}
//
//void Game::Spells() {
//
//}
//
//void Game::Quit() {
//
//}

//Randomly places rooms.
void Game::MakeRooms(std::mt19937& gen) {
	std::uniform_int_distribution<int> distr(1, 10);
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			int r = distr(gen);
			switch (r) {
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
				rooms[y][x] = new Room("Empty Room", "You are in a very bare room.", nullptr);
				break;
			case 5:
			case 6:
			case 7:
				rooms[y][x] = new Room("Hallway", "You are in a hallway.", MakeItem(gen));
				break;
			case 8:
				rooms[y][x] = new Room("Armoury", "You are in a room with racks of old weapons and stands of old armor.", MakeItem(gen));
				break;
			case 9:
				rooms[y][x] = new Room("Tomb", "You are in a burial chamber.", MakeItem(gen));
				break;
			case 10:
				rooms[y][x] = new Room("Treasure Room", "You are in a room filled with various treasure.", MakeItem(gen));
				break;
			}
		}
	}
	rooms[(MAP_HEIGHT - 1) / 2][(MAP_WIDTH - 1) / 2] = new Room("Dungeon Entrance", "You are at the dungeon entrance.", nullptr);
}


/*Random item generator function.
* Generates items from predetermined items of derived types.
* 
*/
Item* Game::MakeItem(std::mt19937 &gen) {
	Item* item{};
	std::uniform_int_distribution<int> getItem(1, 5);
	std::uniform_int_distribution<int> itemType(0, 2);
	std::uniform_int_distribution<int> consumable(0, 5);
	std::uniform_int_distribution<int> weapon(0, 5);
	std::uniform_int_distribution<int> animal(0, 5);
	int r = getItem(gen);
	if (r <= 3) {
		r = itemType(gen);
		switch (r) {
		case 0:
			//Consumables
			r = consumable(gen);
			switch (r) {
			case 0:
				item = new Consumable("Poison", "This is poison.", "You feel weakened.", 1);
				break;
			case 1:
				item = new Consumable("Mana Potion", "This is a mana potion.", "You have regained some mana.", 3);
				break;
			case 2:
				item = new Consumable("Lockpick", "This is a lockpick.", "", 3);
				break;
			case 3:
				item = new Consumable("Water Bottle", "This is a water bottle.", "You feel refreshed.", 5);
				break;
			case 4:
				item = new Consumable("Box of Rations", "This is a box of rations.", "They tasted pretty bland.", 3);
				break;
			case 5:
				item = new Consumable("Health Potion", "This is a health potion.", "You have regained some vitality.", 3);
				break;
			}
			break;
		case 1:
			//Animals
			r = animal(gen);
			switch (r) {
			case 0:
				item = new Animal("Bird", "This is a bird.", "The bird flaps it's wings.");
				break;
			case 1:
				item = new Animal("Rat", "This is a rat.", "The rat scurries around.");
				break;
			case 2:
				item = new Animal("Mouse", "This is a mouse.", "The mouse squeaks.");
				break;
			case 3:
				item = new Animal("Snake", "This is a snake.", "The snake slithers about.");
				break;
			case 4:
				item = new Animal("Skeleton", "This is a skeleton.", "The skeleton rattles.");
				break;
			case 5:
				item = new Animal("Lizard", "This is a lizard.", "The lizard scurries around.");
				break;
			}
			break;
		case 2:
			//Weapons
			r = weapon(gen);
			switch (r) {
			case 0:
				item = new Weapon("Lightsaber", "An elegant weapon for a more civilised age.", false);
				break;
			case 1:
				item = new Weapon("Axe", "This is an axe.", true);
				break;
			case 2:
				item = new Weapon("Sword", "This is a sword.", true);
				break;
			case 3:
				item = new Weapon("Spear", "This is a spear.", true);
				break;
			case 4:
				item = new Weapon("Bow", "This is a bow.", true);
				break;
			case 5:
				item = new Weapon("Yamato", "You feel an aura of pure motivation.", false);
				break;
			}
			break;
		}
		return item;
	}
	else return nullptr;
}

Spell* Game::GenerateSpell(std::mt19937& gen)
{
	std::uniform_int_distribution<int> spells(1, 5);
	std::uniform_int_distribution<int> spellName(0, 28);
	std::uniform_int_distribution<int> spellDmg(10, 200);
	Spell* spell{};
	int spellN = spellName(gen);
	int spellD = spellDmg(gen);
	int spellC = spells(gen);
	switch (spellC) {
	case 1:
	case 2:
	case 3:
	case 4:
		spell = new Spell(spellNames[spellN], spellD);
		break;
	case 5:
		spell = nullptr;
		break;
	}
	return spell;
}
