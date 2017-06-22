//============================================================================
// Name        : 1.4.cpp
// Author      : Matthew Sembinelli
// Version     :
// Copyright   : Copyright 2017
// Description : 1.4 - palindrome_permutation
//============================================================================

#include <iostream>
#include <string>
using namespace std;

// O(n)
bool palindrome_permutation2(string &str)
{
    short character_count[256] = {0};
    int odd_count = 0;
    for(size_t i = 0; i < str.length(); i++)
    {
        if(str[i] != ' ')
        {
            character_count[(int)str[i]]++;
            if(character_count[(int)str[i]] % 2 == 0)
            {
                odd_count--;
            }
            else
            {
                odd_count++;
            }
        }
    }

    if(odd_count <= 1)
    {
        return true;
    }

    return false;
}

// O(n) + O(m)
bool palindrome_permutation(string &str)
{
    short character_count[256] = {0};
    for(size_t i = 0; i < str.length(); i++)
    {
        if(str[i] != ' ')
        {
            character_count[(int)str[i]]++;
        }
    }
    short num_characters_with_odd_occurrences = 0;
    short num_characters_with_even_occurrences = 0;

    for(size_t i = 0; i < sizeof(character_count)/sizeof(*character_count); i++)
    {
        if(character_count[i] > 0)
        {
            if(character_count[i] % 2 == 0)
            {
                // Even
                num_characters_with_even_occurrences++;
            }
            else
            {
                // Odd
                num_characters_with_odd_occurrences++;
            }
        }
    }

    if(num_characters_with_even_occurrences >= 0 && num_characters_with_odd_occurrences <= 1)
    {
        return true;
    }

    return false;
}

void print(string &str, bool result)
{
    if(result)
    {
        cout << str + " is a palindrome permutation." << endl;
    }
    else
    {
        cout << str + " is NOT a palindrome permutation." << endl;
    }
}

int main() {
    string test1 = "tact coa";
    string test2 = "racecar";
    string test3 = "1221";
    string test4 = "hello";
    string test5 = "progressive";
    string test6 = "1";

    print(test1, palindrome_permutation(test1));
    print(test2, palindrome_permutation(test2));
    print(test3, palindrome_permutation(test3));
    print(test4, palindrome_permutation(test4));
    print(test5, palindrome_permutation(test5));
    print(test6, palindrome_permutation(test6));

    print(test1, palindrome_permutation2(test1));
    print(test2, palindrome_permutation2(test2));
    print(test3, palindrome_permutation2(test3));
    print(test4, palindrome_permutation2(test4));
    print(test5, palindrome_permutation2(test5));
    print(test6, palindrome_permutation2(test6));

    return 0;
}
