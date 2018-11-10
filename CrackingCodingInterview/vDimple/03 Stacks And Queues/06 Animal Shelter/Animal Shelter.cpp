#include "Animal Shelter.h"

void AnimalShelter::enqueue(AnimalType t, std::string const name)
{
	Animal obj(name);
	obj.setOrder(++order);
	switch (t)
	{
	case CAT:
		catList.push_back(obj);
		break;
	case DOG:
		dogList.push_back(obj);
		break;
	default:
		throw std::exception("Invalid Animal Type");
		break;
	}
}

Animal AnimalShelter::dequeue(AnimalType type)
{
	Animal obj;
	if (type == AnimalType::DOG)
	{
		if (dogList.empty())
			throw std::exception("No Dog in the Animal Shelter");
		else
		{
			obj = dogList.front();
			dogList.pop_front();
		}
	}
	if (type == AnimalType::CAT)
	{
		if (catList.empty())
			throw std::exception("No Cat in the Animal Shelter");
		else
		{
			obj = catList.front();
			catList.pop_front();
		}
	}
	if (type == AnimalType::ANY)
	{
		if (dogList.empty() && catList.empty())
			throw std::exception("No Animal in the Animal Shelter");

		if (!dogList.empty() && catList.empty())
		{
			obj = dogList.front();
			dogList.pop_front();
		}

		if (dogList.empty() && !catList.empty())
		{
			obj = catList.front();
			catList.pop_front();
		}

		if (!dogList.empty() && !catList.empty())
		{
			if (dogList.front().getOrder() > catList.front().getOrder())
			{
				obj = catList.front();
				catList.pop_front();
			}
			else
			{
				obj = dogList.front();
				dogList.pop_front();
			}
		}
	}
	return obj;
}
