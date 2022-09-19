/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
then the next permutation of that array is the permutation that follows it in the sorted container. 
If such arrangement is not possible, the array must be rearranged as the lowest possible order 
(i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

#include <iostream>
 
using namespace std;
 
void swap(char* a, char* b)
{
    if (*a == *b)
        return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
void rev(string& s, int l, int r)
{
    while (l < r)
        swap(&s[l++], &s[r--]);
}
 
int bsearch(string& s, int l, int r, int key)
{
    int index = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (s[mid] <= key)
            r = mid - 1;
        else {
            l = mid + 1;
            if (index == -1 || s[index] >= s[mid])
                index = mid;
        }
    }
    return index;
}

bool nextpermutation(string& s)
{
    int len = s.length(), i = len - 2 ;
    while (i >= 0 && s[i] >= s[i + 1])
    {
        i--;
    }
    if (i < 0)
    {
        return false;
    }
    else
    {
        int index = bsearch(s, i+1, len-1, s[i]);
        swap(&s[i], &s[index]);
        rev(s, i+1, len-1);
        return true;
    }
    
}

// Driver code
int main()
{
    string s = { "abhishek" };
    bool val = nextpermutation(s);
    if (val == false)
        cout << "No Word Possible" << endl;
    else
        cout << s << endl;
    return 0;
}