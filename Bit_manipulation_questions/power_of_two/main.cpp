#include<bits/stdc++.h>

bool isPowerof2(int n)
{
    return (n && !(n & n-1));
}
int main()
{
    std::cout << isPowerof2(8);
}