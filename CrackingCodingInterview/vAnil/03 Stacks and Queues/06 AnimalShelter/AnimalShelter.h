#pragma once
#ifndef __ANIMAL_SHTELER_
#define __ANIMAL_SHELTER_
#include <iostream>
#include <list>

enum ANIMALTYPE
{
	DOG,
	CAT
};

struct Animal
{
	ANIMALTYPE type;
	std::string name;
};

class AnimalShelter
{
public:
	void enque(Animal const &item)
	{
		if (item.type == ANIMALTYPE::DOG)
		{
			dogList.push_back({item, lastAge++});
		}
		else
		{
			catList.push_back({ item, lastAge++ });
		}
	}

	Animal deque()
	{
		if (dogList.empty() && catList.empty())
			throw std::string("No animal found");

		if (dogList.empty() && !catList.empty())
		{
			AnimalInfo catFront = catList.front();
			catList.pop_front();
			return catFront.item;
		}

		if (!dogList.empty() && catList.empty())
		{
			AnimalInfo dogFront = dogList.front();
			dogList.pop_front();
			return dogFront.item;
		}

		AnimalInfo catFront = catList.front();
		AnimalInfo dogFront = dogList.front();

		if (catFront.age > dogFront.age)
		{
			dogList.pop_front();
			return dogFront.item;
		}
		else
		{
			catList.pop_front();
			return catFront.item;
		}
	}

	Animal dequeSpecial(ANIMALTYPE type)
	{
		if (type == ANIMALTYPE::DOG)
		{
			if (dogList.empty())
				throw std::string("No dog found");

			AnimalInfo dogFront = dogList.front();
			dogList.pop_front();
			return dogFront.item;
		}
		else
		{
			if (catList.empty())
				throw std::string("No cat found");

			AnimalInfo catFront = catList.front();
			catList.pop_front();
			return catFront.item;
		}
	}


private:
	struct AnimalInfo
	{
		Animal item;
		int age;
	};

	std::list<AnimalInfo> dogList;
	std::list<AnimalInfo> catList;
	int lastAge = 0;
};

#endif //__ANIMAL_SHTELER_

