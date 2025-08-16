#include<bits/stdc++.h>

using namespace std;


vector<vector<int>> rotateArray(vector<vector<int>> &arr){
    int n = arr.size();
    vector<vector<int>> ans(n, vector<int>(n));
    for(int i{0};i<n;i++){
        for(int j{0};j<n;j++){
            ans[j][n-1-i] = arr[i][j];
        }
    }
    return ans;
}


vector<vector<int>> rotateArrayOP(vector<vector<int>> &arr){
    int n = arr.size();

    for(int i{0};i<n-1;i++){
        for(int j{i+1};j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    //reverse each row to get the rotated array 
    for(int i{0};i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
    return arr;
}


int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################
    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    vector<vector<int>> ans = rotateArrayOP(arr);


    for(int i{0};i<ans.size();i++){
        for(int j{0};j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}