#include<bits/stdc++.h>

using namespace std;

// ///left rotate an array by one place

// void leftRotatArray(vector<int> &arr){
//     int n = arr.size();
//     int first = arr[0];
//     for(int i=1;i<n;i++){
//         arr[i-1] = arr[i];
//     }
//     arr[n-1] = first;
// }

// //rotate an array by d places 

// void rotateDplaces(vector<int> &arr,int d){
//     int n = arr.size();
//     vector<int> temp;
//     for(int i{0};i<d;i++){
//         temp.push_back(arr[i]);
//     }
//     for(int i{0};i<n-d;i++){
//         arr[i] = arr[d+i];
//     }
//     for(int i{0};i<d;i++){
//         arr[n-d+i] = temp[i];
//     }
// }

// //optimal solution to rotating array by kth places

// void rotateArray(vector<int> &arr,int d){
//     int n = arr.size();
//     int start = 0;
//     int end = d-1;
//     while(start <= end){
//         swap(arr[start],arr[end]);
//         start++;
//         end--;
//     }
//     start = d;
//     end = n-1;
//     while(start <= end){
//         swap(arr[start],arr[end]);
//         start++;
//         end--;
//     }
//     start = 0;
//     end = n-1;
//     while(start <= end){
//         swap(arr[start],arr[end]);
//         start ++;
//         end--;
//     }

// }

// //right rotating an array 

// void rightrotateArray(vector<int> &arr,int d){
//     int n = arr.size();
//     vector<int> temp;

//     for(int i{0};i<n-d-1;i++){
//         temp.push_back(arr[n-d+i]);
//     }
//     for(int i{0};i<n-d;i++){
//         temp.push_back(arr[i]);
//     }
//     //copy all the values to the original array

//     for(int i{0};i<n;i++){
//         arr[i] = temp[i];
//     }
// }

// void optimalrotateArray(vector<int> &arr,int d){
//     int n = arr.size();

//     int start = n-d;
//     int end = n-1;

//     while(start <= end){ //d can be equal to n so O(n);
//         swap(arr[start],arr[end]);
//         start++;
//         end--;
//     }
//     start = 0;
//     end = d;
//     while (start <= end)
//     {
//         swap(arr[start],arr[end]);
//         start ++;
//         end --;
//     }
//     start = 0;
//     end = n-1;

//     while(start <= end){
//         swap(arr[start],arr[end]);
//         start ++;
//         end --;
//     }
// }

// //move all the non zero elements to the end of the array 


// void moveNonZeros(vector<int> &arr){
//     int n1 = arr.size();
//     vector<int> temp;

//     //add the non zero values to the temp array 
//     for(int i{0};i<n1;i++){
//         if(arr[i] != 0){
//             temp.push_back(arr[i]);
//         }
//     }
//     int n2 = temp.size();
//     //move the temp values back to the original array 
//     for(int i{0};i<n2;i++){
//         arr[i] = temp[i];
//     }
//     //copy add the last zeros back to the original array 
//     for(int i{0};i<n1-n2;i++){
//         arr[n2+i]  = 0;
//     }
// }

// //optimal solution for nonzeros

// void moveNonZero(vector<int> &arr){
//     int n = arr.size();

//     int i=1;
//     int j=0;
//     while (i<n)
//     {
//         if(arr[j] == 0 && arr[i] != 0){
//             swap(arr[i],arr[j]);
//             i++,j++;
//         } else if(arr[j] == 0){
//             i++;
//         } else {
//             i++,j++;
//         }
//     }
    
// }

// //union of two sorted arrays

// vector<int> unionArraysBF(vector<int> arr1,vector<int> arr2){
//     set<int> s;
//     for(int i{0};i<arr1.size();i++){
//         s.insert(arr1[i]);
//     }
//     for(int i{0};i<arr2.size();i++){
//         s.insert(arr2[i]);
//     }
//     vector<int> uArr;
//     for(auto it: s){
//         uArr.push_back(it);
//     }
//     return uArr;

// }

// //union of two arrays using optimal solution

// vector<int> unionofArraysOP(vector<int> a,vector<int> b){
//     int n1 = a.size();
//     int n2 = b.size();
    
//     vector<int> unArr;

//     int i=0;
//     int j=0;

