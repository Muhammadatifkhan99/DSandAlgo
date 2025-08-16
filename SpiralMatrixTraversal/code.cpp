#include<bits/stdc++.h>

using namespace std;

void spiralTraversal(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();

    int left = 0;
    int right = m - 1;
    int bottom = n - 1;
    int top = 0;
    while (left <= right && top <= bottom) {
        for(int i = left;i<=right;i++){
            cout << arr[top][i] << " ";
        }
        top++;
        for(int i{top};i<=bottom;i++){
            cout << arr[i][right] << " ";
        }
        right--;
        if(top <= bottom){
            for(int i=right;i>=left;i--){
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }

        if(left <= right){
            for(int i{bottom};i>=top;i--){
                cout << arr[i][left]<<" ";
            }
            left++;
        }
    }
}




int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################
    vector<vector<int>> arr = {
                                {1,2,3,4,5,6},
                                {20,21,22,23,24,7},
                                {19,32,33,34,25,8},
                                {18,31,36,35,26,9},
                                {17,30,29,28,27,10},
                                {16,15,14,13,12,11}
    };


    spiralTraversal(arr);

    return 0;
}