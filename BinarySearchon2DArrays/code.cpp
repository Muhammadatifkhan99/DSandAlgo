#include<bits/stdc++.h>

using namespace std;
vector<int> rowAndMaximumOnesLeetCode(vector<vector<int>>& mat) {
        int n = mat.size();
        int countMax = 0;
        int index = 0;

        for (int i = 0; i < n; i++) {
            int countOnes = 0;
            for (int val : mat[i]) {
                if (val == 1) countOnes++;
            }

            if (countOnes > countMax) {
                countMax = countOnes;
                index = i;
            }
        }

        return {index, countMax};
    }

int lowerBound(vector<int> &mat, int x) {
        int m = mat.size();
        int low = 0, high = m - 1, ans = m;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (mat[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

int rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();

        int countMax = 0;
        int index = 0;

        for (int i = 0; i < n; i++) {
            int m = mat[i].size();   // compute per row
            if (m == 0) continue;

            int firstOne = lowerBound(mat[i], 1);
            int countOnes = m - firstOne;

            if (countOnes > countMax) {
                countMax = countOnes;
                index = i;
            }
        }

        return index;
    }





int main(){

    //###################################################################
    cout<<"Play ground is up" << endl;
    cout << endl;
    //###################################################################

    // vector<int> ans = {2,3,6,7,9};
    // vector<int> ans1 = {1,4,8,10};
    // cout << median(ans,ans1,4) << endl;

    vector<vector<int>> arr = { {0,0,1,1,1},
                                {0,0,0,0,0},
                                {0,0,0,0,0},
                                {0,0,0,0,0},
                                {0,1,1,1,1}
                                            };
    int target = 4;
    cout << rowAndMaximumOnes << endl;
    

    return 0;
}