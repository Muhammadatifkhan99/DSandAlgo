#include<bits/stdc++.h>

using namespace std;

//reverse pairs i < j and a[i] > 2 * a[j]

int reversePairs(vector<int> &arr){
    int n = arr.size();
    int count = 0;

    for(int i{0};i<n;i++){
        for(int j{i+1};j<n;j++){
            if(arr[i] > 2 * arr[j]){
                count++;
            }
        }
    }
    return count;
}


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
        // cout << "Value of start: " << low << endl;
        arr[i] = ans[i-low];
    }
}
int countPairs(vector<int> &arr,int low,int mid,int high){
    int right = mid+1;
    int count = 0;
    for(int i=low;i<=mid;i++){
        while(right <= high && arr[i] > 2 * arr[right]) right++;
        count+= (right - (mid+1));
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
    count += countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return count;
}

int team(vector<int> &skills){
    //write your code here
    int n = skills.size();
    return mergeSort(skills,0,n-1);
}


int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {40,25,19,12,9,6,2};
    cout << team(ans);




    return 0;
}