#include<bits/stdc++.h>

using namespace std;

//rearrange array elements by sign

//bruteforce approach
void rearrangeElements(vector<int> &arr){
    vector<int> pos;
    vector<int> neg;
    int n = arr.size();

    for(int i{0};i<n;i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else neg.push_back(arr[i]);
    }

    for(int i{0};i<n/2;i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
}

//optimal solution

vector<int> rearrangeElementOP(vector<int> &arr){
    int n = arr.size();
    int pIndex = 0;
    int nIndex = 1;
    vector<int> ans(n,0);

    for(int i{0};i<n;i++){
        if(arr[i] > 0){
            ans[pIndex] = arr[i];
            pIndex += 2;
        } else {
            ans[nIndex] = arr[i];
            nIndex+=2;
        }
    }
    return ans;
}





int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> arr = {3,1,-2,-5,2,-4};
    vector<int> ans = rearrangeElementOP(arr);
    for(auto it: ans){
        cout << it << " ";
    }



    return 0;
}