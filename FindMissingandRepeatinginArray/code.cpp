#include<bits/stdc++.h>

using namespace std;


//find missing and repeating in array

vector<int> findMissingAndRepeating(vector<int> &ar){
    int n = ar.size();

    int repeating = -1;
    int missing   = -1;


    for(int i{1};i<n;i++){
        int count = 0;
        for(int j{0};j<n;j++){
            if(ar[j] == i){
                count++;
            }
        }
        if(count == 2) repeating = i;
        else if(count == 0) missing = i;
        if(repeating != -1 && missing != -1) break;
    }
    return {repeating,missing};
}

vector<int> findMissingAndRepeatingBetter(vector<int> &arr){
    int n = arr.size();

    int missing = -1;
    int repeating = -1;

    vector<int> hasharray(n+1,0);
    int count=0;
    for(int i{0};i<n;i++){
        hasharray[arr[i]]++;
    }
    for(int i{1};i<n;i++){
        if(hasharray[i]==2){
            repeating = i;
        }
        else if(hasharray[i] == 0){
            missing = i;
        }
        if(missing != -1 && repeating != -1){
            break;
        }
    }
    return {repeating,missing};
}

vector<int> findMissingAndRepeatingOP(vector<int> &arr){
    long long n = arr.size();

    long long SN = (n*(n+1))/2;
    long long S2N = (n*(n+1)*(2*n+1))/6;

    long long S = 0, S2 = 0;

    for(int i{0};i<n;i++){
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = S - SN;
    long long val2 = S2 - S2N;

    val2 = val2/val1;
    long long x = (val1+val2)/2;
    long long y = x - val1;

    return {(int)x,(int)y};
}


int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {4,3,6,2,1,1};

    for(auto it: findMissingAndRepeatingOP(ans)){
        cout << it << " ";
    }








    return 0;
}