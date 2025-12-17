#include<bits/stdc++.h>

using namespace std;

//finding the peak element

//Brute Force Solution 

int peakofArrayBF(vector<int> &arr){
    int n = arr.size();

    for(int i{0};i<n;i++){
        if(((i==0) || (arr[i-1] < arr[i])) && ((i==n-1) || (arr[i] > arr[i+1]))){
            return i;
        }
    }
    return -1;
}

//most optimal solution
int peakofArray(vector<int> &arr){
    int n = arr.size();
    if(n==1) return arr[0];
    if(arr[0] > arr[1]) return arr[0];
    if(arr[n-1] > arr[n-2]) return arr[n-1];

    int low =1;
    int high = n-2;
    while (low <= high)
    {
        int mid = low+((high-low)/2);
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) return mid;
        else if(arr[mid] < arr[mid-1]) high = mid-1;
        else low = mid+1;
    }
    //if no peak element found return -1;
    return -1;
}



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {1,2,3,4,5};
    cout << peakofArray(ans);
    cout << endl;
    cout << ans[peakofArray(ans)];
    cout << endl;
    cout << peakofArrayBF(ans);
    cout << endl;
    cout << ans[peakofArrayBF(ans)];


    return 0;
}