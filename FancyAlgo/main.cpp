//
//  main.cpp
//  FancyAlgo
//
//  Created by Yixuan Tan on 11/21/16.
//  Copyright © 2016 Yixuan Tan. All rights reserved.
//

/*
Lintcode 43 Maximum subarray III
Given an array of integers and a number k, find k non-overlapping subarrays which have the largest sum.
The number in each subarray should be contiguous.
Return the largest sum.
*/


// Solution 1 (25ms)
// time O(N^2)
// idea: local[i][j]   the i-th element must be selected
//       global[i][j]  the i-th  element not necessarily be selected

int maxSubArray(vector<int> nums, int k) {
    int n = nums.size();
    vector<vector<int>> g(n + 1, vector<int>(k + 1, INT_MIN)); // because of using max() later, initialize with INT_MIN;
    vector<vector<int>> l(n + 1, vector<int>(k + 1, INT_MIN));
    
    // from i elements select 0 subarray, what is the sum => 0;
    for (int i = 0; i <= n; i++) {
        g[i][0] = 0;
        l[i][0] = 0;
    }
    
    // from 0 element select i subarry, it is nonsense. INT_MIN;
    
    // recurrence
    for (int j = 1; j <= k; j++) {
        for (int i = j; i <= n; i++) {
            l[i][j] = max(g[i-1][j-1], l[i-1][j]) + nums[i - 1];
            g[i][j] = max(g[i-1][j], l[i][j]);
        }
    }
    
    return g[n][k];
}



// Solution 2 (71ms)
// time O(N^2)
// idea from http://www.meetqun.com/thread-10347-1-1.html
// recurrence:  dp[i][j][0/1]: from first i elements select j subarray, the sum is what? 0 means i-th element is not selected, 1 otherwise.
// notes: 1. creat another dimension to track the information: if the i-th element is selected or not for dp[i][j][0/1]

int maxSubArray(vector<int> nums, int k) {
    int n = nums.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, INT_MIN))); // dp[i][j][0/1] 从前i个数中选出j个subarrays，第3个index 为0表示第i个数不被选中，为1表示被选中。
    for (int i = 0; i <= n; i++) {
        dp[i][0][0] = 0;
        dp[i][0][1] = 0;
    }
    
    for (int j = 1; j <= k; j++) {
        for (int i = j; i <= n; i++) {
            dp[i][j][0] = max(dp[i-1][j][1], dp[i-1][j][0]);
            dp[i][j][1] = max(dp[i-1][j-1][0], max(dp[i-1][j-1][1], dp[i-1][j][1])) + nums[i - 1];
        }
    }
    return max(dp[n][k][0], dp[n][k][1]);
}


