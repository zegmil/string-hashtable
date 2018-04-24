#pragma once
#include "List.h"

class HashTable
{
	List * elements;
	int size;
public:
	HashTable(int size);
	void add(const String &string);
	void remove(const String &string);
	bool exists(const String &string);
	void printDistribution();
};