//     while(i < n1 && j < n2){
//         if(a[i] <= b[j]){
//             if(unArr.size() == 0 || unArr.back() != a[i]) {
//                 unArr.push_back(a[i]);
//             }
//             i++;
//         } 
//         else{
//             if(unArr.size() == 0 || unArr.back() != b[j]) {
//                 unArr.push_back(b[j]);
//             }
//             j++;
//         }
//     }
//     while(j<n2){
//         if(unArr.size() == 0 || unArr.back() != b[j]){
//                 unArr.push_back(b[j]);
//         }
//         j++;
//     }
//     while(i<n1){
//         if(unArr.size() == 0 || unArr.back() != a[i]){
//                 unArr.push_back(a[i]);
//         }
//         i++;
//     }

//     return unArr;

// }
// //intersection of two arrays using brute force approach

// vector<int> intersect(vector<int> a,vector<int> b){
//     int n1 = a.size();
//     int n2 = b.size();
//     vector<int> ans;
//     vector<int> vis(n2,0);

//     for(int i{0};i<n1;i++){
//         for(int j{0};j<n2;j++){
//             if(a[i] == b[j] && vis[j] == 0){
//                 ans.push_back(a[i]);
//                 vis[j] = 1;
//                 break;
//             }
//             if(b[j] > a[i]){
//                 break;
//             }
//         }
//     }
//     return ans;
// }

// //optimal solution 

// vector<int> intersection(vector<int> a,vector<int> b){
//     int i = 0;
//     int j = 0;
//     vector<int> ans;
//     while(i < a.size() && j < b.size()){
//         if(a[i] == b[j]){
//             ans.push_back(a[i]);
//             i++,j++;
//         }
//         if(a[i] < b[j]){
//             i++;
//         }
//     }
//     return ans;
// }


// //brute force approach single elements

// int singleEl(vector<int> &arr){
//     for(int i{0};i<arr.size();i++){
//         int count = 0;
//         for(int j{0};j<arr.size();j++){
//             if(arr[i] == arr[j]){
//                 count ++;
//             }
//         }
//         if(count == 1){
//             return arr[i];
//         }
//     }
//     return -1;
// }
// //optimal solution to single sum

// int singleNumber(vector<int> array){
//     int ans {0};
//     for(auto val:array){
//         ans = ans ^ val;
//     }
//     return ans;
// }

// vector<int> twoSum(vector<int>& nums, int target) {
//     //brute force solution
//     for(int i{0};i<nums.size();i++){
//         for(int j{i+1};j<nums.size();j++){
//             if(nums[i] + nums[j] == target){
//                 return {i,j};
//             }
//         }
//     }
//     return {-1,-1};
// }

// vector<int> twoSumop(vector<int>& nums, int target) {
//     int start = 0;
//     int end = start + 1;
//     while(start < nums.size() && end < nums.size()){
//         if(nums[start] + nums[end] == target){
//             return {start,end};
//         }
//         end++;
//         start++;
//     }
//     return {-1,-1};
// }

// //printing all the subarrays

// void printAllSubArrays(vector<int> arr){
//     for(int st {0};st<arr.size();st++){
//         for(int end = st;end < arr.size(); end++){
//             for(int i= st;i<=end;i++){
//                 cout << arr[i];
//             }cout << " ";
//         }cout << endl;
//     }
// }

// //max subarray sum

// int subArraySum(vector<int> arr){
//     int maxSum {0};
//     for(int st{0};st<arr.size();st++){
//         int currSum {0};
//         for(int end{st};end<arr.size();end++){
//             currSum += arr[end];
//             maxSum = max(currSum,maxSum);
//         }
//     }
//     return maxSum;
// }

// ///kadane algorithms

// int maxSum(vector<int> arr){
//     int maxSum {0};
//     int currSum{0};
//     for(int i{0};i<arr.size();i++){
//         currSum += arr[i];
//         maxSum = max(maxSum,currSum);
//         if(currSum < 0){
//             currSum = 0;
//         }
//     }
//     return maxSum;
// }


// vector<int> pairSumBF(vector<int> nums,int target){
//     for(int i{0};i<nums.size();i++){
//         for(int j{i+1};j<nums.size();j++){
//             if(nums[i] + nums[j] == target){
//                 return{i,j};
//             }
//         }
//     }
//     return {-1,-1};
// }

// vector<int> pairSumOP(vector<int> nums,int target){
//     int i = 0;
//     int j = nums.size()-1;

//     while(i < j){
//         if(nums[i] + nums[j] > target){
//             j--;
//         }
//         if (nums[i] + nums[j] < target){
//             i++;
//         }
//         if(nums[i] + nums[j] == target){
//             return {i,j};
//         }
//     }
//     return {-1,-1};
// }

