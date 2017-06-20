//============================================================================
// Name        : 1.1.cpp
// Author      : Matthew Sembinelli
// Version     :
// Copyright   : Copyright 2017
// Description : 1.1 - is_unique
//============================================================================

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

bool is_unique_no_structures(const string &str)
{
	// Do a comparison in place.
	// Uses O(n) space but is O(n^2) time.
	for(size_t i = 0; i < str.length(); i++)
	{
		for(size_t j = str.length() - 1; j >= i; i--)
		{
			if(str[i] == str[j])
			{
				return false;
			}
		}
	}

	return true;
}

bool is_unique_optimized(const string &str)
{
	// Use a bitset since we don't need to count beyond 1 for each entry.
	// Still acts like a hash table, but reduces space by a factor of 8.
	// O(n) space, O(n) time
	bitset<256> bits(0);

	for(size_t i = 0; i < str.length(); i++)
	{
		int entry = str[i];
		if(bits.test(entry) > 0)
		{
			return false;
		}
		bits.set(entry);
	}

	return true;
}

bool is_unique(const string &str)
{
	// The integer array acts like a hash table.
	// Keep a counter at each array entry.
	// The character casted to int acts as the key.
	// O(n) space, O(n) time
	int character_counter[256] = { 0 };

	for(size_t i = 0; i < str.length(); i++)
	{
		int entry = str[i];
		if(character_counter[entry]++ > 1)
		{
			return false;
		}
	}

	return true;
}

void print(string str, bool unique)
{
	if(unique)
	{
		cout << str + " is unique!";
	}
	else
	{
		cout << str + " is NOT unique!";
	}
	cout << endl;
}

int main() {
	string test1 = "hello!";
	string test2 = "123456";
	string test3 = "blockchain";
	string test4 = " ";
	string test5 = "square";
	string test6 = "github";

	print(test1, is_unique(test1));
	print(test2, is_unique(test2));
	print(test3, is_unique(test3));
	print(test4, is_unique(test4));
	print(test5, is_unique(test5));
	print(test6, is_unique(test6));

	print(test1, is_unique_optimized(test1));
	print(test2, is_unique_optimized(test2));
	print(test3, is_unique_optimized(test3));
	print(test4, is_unique_optimized(test4));
	print(test5, is_unique_optimized(test5));
	print(test6, is_unique_optimized(test6));

	print(test1, is_unique_no_structures(test1));
	print(test2, is_unique_no_structures(test2));
	print(test3, is_unique_no_structures(test3));
	print(test4, is_unique_no_structures(test4));
	print(test5, is_unique_no_structures(test5));
	print(test6, is_unique_no_structures(test6));

	return 0;
}
