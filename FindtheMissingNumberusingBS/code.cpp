#include<bits/stdc++.h>

using namespace std;

//find the least capacity to ship packages within D days

int findMissingNumber(vector<int> &arr,int k){
    int n = arr.size();

    for(int i{0};i<n;i++){
        if(arr[i] <= k) k++;
        else break;
    }
    return k;
}

int findMissingNumberBS(vector<int> &arr,int k){
    int n = arr.size();

    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = low+((high - low)/2);

        int missing = arr[mid] - (mid+1);
        if(missing < k) low = mid+1;
        else high = mid-1;
    }
    return (high+1+k);
}
int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {2,3,4,7,11};
    cout << findMissingNumber(ans,5) << endl;
    cout << findMissingNumberBS(ans,5) << endl;
    

    return 0;
}