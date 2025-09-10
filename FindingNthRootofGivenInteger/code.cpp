#include<bits/stdc++.h>

using namespace std;

///finding the nth root of the given integer

int nthTime(int n,int i){
    int prod = 1;
    while(n>0){
        prod = prod * i;
        n--;
    }
    return prod;
}

//calculating power using binary exponentiation 

int nthTimes(int n,int i){

}

int nthRoot(int n,int m){
    for(int i{1};i<m;i++){
        if(nthTime(n,i) == m){
            return i;
        }
    }
    return -1;
}

int nthRootOP(int n,int m){
    int low = 1;
    int high = m;

    while(low <= high){
        int mid = low+((high-low)/2);
        if(nthTime(n,mid)==m){
            return mid;
        }else if(nthTime(n,mid) > m){
            high = mid-1;
        }else low = mid+1;
    }
    return -1;
}

//binary exponentiation 

int binaryExponentiation(int n,int x){
    long long ans = 1;

    while(n > 0){
        if((n%2) == 1){
            ans = ans * x;
            n = n-1;
        }else {
            x = x*x;
            n /=2;
        }
    }
    return ans;
}



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {1,2,3,4,5};
    int n = 2;
    int m = 625;
    cout << nthRoot(n,m);
    cout << endl;
    cout << nthRootOP(n,m);
    cout << endl;
    cout << binaryExponentiation(7,2);


    return 0;
}