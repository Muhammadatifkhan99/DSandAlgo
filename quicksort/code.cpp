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

///MERGE SORT
void merge(vector<int> &arr,int start,int end ,int mid){
    int left = start;
    int right = mid+1;
    vector<int> temp;

    while(left <= mid && right <= end){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
    }
    }
    //if some elements are left on the left side move them to temp
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= end){
        temp.push_back(arr[right]);
        right++;
    }

    ///now copy them to original array given
    for(int i=start;i<=end;i++){
        arr[i] = temp[i-start];
    }

}

int f(vector<int> &arr,int low,int high){
    int i = low;
    int j = high;

    int pivot = low;

    while (i < j)
    {
        while(arr[i] <= arr[pivot] && i <= high){
            i++;
        }
        while(arr[j] > arr[pivot] && j>= low){
            j--;
        }
        if(i < j) swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[pivot]);
    return j;
    
}


void qs(vector<int> &arr,int low,int high){
    if(low < high){
        int pIndex = f(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}

void mergeSort(vector<int> &arr,int start,int end){
    if(start >= end)return;
    int mid = start + (end-start)/2;
    mergeSort(arr,start,mid); //this need to be called till mid only and not mid -1;
    mergeSort(arr,mid+1,end);
    merge(arr,start,end,mid);
}


int main(){

    vector<int> arrv = {3,6,2,8,6,9,7,5,1,2,0};
    qs(arrv,0,arrv.size()-1);
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