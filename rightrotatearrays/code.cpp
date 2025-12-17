#include<bits/stdc++.h>

using namespace std;

///left rotate an array by one place

void leftRotatArray(vector<int> &arr){
    int n = arr.size();
    int first = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = first;
}

//rotate an array by d places 

void rotateDplaces(vector<int> &arr,int d){
    int n = arr.size();
    vector<int> temp;
    for(int i{0};i<d;i++){
        temp.push_back(arr[i]);
    }
    for(int i{0};i<n-d;i++){
        arr[i] = arr[d+i];
    }
    for(int i{0};i<d;i++){
        arr[n-d+i] = temp[i];
    }
}

//optimal solution to rotating array by kth places

void rotateArray(vector<int> &arr,int d){
    int n = arr.size();
    int start = 0;
    int end = d-1;
    while(start <= end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    start = d;
    end = n-1;
    while(start <= end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    start = 0;
    end = n-1;
    while(start <= end){
        swap(arr[start],arr[end]);
        start ++;
        end--;
    }

}

//right rotating an array 

void rightrotateArray(vector<int> &arr,int d){
    int n = arr.size();
    vector<int> temp;

    for(int i{0};i<n-d-1;i++){
        temp.push_back(arr[n-d+i]);
    }
    for(int i{0};i<n-d;i++){
        temp.push_back(arr[i]);
    }
    //copy all the values to the original array

    for(int i{0};i<n;i++){
        arr[i] = temp[i];
    }
}

void optimalrotateArray(vector<int> &arr,int d){
    int n = arr.size();

    int start = n-d;
    int end = n-1;

    while(start <= end){ //d can be equal to n so O(n);
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    start = 0;
    end = d;
    while (start <= end)
    {
        swap(arr[start],arr[end]);
        start ++;
        end --;
    }
    start = 0;
    end = n-1;

    while(start <= end){
        swap(arr[start],arr[end]);
        start ++;
        end --;
    }
}

//move all the non zero elements to the end of the array 


void moveNonZeros(vector<int> &arr){
    int n1 = arr.size();
    vector<int> temp;

    //add the non zero values to the temp array 
    for(int i{0};i<n1;i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    int n2 = temp.size();
    //move the temp values back to the original array 
    for(int i{0};i<n2;i++){
        arr[i] = temp[i];
    }
    //copy add the last zeros back to the original array 
    for(int i{0};i<n1-n2;i++){
        arr[n2+i]  = 0;
    }
}

//optimal solution for nonzeros

void moveNonZero(vector<int> &arr){
    int n = arr.size();

    int i=1;
    int j=0;
    while (i<n)
    {
        if(arr[j] == 0 && arr[i] != 0){
            swap(arr[i],arr[j]);
            i++,j++;
        } else if(arr[j] == 0){
            i++;
        } else {
            i++,j++;
        }
    }
    
}

//union of two sorted arrays

vector<int> unionArraysBF(vector<int> arr1,vector<int> arr2){
    set<int> s;
    for(int i{0};i<arr1.size();i++){
        s.insert(arr1[i]);
    }
    for(int i{0};i<arr2.size();i++){
        s.insert(arr2[i]);
    }
    vector<int> uArr;
    for(auto it: s){
        uArr.push_back(it);
    }
    return uArr;

}

int main(){
    vector<int> arr1 = {1,1,2,3,4,5};
    vector<int> arr2 = {2,3,4,4,5};
    // int d = 3;
   
    for(int it: unionArraysBF(arr1,arr2) ){
        cout << it << " ";
    }


    // vector<int> arr = {1,2,3,4,5,6,7};
    // int d = 3;
    // optimalrotateArray(arr,d%arr.size());
    // for(int it: arr){
    //     cout << it << " ";
    // }

    return 0;
}