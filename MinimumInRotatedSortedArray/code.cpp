#include<bits/stdc++.h>

using namespace std;

//Find the minimum in rotated Sorted Array 

//Brute Force Approach 

int findingMinimumSorted(vector<int> &arr){
    int n = arr.size();

    int mini = INT_MAX;
    for(int i{0};i<n;i++){
        if(arr[i] < mini){
            mini = arr[i];
        }
    }
    return mini;
}

//Best and optimal approaches with BS

int findingMinimuminSorted(vector<int> &arr){
    int n = arr.size();

    int low = 0;
    int high = n-1;
    int ans = INT_MAX;

    while(low <= high){
        int mid = low+((high-low)/2);
        //finding the sorted part of the array 
        if(arr[low] <= arr[mid]){
            ans = min(ans,arr[low]);
            low = mid+1;
        } else {
            ans = min(ans,arr[mid]);
            high = mid-1;
        }
    }
    return ans;
}

//minor optimization if we find the sorted part of the array
int findingMinimuminSortedOpti(vector<int> &arr){
    int n = arr.size();

    int low = 0;
    int high = n-1;
    int ans = INT_MAX;

    while(low <= high){
        int mid = low+((high-low)/2);
        //finding the sorted part of the array 
        if(arr[low] <= arr[high]){
            ans = min(ans,arr[low]);
            break;
        }
        if(arr[low] <= arr[mid]){
            ans = min(ans,arr[low]);
            low = mid+1;
        } else {
            ans = min(ans,arr[mid]);
            high = mid-1;
        }
    }
    return ans;
}


int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {2,3,4,5,1};
    cout << findingMinimumSorted(ans);
    cout << endl;
    cout << findingMinimuminSorted(ans);
    cout << endl;
    cout << findingMinimuminSortedOpti(ans);


    return 0;
}