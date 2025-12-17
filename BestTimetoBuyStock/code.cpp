#include<bits/stdc++.h>

using namespace std;


//best time to buy and sell stock

int bestStock(vector<int> &arr){
    int n = arr.size();

    int smallest = INT_MAX;
    int largest = INT_MIN;
    int index =0;

    for(int i{0};i<n;i++){
        if(arr[i] < smallest){
            smallest = arr[i];
            index = i;
        }
    }
    for(int i=index;i<n;i++){
        if(arr[i] > largest){
            largest = i;
        }
    }
    if(arr[largest] - smallest < 0){
        return 0;
    }
    return arr[largest] - smallest;
}



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> arr = {7,1,5,3,6,4};
    cout << bestStock(arr) << endl;


    return 0;
}