// to find GCD (greatest common divisor) or HCF

#include<bits/stdc++.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
}

int main()
{
    std::cout << gcd(42 , 24) << "  ";
}