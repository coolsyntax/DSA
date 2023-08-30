// find number of ways to reach the last square on grid i.e. bottom right from starting point
// i.e. top left with only 2 leagal moves i.e. you can either move down or right.

#include<bits/stdc++.h>
using namespace std;

int grid_traveler(int m, int n){
    if(m == 0 || n == 0){
        return 0;
    }

    if(m == 1 && n == 1){
        return 1;
    }

    return grid_traveler(m-1, n) + grid_traveler(m, n-1);
}
// this code takes O(2^m+n) time 

int grid_traveler_memo(int m, int n){

    static map<pair<int, int>, int> memo;   // we use pair because map take only on key hnce used it as pair type

    // looks if combination is present in map or not
    if(memo.count({m, n}) > 0){
        return memo[{m, n}];
    }

    if(m == 0 || n == 0){
        return 0;
    }

    if(m == 1 && n == 1){
        return 1;
    }

    int temp = grid_traveler_memo(m-1, n) + grid_traveler_memo(m, n-1);

    // since m,n and n,m will return the same value as seen from the tree
    // hence we directly store the value in the first iteration on the combination
    memo.insert({{m, n}, temp});
    memo.insert({{n, m}, temp});

    return memo[{m, n}];
}
// this code takes O(n*m) time


int main(){

    //cout << grid_traveler(3, 3) << "\n";
    cout << grid_traveler_memo(3, 3) << "\n";
    return 0;
}