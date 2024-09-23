/*
class Solution {

// Memoization - O(m*n) tc, O(m-1 + n-1) + O(m*n) sc

private:
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp)
    {
        if(i<0 || j<0) return 1e9;
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up = helper(grid, i-1, j, dp) + grid[i][j];
        int left = helper(grid, i, j-1, dp) + grid[i][j];

        return dp[i][j] = min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(grid, m-1, n-1, dp);
    }
};*/

/*
class Solution {

// Tabulation - O(m*n) tc, O(m*n) sc

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else
                {
                    int up = 1e9, left = 1e9;
                    if(i>0) up = dp[i-1][j] + grid[i][j];
                    if(j>0) left = dp[i][j-1] + grid[i][j];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};*/


class Solution {

// Space Optimization - O(m*n) tc, O(n) sc

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, -1);
        for(int i=0; i<m; i++)
        {
            vector<int> cur(n, -1);
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0) cur[j] = grid[i][j];
                else
                {
                    int up = 1e9, left = 1e9;
                    if(i>0) up = prev[j] + grid[i][j];
                    if(j>0) left = cur[j-1] + grid[i][j];
                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};