// int majorityElement(vector<int> nums){
//     int count {0};
//     for(int i{0};i<nums.size();i++){
//         for(int j{0};j<nums.size();j++){
//             if(nums[i] == nums[j]){
//                 count++;
//             }
//             if(count > nums.size()/2){
//                 return nums[i];
//         }
//         }
//     }
//     return -1;
// }


// int majorityElementB(vector<int> &nums){
//     sort(nums.begin(),nums.end());
//     int freq = 1;
//     int ans = nums[0];
//     for(int i{1};i<nums.size();i++){
//         if(nums[i] == nums[i-1]){
//             freq++;
//         }
//         else {
//             freq = 1;
//             ans = nums[i];
//         }
//     }
//     return ans;
// }

// string timeConversion(string s) {
//     if(s[8] == 'P'){
//         s[0] = s[0] + 1;
//         s[1] = s[1] + 2;
//         s.erase(8,2);
//     }
//     else {
//         s.erase(8,2);
//     }
//     if(s[0] == 1 && s[1] == 2){
//         s[0] = 0;
//         s[1] = 0;
//     }
//     return s;
// }

// //stock buy and sell problem

// int maxProfit(vector<int> &prices){
//     int smallest = INT_MAX;
//     for(int i{0};i<prices.size();i++){
//         if(prices[i] < smallest){
//             smallest = prices[i];
//         }
//     }
//     cout << smallest << endl;
//     int largest = INT_MIN;
//     for(int i{smallest};i<prices.size();i++){
//         if(prices[i] > largest){
//             largest = prices[i];
//         }
//     }
//     cout << largest << endl;
//     return largest - smallest;
// }

// //container with most water
// int maxWater(vector<int> ht){
//     int ans = 0;
//     int mWater = 0;
//     for(int i{0};i<ht.size();i++){
//         for(int j {i+1};j<ht.size();j++){
//             int w = 0;
//             w = j - i;
//             int h=0;
//             h = min(ht[i],ht[j]);
//             ans = w * h;
//             mWater = max(ans,mWater);
//         }
//     }
//     return mWater;
// }


// int maxArea(vector<int>& height) {
//         int maxWater = 0;
//         int lp = 0;
//         int rp = height.size() - 1;
//         while(lp < rp){
//             int w = rp - lp;
//             int ht = min(height[rp],height[lp]);
//             int area = w * ht;
//             maxWater = max(area,maxWater);
//             if(height[lp] < height[rp]){
//                 lp++;
//             } else rp--;
//         }
//         return maxWater;
// }

//find the missing numbers in an array 

int missingNum(vector<int> &arr,int N){
    int mNum = 1;
    for(int i{0};i<N;i++){
        if(arr[i] == mNum){
            mNum++;
        } else return mNum;
    }
    return -1;
}

///brute force approach
int missingNu(vector<int> &arr,int N){
    for(int i=1;i<N;i++){
        bool flag = 0;
        for(int j{0};j<arr.size();j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            return i;
        }
    }
    return -1;
}
//Better Approach
int missingN(vector<int> & arr,int N){
    vector<int> hashes(N+1,0);
    for(int i{0};i<N;i++){
        hashes[arr[i]]++;
    }
    for(int i{0};i<N;i++){
        if(hashes[i] == 0){
            return i;
        }
    }
    return -1;
}
//Optimal Solution
int missingNU(vector<int> &arr,int n){
    int sum = n*(n+1)/2;
    int s2 = 0;
    for(int i{0};i<n;i++){
        s2 += arr[i];
    }
    return sum - s2;
}
//Optimal Solution using XOR
int missingNUU(vector<int> &arr,int n){
    int XOR1 = 0;
    int XOR2 = 0;
    for(int i=1;i<=n;i++){
        XOR1 = XOR1 ^ i;
    }
    for(int i{0};i<n;i++){
        XOR2 = XOR2 ^ arr[i];
    }
    return XOR1 ^ XOR2;

}
//Optimal one loop XOR
int missingXOR(vector<int> &arr,int N){
    int XOR1 = 0;
    int XOR2 = 0;
    for(int i{0};i<N-1;i++){
        XOR2 = XOR2 ^ arr[i];
        XOR1 = XOR1 ^ (i+1);
    }
    XOR1 = XOR1 ^ N;
    return XOR1 ^ XOR2;
}

//finding elements that appear once in the array 

