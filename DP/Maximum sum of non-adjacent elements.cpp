#include <bits/stdc++.h> 

/*

// Memoization - O(n) tc, O(n) + O(n) sc

int helper(vector<int> &nums, int i, vector<int> &dp)
{
    if(i==0) return nums[i];
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];

    int pick = nums[i] + helper(nums, i-2, dp);   
    int not_pick = 0 + helper(nums, i-1, dp);   
    
    return dp[i] = max(pick, not_pick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1, -1);
    return helper(nums, n-1, dp);
}
*/

/*

// Tabulation - O(n) tc, O(n) sc

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1, -1);
    dp[0] = nums[0];
    for(int i=1; i<=n; i++)
    {
        int pick = nums[i] + 0;
        if(i-2>=0)
        {
            pick = nums[i] + dp[i-2];
        }
        int not_pick = 0 + dp[i-1];

        dp[i] = max(pick, not_pick);
    }
    return dp[n-1];
}*/


// Space Optimized - O(n) tc, O(1);

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev, val = nums[0];
    for(int i=1; i<n; i++)
    {
        int pick = nums[i] + 0;
        if(i-2>=0)
        {
            pick = nums[i] + prev;
        }
        int not_pick = 0 + val;

        prev = val;
        val = max(pick, not_pick);
    }
    return val;
}
