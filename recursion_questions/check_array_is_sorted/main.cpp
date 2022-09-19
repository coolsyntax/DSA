#include<bits/stdc++.h>

bool isSorted(int arr[], int n)
{
    if(n == 1)
        return true;
    bool restarray = isSorted(arr+1, n-1);
    return (arr[0] < arr[1] && restarray);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    std::cout << isSorted(arr, 5) << "\n";
}