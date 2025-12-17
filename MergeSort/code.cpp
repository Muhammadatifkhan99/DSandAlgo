#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
#include<map>

using namespace std;

// void merge(vector<int> &arr,int low,int mid,int high){
//     vector<int> ans;
//     int left = low;
//     int right = mid + 1;
//
//     while (left <= mid && right <= high)
//     {
//         if(arr[left] <= arr[right]){
//             ans.push_back(arr[left]);
//             left++;
//         }
//         else {
//             ans.push_back(arr[right]);
//             right++;
//         }
//     }
//     while(left <= mid){
//         ans.push_back(arr[left]);
//         left++;
//     }
//     while (right <= high)
//     {
//         ans.push_back(arr[right]);
//         right++;
//     }
//
//     //copies values to the older array
//
//     for(int i = low;i<=high;i++){
//         cout << "Value of start: " << low << endl;
//         arr[i] = ans[i-low];
//     }
// }
//
// void mergeSort(vector<int> &arr,int low,int high){
//     if(low >= high){
//         return;
//     }
//     int mid = (low + high)/2;
//     mergeSort(arr,low,mid);
//     mergeSort(arr,mid+1,high);
//     merge(arr,low,mid,high);
// }

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    cout << "\n=== Merging: arr[" << low << " to " << mid << "] and arr[" << mid+1 << " to " << high << "] ===" << endl;
    cout << "Left: ";
    for(int i = low; i <= mid; i++) cout << arr[i] << " ";
    cout << "\nRight: ";
    for(int i = mid+1; i <= high; i++) cout << arr[i] << " ";
    cout << endl;

    vector<int> ans;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            ans.push_back(arr[left]);
            left++;
        } else {
            ans.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        ans.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        ans.push_back(arr[right]);
        right++;
    }

    // Debug: print merged temp array
    cout << "Merged temp array: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    // Copy values back to arr
    for (int i = low; i <= high; i++) {
        cout << "Copying ans[" << (i - low) << "] = " << ans[i - low] << " → arr[" << i << "]" << endl;
        arr[i] = ans[i - low];
    }

    // Show array after merge
    cout << "Array after merge: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

void mergeSort(vector<int> &arr, int low, int high) {
    cout << "mergeSort called: low = " << low << ", high = " << high << endl;

    if (low >= high) {
        cout << "Base case reached for range [" << low << ", " << high << "] — returning\n";
        return;
    }

    int mid = (low + high) / 2;
    cout << "mid = " << mid << endl;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main() {
    vector<int> arr = {5, 2, 8, 1};
    cout << "Initial array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "\nFinal sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}



// int main(){
//     vector<int> arr = {3,26,4,45,9};
//     mergeSort(arr,0,4);
//
//     for(auto it: arr){
//         cout << it << " ";
//     }
//     cout << endl;
//
//     // for(auto it: binaryTreePaths(r1)){
//     //     cout << it << endl;
//     // }
//
//
//     return 0;
// }