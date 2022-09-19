// When a function calls itself to make the problem smaller 
// to solve it is called recursion

#include<bits/stdc++.h>

int sum_till_n(int n)
{
    if (n == 0)
    {
        return 0;
    }
    
    return n + sum_till_n(n-1);
}

int main()
{
    std::cout << sum_till_n(4) << "\n";
}