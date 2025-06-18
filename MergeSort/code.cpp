#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
#include<map>

using namespace std;

void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> ans;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if(arr[left] <= arr[right]){
            ans.push_back(arr[left]);
            left++;
        }
        else {
            ans.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        ans.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        ans.push_back(arr[right]);
        right++;
    }

    //copies values to the older array

    for(int i = low;i<=high;i++){
        arr[i] = ans[i-low];
    }
}

void mergeSort(vector<int> &arr,int low,int high){
    if(low >= high){
        return;
    }
    int mid = (low + high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}


int main(){
    vector<int> arr = {3,26,4,45,9};
    mergeSort(arr,0,4);

    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;

    // for(auto it: binaryTreePaths(r1)){
    //     cout << it << endl;
    // }


    return 0;
}