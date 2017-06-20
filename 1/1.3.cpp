//============================================================================
// Name        : 1.3.cpp
// Author      : Matthew Sembinelli
// Version     :
// Copyright   : Copyright 2017
// Description : 1.3 - urlify
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void urlify(string &str, int true_length)
{
    string url_chars = "%20";
    int urlify_end_index = true_length - 1;
    for(size_t i = true_length - 1; i != 0; i--)
    {
        if(str[i] == ' ')
        {
            // Shift every character 2 to the right
            int current_word_size = urlify_end_index - i;
            int word_end_index = urlify_end_index;
            while(current_word_size--)
            {
                str[word_end_index + 2] = str[word_end_index];
                word_end_index--;
            }
            // String size increases by two, track this for next time so we know where to start moving stuff from
            urlify_end_index += 2;

            // Replace the string section with '%20'
            str.replace(i, url_chars.length(), url_chars);
        }
    }
}

void print(string &str)
{
    cout << "URLify string: " + str << endl;
}

int main() {
    string test1 = "Mr John Smith    ";
    string test2 = "Good day  ";
    string test3 = "Ethereum Bitcoin Litecoin      ";

    urlify(test1, 13);
    urlify(test2, 8);
    urlify(test3, 25);

    print(test1);
    print(test2);
    print(test3);

    return 0;
}
