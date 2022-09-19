#include<bits/stdc++.h>

int firstocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    
    if (arr[i] == key)
    {
        return i;
    }
    return firstocc(arr, n, i+1, key);
}

int lastocc(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int restarray = lastocc(arr, n, i+1, key);
    if (restarray != -1)
    {
        return restarray;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}
int main()
{
    int arr[] = {4,2,1,2,5,2,7};
    std::cout << firstocc(arr, 7, 0, 2) << "\n";
    std::cout << lastocc(arr, 7, 0, 2) << "\n";
}