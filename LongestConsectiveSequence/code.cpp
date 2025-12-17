#include<bits/stdc++.h>

using namespace std;

bool linearSearch(vector<int> &arr,int x){
    int n = arr.size();
    for(int i{0};i<n;i++){
        if(arr[i] == x){
            return true;
        }
    }
    return false;
}

int lenConsectiveSequenceBF(vector<int> arr){
    int n = arr.size();
    int longest = 1;

    for(int i{0};i<n;i++){
        int x = arr[i];
        int count = 1;
        while(linearSearch(arr,x+1) == true){
            count++;
            x = x+1;
        }
        longest = max(count,longest);
    }
    return longest;
}
int lenConsectiveSequenceB(vector<int> &arr){
    int n = arr.size();
    int longest = 1;
    int count = 0;
    int lastSmaller = INT_MIN;

    sort(arr.begin(),arr.end());

    for(int i{0};i<n;i++){
        if(arr[i]-1==lastSmaller){
            count++;
            lastSmaller = arr[i];
        } else if(arr[i] != lastSmaller){
            count = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest,count);
    }
    return longest;
}

int lenConsectiveSequenceOP(vector<int> &arr){
    int n = arr.size();
    int longest = 1;
    unordered_set<int> st;

    //add elements to the set
    for(int i{0};i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1)!= st.end()){
                cnt++;
                x = x+1;
            }
            longest = max(cnt,longest);
        }
    }
    return longest;
}




int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    vector<int> arr = {100,102,100,101,101,4,3,2,3,2,1,1,1,2};
    cout << lenConsectiveSequenceOP(arr) << endl;




    return 0;
}