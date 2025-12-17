#include<bits/stdc++.h>

using namespace std;

//find the smallest divisor

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
    // cout << "MAX of Array: " << largest << endl;
    return largest;
}

int smallestDivisor(vector<int> &arr,int threshold){
    int n = arr.size();

    int ans = INT_MAX;
    int maxi = maxiofArray(arr);

    int value = 0;
    for(int i{1};i<=maxi;i++){
        value = 0;
        for(int j = 0; j < n; j++){
            double a = (double)arr[j] / i;
            value += (int)ceil(a);
        }
        // cout << "value is: "<<value<<" at "<<i<< endl;
        if(value <= threshold){
            ans = min(i,ans);
        }
    }
    return ans;
}

int sumOff(vector<int> &arr,int mid){
    int n = arr.size();

    int sum = 0;

    for(int i{0};i<n;i++){
        double a = (double)arr[i] / mid;
        sum += (int)ceil(a);
    }
    return sum;
}

int smallestDivisorBS(vector<int> &arr,int threshold){
    int n =arr.size();

    int low = miniofArray(arr);
    int high = maxiofArray(arr);
    int ans = -1;

    while(low <= high){
        int mid = low+((high-low)/2);

        if(sumOff(arr,mid) <= threshold){
            ans = mid;
            high = mid - 1;
        }else low = mid+1;
    }
    return ans;
}



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {1,2,5,9};
    cout << smallestDivisor(ans,6);
    // cout << bouquetBinarySearch(ans,2,3);
    cout << endl;

    cout << smallestDivisorBS(ans,6) << endl;


    return 0;
}