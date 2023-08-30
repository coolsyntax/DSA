#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    return fib(n-1) + fib(n-2);
}
// fib take O(2^n) time to compute hence not a very efficient way.
// genrates a binary tree of n height.


int fib_memo(int n){

    static map<int, int> memory;   // this is a hash map which stores key value pairs
    // we use static so that memory does not change with every call
    // we use memory inside this function so that user does not have to pass any value

    
    if(memory.count(n) > 0){
        return memory[n];
    }

    if(n <= 1){
        return n;
    }

    int temp = fib_memo(n-1) + fib_memo(n-2);
    memory.insert({n, temp});
    return memory[n];
}
// fib_memo take O(n) time to compute
int main(){
    cout << fib (7) << "\n";
    cout << fib_memo(7) << "\n";
    return 0;
}