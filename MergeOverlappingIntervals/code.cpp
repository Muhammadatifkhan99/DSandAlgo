#include<bits/stdc++.h>

using namespace std;


//merge overlapping intervals in 2d vector


vector<vector<int>> mergeIntervals(vector<vector<int>> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for(int i{0};i<n;i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j{i+1};j<n;j++){
            if(arr[j][0] <= end){
                end = max(arr[j][1],end);
            }
            else break;
        }
        ans.push_back({start,end});
    }
    return ans;
}

vector<vector<int>> mergeIntervalsOP(vector<vector<int>> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for(int i{0};i<n;i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        } else {
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
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

        vector<vector<int>> vec = {
        {1, 3},
        {2, 4},
        {2, 6},
        {8, 9},
        {8, 10},
        {9, 11},
        {15, 18},
        {16, 17}
    };

    for(auto it: mergeIntervalsOP(vec)){
        for(auto i: it){
            cout << i << " ";
        } cout << endl;
    }







    return 0;
}