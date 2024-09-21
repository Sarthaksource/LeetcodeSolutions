/*
class Solution {

// Memoization - O(m*n) tc, O(m-1 + n-1) + O(m*n) sc

private:
    int helper(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp)
    {
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = helper(obstacleGrid, i-1, j, dp);
        int left = helper(obstacleGrid, i, j-1, dp);

        return dp[i][j] = (up+left);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(obstacleGrid, m-1, n-1, dp);
    }
};
*/


class Solution {

// Tabulation - O(m*n) tc, O(m*n) sc

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j] = 1;
                }
                else if(i>0 && j>0 && obstacleGrid[i][j]==1) dp[i][j] = 0;
                else
                {
                    int left = 0, up = 0;
                    if(i>0 && obstacleGrid[i][j]!=1) up = dp[i-1][j];
                    if(j>0 && obstacleGrid[i][j]!=1) left = dp[i][j-1];

                    dp[i][j] = up+left;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
