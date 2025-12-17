#include<bits/stdc++.h>

using namespace std;

//maximum subarray product

int maxSubarrayProd(vector<int> &arr){
    int n= arr.size();
    int maxi = INT_MIN;

    for(int i{0};i<n;i++){
        for(int j{i};j<n;j++){
            int prod = 1;
            for(int k{i};k<=j;k++){
                prod *= arr[k];
            }
            maxi = max(prod,maxi);
        }
    }
    return maxi;
}

int maxSubArrayProdOP(vector<int> &arr){
    int n = arr.size();

    int prefix = 1;
    int suffix = 1;
    int maxi = INT_MIN;

    for(int i{0};i<n-1;i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n-i-1];
        maxi = max(maxi,max(prefix,suffix));
    }
    return maxi;
}

int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {2,3,-2,4};
    cout << maxSubArrayProdOP(ans);




    return 0;
}