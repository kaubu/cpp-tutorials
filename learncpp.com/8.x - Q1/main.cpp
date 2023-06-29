#include <iostream>
#include <string>

enum class MonsterType
{
	ogre,
	dragon,
	orc,
	giantSpider,
	slime
};

struct Monster
{
	MonsterType monsterType;
	std::string name;
	int health;
};

void printMonster(Monster monster)
{
	std::string stringMonsterType{};
	
	switch (monster.monsterType)
	{
		case MonsterType::ogre:
		{
			stringMonsterType = "Ogre";
			break;
		}
		case MonsterType::dragon:
		{
			stringMonsterType = "Dragon";
			break;
		}
		case MonsterType::orc:
		{
			stringMonsterType = "Orc";
			break;
		}
		case MonsterType::giantSpider:
		{
			stringMonsterType = "Giant Spider";
			break;
		}
		case MonsterType::slime:
		{
			stringMonsterType = "Slime";
			break;
		}
	}

	std::cout << "This " << stringMonsterType << " is named " << monster.name << " and has " << monster.health << " health.\n";
}

int main()
{
	Monster torg = Monster{ MonsterType::ogre, "Torg", 145 };
	Monster blurp = Monster{ MonsterType::slime, "Blurp", 23 };

	printMonster(torg);
	printMonster(blurp);
	
	return 0;
}