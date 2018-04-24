#include "HashTable.h"
using namespace std;

HashTable::HashTable(int size) {
	elements = new List[size];
	this->size = size;
}

void HashTable::add(const String &string) {
	int hash = string.hashCode(size);
	elements[hash].add(string);
}

void HashTable::remove(const String &string) {
	int hash = string.hashCode(size);
	elements[hash].remove(string);
}

bool HashTable::exists(const String &string) {
	int hash = string.hashCode(size);
	if (elements[hash].find(string) != NULL)
		return true;
	else
		return false;
}

void HashTable::printDistribution() {
	int amount = 0;
	int length;
	for (int i = 0; i < size; i++) {
		length = elements[i].getLength();
		cout << "[" << i << "] = " << length << endl;
		amount += length;
	}
	cout << endl << "Suma elementow : " << amount << endl << endl;
}

