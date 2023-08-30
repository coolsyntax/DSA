// We are given an array and a target number,
// we have to find any one combination of array elements that 
// sum up to target number, if no such combination exists
// return null
// array consists of all positive int
// numbers in the array can be reused
// output will be a array of numbers which sum up to target value

#include<bits/stdc++.h>
using namespace std;

vector<int> how_sum(int target, vector<int> arr){
    if(target <= 0){
        return vector<int>();
    }

    for(auto num : arr){
        if(num <= target){
            vector<int> result = how_sum(target - num, arr);
            if(!result.empty() || target - num == 0){
                result.push_back(num);
                return result;
            }
        }
    }
    return vector<int>();
}
// time complexity is O(n^m)

vector<int> how_sum_memo(int target, vector<int> arr){

    static map<int, vector<int>> memo;
    
    if(memo.count(target) > 0){
        return memo[target];
    }
    if(target <= 0){
        return vector<int>();
    }

    for(auto num : arr){
        if(num <= target){
            vector<int> result = how_sum_memo(target - num, arr);
            if(!result.empty() || target - num == 0){
                result.push_back(num);
                memo.insert({target, result});
                return memo[target];
            }
        }
    }
    return vector<int>();
}
// time comlexity is O(n*m^2)


int main(){
    std::vector<int> nums = {2, 3};
    int target = 7;
    std::vector<int> result = how_sum_memo(target, nums);
    if(!result.empty()){
        for(auto c : result){
            cout << c << "  ";
        }
    }
    else{
        cout << "no string found";
    }

    return 0;
}