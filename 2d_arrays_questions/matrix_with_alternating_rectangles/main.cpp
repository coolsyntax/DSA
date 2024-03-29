/*
Write a code which inputs two numbers m and n and creates a matrix of size m x n (m rows and n columns) in which every elements is either X or 0. The Xs and 0s must be filled alternatively, the matrix should have outermost rectangle of Xs, then a rectangle of 0s, then a rectangle of Xs, and so on.

Examples:  

Input: m = 3, n = 3
Output: Following matrix 
X X X
X 0 X
X X X

Input: m = 4, n = 5
Output: Following matrix
X X X X X
X 0 0 0 X
X 0 0 0 X
X X X X X

Input:  m = 5, n = 5
Output: Following matrix
X X X X X
X 0 0 0 X
X 0 X 0 X
X 0 0 0 X
X X X X X

Input:  m = 6, n = 7
Output: Following matrix
X X X X X X X
X 0 0 0 0 0 X
X 0 X X X 0 X
X 0 X X X 0 X
X 0 0 0 0 0 X
X X X X X X X 
*/

// The code of this code is similar to spiral print 
// Except an additional flip condition must be added
// x = (x == '0')? 'X': '0';

#include <bits/stdc++.h>
using namespace std;

// Function to print alternating rectangles of 0 and X
void fill0X(int m, int n)
{
	/* k - starting row index
		m - ending row index
		l - starting column index
		n - ending column index
		i - iterator */
	int i, k = 0, l = 0;

	// Store given number of rows and columns for later use
	int r = m, c = n;

	// A 2D array to store the output to be printed
	char a[m][n];
	char x = 'X'; // Initialize the character to be stored in a[][]

	// Fill characters in a[][] in spiral form. Every iteration fills
	// one rectangle of either Xs or Os
	while (k < m && l < n)
	{
		/* Fill the first row from the remaining rows */
		for (i = l; i < n; ++i)
			a[k][i] = x;
		k++;

		/* Fill the last column from the remaining columns */
		for (i = k; i < m; ++i)
			a[i][n-1] = x;
		n--;

		/* Fill the last row from the remaining rows */
		if (k < m)
		{
			for (i = n-1; i >= l; --i)
				a[m-1][i] = x;
			m--;
		}

		/* Print the first column from the remaining columns */
		if (l < n)
		{
			for (i = m-1; i >= k; --i)
				a[i][l] = x;
			l++;
		}

		// Flip character for next iteration
		x = (x == '0')? 'X': '0';
	}

	// Print the filled matrix
	for (i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout <<" "<< a[i][j];
		cout <<"\n";
	}
}

/* Driver program to test above functions */
int main()
{
	puts("Output for m = 5, n = 6");
	fill0X(5, 6);

	puts("\nOutput for m = 4, n = 4");
	fill0X(4, 4);

	puts("\nOutput for m = 3, n = 4");
	fill0X(3, 4);

	return 0;
}