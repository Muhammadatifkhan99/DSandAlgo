#include<bits/stdc++.h>

using namespace std;

//book allocation problem

int func(vector<int> &arr,int pages){
    int n = arr.size();
    int Student = 1;
    int pageStudent = 0;

    for(int i{0};i<n;i++){
        if(pageStudent + arr[i] <= pages){
            pageStudent += arr[i];
        } else {
            Student++;
            pageStudent = arr[i];
        }
    }
    return Student;
}

int bookAllocationProblem(vector<int> &arr,int m){
    int n = arr.size();
    if(m > n) return -1;
    // sort(arr.begin(),arr.end());
    int ans = 0;

    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    int cntStudent = 0;

    for(int pages = low;pages<=high;pages++){
        cntStudent = func(arr,pages);

        if(cntStudent == m){
            return pages;
        }
    }
}

//book allocation using binary search

int bookAllocationBS(vector<int> &arr,int m){
    int n = arr.size();

    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low<= high){
        int mid = low+((high-low)/2);

        if(func(arr,mid) >= m){
            high = mid - 1;
        } else {
            low = mid+1;
        }
    }
    return high;
}


int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {25,46,28,49,24};
    int m = 4;
    cout << bookAllocationProblem(ans,m) << endl;
    // cout << findMissingNumberBS(ans,5) << endl;
    

    return 0;
}