#include<bits/stdc++.h>

using namespace std;


///Majority Elements in an Array 

int majorityElement(vector<int> &arr){
    for(int i{0};i<arr.size();i++){
        int count = 0;
        for(int j{0};j<arr.size();j++){
            if(arr[i] == arr[j]){
                count++;
            }
            if(count>arr.size()/2){
                return count;
            }
        }
    }
    return -1;
}

//Hashing Solution 

int majorityElementH(vector<int> &arr){
    map<int,int> mpp;
    for(int i{0};i<arr.size();i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        if(it.second > arr.size()/2){
            return it.first;
        }
    }
    return -1;
}

//Moore's Voting Algorithm
int majorityElementOP(vector<int> &arr){
    int freq {0};
    int ans = 0;
    for(int i{0};i<arr.size();i++){
        if(freq == 0){
            ans = arr[i];
        }
        if(ans == arr[i]){
            freq++;
        } else freq--;
    }
    return ans;
}

// void rotate(vector<int>& nums, int k) {
//         if(nums.empty()) return;
//         //reverse the entire array
//         int start = 0;
//         int end = nums.size()-1;
//         while(start <= end){
//             swap(nums[start],nums[end]);
//             start++;
//             end--;
//         }
//         //print array
//         for(auto it: nums){
//             cout <<it<< " ";
//         }
//         cout << endl;
//         start = 0;
//         end = k-1;
//         while(start <= end){
//             swap(nums[start],nums[end]);
//             start++;
//             end--;
//         }
//         //print array
//         for(auto it: nums){
//             cout <<it<< " ";
//         }
//         cout << endl;
//         start = k;
//         end = nums.size()-1;
//         while(start <= end){
//             swap(nums[start],nums[end]);
//             start++;
//             end--;
//         }
//         //print array
//         for(auto it: nums){
//             cout <<it<< " ";
//         }
// }



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> arr = {2,2,3,3,1,2,2};

    return 0;
}