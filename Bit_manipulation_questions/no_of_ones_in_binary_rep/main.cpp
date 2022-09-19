#include<bits/stdc++.h>

int numberOfOnes(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n-1);
        count++;
    }
    return count;
}
int main()
{
    std:: cout << numberOfOnes(19) << "\n";
}