#include "String.h"


String::String() 
{
	value = 0;
	length = 0;
}
String::~String()
{
	if (value != 0)
		delete value;
}
String::String(const char * text) 
{
	value = 0;
	length = 0;
	assign(text);
}

String::String(const String &text)
{
	value = 0;
	length = 0;
	assign(text.value);
}

String * String::operator = (const char *text)
{
	assign(text);
	return this;
}

String * String::operator = (const String &text)
{
	assign(text.value);
	return this;
}

void String::assign(const char * text)
{
	if (value != 0)
		delete value;
	length = 0;
	for (; text[length] != '\0'; length++);
	value = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		value[i] = text[i];
	}
	value[length] = '\0';
}


String& String::operator + (const char * text) const
{
	int textLength = 0;
	for (; text[textLength] != '\0'; textLength++);
	int resultLength = length + textLength;
	char * result = new char[resultLength+1];
	int i = 0;
	for (; i < length; i++)
		result[i] = value[i];
	for (int a = 0; i < resultLength; i++, a++)
		result[i] = text[a];
	result[i] = '\0';
	return String(result);
}
String& String::operator + (const String & text) const
{
	return(*this + text.value);
}

bool String::operator == (const String & text) const
{
	if (length != text.length)
		return false;
	else
	{
		for (int i = 0; i < length; i++)
		{
			if (value[i] != text.value[i])
				return false;
		}
		return true;
	}
}

bool String::operator != (const String & text) const
{
	if (*this == text)
		return false;
	else
		return true;	
}

int String::hashCode(int bound) const {
	int hash = 0;
	int coefficient = 3; // Arbitrarly chosen
	for (int i = 0; i < length; i++)
	{
		hash += value[i] * pow(coefficient, i);
	}
	return hash % bound;
}