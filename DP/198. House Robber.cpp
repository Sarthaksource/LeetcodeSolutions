/*class Solution {

// Memoization - O(n) tc, O(n) + O(n) sc

private:
    int helper(vector<int>& nums, int n, vector<int>& dp)
    {
        if(n==0) return nums[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick = nums[n] + helper(nums, n-2, dp);
        int not_pick = 0 + helper(nums, n-1, dp);

        return dp[n] = max(pick, not_pick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, n-1, dp);
    }
};*/

/*
class Solution {

// Tabulation - O(n) tc, O(n) sc

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            int pick = nums[i];
            if(i-2>=0)
            {
                pick = nums[i] + dp[i-2];
            }
            int not_pick = 0 + dp[i-1];

            dp[i] = max(pick, not_pick);
        }

        return dp[n-1];
    }
};*/


class Solution {

// Space optimized - O(n) tc, O(1) sc

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev, val = nums[0];
        for(int i=1; i<n; i++)
        {
            int pick = nums[i];
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
};
