/*
Given a matrix where every row is sorted in increasing order. 
Write a function that finds and returns a common element in all rows. 
If there is no common element, then returns -1. 

Example: 
 

Input: mat[4][5] = { {1, 2, 3, 4, 5},
                    {2, 4, 5, 8, 10},
                    {3, 5, 7, 9, 11},
                    {1, 3, 5, 7, 9},
                  };
Output: 5
*/

#include <bits/stdc++.h>
using namespace std;
 
// Specify number of rows and columns
#define M 4
#define N 5
 
// Returns common element in all rows of mat[M][N]. If there is no
// common element, then -1 is returned
int findCommon(int mat[M][N])
{
    int column[M];
    int min_row;

    for (int i = 0; i < M; i++)
    {
        column[i] = N-1;
    }
    
    min_row = 0;

    while (column[min_row] >= 0)
    {
        for (int i = 0; i < M; i++)
        {
            if (mat[i][column[i]] < mat[min_row][column[min_row]])
            {
                min_row = i;
            }
        }
        
        int eq_count = 0;

        for (int i = 0; i < M; i++)
        {
            if (mat[i][column[i]] > mat[min_row][column[min_row]])
            {
                if (column[i] == 0)
                {
                    return -1;
                }
                column[i] -= 1;
            }
            else
            {
                eq_count++;
            }
        }
        if (eq_count == M)
        {
            return mat[min_row][column[min_row]];
        }
    }
    return -1;
}


// Driver Code
int main()
{
    int mat[M][N] = {
        { 1, 2, 3, 4, 5 },
        { 2, 4, 5, 8, 10 },
        { 3, 5, 7, 9, 11 },
        { 1, 3, 5, 7, 9 },
    };
    int result = findCommon(mat);
    if (result == -1)
        cout << "No common element";
    else
        cout << "Common element is " << result;
    return 0;
}