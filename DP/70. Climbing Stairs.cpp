/*class Solution {

Memoization - O(n) tc, O(n) + O(n) sc

private:
    int helper(int n, vector<int>& dp)
    {
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = helper(n-1, dp) + helper(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};*/


/*class Solution {

// Tabulation - O(n) tc, O(n) sc

public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1; dp[1] = 1;
        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};*/


class Solution {

//Space Optimized - O(n) tc, O(1) sc

public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int prev1 = 1, prev2 = 1, val;
        for(int i=2; i<=n; i++)
        {
            val = prev1 + prev2;
            prev2 = prev1;
            prev1 = val;
        }
        return val;
    }
};
