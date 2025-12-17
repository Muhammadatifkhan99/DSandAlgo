#include<bits/stdc++.h>

using namespace std;

//Aggressive Cows Problem

bool canWePlaceCows(vector<int> &stalls,int dist,int cows){
    int n = stalls.size();

    int cntCows = 1;
    int last = stalls[0];
    for(int i{1};i<n;i++){
        if(stalls[i] - last >= dist){
            cntCows ++;
            last = stalls[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

// int aggressiveCows(vector<int> &stalls,int cows){
//     int n = stalls.size();
    

//     sort(stalls.begin(),stalls.end());
//     int min = stalls[0];
//     int max = stalls[n-1];
//     for(int i{1};i<max-min;i++){
//         if(canWePlaceCows(stalls,i,cows) == true){
//             continue;
//         }else {
//             return (i-1);
//         }
//     }
//     return -1;
// }

//Optimal Solution

int aggressiveCows(vector<int> &stalls,int cows){
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();

    int low = 1;
    int high = stalls[n-1] - stalls[0];

    while(low <= high){
        int mid = low+((high-low)/2);
        if(canWePlaceCows(stalls,mid,cows)==true){
            low = mid+1;
        }
        else high = mid-1;
    }
    return high;
}
int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {0,3,4,7,10,9};
    int cows = 4;
    cout << aggressiveCows(ans,cows) << endl;
    // cout << findMissingNumberBS(ans,5) << endl;
    

    return 0;
}