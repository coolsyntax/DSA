/*
Given a 2D matrix, print all elements of the given matrix in diagonal order. 
For example, consider the following 5 X 4 input matrix.  

Example:

1     2     3     4
5     6     7     8
9    10    11    12
13    14    15    16
17    18    19    20


Diagonal printing of the above matrix is

1
5 2
9 6 3
13 10 7 4
17 14 11 8
18 15 12
19 16
20
*/

#include<bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 4

/*
void diagonalOrder(int M[ROW][COL])
{
    
    int i = 0;
    while (i < ROW)
    {
        int j = i;
        int k = 0;
        while (j >= 0 && k < COL)
        {
            std::cout << std::setw(5) << M[j][k] ;
            j--;
            k++;
        }
        std::cout << "\n";
        i++;
    }
    i = 1;
    while (i < COL)
    {
        int j = i;
        int k = ROW-1;
        while (j < COL )
        {
            std::cout << std::setw(5) << M[k][j] ;
            j++;
            k--;
        }
        std::cout << "\n";
        i++;
    }
}
*/

// A utility function to find min
// of two integers
int minu(int a, int b)
{
    return (a < b) ? a : b;
}
 
// A utility function to find min
// of three integers
int min(int a, int b, int c)
{
    return minu(minu(a, b), c);
}
 
// A utility function to find
// max of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
// The main function that prints given
// matrix in diagonal order
void diagonalOrder(int matrix[][COL])
{
     
    // There will be ROW+COL-1 lines
    // in the output
    for(int line = 1;
            line <= (ROW + COL - 1);
            line++)
    {
         
        /* Get column index of the first element
           in this line of output.
           The index is 0 for first ROW lines and
           line - ROW for remaining lines  */
        int start_col =  max(0, line - ROW);
 
        /* Get count of elements in this line. The
           count of elements is equal to minimum of
           line number, COL-start_col and ROW */
         int count = min(line, (COL - start_col), ROW);
 
        /* Print elements of this line */
        for(int j = 0; j < count; j++)
            cout << setw(5) <<
            matrix[minu(ROW, line) - j - 1][start_col + j];
 
        /* Print elements of next
           diagonal on next line */
        cout << "\n";
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
                        { 9, 10, 11, 12 },
                        { 13, 14, 15, 16 },
                        { 17, 18, 19, 20 },};
    std::cout << "Given matrix is \n";
    printMatrix(M);
 
    std::cout << "\nDiagonal printing of matrix is \n";
    diagonalOrder(M);
    return 0;
}