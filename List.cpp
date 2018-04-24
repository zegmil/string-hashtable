#include "List.h"
using namespace std;

List::List() {
	length = 0;
	first = NULL;
	last = NULL;
}

void List::add(const String &string) {
	Element * newElement = new Element();
	newElement->string = string;
	newElement->next = NULL;
	if (first == NULL)
		first = newElement;
	else 
		last->next = newElement;
	last = newElement;
	length++;
}

void List::remove(const String &string) {
	Element * current = first;
	Element * previous = NULL;
	while (current != NULL) {
		if (current->string != string) {
			previous = current;
			current = current->next;
		}
		else break;
	}
	if (current != NULL) {
		if (previous != NULL)
		{
			if (current->next != NULL)
				previous->next = current->next;
			else {
				previous->next = NULL;
				last = previous;
			}
		}
		else
			first = current->next;
		delete current;
		length--;
	}
}

Element * List::find(const String &string) {
	Element * current = first;
	while (current != NULL && current->string != string) {
		current = current->next;
	}
	return current;
}

int List::getLength() {
	return length;
}

void List::print() {
	Element *current = first;
	while (current != NULL) {
		cout << current->string.value << endl;
		current = current->next;
	}
}