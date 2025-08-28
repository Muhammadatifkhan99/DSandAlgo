#include<bits/stdc++.h>

using namespace std;


//merge two sorted arrays without extra space

void merge(vector<int> &arr1,vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();

    vector<int> ans;
    int left = 0;
    int right = 0;
    int index = 0;

    while (left < n && right < m){
        if(arr1[left] <= arr2[right]) {
            ans.push_back(arr1[left]);
            left++,index++;
        } else {
            ans.push_back(arr2[right]);
            index++,right++;
        }
    }
    while(left < n){
        ans.push_back(arr1[left]);
        index++,left++;
    }
    while(right < m){
        ans.push_back(arr2[right]);
        index++,right++;
    }
    
    for(int i{0};i<n+m;i++){
        if(i<n) arr1[i] = ans[i];
        else arr2[i-n] = ans[i];
    }
}


///OPTIMAL SOLUTION 1

void mergeOP1(vector<int> &arr1,vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();

    int start = 0;
    int end = n-1; //for arr1 we have to start from the last element

    while(start < m && end > 0){
        if(arr1[end] >arr2[start]){
            swap(arr1[end],arr2[start]);
            start++;
            end--;
        } else start++,end--;
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}

void mergeOP2(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();

    int len = n + m;
    int gap = (len/2) + (len % 2);

    while(gap > 0){
        int left = 0;
        int right = left + gap;

        while(right < len){
            //let check where the pointers are
            if(left < n && right >= n){
                //swap between two arrays, arr1,arr2
                if(arr1[left] > arr2[right-n]){
                    swap(arr1[left],arr2[right-n]);
                }
            } else if (left >= n){
                if(arr2[left-n] > arr2[right-n]){
                    swap(arr2[left-n],arr2[right-n]);
                }
            } else {
                if(arr1[left] > arr1[right]){
                    swap(arr1[left],arr1[right]);
                }
            }
            left++;
            right++;
        }
        if(gap == 1) break;

        gap = (gap/2) + (gap%2);
    }
}



int main(){

    //###################################################################
    cout<<"Play ground is up and running, just Code !!!" << endl;
    cout << endl;
    //###################################################################

    // cout << funcNCR(4-1,3-1) << endl;
    // nthRow(6,3);
    vector<int> arr1 = {1,3,5,7};
    vector<int> arr2 = {0,2,6,8,9};

    mergeOP2(arr1,arr2);
    for(auto it: arr1){
        cout << it << " ";
    }
    cout << endl;
    cout << "Array 2 Elements" << endl;
    
    for(auto it: arr2){
        cout << it << " ";
    }








    return 0;
}