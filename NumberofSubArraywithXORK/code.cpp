#include<bits/stdc++.h>

using namespace std;


//number of subarray with xor k

int numberofSubArray(vector<int> &ans,int target){
    int n = ans.size();
    int count=0;

    for(int i{0};i<n;i++){
        for(int j{i};j<n;j++){
            int Xor = 0;
            for(int k{i};k<=j;k++){
                Xor = Xor ^ ans[k];
            }
            if(Xor == target) count++;
        }
    }
    return count;
}

int numberofSubArrayBetter(vector<int> &ans,int target){
    int n = ans.size();
    int count=0;

    for(int i{0};i<n;i++){
        int Xor = 0;
        for(int j{i};j<n;j++){
            Xor = Xor ^ ans[j];
            if(Xor == target) count++;
        }
    }
    return count;
}

//Optimal Solution

int numberofSubArrayOP(vector<int> &ans,int target){
    int n = ans.size();

    int xr = 0;
    map<int,int> mpp;
    mpp[xr]++; //(0,1);
    int count = 0;

    for(int i{0};i<n;i++){
        xr = xr ^ ans[i];
        int x = xr ^ target;
        count += mpp[x];
        mpp[xr]++;
    }
    return count;
}


int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    // cout << funcNCR(4-1,3-1) << endl;
    // nthRow(6,3);

    vector<int> res = {4,2,2,6,4};
    cout << numberofSubArrayOP(res,6);






    return 0;
}