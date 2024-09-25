/*
class Solution {

// Memoization - O(n*n) tc, O(n) + O(n*n) sc

private:
    int helper(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp)
    {
        if(i>triangle.size()-1 || j>triangle[i].size()-1) return INT_MAX;
        if(i==triangle.size()-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = helper(triangle, i+1, j, dp);
        int diagonal = helper(triangle, i+1, j+1, dp);

        return dp[i][j] = min(down, diagonal) + triangle[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        return helper(triangle, 0, 0, dp);
    }
};
*/

/*
class Solution {

// Tabulation - O(n*n) tc, O(n*n) sc

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
        int n = triangle.size();
        dp[n-1] = triangle[n-1];
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];

                dp[i][j] = min(down, diagonal) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
*/

class Solution {

// Space Optimization - O(n*n) tc, O(n) sc

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> next(n, -1);
        next = triangle[n-1];
        
        for(int i=n-2; i>=0; i--)
        {
            vector<int> cur(n, -1);
            for(int j=i; j>=0; j--)
            {
                int down = next[j];
                int diagonal = next[j+1];

                cur[j] = min(down, diagonal) + triangle[i][j];
            }
            next = cur;
        }
        return next[0];
    }
};
