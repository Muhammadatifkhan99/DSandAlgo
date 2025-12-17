#include<bits/stdc++.h>

using namespace std;

//find the least capacity to ship packages within D days

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
int sumofArray(vector<int> arr){
    int n = arr.size();

    int sum = 0;

    for(int i{0};i<n;i++){
        sum+= arr[i];
    }
    return sum;
}
int daysRequire(vector<int> &arr,int capcity){
    int days = 1;
    int load = 0;

    for(int i{0};i<arr.size();i++){
        if(load + arr[i] > capcity){
            days = days + 1;
            load = arr[i];
        }else {
            load += arr[i];
        }
    }
    return days;
}

int shippingCapacity(vector<int> &arr,int days){
    int n = arr.size();

    int max = maxiofArray(arr);
    int sum = sumofArray(arr);

    for(int capacity{max};capacity<=sum;capacity++){
        int daysReq = daysRequire(arr,capacity);
        if(daysReq <= days){
            // cout << "The Capacity Required will be: " << capacity << endl;
            return daysReq;
        }
    }
    return -1;
}

int shippingCapacityBS(vector<int> &arr,int days){
    int n = arr.size();

    int max = maxiofArray(arr);
    int sum = sumofArray(arr);

    int low = max;
    int high = sum;

    while(low <= high){
        int mid = low+((high-low)/2);
        int dayRequired = daysRequire(arr,mid);
        if(dayRequired <= days){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return low;
}



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {1,2,3,4,5};
    cout << shippingCapacityBS(ans,5) << endl;
    

    return 0;
}