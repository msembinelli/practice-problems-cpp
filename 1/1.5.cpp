//============================================================================
// Name        : 1.5.cpp
// Author      : Matthew Sembinelli
// Version     :
// Copyright   : Copyright 2017
// Description : 1.5 - one_away
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>
#include <bitset>
using namespace std;

bool one_away_difference_of_one(string &str1, string &str2)
{
    bool found_missing_char = false;
    size_t index1 = 0;
    size_t index2 = 0;
    while(index2 < str2.length() && index1 < str1.length())
    {
        if(str1[index1] != str2[index2])
        {
            if(!found_missing_char)
            {
                found_missing_char = true;
            }
            else
            {
                return false;
            }
            index2++;
        }
        else
        {
            index1++;
            index2++;
        }
    }

    return true;
}

bool one_away_equal_length_helper(string &str1, string &str2)
{
    bool found_different_char = false;
    for(size_t i = 0; i < str1.length(); i++)
    {
        if(str1[i] != str2[i])
        {
            if(!found_different_char)
            {
                found_different_char = true;
            }
            else
            {
                return false;
            }

        }
    }
    return true;
}

// O(n) (if n < m) or O(m) (if m < n)
bool one_away2(string &str1, string &str2)
{
    if(abs(str1.length() - str2.length()) > 1)
    {
        return false;
    }

    if(str1.length() == str2.length())
    {
        return one_away_equal_length_helper(str1, str2);
    }
    else if(str1.length() > str2.length())
    {
        return one_away_difference_of_one(str2, str1);
    }
    else
    {
        return one_away_difference_of_one(str1, str2);
    }

    return false;
}

// O(n) + O(m)
bool one_away(string &str1, string &str2)
{
    if(abs(str1.length() - str2.length()) > 1)
    {
        return false;
    }

    bitset<256> bits(0);
    for(size_t i = 0; i < str1.length(); i++)
    {
        bits.set(str1[i]);
    }
    for(size_t i = 0; i < str2.length(); i++)
    {
        bits.reset(str2[i]);
    }

    if(bits.count() > 1)
    {
        return false;
    }

    return true;
}

void print(string &str1, string &str2, bool result)
{
    if(result)
    {
        cout << str1 + ", " + str2 + " -> " + "true" << endl;
    }
    else
    {
        cout << str1 + ", " + str2 + " -> " + "false" << endl;
    }
}

int main() {
    string test1[] = {"pale", "ple"};
    string test2[] = {"pales", "pale"};
    string test3[] = {"pale", "bale"};
    string test4[] = {"pale", "bake"};

    print(test1[0], test1[1], one_away(test1[0], test1[1]));
    print(test2[0], test2[1], one_away(test2[0], test2[1]));
    print(test3[0], test3[1], one_away(test3[0], test3[1]));
    print(test4[0], test4[1], one_away(test4[0], test4[1]));

    print(test1[0], test1[1], one_away2(test1[0], test1[1]));
    print(test2[0], test2[1], one_away2(test2[0], test2[1]));
    print(test3[0], test3[1], one_away2(test3[0], test3[1]));
    print(test4[0], test4[1], one_away2(test4[0], test4[1]));

    return 0;
}
