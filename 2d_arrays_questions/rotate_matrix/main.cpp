/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/

#include<bits/stdc++.h>
using namespace std;

void printMatrix(int matrix[5][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            std::cout << std::setw(5) << matrix[i][j];
             
        cout << "\n";
    }
}

void rotated_matrix(int M[5][5])
{
    int n = 5; // length of matrix
    for (int i = 0; i < (n+1)/2; i++)
    {
        for (int j = 0; j < n/2; j++)
        {
            int temp = M[n-1-i][i];
            M[n-1-j][i] = M[n-1-i][n-1-j];
            M[n-1-i][n-1-j] = M[j][n-1-i];
            M[j][n-1-i] = M[i][j];
            M[i][j] = temp;
        }
    }
    printMatrix(M);
}

int main()
{
    
    int M[5][5] = { { 1, 2, 3, 4, 21 },
                        { 5, 6, 7, 8, 22 },
                        { 9, 10, 11, 12, 23 },
                        { 13, 14, 15, 16, 24 },
                        { 17, 18, 19, 20, 25 }};
    cout << "Given matrix is \n";
    printMatrix(M);
 
    cout << "\nRotated printing of matrix is \n";
    rotated_matrix(M);
    return 0;
}