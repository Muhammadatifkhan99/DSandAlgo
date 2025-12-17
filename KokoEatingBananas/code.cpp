#include<bits/stdc++.h>

using namespace std;

//koko eating bananas

int maxArray(vector<int> &v){
    int n = v.size();

    int maxi = INT_MIN;
    for(int i{0};i<n;i++){
        maxi = max(maxi,v[i]);
    }
    return maxi;
}

int totalTime(vector<int> &v,int h){
    int n= v.size();

    int totalHours = 0;
    for(int i{0};i<n;i++){
        totalHours += ceil((double)v[i]/(double)h);
    }
    return totalHours;
}

int eatingBananas(vector<int> &v, int h){
    int n = v.size();

    int low = 0;
    int high = maxArray(v);

    while(low <= high){
        int mid = low+((high-low)/2);
        int totalHours = totalTime(v,mid);
        if(totalHours <= h){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return low;
}



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {3,6,7,11};
    cout << eatingBananas(ans,8);


    return 0;
}