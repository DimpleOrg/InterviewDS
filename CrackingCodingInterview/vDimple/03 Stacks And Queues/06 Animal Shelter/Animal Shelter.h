#pragma once
#ifndef __ANIMAL_SHELTER_
#define __ANIMAL_SHELTER_

#ifdef _ANIMALSHELTER_
#define ANIMALSHELTER_API __declspec(dllexport)
#else
#define ANIMALSHELTER_API __declspec(dllimport)
#endif

#include<iostream>
#include<list>

enum AnimalType {DOG, CAT, ANY};

class Animal
{
	size_t order;
	std::string name;
public:
	Animal(): order(0) {}
	Animal(std::string nam)
	{ 
		name = nam;
	}
	void setOrder(size_t i)
	{
		order = i;
	}
	size_t getOrder() const
	{
		return order;
	}
	std::string getname() const
	{
		return name;
	}
};

class AnimalShelter
{
	size_t order = 0;
	std::list<Animal> catList;
	std::list<Animal> dogList;
public:
	__declspec(dllexport) void enqueue(AnimalType, std::string const);
	__declspec(dllexport) Animal dequeue(AnimalType type);
};


#endif