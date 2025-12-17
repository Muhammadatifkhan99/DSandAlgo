#include<bits/stdc++.h>

using namespace std;

//Binary Search Algorithm

int binarySearch(vector<int> &arr,int target){
    int n = arr.size();

    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid] == target){
            return mid;
        }else if(target > arr[mid]){
            low = mid + 1;
        } else {
            high = mid-1;
        }
    }
    return -1;
}





int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {2,3,5,6,7,8};
    cout << binarySearch(ans,7);



    return 0;
}