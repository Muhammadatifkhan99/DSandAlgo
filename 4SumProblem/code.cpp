#include<bits/stdc++.h>

using namespace std;


//4 sum problem

vector<vector<int>> fourSum(vector<int> &nums,int target){
    int n = nums.size();

    set<vector<int>> st;

    for(int i{0};i<n;i++){
        for(int j{i+1};j<n;j++){
            set<long long> hashset;
            for(int k{j+1};k<n;k++){
                long long sum = nums[i]+nums[j];
                sum += nums[k];
                long long fourth = target - (sum);
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp = {nums[i],nums[j],nums[k],(int)fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//four sum optimal solution 

vector<vector<int>> fourSumOP(vector<int> &nums, int target){
    int n = nums.size();

    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i{0};i<n;i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j{i+1};j<n;j++){
            if(j != i+1 && nums[j] == nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l) {
                int fourSum = nums[i] + nums[j] + nums[k] + nums[l];
                if(fourSum < target){
                    k++;
                } else if(fourSum > target){
                    l--;
                } else {
                    vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l && nums[k] == nums[k-1]) k++;
                    while(k < l && nums[l] == nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    // cout << funcNCR(4-1,3-1) << endl;
    // nthRow(6,3);

    vector<int> res = {1,1,1,2,2,2,3,3,3,4,4,4,5,5};
    vector<vector<int>> ans = fourSumOP(res,8);

    for(auto it: ans){
        for(auto i: it){
            cout << i << " ";
        }
        cout << endl;
    }






    return 0;
}