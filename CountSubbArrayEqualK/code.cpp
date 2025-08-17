#include<bits/stdc++.h>

using namespace std;

//Number of subarray that equals sum k;


int countSubArraySumEqualK(vector<int> &arr,int k){
    int n = arr.size();
    int count = 0;

    for(int start = 0;start<n;start++){
        for(int end=start;end<n;end++){
            int sum = 0;
            for(int i=start;i<=end;i++){
                sum += arr[i];
            }
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

int countSubArraySumEqualKB(vector<int> &arr,int k){
    int n = arr.size();
    int count = 0;

    for(int start = 0;start<n;start++){
        int sum = 0;
        for(int end=start;end<n;end++){
            sum += arr[end];
            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

int countSubArraySumEqualKOP(vector<int> &arr,int k){
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int count = 0;
    for(int i{0};i<arr.size();i++){
        preSum += arr[i];
        int remove = preSum - k;
        count += mpp[remove];
        // if(mpp.find(remove) != mpp.end()){
        //     count++;
        // }
        mpp[preSum] += 1;
    }
    return count;
}


int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    cout << countSubArraySumEqualKOP(arr,3);






    return 0;
}