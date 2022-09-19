#include<bits/stdc++.h>
using namespace std;


int setBit(int n, int pos)
{
    return (n | (1<<pos));
}
int getBit(int n, int pos)
{
    return (n &(1 >> pos)!=0);
}
int unique(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum^arr[i];
    }
    return xorsum;
}

void two_unique_numbers(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum^arr[i];
    }
    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0;
    while (setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;    
    }

    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (getBit(arr[i], pos-1))
        {
            newxor = newxor^arr[i];
        }
    }
    cout << newxor << " \n";
    cout << (tempxor^newxor) << " \n";
}

// unique number in an array where all numbers are triplets except unique number

int triplet_unique(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getBit(arr[j], i))
            {
                sum++;
            }
        }
        if (sum%3 != 0)
        {
            result = setBit(result, i);
        }
    }
    return result;
}
int main()
{
    int arr[8] = {1,1,5,3,3,7,6,6};
    //cout << unique(arr, 5) << " ";
    //two_unique_numbers(arr, 8);
}