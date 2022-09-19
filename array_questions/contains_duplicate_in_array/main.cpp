/*
Given an integer array nums, return true if
 any value appears at least twice in the array,
 and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:

1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
*/

#include <bits/stdc++.h>

int main()
{
    int arr[] = {1,2,3,1,4, 2, 4, 5, 2, 3, 1};
    int size_of_array = sizeof(arr)/sizeof(arr[0]);
    // brut force approach
    for (int i = 0; i <= size_of_array-2; i++)
    {
        for (int j = i+1; j <= size_of_array-1; j++)
        {
            if (arr[i]==arr[j])
            {
                std::cout << "true\n";
                return 0;
            }
        }
    }
    // complexity O(n*n)
    printRepeating(arr, size_of_array);  //complexity O(n) space and time 
}

void printRepeating(int arr[], int size) 
{ 
    int *count = new int[sizeof(int)*(size - 2)]; 
    int i; 
          
    std::cout << " Repeating elements are "; 
    for(i = 0; i < size; i++) 
    { 
        if(count[arr[i]] == 1) 
            std::cout << arr[i] << " "; 
        else
            count[arr[i]]++; 
    } 
} 
    //https://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/