#include<bits/stdc++.h>

using namespace std;

int largestinArray(vector<int> &arr){ //O(nlogn) the sort function sort in logn time
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}


int largestnArray(vector<int> arr){ //o(n) time complexity
    int largest = arr[0];
    for(int i{0};i<=arr.size()-1;i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}

int secLargestnArray(vector<int> arr){
    int secLar {0};
    int largest = largestnArray(arr);
    for(int i=0;i<arr.size();i++){
        if(arr[i] > secLar && arr[i] != largest){
            secLar = arr[i];
        }
    }
    return secLar;
}

//optimal approach to finding the second largest element

int secondLargestOptimal(vector<int> arrv){
    int largest = arrv[0];
    int secLar = -1;
    for(int i{0};i<arrv.size();i++){
        if(arrv[i] > largest){
            secLar = largest;
            largest = arrv[i];
        }
        else if (arrv[i] < largest && arrv[i] > secLar){
            secLar = arrv[i];
        }
    }
    return secLar;
}

//second smallest in array

int secondSmallest(vector<int> arr){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i{0};i<arr.size();i++){
        if(arr[i] < smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < ssmallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

//checking if array is sorted or not

bool isSorted(vector<int> &arr){
    for(int i{0};i<arr.size();i++){
        if(arr[i] <= arr[i+1]){
        } else return false;
    }
    return true;
}


//removing duplicates form sorted array 

void removeDuplicates(vector<int> &arr){
    int n = arr.size() -1;

    for(int i{0};i<=n;i++){
        for(int j{i+1};j<=n;j++){
        if(arr[i] == arr[j]){
            arr[j] = 0;
        }
    }
    }
}

//remove duplicates using hashing
void removeDupli(vector<int> &arr){
    set<int> s;
    for(int i{0};i<arr.size();i++){
        s.insert(arr[i]);
    }
    int index{0};
    for(auto it:s){
        arr[index] = it;
        index++;
    }
}

//optimal solution to removing duplicates

int removeDuplicatesOP(vector<int> &arr){
    int i{0};
    for(int j{0};j<arr.size();j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i+=1;
        }
    }
    return i+1;
}

int main(){

    vector<int> arrv = {3,6,2,6,9,5,1,2,0};
    cout << largestinArray(arrv) << endl;
    cout << largestnArray(arrv) << endl;
    cout << secLargestnArray(arrv) << endl;
    cout << secondLargestOptimal(arrv) << endl;
    cout << secondSmallest(arrv) << endl;

    vector<int> arr1 = {1,1,2,2,2,3,3};
    cout << boolalpha;
    cout << isSorted(arr1) << endl;
    // removeDuplicates(arr1);
    cout << removeDuplicatesOP(arr1);

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