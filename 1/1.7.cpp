//============================================================================
// Name        : 1.7.cpp
// Author      : Matthew Sembinelli
// Version     :
// Copyright   : Copyright 2017
// Description : 1.7 - Rotate Matrix
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

void rotate_matrix_in_place(int** matrix, int n)
{
    for(int i = 0; i < n/2; i++)
    {
        for(int j = i; j < n-i-1; j++)
        {
            int tmp = matrix[j][i];
            matrix[j][i] = matrix[n-i-1][j];
            matrix[n-i-1][j] = matrix[n-j-1][n-i-1];
            matrix[n-j-1][n-i-1] = matrix[i][n-j-1];
            matrix[i][n-j-1] = tmp;
        }
    }
}

void print_matrix(int** matrix, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << setw(3);
        for(int j = 0; j < n; j++)
        {
            cout << left << matrix[i][j] << setw(3);
        }
        cout << endl;
    }
}

int main() {
    srand(time(NULL));

    int n = 4;
    int** matrix = new int*[n];
    for(int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            matrix[i][j] = rand() % 10 + 1;
        }
    }

    print_matrix(matrix, n);

    cout << endl << "Rotate 90 degrees:" << endl;

    rotate_matrix_in_place(matrix, n);

    print_matrix(matrix, n);

    return 0;
}
