#include<bits/stdc++.h>

using namespace std;
///brute force

vector<int> twoSum(vector<int> &arr,int target){
    int n = arr.size();
    for(int i{0};i<n;i++){
        int num = arr[i];
        for(int j{0};j<n;j++){
            if(i==j){
                continue;
            }
            if(num + arr[j] == target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

//better solution 

vector<int> twoSumB(vector<int> &arr,int target){
    map<int,int> mpp;
    //o(nlogn)
    int n = arr.size();
    for(int i{0};i<n;i++){ //o(n)
        int a = target - arr[i];
        if(mpp.find(a) != mpp.end()){ //o(logn)
            int b = mpp[a];
            return {b,i};
        }
        mpp[arr[i]] = i;
    }
    return {-1,-1};
}

//optimal solution 
vector<int> twoSumOP(vector<int> &arr,int target){
    int n= arr.size();
    int start = 0;
    int end = n-1;
    sort(arr.begin(),arr.end());
    while(start < end){
        if(arr[start] + arr[end] == target){
            return {start,end};
        } else if(arr[start] + arr[end] < target){
            start ++;
        } else end --;
    }
    return {-1,-1};
}


int main(){

    vector<int> arr = {2,6,5,8,11};
    for(auto it: twoSumOP(arr,14)){
        cout << it << " ";
    }

    return 0;
}