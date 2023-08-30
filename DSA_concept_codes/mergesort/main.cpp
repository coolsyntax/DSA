#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int i, j, k;
    i = j = k = 0;
    Array *arr3 = new Array(length + arr2.length);
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
        {
            arr3->A[k++] = A[i++];
        }
        else
        {
            arr3->A[k++] = arr2.A[j++];
        }
    }
    for (; i < length; i++)
    {
        arr3->A[k++] = A[i];
    }
    for (; j < arr2.length; j++)
    {
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = length + arr2.length;
    return arr3;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
    
}

int main()
{
}