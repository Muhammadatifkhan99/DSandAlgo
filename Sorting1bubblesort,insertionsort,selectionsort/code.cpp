#include<bits/stdc++.h>

using namespace std;

void selection_sort(int arr[],int n){
    for(int i{0};i<=n-2;i++){
        int mini = i;
        for(int j{i+1};j <= n-1;j++){
            if(arr[j] < arr[mini]){
                swap(arr[mini],arr[j]);
            }
        }
    }
}

void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i{n-1};i>=0;i--){
        int didSwap = 0;
        for(int j=0;j<= i -1;j++){
        if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            didSwap = 1;
        }
        }
        if(didSwap == 0){
            break;
        }
        cout << "runs\n" ;
    }
}

void insertion_sort(vector<int> &arr){
    int n = arr.size();
    for(int i{0};i<=n-1;i++){
        int j = i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}


int main(){

    vector<int> arrv = {3,6,2,8,6,9,7,5,1,2,0};
    insertion_sort(arrv);
    for(auto it:arrv){
        cout << it << " " ;
    }
    // int n;
    // cin >>n;

    // int arr[n];
    // for(int i{0};i<n;i++){
    //     cin >> arr[i];
    // }
    // selection_sort(arr,n);
    // for(int i{0};i<n;i++){
    //     cout << arr[i] << " ";
    // }

    return 0;
}