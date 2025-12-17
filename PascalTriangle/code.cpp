#include<bits/stdc++.h>

using namespace std;
//calculating NCR in minimal time

int funcNCR(int n,int r){
    long long res = 1;
    for(int i{0};i<r;i++){
        res = res * (n-i);
        res/= i+1;
    }
    return res;
}

///printing any nth row of the pascal triangle

void nthRow(int n,int c){
    for(int c=1;c<=n;c++){
        cout << funcNCR(n-1,c-1) << " ";
    }
}
//printing nth row using an optimal solution 

void nthRowOP(int n){
    int ans = 1;
    cout << ans << " ";
    for(int i{1};i<n;i++){
        ans = ans * (n-i);
        ans = ans/i;
        cout << ans << " ";
    }
}


int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    // cout << funcNCR(4-1,3-1) << endl;
    // nthRow(6,3);

    nthRowOP(4);









    return 0;
}