#include<bits/stdc++.h>

using namespace std;
//Minimise Maximum Distance Between Gas Stations

long double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size();

    vector<int> howMany(n-1,0);
    for(int gasStations = 1;gasStations <= k;gasStations++){
        long double maxSection = -1;
        int maxIndex= -1;
        for(int i{0};i<n-1;i++){
            long double diff = (arr[i+1] - arr[i]);
            long double sectionLength = diff/(long double)(howMany[i]+1);
            if(sectionLength > maxSection){
                maxSection = sectionLength;
                maxIndex = i;
            }
        }
        howMany[maxIndex]++;

    }
    long double maxAns = -1;
    for(int i{0};i<n-1;i++){
        long double diff = (arr[i+1] - arr[i]);
        long double sectionLength = diff / (long double) (howMany[i]+1);
        maxAns = max(maxAns,sectionLength);
    }
    return maxAns;
}

long double minimiseMaxDistancePQ(vector<int> &arr,int k){
    int n = arr.size();
    vector<int> howMany(n-1,0);
    priority_queue<pair<long double,int>> pq;
    for(int i{0};i<n-1;i++){
        pq.push({arr[i+1]-arr[i],i});
    }
    for(int gasStation=1;gasStation<=k;gasStation++){
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd+1] - arr[secInd];
        long double newSectionLen = iniDiff / (long double) (howMany[secInd]+1);
        pq.push({newSectionLen,secInd});
    }
    return pq.top().first;
}

//optimal solution

int numberOfGasStationRequired(int mid ,vector<int> &arr){
    long cnt = 0;
    for(int i{1};i<arr.size();i++){
        int numberInBetween = ((arr[i]-arr[i-1])/mid);
        if((arr[i] - arr[i-1])/mid == numberInBetween*mid){
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistanceBS(vector<int> &arr,int k){
    int n= arr.size();
    long double low = 0;
    long double high = 0;

    for(int i{0};i<n-1;i++){
        high = max(high,(long double)(arr[i+1]-arr[i]));
    }
    long double diff = 1e-6;
    while(high - low > diff){
        long double mid = low + high/2.0;
        int cnt = numberOfGasStationRequired(mid,arr);
        if(cnt > k){
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}


int main(){

    //###################################################################
    cout<<"Play ground is up" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {1,13,17,23};
    int k = 5;
    cout << minimiseMaxDistance(ans,k) << endl;
    cout << minimiseMaxDistancePQ(ans,k) << endl;
    cout << minimiseMaxDistanceBS(ans,k) << endl;
    // cout << findMissingNumberBS(ans,5) << endl;
    

    return 0;
}