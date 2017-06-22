//============================================================================
// Name        : 1.6.cpp
// Author      : Matthew Sembinelli
// Version     :
// Copyright   : Copyright 2017
// Description : 1.6 - String Compression
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>
#include <bitset>
using namespace std;

string compress_string(string &str)
{
    size_t index = 1;
    size_t erases = 0;
    string original_str(str);

    while(index < str.length())
    {
        if(str[index-1] == str[index])
        {
            str.erase(index, 1);
            ++erases;
            if(index >= str.length())
            {
                char buf[32];
                str.append(itoa(++erases, buf, 10));
                break;
            }
        }
        else
        {
            char buf[32];
            str.insert(index, itoa(++erases, buf, 10));
            erases = 0;
            index += 2;
        }
    }

    if(str.length() >= original_str.length())
    {
        return original_str;
    }

    return str;
}

void print(string str)
{
    cout << str << endl;
}

int main() {
    string test1 = "aabcccccaaa";
    string test2 = "aabbccdd";
    string test3 = "abcde";
    string test4 = "aaaaaaaaaaa";

    print(compress_string(test1));
    print(compress_string(test2));
    print(compress_string(test3));
    print(compress_string(test4));

    return 0;
}
