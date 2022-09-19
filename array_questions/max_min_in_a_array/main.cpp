/*
Write a C function to return minimum and maximum in an array. Your program should make the minimum number of comparisons. 
*/


#include <bits/stdc++.h>

// creating a class since 2 elements cannot be returned from a function 
// at the same time
class max_min_elements
{
public:
    int max;
    int min;
};

// this function finds the minimum and maximum elements
max_min_elements get_max_min(int arr[], int n)
{
    max_min_elements max_min ;  // creating an object of max_min class
    max_min.min = INT8_MAX;     // accessing members of class max_min_elements
    max_min.max = INT8_MIN;     // accessing members of class max_min_elements

    // loop to find out max and min elements in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max_min.max)
        {
            max_min.max = arr[i];
        }
        if (arr[i] < max_min.min)
        {
            max_min.min = arr[i];
        }
    }
    return max_min;
}

int main()
{
    // instead of array vector can be used
    int A[] = {1,5,3,7,9,2,6};
    int A_size = sizeof(A)/sizeof(A[0]);
    // elements is an object of class calling the function
    max_min_elements elements = get_max_min(A, A_size);
    std::cout << elements.max << " " << elements.min;
}

// time complexity of this program is O(n)