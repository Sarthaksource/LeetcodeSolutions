#include <bits/stdc++.h> 

/*

// Memoization - O(n) tc, O(n) + O(n) sc

int helper(int n, vector<int>& heights, vector<int>& dp)
{
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int left = helper(n-1, heights, dp) + abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n>1)
    {
        right = helper(n-2, heights, dp) + abs(heights[n]-heights[n-2]);
    }
    return dp[n] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return helper(n-1, heights, dp);
}*/

/*

// Tabulation - O(n) tc, O(n) sc

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int i=1; i<=n; i++)
    {
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1)
        {
            right = dp[i-2] + abs(heights[i]-heights[i-2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n-1];
}*/


// Space Optimized - O(n) tc, O(1) sc

int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0, prev2, val;
    for(int i=1; i<n; i++)
    {
        int left = prev1 + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1)
        {
            right = prev2 + abs(heights[i]-heights[i-2]);
        }
        val = min(left, right);
        prev2 = prev1;
        prev1 = val;
    }
    return val;
}
