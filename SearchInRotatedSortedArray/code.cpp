#include<bits/stdc++.h>

using namespace std;

//search in a rotated sorted array 

int searchINRotatedArray(vector<int> &arr,int target){
    int n = arr.size();

    int low =0;
    int high = n-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return mid;

        //check which half is sorted and then move forward
        if(arr[low] <= arr[mid]){
            //left half is sorted
            if(arr[low] <= target && target <= arr[mid]){
                high = mid-1;
            } else low = mid+1;
        } else {
            //right half will be sorted
            if(arr[mid] <= target && target <= arr[high]){
                low = mid+1;
            } else high = mid-1;
        }
    }
    return -1;
}

bool search(vector<int>& arr, int target) {
    int n = arr.size();
    // for(int i{0};i<n;i++){
    //     if(arr[i] == target){
    //         return true;
    //     }
    // }
    // return false;

    int low =0;
    int high = n-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == target) return true;
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }
        //check which half is sorted and then move forward
        if(arr[low] <= arr[mid]){
            //left half is sorted
            if(arr[low] <= target && target < arr[mid]){
                high = mid-1;
            } else low = mid+1;
        } else {
            //right half will be sorted
            if(arr[mid] < target && target <= arr[high]){
                low = mid+1;
            } else high = mid-1;
        }
    }
    return false;
}


int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {7,8,9,1,2,3,4,5,6};
    cout << searchINRotatedArray(ans,5);


    return 0;
}