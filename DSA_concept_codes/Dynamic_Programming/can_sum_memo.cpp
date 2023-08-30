// We are given an array of int and a target, we have to find out weather 
// the target sum is possible or not.
// numbers in the array can be reused.
// array has all positive int

#include<bits/stdc++.h>
using namespace std;

bool can_sum(int number, vector<int> arr){
    if(number == 0){        
        // if after subtracting array value target number becomes 
        // zero then a target sum is possible.
        return true;
    }

    if(number < 0){
        // if number becomes negative there is no way target sum is possible
        return false;
    }

    for(int i = 0; i < arr.size(); i++){
        int remainder = number-arr[i];      //subtracting i^th value to see how target number changes
        if(can_sum(remainder, arr) == true){
            return true;
        }
    }

    return false;
}
// this code takes O(n^m) time

bool can_sum_memo(int number, vector<int> arr){

    static map<int, bool> memo;

    if(memo.count(number) > 0){
        return memo[number];
    }

    if(number == 0){        
        // if after subtracting array value target number becomes 
        // zero then a target sum is possible.
        return true;
    }

    if(number < 0){
        // if number becomes negative there is no way target sum is possible
        return false;
    }

    for(int i = 0; i < arr.size(); i++){
        int remainder = number-arr[i];      //subtracting i^th value to see how target number changes
        if(can_sum(remainder, arr) == true){
            memo.insert({number, true});
            return true;
        }
    }
    memo.insert({number, false});
    return false;
}
// this code takes O(m*n) time


int main(){
    
    vector<int> arr = {2, 4};
    //cout << can_sum(9, arr) << "\n";
    cout << can_sum_memo(9, arr) << "\n";

    return 0;
}