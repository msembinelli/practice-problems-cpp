//============================================================================
// Name        : 1.8.cpp
// Author      : Matthew Sembinelli
// Version     :
// Copyright   : Copyright 2017
// Description : 1.8 - Zero Matrix
// Could still use some improvement. There is a more efficient algorithm.
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <bitset>
using namespace std;

void zero_matrix(int** matrix, int m, int n)
{
    bool columns[m] = {0};
    bool rows[n] = {0};
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 0)
            {
                columns[i] = true;
                rows[j] = true;
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        if(columns[i] == true)
        {
            for(int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for(int j = 0; j < n; j++)
    {
        if(rows[j] == true)
        {
            for(int i = 0; i < n; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void print_matrix(int** matrix, int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        cout << setw(3) << flush;
        for(int j = 0; j < n; j++)
        {
            cout << left << matrix[i][j] << setw(3) << flush;
        }
        cout << endl << flush;
    }
}

int main() {
    srand(time(NULL));

    int m = 6;
    int n = 4;

    int** matrix = new int*[m];
    for(int i = 0; i < m; i++)
    {
        matrix[i] = new int[n];
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }

    print_matrix(matrix, m, n);

    cout << endl << "After zeroing:" << endl << flush;

    zero_matrix(matrix, m, n);

    print_matrix(matrix, m, n);

    return 0;
}
