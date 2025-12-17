#include<bits/stdc++.h>

using namespace std;

//count inversion problem


int countInversion(vector<int> &arr){
    int n = arr.size();
    int count = 0;

    for(int i{0};i<n-1;i++){
        for(int j{i+1};j<n;j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    return count;
}


//count inversion using optimal solution


int merge(vector<int> &arr,int low,int mid,int high){
    vector<int> ans;
    int left = low;
    int right = mid + 1;

    int count = 0;

    while (left <= mid && right <= high)
    {
        if(arr[left] <= arr[right]){
            ans.push_back(arr[left]);
            left++;
        }
        else {
            ans.push_back(arr[right]);
            count += (mid - left + 1);
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
        // cout << "Value of start: " << low << endl;
        arr[i] = ans[i-low];
    }
    return count;
}

int mergeSort(vector<int> &arr,int low,int high){
    int count = 0;
    if(low >= high){
        return count;
    }
    int mid = (low + high)/2;
    count += mergeSort(arr,low,mid);
    count += mergeSort(arr,mid+1,high);
    count += merge(arr,low,mid,high);

    return count;
}

int numberofInversion(vector<int> &a){
    int n = a.size();
    return mergeSort(a,0,n-1);
}

int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {5,3,2,4,1};
    cout << numberofInversion(ans) << endl;









    return 0;
}