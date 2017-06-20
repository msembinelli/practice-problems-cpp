//============================================================================
// Name        : 1.2.cpp
// Author      : Matthew Sembinelli
// Version     :
// Copyright   : Copyright 2017
// Description : 1.2 - check_permutation
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check_permutation_char_count(string &str1, string &str2)
{
    if(str1.length() != str2.length())
    {
        return false;
    }

    short count_chars[255] = { 0 };
    for(size_t i = 0; i < str1.length(); i++)
    {
        count_chars[(int)str1[i]]++;
        count_chars[(int)str2[i]]--;
    }

    for(size_t i = 0; i < sizeof(count_chars)/sizeof(short); i++)
    {
        if(count_chars[i] != 0)
        {
            return false;
        }
    }

    return true;
}

bool check_permutation(string &str1, string &str2)
{
    if(str1.length() != str2.length())
    {
        return false;
    }

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    for(size_t i = 0; i < str1.length(); i++)
    {
        if(str1[i] != str2[i])
        {
            return false;
        }
    }

    return true;
}

void print(const string &str1, const string &str2, bool permutation)
{
    if(permutation)
    {
        cout << str1 + " is a permutation of "+ str2;
    }
    else
    {
        cout << str1 + " is NOT a permutation of "+ str2;
    }
    cout << endl;
}

int main() {
    string string_list[] = { "123456", "314265", "string", "gnrsti", "hello", "hell0" };

    for(size_t i = 0; i < 6; i+=2)
    {
        print(string_list[i], string_list[i+1], check_permutation_char_count(string_list[i], string_list[i+1]));
    }

    for(size_t i = 0; i < 6; i+=2)
    {
        print(string_list[i], string_list[i+1], check_permutation(string_list[i], string_list[i+1]));
    }

    return 0;
}
