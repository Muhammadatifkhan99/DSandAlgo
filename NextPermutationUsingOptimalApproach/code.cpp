#include<bits/stdc++.h>

using namespace std;

//Generate all the permutation of an array 

// vector<vector<int>> 



//Next Permutations


vector<int> nextPermutation(vector<int> &nums){
    //find the break point of array 

    int n = nums.size();
    int index=-1;
    for(int i{n-2};i>0;i--){
        if(nums[i] < nums[i+1]){
            index = i;
            break;
        }
    }
    //if index == -1; reverse array
    if(index == -1){
        reverse(nums.begin(),nums.end());
        return nums;
    }
    for(int i{n-1};i>0;i--){
        if(nums[i] > nums[index]){
            swap(nums[i],nums[index]);
        }
    }
    reverse(nums.begin() + index + 1,nums.end());
    return nums;
}





int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> arr = {1,3,2};
    vector<int> ans = nextPermutation(arr);
    for(auto it: ans){
        cout << it << " ";
    }



    return 0;
}