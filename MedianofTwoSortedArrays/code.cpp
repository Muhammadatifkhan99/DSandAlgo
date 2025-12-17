#include<bits/stdc++.h>

using namespace std;
//Median of two sorted arrays of different sizes

//brute force 
long double medianSortedArray(vector<int> &arr1,vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    
    vector<int> ans;

    
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        } else {
            ans.push_back(arr2[j++]);
        }
    }
    while(i<n1){
        ans.push_back(arr1[i++]);
    }
    while(j<n2){
        ans.push_back(arr2[j++]);
    }
    int n = n1 + n2;
    if(n%2 == 1){
        return ans[n/2];
    }
    return (double)((double)(ans[n/2])+(double)(ans[n/2]-1))/2.0;
}

long double medianSortedArrayB(vector<int> &a,vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();

    int i = 0,j= 0;
    int n = (n1+n2);
    int ind2 = (n/2);
    int ind1 = ind2 -1;
    int cnt = 0;

    int ind1el = -1;
    int ind2el = -1;

    while(i<n1 && j<n2) {
        if(a[i] > b[i]){
            if(cnt==ind1) ind1el = a[i];
            if(cnt==ind2) ind2el = a[i];
            cnt++;
            i++;
        } else {
            if(cnt==ind1) ind1el = b[i];
            if(cnt==ind2) ind1el = b[i];
            cnt++;
            j++;
        }
    }
    //check if there any elements in a array
    while(i<n1){ 
        if(cnt==ind1) ind1el = a[i];
        if(cnt==ind2) ind2el = a[i];
        cnt++;
        i++;
    }

    while(j<n1){ 
        if(cnt==ind1) ind1el = b[j];
        if(cnt==ind2) ind2el = b[j];
        cnt++;
        j++;
    }
    if(n%2 == 1) return ind2el;
    return (double)((double)(ind1el+ind2el))/2.0;
}

long double median(vector<int> &a, vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();

    if(n1>n2) return median(b,a); //make sure the shorter array is used for BS
    int low = 0;
    int high = n1;
    int left = (n1+n2+1)/2;
    int n= n1+n2;
    while(low <= high){
        int mid1 = (low+high)/2;
        int mid2 = left-mid1;
        int l1 = INT_MIN; 
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1-1 >= 0) l1 = a[mid1 -1];
        if(mid2 -1 >= 0) l2 = b[mid2-1];
        if(l1 <= r2 && l2<=r1) {
            if(n%2 == 1)return max(l1,l2);
            return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
        } else if(l1>r2) high = mid1-1;
        else low=mid1+1;
    }
    return 0;
}




int main(){

    //###################################################################
    cout<<"Play ground is up" << endl;
    cout << endl;
    //###################################################################

    vector<int> ans = {1,3,4,7,10,12};
    vector<int> ans1 = {2,3,6,15};
    cout << medianSortedArray(ans,ans1) << endl;
    cout << medianSortedArray(ans,ans1) << endl;
    cout << median(ans,ans1) << endl;

    

    return 0;
}