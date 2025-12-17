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

//better solution 

bool search2DMatII(vector<vector<int>> &mat,int target){
    int n=mat.size();
    int m = mat[0].size();
    int ind = -1;

    for(int i{0};i<n;i++){
        ind = biSearch(mat[i],target);
        if(ind != -1){
            return true;
        }
    }
    return false;
}

//optimal solution 

bool search2DMatIIOptimal(vector<vector<int>> &mat,int target){
    int row = 0;
    int n = mat.size();
    int m = mat[0].size();
    int col = m-1;

    while(row < n && col > 0){
        if(mat[row][col] == target){
            return true; // {row,col};
        }
        else if (mat[row][col] < target){
            row++;
        } else col--;
    }
    return false;
}







int main(){

    //###################################################################
    cout<<"Play ground is up" << endl;
    cout << endl;
    //###################################################################
    vector<vector<int>> mat = {
                                {1,4,7,11,15},
                                {2,5,8,12,19},
                                {3,6,9,16,22},
                                {10,13,14,17,24},
                                {18,21,23,26,30}
    };

    int target = 21;
    cout << boolalpha;
    cout << search2DArray(mat,target) << endl;
    cout << search2DMatII(mat,target) << endl;
    cout << search2DMatIIOptimal(mat,target) << endl;

    // vector<int> ans = {2,3,6,7,9};
    // vector<int> ans1 = {1,4,8,10};
    // cout << median(ans,ans1,4) << endl;
    return 0;
}