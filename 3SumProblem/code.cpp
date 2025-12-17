#include<bits/stdc++.h>

using namespace std;


//calculating the majority element n/3 times the size of the array

vector<vector<int>> threeSumProblem(vector<int> &ans){
    set<vector<int>> nums;
    int n = ans.size();
    for(int i{0};i<n;i++){
        for(int j{i+1};j<n;j++){
            for(int k{j+1};k<n;k++){
                if(ans[i]+ans[j]+ans[k]==0){
                    vector<int> temp = {ans[i],ans[j],ans[k]};
                    sort(temp.begin(),temp.end());
                    nums.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> p(nums.begin(),nums.end());
    return p;
}


vector<vector<int>> threeSumProblemBetter(vector<int> &ans){
    set<vector<int>> nums;
    int n = ans.size();
    for(int i{0};i<n;i++){
        set<int> hashset;
        for(int j{i+1};j<n;j++){
            int third = -(ans[i] + ans[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {ans[i],ans[j],third};
                sort(temp.begin(),temp.end());
                nums.insert(temp);
            }
            hashset.insert(ans[j]);
        }
    }
    vector<vector<int>> p(nums.begin(),nums.end());
    return p;
}


///optimal solution
vector<vector<int>> threeSum(vector<int>& ans) {
    vector<vector<int>> nums;
    int n = ans.size();
    sort(ans.begin(),ans.end());
    for(int i{0};i<n;i++){
        if(i>0 && ans[i] == ans[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = ans[i] + ans[j] + ans[k];
            if(sum < 0){
                j++;
            } else if(sum > 0){
                k--;
            } else {
                vector<int> temp = {ans[i],ans[j],ans[k]};
                nums.push_back(temp);
                j++;
                k--;
                while(j<k && ans[j] == ans[j-1]) j++;
                while(j<k && ans[k] == ans[k+1]) k--;
            }
        }
    }
    return nums;
    }

int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    // cout << funcNCR(4-1,3-1) << endl;
    // nthRow(6,3);

    vector<int> res = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSumProblemBetter(res);

    for(auto it: ans){
        for(auto i: it){
            cout << i << " ";
        }
    }
    cout << endl;

    vector<vector<int>> ans1 = threeSum(res);

    for(auto it: ans1){
        for(auto i: it){
            cout << i << " ";
        }
    }









    return 0;
}