#include<bits/stdc++.h>

/*  
    Get i bit
    Mask: Right shift n ‘i’ times, and check the first bit.
*/
int getBit(int n, int pos)
{
    return (n >> pos) & 1;
}

/*  
    Set i bit
    Mask: 1 << i
    Bitwise OR operation between n and mask sets the i bit to one.
*/
int setBit(int n, int pos)
{
    return (n | (1 >> pos));
}

/*
    Clear i bit
    Mask: ~ (1 << i )
    In the mask, all the bits would be one, except the i bit. 
    Taking bitwise AND with nwould clear the i bit.
*/
int clearBit(int n, int pos)
{
    int mask = ~(1 << pos);
    return (n & mask);
}

/*
    Toggle i bit
    Mask: 1 << i
    Bitwise XOR operation between n and mask toggle the i bit.
*/
int toogleBit(int n, int pos)
{
    return (n xor (1 << pos));
}

/*
    Update i’th bit to the given value
    Mask: mask has all the bits set to one except i'th bit.
    n = n & mask, i'th bit is cleared.
    Now, to set i'th bit to value, we take value << pos as the mask.
*/
int updateBit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = n & mask;
    return (n | (value << pos));
}

// coompute xor from 1 to n
int compute_xor(int n)
{
    if(n % 4 == 0)
    {
        return n;
    }
    
    if (n % 4 == 1)
    {
        return 1;
    }
    
    if (n % 4 == 2)
    {
        return n+1;
    }
    
    else
    {
        return 0;
    }
}



int main()
{

}