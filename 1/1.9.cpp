//============================================================================
// Name        : 1.9.cpp
// Author      : Matthew Sembinelli
// Version     :
// Copyright   : Copyright 2017
// Description : 1.9 - String Rotation
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool is_rotation(string &str1, string &str2)
{
    if(str1.length() == 0)
    {
        return false;
    }
    if(str1.length() != str2.length())
    {
        return false;
    }

    string tmp = str1 + str1;
    if(tmp.find(str2) != string::npos)
    {
        return true;
    }

    return false;
}

void print(string &str1, string &str2, bool result)
{
    if(result)
    {
        cout << str1 + " is a rotation of " + str2 << endl;
    }
    else
    {
        cout << str1 + " is NOT a rotation of " + str2 << endl;
    }
}

int main() {
    string test1[] = {"waterbottle", "erbottlewat"};
    string test2[] = {"waterbottle", "erbotlewat"};
    string test3[] = {"hello", "ello"};
    string test4[] = {"newest", "stnewe"};

    print(test1[0], test1[1], is_rotation(test1[0], test1[1]));
    print(test2[0], test2[1], is_rotation(test2[0], test2[1]));
    print(test3[0], test3[1], is_rotation(test3[0], test3[1]));
    print(test4[0], test4[1], is_rotation(test4[0], test4[1]));

    return 0;
}
