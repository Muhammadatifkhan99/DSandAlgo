#include<bits/stdc++.h>

using namespace std;


//merge two sorted arrays without extra space

vector<int> merge(vector<int> &arr1,vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();

    vector<int> ans;
    int left = 0;
    int right = 0;
    int index = 0;

    while (left < n && right < m){
        if(arr1[left] <= arr2[right]) {
            ans.push_back(arr1[left]);
            left++,index++;
        } else {
            ans.push_back(arr2[right]);
            index++,right++;
        }
    }
    while(left < n){
        ans.push_back(arr1[left]);
        index++,left++;
    }
    while(right < m){
        ans.push_back(arr2[right]);
        index++,right++;
    }
    return ans;
}




int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    // cout << funcNCR(4-1,3-1) << endl;
    // nthRow(6,3);
    vector<int> arr1 = {1,3,5,7};
    vector<int> arr2 = {0,2,6,8,9};

    for(auto it:merge(arr1,arr2)){
        cout << it << " ";
    }








    return 0;
}