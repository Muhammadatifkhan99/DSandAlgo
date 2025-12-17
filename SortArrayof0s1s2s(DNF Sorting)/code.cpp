#include<bits/stdc++.h>

using namespace std;
//sort an array of zeros,ones,twos

void sort0sBF(vector<int> &arr){
    sort(arr.begin(),arr.end());
}

void sort0sBetter(vector<int> &arr){
    int count0=0;
    int count1=0;
    int count2=0;
    int n = arr.size();
    for(int i{0};i<n;i++){
        if(arr[i]==0) count0++;
        else if(arr[i]==1) count1++;
        else count2++;
    }
    for(int i{0};i<count0;i++){
        arr[i] = 0;
    }
    for(int i{count0};i<count0+count1;i++){
        arr[i] = 1;
    }
    for(int i{count0+count1};i<n;i++){
        arr[i] = 2;
    }
}

//optimal solution

void sort0sOP(vector<int> &a){
    //DNF sorting algorithm
    //three pointers, 3 rules
    int low = 0;
    int mid = 0;
    int n = a.size();
    int high = n - 1;
    while(mid <= high){
        if(a[mid] == 0){
            swap(a[mid],a[low]);
            mid++,low++;
        } else if(a[mid] == 1){
            mid++;
        }else {
            swap(a[mid],a[high]);
            high--;
        }
    }
}



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> arr = {0,1,2,0,1,1,0,0,0,1};
    sort0sOP(arr);
    for(auto it: arr){
        cout << it << " ";
    }

    return 0;
}