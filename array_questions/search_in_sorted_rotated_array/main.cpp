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
int binarySearch(int A[], int l, int h, int key)
{
    if (h < l)
        return -1;
 
    int mid = (l + h) / 2;
    if (key == A[mid])
        return mid;
 
    if (key > A[mid])
        return binarySearch(A, (mid + 1), h, key);
 
    return binarySearch(A, l, (mid - 1), key);
}
 
// Function to get pivot. For array 3, 4, 5, 6, 1, 2
// it returns 3 (index of 6)
int findPivot(int A[], int l, int h)
{
    // Base cases
    if (h < l)
        return -1;
    if (h == l)
        return l;
 
    // l + (h - l)/2;
    int mid = (l + h) / 2;
    if (mid < h && A[mid] > A[mid + 1])
        return mid;
 
    if (mid > l && A[mid] < A[mid - 1])
        return (mid - 1);
 
    if (A[l] >= A[mid])
        return findPivot(A, l, mid - 1);
 
    return findPivot(A, mid + 1, h);
}
 
// Searches an element key in a pivoted
// sorted array A[] of size n
int pivotedBinarySearch(int A[], int n, int key)
{
    int pivot = findPivot(A, 0, n - 1);
 
    // If we didn't find a pivot,
    // then array is not rotated at all
    if (pivot == -1)
        return binarySearch(A, 0, n - 1, key);
 
    // If we found a pivot, then first compare with pivot
    // and then search in two subarrays around pivot
    if (A[pivot] == key)
        return pivot;
 
    if (A[0] <= key)
        return binarySearch(A, 0, pivot - 1, key);
 
    return binarySearch(A, pivot + 1, n - 1, key);
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

/*
int binary_search(vector<int> nums, int low, int high, int target){
    if(low > high){
        return -1;
    }
    
    int mid = (high + low) / 2;

    if(target == nums[mid]){
        return mid;
    }

    if(nums[low] <= nums[mid]){

        if(target >= nums[low] && target <= nums[mid]){
            return binary_search(nums, low, mid-1, target);   
        }

        return binary_search(nums, mid+1, high, target);
    }

    if(target >= nums[mid] && target <= nums[high]){
        return binary_search(nums, mid+1, high, target);
    }

    return binary_search(nums, low, mid-1, target);
}
*/