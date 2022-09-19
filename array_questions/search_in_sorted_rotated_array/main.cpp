/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-10^4 <= target <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;
 
// Standard Binary Search function
int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
 
    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;
 
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
 
    return binarySearch(arr, low, (mid - 1), key);
}
 
// Function to get pivot. For array 3, 4, 5, 6, 1, 2
// it returns 3 (index of 6)
int findPivot(int arr[], int low, int high)
{
    // Base cases
    if (high < low)
        return -1;
    if (high == low)
        return low;
 
    // low + (high - low)/2;
    int mid = (low + high) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
 
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
 
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
 
    return findPivot(arr, mid + 1, high);
}
 
// Searches an element key in a pivoted
// sorted array arr[] of size n
int pivotedBinarySearch(int arr[], int n, int key)
{
    int pivot = findPivot(arr, 0, n - 1);
 
    // If we didn't find a pivot,
    // then array is not rotated at all
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);
 
    // If we found a pivot, then first compare with pivot
    // and then search in two subarrays around pivot
    if (arr[pivot] == key)
        return pivot;
 
    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);
 
    return binarySearch(arr, pivot + 1, n - 1, key);
}
 
// Driver program to check above functions
int main()
{
    // Let us search 3 in below array
    int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int key = 3;
 
    // Function calling
    cout << "Index of the element is : "
         << pivotedBinarySearch(arr1, n, key);
 
    return 0;
}