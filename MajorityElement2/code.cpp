#include<bits/stdc++.h>

using namespace std;


//calculating the majority element n/3 times the size of the array

vector<int> majorityElement(vector<int> &ans){
    vector<int> res;
    for(int i{0};i<ans.size();i++){
        if(res.size() == 0 || res[0] != ans[i]){
            int count = 0;
            for(int j{0};j<ans.size();j++){
                if(ans[j] == ans[i]){
                    count++;
                }
                if(count > ans.size()/3){
                res.push_back(ans[i]);
                }
            }
        }
        if(res.size() == 2) break;
    }
    return res;
}


vector<int> majorityElementBetter(vector<int> &ans){
    vector<int> ls;
    map<int,int> mpp;
    int n = ans.size();
    int mm = (int)(n/3)+1;
    for(int i{0};i<n;i++){
        mpp[ans[i]]++;
        if(mpp[ans[i]] == mm){
            ls.push_back(ans[i]);
        }
        if(ls.size() == 2) break;
    }
    // sort(ls.begin(),ls.end());
    return ls;
}

vector<int> majorityElementOP(vector<int> &ans){
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    int n = ans.size();

    int cnt1 = 0;
    int cnt2 = 0;

    for(int i{0};i<n;i++){
        if(cnt1 == 0 && el2 != ans[i]){
            cnt1 = 1;
            el1 = ans[i];
        }
        else if(cnt2 == 0 && el1 != ans[i]){
            cnt2 = 1;
            el2 = ans[i];
        }
        else if(el1 == ans[i]) cnt1++;
        else if(el2 == ans[i]) cnt2++;
        else cnt1--,cnt2--;
    }
    vector<int> ls;
    cnt1 = 0;
    cnt2 = 0;
    for(int i{0};i<n;i++){
        if(el1 == ans[i]) cnt1++;
        if(el2 == ans[i]) cnt2++;
    }
    if(cnt1 >= (int)(n/3)+1) ls.push_back(el1);
    if(cnt2 >= (int)(n/3)+1) ls.push_back(el2);
    sort(ls.begin(),ls.end());
    return ls;
}


int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    // cout << funcNCR(4-1,3-1) << endl;
    // nthRow(6,3);

    vector<int> res = {1,3,3,3,2,2,2};
    vector<int> ans = majorityElementOP(res);

    for(auto it: ans){
        cout << it << " ";
    }









    return 0;
}