/*class Solution {

// Memoization - O(m*n) tc, O(n-1 + m-1) + O(m*n) sc

private:
    int helper(int i, int j, vector<vector<int>>& dp)
    {
        if(i==0 || j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = helper(i, j-1, dp);
        int left = helper(i-1, j, dp);

        return dp[i][j] = (up + left);
    }
public:
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m, vector<int>(n, -1));
       return helper(m-1, n-1, dp); 
    }
};*/

class Solution {

// Tabulation - O(m*n) tc, O(m*n) sc

public:
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m, vector<int>(n, -1));
       for(int i=0; i<m; i++)
       {
            for(int j=0; j<n; j++)
            {
                if(i==0 || j==0) dp[i][j] = 1;
                else
                {
                    int left = 0, up = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
       }
        return dp[m-1][n-1];
    }
};
