#pragma once
#include "String.h"
#include <iostream>
struct Element {
	String string;
	Element * next;
};
class List {
	int length;
	Element * first;
	Element * last;
public:
	List();
	void add(const String &string);
	void remove(const String &string);
	Element * find(const String &string);
	int getLength();
	void print();
};