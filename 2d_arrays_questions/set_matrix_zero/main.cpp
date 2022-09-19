/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1
*/

#include<bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 4

void set_zero(int M[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (M[i][j] == 0)
            {
                M[i][0] = 0;
                M[0][j] = 0;
            }
        }
    }
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (M[0][j] == 0 || M[i][0] == 0)
            {
                M[i][j] = 0;
            } 
        }
    }
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
            std::cout << std::setw(5) << M[i][j];
             
        std::cout << "\n";
    }
}

void printMatrix(int matrix[ROW][COL])
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
            std::cout << std::setw(5) << matrix[i][j];
             
        std::cout << "\n";
    }
}

int main()
{
    
    int M[ROW][COL] = { { 1, 2, 3, 4 },
                        { 5, 6, 7, 8 },
                        { 9, 0, 11, 12 },
                        { 13, 14, 15, 16 },
                        { 17, 18, 19, 0 },};
    cout << "Given matrix is \n";
    printMatrix(M);
 
    cout << "matrix after setting zero \n";
    set_zero(M);
    return 0;
}