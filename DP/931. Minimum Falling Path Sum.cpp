/*
class Solution {

// Memoization - O(n*n) tc, O(n) + O(n*n) sc

private:
    int helper(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp)
    {
        if(i==matrix.size()-1 && (j<=matrix[i].size()-1 && j>=0)) return matrix[i][j];
        if(j>matrix[i].size()-1 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = helper(matrix, i+1, j, dp);
        int diagonalLeft = helper(matrix, i+1, j-1, dp);
        int diagonalRight = helper(matrix, i+1, j+1, dp);

        return dp[i][j] = min(down, min(diagonalLeft, diagonalRight)) + matrix[i][j];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minVal = INT_MAX;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), -1));
        for(int i=0; i<matrix.size(); i++)
        {
            minVal = min(minVal, helper(matrix, 0, i, dp));
        }
        return minVal;
    }
};
*/

/*
class Solution {

// Tabulation - O(n*n) tc, O(n*n) sc

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), -1));

        int n = matrix.size();
        dp[n-1] = matrix[n-1];
        for(int i=n-2; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                int down = INT_MAX;
                int diagonalLeft = INT_MAX;
                int diagonalRight = INT_MAX;

                down = dp[i+1][j];
                if(j>0) diagonalLeft = dp[i+1][j-1];
                if(j<n-1) diagonalRight = dp[i+1][j+1];
            
                dp[i][j] = min(down, min(diagonalLeft, diagonalRight)) + matrix[i][j];
            }
        }

        int minVal = INT_MAX;
        for(int i=0; i<n; i++)
        {
            minVal = min(minVal, dp[0][i]);
        }
        return minVal;
    }
};
*/


class Solution {

// Space Optimized - O(n*n) tc, O(n) sc

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> next(matrix.size(), -1);

        int n = matrix.size();
        next = matrix[n-1];
        for(int i=n-2; i>=0; i--)
        {
            vector<int> cur(matrix.size(), -1);
            for(int j=n-1; j>=0; j--)
            {
                int down = INT_MAX;
                int diagonalLeft = INT_MAX;
                int diagonalRight = INT_MAX;

                down = next[j];
                if(j>0) diagonalLeft = next[j-1];
                if(j<n-1) diagonalRight = next[j+1];
            
                cur[j] = min(down, min(diagonalLeft, diagonalRight)) + matrix[i][j];
            }
            next = cur;
        }

        int minVal = INT_MAX;
        for(int i=0; i<n; i++)
        {
            minVal = min(minVal, next[i]);
        }
        return minVal;
    }
};
