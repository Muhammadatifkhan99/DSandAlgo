#include<bits/stdc++.h>

using namespace std;

// int freq(char c,string s){
//     int count = 0;
//     for(int i=0;i<s.size();i++){
//         if(c == s[i]){
//             count++;
//         }
//     }
//     return count;
// }

// vector<int> freq1(string s){
//     vector<int> hashh(s.size()+1,0);
//     for(int i{0};i<s.size();i++){
//         hashh[s[i] - 'a'] +=1;
//     }
//     return hashh;
// }

int main(){

    // for(auto it: freq1("abcabegc")){
    //     cout << it << endl;
    // }
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    //prestoring;;;;;;;;;;;;;;;
    // map<int,int> mpp;
    unordered_map<int,int> mpp;

    for(int i{0};i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto it: mpp){
    cout << it.first << " -> " << it.second << endl;
}
    

    int q;
    cin >>q;

    while(q--){
        int num;
        cin >> num;
        ///fetching
        cout << mpp[num] << endl;
    }


    return 0;
}