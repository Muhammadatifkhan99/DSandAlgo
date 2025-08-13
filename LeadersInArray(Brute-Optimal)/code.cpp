#include<bits/stdc++.h>

using namespace std;

//leaders in array 

vector<int> leadersInArray(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;

    for(int i{0};i<n;i++){
        bool flag = true;
        for(int j{i+1};j<n;j++){
            if(arr[j] > arr[i]){
                flag = false;
                break;
            }
        }
        if(flag == true){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

//optimal solution 

vector<int> leadersInArrayOP(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;
    int maxi = INT_MIN;

    for(int i{n-1};i>=0;i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi,arr[i]);
    }
    return ans;
}




int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> arr = {10,22,12,3,0,6};
    vector<int> ans = leadersInArrayOP(arr);
    for(auto it: ans){
        cout << it << " ";
    }



    return 0;
}