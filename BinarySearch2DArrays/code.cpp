#include<bits/stdc++.h>
#include<algorithm>

using namespace std;


///Binary Search on 2D Arrays

bool search2DArray(vector<vector<int>> &mat,int target){
    int n = mat.size();
    int m = mat[0].size();

    for(int i{0};i<n;i++){
        for(int j{0};j<n;j++){
            if(mat[i][j] == target){
                return true;
            }
        }
    }
    return false;
}
bool biSearch(vector<int> &arr,int target){
    int n= arr.size();

    int low = 0;
    int high = n-1;
    while(low < high){
        int mid = (low+high) >> 1;
        if(arr[mid] == target) return true;
        if(arr[mid] <= target){
            low = mid+1;
        }else {
            high = mid-1;
        }
    }
    return false;
}

bool search2DArrayB(vector<vector<int>> &mat,int target){
    int n = mat.size();
    int m = mat[0].size();

    for(int i{0};i<n;i++){
        if(target >= mat[i][0] && target <= mat[i][m-1]){
            return biSearch(mat[i],target);
        }
    }
    return false;
}

bool search2DArrayBS(vector<vector<int>> &mat,int target){
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = n*m-1;

    while(low <= high){
        int mid = (low+high) >> 1;
        int row = mid/m;
        int col = mid%m;

        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) low = mid+1;
        else high = mid-1;
    }
    return false;
}







int main(){

    //###################################################################
    cout<<"Play ground is up" << endl;
    cout << endl;
    //###################################################################
    vector<vector<int>> mat = {
                                {3,4,7,9},
                                {12,13,16,19},
                                {20,21,23,29}
    };

    int target = 21;
    cout << boolalpha;
    cout << search2DArray(mat,target) << endl;
    cout << search2DArrayB(mat,target) << endl;
    cout << search2DArrayBS(mat,target) << endl;


    // vector<int> ans = {2,3,6,7,9};
    // vector<int> ans1 = {1,4,8,10};
    // cout << median(ans,ans1,4) << endl;
    return 0;
}