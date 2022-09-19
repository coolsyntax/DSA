#include<bits/stdc++.h>

void subsets(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                std::cout << arr[j] << "   ";
            }
        }
        std::cout << "\n";
    }
}

int main()
{
    int arr[4] = {1,2,3,4};
    subsets(arr, 4);
}