/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int M[5][5] = { { 1, 2, 3, 4, 21 },
                        { 5, 6, 7, 8, 22 },
                        { 9, 10, 11, 12, 23 },
                        { 13, 14, 15, 16, 24 },
                        { 17, 18, 19, 20, 25 }};

            
    int row_start = 0, row_end = 4, col_start = 0, col_end = 4;
    while (row_start <= row_end && col_start <= col_end)
    {
        for (int i = col_start; i <= col_end ; i++)
        {
            cout << std::setw(5) << M[row_start][i];
        }
        row_start++;
        for (int i = row_start; i <= row_end ; i++)
        {
            cout << std::setw(5) << M[i][col_end];
        }
        col_end--;
        for (int i = col_end; i >= col_start ; i--)
        {
            cout << std::setw(5) << M[row_end][i];
        }
        row_end--;
        for (int i = row_end; i >= row_start; i--)
        {
            cout << std::setw(5) << M[i][col_start];
        }
        col_start++;
    }
}