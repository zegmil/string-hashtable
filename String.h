#pragma once
#include <stdlib.h>
#include <math.h>
class String
{
public:
	int length;
	char * value;

	String();
	~String();
	String(const char * text);
	String(const String &text);
	String* operator = (const char *text);
	String*  operator = (const String &text);
	void assign(const char * text);
	String& operator + (const char * text) const;
	String& operator + (const String & text) const;
	bool operator == (const String & text) const;
	bool operator != (const String & text) const;
	int hashCode(int bound) const; // for Strings only
};