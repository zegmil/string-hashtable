#include "HashTable.h"
#include <time.h>
#define SIZE 50000
#define LOOKUPS_NUMBER 10000
using namespace std;

bool arrayLookUp(String * array, const String &string) {
	for (int i = 0; i < SIZE; i++) {
		if (array[i] == string)
			return true;
	}
	return false;
}

String *generateRandomString() {
	String *string = new String();
	int randomSize = rand() % 10 + 3;
	string->value = new char[randomSize];
	for (int j = 0; j < randomSize - 1; j++) {
		char randomChar = rand() % 90 + 32;
		string->value[j] = randomChar;
	}
	string->value[randomSize - 1] = '\0';
	string->length = randomSize;
	return string;
}

int main() {
	srand(time(NULL));
	String * stringTable = new String[SIZE];
	//Filling the table with random strings
	for (int i = 0; i < SIZE; i++) {
		String * randomString = generateRandomString();
		stringTable[i] = *randomString;
		delete randomString;
	}
	HashTable hashTable(20);
	for (int i = 0; i < SIZE; i++) {
	hashTable.add(stringTable[i]);
	}
	//Distrubution
	hashTable.printDistribution();
	// Look up speed
	clock_t hashLookupStart = clock();
	for (int t = 0; t < LOOKUPS_NUMBER; t++) {
		String *randomString = generateRandomString();
		hashTable.exists(*randomString);
		delete randomString;
	}
	clock_t hashLookupFinish = clock();

	clock_t arrayLookupStart = clock();
	for (int t = 0; t < LOOKUPS_NUMBER; t++) {
		String *randomString = generateRandomString();
		arrayLookUp(stringTable, *randomString);
		delete randomString;
	}
	clock_t arrayLookupFinish = clock();

	cout << "HashTable look up time: " << (double)(hashLookupFinish - hashLookupStart) / CLOCKS_PER_SEC << endl;
	cout << "Array look up time: " << (double)(arrayLookupFinish - arrayLookupStart) / CLOCKS_PER_SEC << endl;
	// Correctness 
	String testValue = "testValue";
	String tmp = stringTable[SIZE / 2];
	hashTable.remove(tmp);
	hashTable.remove(stringTable[SIZE / 3]);
	hashTable.add(testValue);
	hashTable.printDistribution();

	if (hashTable.exists(testValue) && !hashTable.exists(tmp) && !hashTable.exists(stringTable[SIZE / 3]))
		cout << "Adding and removing seems to work :)" << endl;
	else
		cout << "Something's wrong with adding or removing :(" << endl;

	system("pause");
	return 0;
}
