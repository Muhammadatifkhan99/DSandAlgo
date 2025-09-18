#include<bits/stdc++.h>

using namespace std;

//minimum number of days to make m bouquets

bool isPossible(vector<int> &arr,int day,int m,int k){
    int n = arr.size();

    int count = 0;
    int noofB = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<= day){
            count++;
        }else {
            noofB += (count/k);
            count = 0;
        }
    }
    noofB += (count/k);
    if(noofB >= m) return true;
    else return false;
}

//minimum of the array 

int miniofArray(vector<int> arr){
    int n = arr.size();

    int smaller = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i] < smaller){
            smaller = arr[i];
        }
    }
    // cout << "MINI OF ARRAY IS: "<<smaller<< endl;
    return smaller;
}

//maxi of array 

int maxiofArray(vector<int> arr){
    int n = arr.size();

    int largest = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    // cout << "MAX of Array" << largest << endl;
    return largest;
}

int bouquet(vector<int> arr, int m,int k){
    int n = arr.size();
    if(n<m*k) return -1;
    int mini = miniofArray(arr);
    int maxi = maxiofArray(arr);
    for(int i=mini;i<=maxi;i++){
        if(isPossible(arr,i,m,k)== true){
            return i;
        }
    }
    return -1;
}


//optimal solution using Binary Search 


int bouquetBinarySearch(vector<int> &arr,int m,int k){
    int n = arr.size();
    int val = m * 1LL * k * 1LL;
    if(n < val) return -1;

    int mini = miniofArray(arr);
    int maxi = maxiofArray(arr);

    int low = mini;
    int high = maxi;

    while(low <= high){
        int mid = low+((high-low)/2);
        if(isPossible(arr,mid,m,k)){
            high = mid-1;
        }else low = mid+1;
    }
    return low;
}



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {7,7,7,7,13,11,12,7};
    cout << bouquetBinarySearch(ans,2,3);


    return 0;
}