/*

Given an array (or string), the task is to reverse the array/string.
Examples : 
 

Input  : arr[] = {1, 2, 3}
Output : arr[] = {3, 2, 1}

Input :  arr[] = {4, 5, 1, 2}
Output : arr[] = {2, 1, 5, 4}

*/


#include <bits/stdc++.h>

void reverse_array(int arr[], int n)
{
    int start = 0, end = n-1, temp = 0;
    while (start < end)
    {
        // swap operations
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        // iterator update
        start++;
        end--;
    }
    
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " " ;
    }
    std::cout << "\n";
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int size = 6;
    print_array(arr, size);
    reverse_array(arr , size);
    print_array(arr, size);
}

// complexity of this program is O(n)