#include<bits/stdc++.h>
#include<algorithm>

using namespace std;


//median of row wise in sorted matrix

int medianRowWise(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<int> oneD;

    for(int i{0};i<n;i++){
        for(int j{0};j<m;j++){
            oneD.push_back(mat[i][j]);
        }
    }
    sort(oneD.begin(),oneD.end());
    return oneD[(n*m)/2];
}
int upperBound(vector<int> &arr,int x,int n){
    int low = 0;
    int high = n-1;
    int ans = n;
    while (low <= high){
        int mid = (low+mid)/2;
        if(arr[mid] > x){
            ans = mid;
            high = mid -1;
        }else {
            low = mid+1;
        }
    }
    return ans;
}

int blackBox(vector<vector<int>> &mat,int n,int m,int mid){
    int cnt = 0;
    for(int i{0};i<n;i++){
        cnt += upperBound(mat[i],mid,m);
    }
    return cnt;
}

int medianRowWiseOptimal(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    
    int low = INT_MAX;
    int high = INT_MIN;

    int req = (n*m)/2;

    for(int i{0};i<n;i++){
        low = min(low,mat[i][0]);
        high = max(high,mat[i][m-1]);
    }

    while(low <= high){
        int mid = (low+high)/2;
        int smallarEqual = blackBox(mat,n,m,mid);

        if(smallarEqual <= req) low = mid+1;
        else high = mid -1;
    }
    return low;
}


int main(){

    //###################################################################
    cout<<"Play ground is up and running" << endl;
    //###################################################################
    vector<vector<int>> mat = {
                                {1,5,7,9,11},
                                {2,3,4,5,10},
                                {9,10,12,14,16}
    };
    cout << medianRowWiseOptimal(mat) << endl;

    // vector<int> ans = {2,3,6,7,9};
    // vector<int> ans1 = {1,4,8,10};
    // cout << median(ans,ans1,4) << endl;
    return 0;
}