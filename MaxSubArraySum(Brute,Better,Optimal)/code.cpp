#include<bits/stdc++.h>

using namespace std;


//maximum sub array sum

int maxSubArraySumBF(vector<int> &arr){
    int n = arr.size();

    int maxSum = INT_MIN;

    for(int i{0};i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += arr[k];
                maxSum = max(sum,maxSum);
            }
        }
    }
    return maxSum;
}

int maxSubArraySumBetter(vector<int> &arr){
    int n = arr.size();

    int maxSum = INT_MIN;

    for(int i{0};i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            maxSum = max(sum,maxSum);
        }
    }
    return maxSum;
}

int maxSubArraySumOP(vector<int> &arr){
    int n = arr.size();
    int maxSum=0;
    int sum = 0;
    for(int i{0};i<n;i++){
        sum += arr[i];
        maxSum = max(sum,maxSum);
        if(sum < 0){
            sum = 0;
        }
    }
    return maxSum;
}



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> arr = {-2,-1,3,1};
    cout << maxSubArraySumBF(arr) << endl;
    cout << maxSubArraySumBetter(arr) << endl;
    cout << maxSubArraySumOP(arr) << endl;

    return 0;
}