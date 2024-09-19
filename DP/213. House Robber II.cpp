/*
class Solution {

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
        if(n==1) return nums[0];
        vector<int> dp(n, -1);
        int lastLeft = helper(nums, n-2, dp);
        dp.clear();
        // nums.erase(nums.begin());
        nums[0] = 0;
        n = nums.size();
        dp.resize(n, -1);
        int firstLeft = helper(nums, n-1, dp);
        return max(firstLeft, lastLeft);
    }
};*/

/*
class Solution {

// Tabulation - O(n) tc, O(n) sc

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for(int i=1; i<n-1; i++)
        {
            int pick = nums[i];
            if(i-2>=0)
            {
                pick = nums[i] + dp[i-2];
            }
            int not_pick = 0 + dp[i-1];

            dp[i] = max(pick, not_pick);
        }
        int lastLeft = dp[n-2];
        dp.clear();
        dp.resize(n, -1);
        dp[0] = 0;
        for(int i=1; i<=n-1; i++)
        {
            int pick = nums[i];
            if(i-2>=0)
            {
                pick = nums[i] + dp[i-2];
            }
            int not_pick = 0 + dp[i-1];

            dp[i] = max(pick, not_pick);
        }
        int firstLeft = dp[n-1];

        dp[n-1] = max(lastLeft, firstLeft);

        return dp[n-1];
    }
};*/


class Solution {

// Space Optimized - O(n) tc, O(1) sc

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int val = nums[0], prev;
        for(int i=1; i<n-1; i++)
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
        int lastLeft = val;
        val = 0, prev = 0;
        for(int i=1; i<=n-1; i++)
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
        int firstLeft = val;

        val = max(lastLeft, firstLeft);

        return val;
    }
};
