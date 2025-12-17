#include<bits/stdc++.h>

using namespace std;

//finding the square root of a number using binary search 

//brute force

int squareRoot(int n){
    int ans = 0;

    for(int i{0};i<n;i++){
        if(i*i <= n){
            ans = i;
        }
    }
    return ans;
}


int squareRootOP(int n){

    int low = 0;
    int high = n;
    int ans = 0;

    while (low < high){
        long long mid = low+((high-low)/2);
        long long sqr = mid * mid;
        if(sqr <= n){
            ans = mid;
            low = mid+1;
        }else high = mid-1;
    }
    return ans;
}

int floorSqrt(int n) {
    return n * n;
}



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {1,2,3,4,5};
    int n = 8;
    cout << squareRootOP(n);
    cout << endl;
    cout << floorSqrt(10);


    return 0;
}