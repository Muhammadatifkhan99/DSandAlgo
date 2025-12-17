#include<bits/stdc++.h>

using namespace std;

//implementing lowerbound in c++


int lowerbound(vector<int> &arr,int target){
    int n = arr.size();

    int low =0;
    int high = n-1;
    int ans = n;

    while(low <= high){
        int mid = low + (high - low) / 2;
        //lower bound is great and good
        if(arr[mid] >= target){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

//upper bound 

int upperbound(vector<int> &arr,int target){
    int n= arr.size();

    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        //upper bound is greate
        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }else low = mid +1;
    }
    return ans;
}


//search insert postion in array 

int insertPosition(vector<int> &ans,int target){
    int n = ans.size();

    int i = 0;
    
    while(i <= n){
        if(target > ans[i]){
            i++;
        }
        else return i;
    }
    return -1;
}

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();

    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(nums[mid] >= target){
            ans = mid;
            high = mid - 1;
        } 
        else low = mid+1;
    }
    return ans;
}

vector<int> firstandLastOccurances(vector<int> &arr,int target){
    int n = arr.size();

    int lb = lowerbound(arr,target);
    if((lb == n) || (arr[lb] != target)) return {-1,-1};
    return {lb,upperbound(arr,target) -1}; 
}

//first and last occurance in array 

vector<int> firstandLastOccurancesBS(vector<int> &arr,int target){
    int low = 0;
    int n = arr.size();
    int high = n-1;
    int first = -1;
    //we need to find the first occcurance which is most likely towards the start of the array(sorted)
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            first = mid;
            high = mid-1;
        }else if(arr[mid] < target){
            low = mid+1;
        }else high = mid-1;
    }
    //last occurance
    int last = -1;
    low = 0;
    high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            last = mid;
            low = mid+1;
        }else if(arr[mid] < target){
            low = mid+1;
        }else high = mid-1;
    }
    return {first,last};
    // int n = arr.size();
    // int lb = lowerbound(arr,target);
    // if((lb == n) || (arr[lb] != target)) return {-1,-1};
    // return {lb,upperbound(arr,target) -1}; 
}

int countingOccurances(vector<int> &arr,int target){
    int count = 0;
    vector<int> ans = firstandLastOccurancesBS(arr,target);
    if(ans[0] == -1) return 0;
    return ans[1] - ans[0] + 1;
}

int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {5,7,7,8,8,8,8,10};
    
    for(auto it: firstandLastOccurancesBS(ans,8)){
        cout << it << " ";
    }
    cout << endl;
    cout << countingOccurances(ans,8);
    // cout << lowerbound(ans,45);
    // cout << endl;
    // cout << ans[lowerbound(ans,45)];
    // cout << endl;
    // cout << upperbound(ans,3);

    // cout << endl;
    // vector<int> arr = {1,2,3,4,5,6};
    // int target = 3;
    // cout << insertPosition(arr,target);

    // int lb = lower_bound(ans.begin(),ans.end(),1)-(ans.begin());
    // cout << lb << endl;



    return 0;
}