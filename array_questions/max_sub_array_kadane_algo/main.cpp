/*
Maximum Subarray

Given an integer array nums, find the contiguous subarray
 (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:

Input: nums = [1]
Output: 1

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
 

Follow up: If you have figured out the O(n) solution, 
try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <bits/stdc++.h>

int main()
{
    int current_sum = 0, max_till_now = 0;
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int size_of_array = sizeof(arr)/sizeof(arr[0]);
    // kadane algorithm
    for (int i = 0; i < size_of_array-1; i++)
    {
        current_sum += arr[i];
        max_till_now = std::max(current_sum, max_till_now);
        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }
    std::cout << max_till_now;
}
// time complexity of this algo is O(n)