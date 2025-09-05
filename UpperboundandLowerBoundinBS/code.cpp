#include<bits/stdc++.h>

using namespace std;

//implementing lowerbound in c++


int lowerbound(vector<int> &arr,int target){
    int n = arr.size();

    int low =0;
    int high = n-1;
    int ans = n;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

//upper bound 

int upperbound(vector<int> &arr,int target){
    int n= arr.size();

    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }else low = mid +1;
    }
    return ans;
}


//search insert postion in array 

int insertPosition(vector<int> &ans,int target){
    int n = ans.size();

    int i = 0;
    
    while(i <= n){
        if(target > ans[i]){
            i++;
        }
        else return i;
    }
    return -1;
}

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();

    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        } 
        else low = mid+1;
    }
    return ans;
}


int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {3,5,8,9,12,15,18,19,20,23,56,65,78};
    cout << lowerbound(ans,45);
    cout << endl;
    cout << ans[lowerbound(ans,45)];
    cout << endl;
    cout << upperbound(ans,3);

    cout << endl;
    vector<int> arr = {1,2,3,4,5,6};
    int target = 3;
    cout << insertPosition(arr,target);

    // int lb = lower_bound(ans.begin(),ans.end(),1)-(ans.begin());
    // cout << lb << endl;



    return 0;
}