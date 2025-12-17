#include<bits/stdc++.h>

using namespace std;

//single element in sorted array 


int singleElementArray(vector<int> &arr){
    int n = arr.size();

    for(int i{0};i<n;i++){
        if(i==0){
            if(arr[i] != arr[i+1]) return arr[i];
        }
        else if(i==n-1){
            if(arr[i] != arr[i-1]) return arr[i];
        }
        else {
            if(arr[i] != arr[i+1] && arr[i] != arr[i-1]){
                return arr[i];
            }
        }
    }
    return -1;
}

//optimal solution

int singleElementArrayOP(vector<int> &arr){
    int n = arr.size();

    int low  = 0+1;
    int high = n-2;

    while(low <= high){
        int mid = low+((high-low)/2);
        if(arr[mid]!= arr[mid+1] && arr[mid] != arr[mid-1]){
            return arr[mid];
        }
        if((mid%2 == 1 && arr[mid] != arr[mid-1]) || (mid%2==0 && arr[mid] == arr[mid+1])){ 
            low = mid+1;
        }else high = mid-1; 
    }
    return -1;
}



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {1,1,2,2,3,3,4,6,6};
    cout << singleElementArrayOP(ans);
    cout << endl;


    return 0;
}