//1. Brute Force
int elementOnceA(vector<int> &arr){
    for(int i{0};i<arr.size();i++){
        int counter = 0;
        int num = 0;
        num = arr[i];
        for(int j{0};j<arr.size();j++){
            if(arr[j] == num){
                counter++;
            }
        }
        if(counter == 1){
            return num;
        }
    }
    return -1;
}
//hashing
int elementOnceB(vector<int> &arr){
    //1. first we need to find the max element in the give array and then hash it;
    int maxi = arr[0];
    for(int i{1};i<arr.size();i++){
        maxi = max(arr[i],maxi);
    }
    vector<int> hashes(maxi,0);
    for(int i{0};i<= maxi;i++){
        hashes[arr[i]]++;
    }
    for(int i=0;i<maxi;i++){
        if(hashes[arr[i]] == 1){
            return arr[i];
        }
    }
    return -1;
}
//optimal Solution using XOR Operations
int elementOnceC(vector<int> &arr){
    int ans = 0;
    for(auto it: arr){
        ans = ans ^ it;
    }
    return ans;
}

//subarray
void subarray(vector<int> &arr,int d){
    int len = 0;
    for(int i{0};i<arr.size();i++){
        int sum = 0;
        for(int j{i};j<arr.size();j++){
            for(int k{i};k<j;k++){
                sum += arr[k];
            }
            if(sum == d){
                len = max(len,j-i+1);
            }
        }
    }
    cout << len << endl;
}

void subarray1(vector<int> &arr,int k){
    int len = 0;
    for(int i{0};i<arr.size();i++){
        int sum = 0;
        for(int j{i};j<arr.size();j++){
            sum += arr[j];
            if(sum == k){
                len = max(len,j-i+1);
            }
        }
    }
    cout << len << endl;
}

int subArraySumK(vector<int> &arr,int k){
    map<long long, int> preSumMap;
    long long sum {0};
    int maxLen {0};
    for(int i{0};i<arr.size();i++){
        sum += arr[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen,len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
        preSumMap[sum] = i;
        }
    }
    return maxLen;
}

int subArraySumKOP(vector<int> &arr,int k){
    int left  = 0;
    int right = 0;
    long long sum = arr[0];
    int maxLen = 0;
    int n = arr.size();
    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen,right - left + 1);
        }
        right++;
        if(right < n) sum += arr[right];

    }
    return maxLen;
}

int main(){

    vector<int> arr = {1,2,3,1,1,1,1,3,3};
    cout << subArraySumK(arr,3)<<endl;
    cout << subArraySumKOP(arr,6)<<endl;







    // subarray(arr,3);
    // cout << endl;
    // subarray1(arr,3);





    // vector<int> arr = {1,1,2,2,8};
    // cout << elementOnceA(arr) << endl;
    // cout << elementOnceB(arr) << endl;
    // cout << elementOnceC(arr) << endl;




    // int n = 5;
    // cout << missingXOR(arr,n);


    // vector<int> arr = {1,8,6,2,5,4,8,3,7};
    // cout << maxWater(arr) << endl;
    // cout << maxArea(arr);

    // vector<int> prices = {7,1,5,3,6,4};
    // cout << maxProfit(prices);





    // cout << timeConversion("12:40:22PM");


    // vector<int> nums = {1,2,2,2,1};
    // cout << majorityElementB(nums) ;


    // vector<int> nums = {2,7,11,15};
    // for(auto it: pairSumBF(nums,9)){
    //     cout << it << " ";
    // }

    // for(auto it: pairSumOP(nums,9)){
    //     cout << it << " ";
    // }



    // vector<int> nums = {3,-4,5,4,-1,7,-8};/
    // printAllSubArrays(nums);
    // cout << maxSum(nums);
    // for(auto it: twoSumop(nums,17)){
    //     cout << it << endl;
    // }


    // vector<int> arr = {1,2,1,2,4};
    // cout << singleEl(arr) << endl;
    // cout << singleNumber(arr) << endl;



    // vector<int> arr1 = {1,2,2,3,3,4,5,6};
    // vector<int> arr2 = {2,3,3,5,6,6,7};
    // // int d = 3;
   
    // for(int it: intersect(arr1,arr2) ){
    //     cout << it << " ";
    // }


    // vector<int> arr = {1,2,3,4,5,6,7};
    // int d = 3;
    // optimalrotateArray(arr,d%arr.size());
    // for(int it: arr){
    //     cout << it << " ";
    // }

    return 0;
}