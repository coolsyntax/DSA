/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are 
horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

// For searching in all 8 direction
int x[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int y[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
 
// This function searches in
// all 8-direction from point
// (row, col) in grid[][]
bool search2D(char *grid, int row, int col, string word, int R, int C)
{
    // If first character of word doesn't
    // match with given starting point in grid.
    if (*(grid+row*C+col) != word[0])
        return false;
 
    int len = word.length();
 
    // Search word in all 8 directions
    // starting from (row, col)
    for (int dir = 0; dir < 8; dir++) {
        // Initialize starting point
        // for current direction
        int k, rd = row + x[dir], cd = col + y[dir];
 
        // First character is already checked,
        // match remaining characters
        for (k = 1; k < len; k++) {
            // If out of bound break
            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;
 
            // If not matched,  break
            if (*(grid+rd*C+cd) != word[k])
                break;
 
            // Moving in particular direction
            rd += x[dir], cd += y[dir];
        }
 
        // If all character matched, then value of k must
        // be equal to length of word
        if (k == len)
            return true;
    }
    return false;
}

void patternSearch(char *grid, string word,int R,int C)
{
    for (int row = 0; row < R; row++)
        for (int col = 0; col < C; col++)
            if (search2D(grid, row, col, word, R, C))
                cout << "pattern found at "
                     << row << ", "
                     << col << endl;
}

int main()
{
    int R = 3, C = 4;
    char grid[3][4] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
 
    patternSearch((char *)grid, "ABCCED", R, C);
    cout << endl;
    
    return 0;
}