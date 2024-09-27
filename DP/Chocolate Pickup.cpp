/*#include <bits/stdc++.h> 

// Memoization - O(r*c*c) *9 tc, O(r) + O(r*c*c) sc

int helper(vector<vector<int>> &grid, int i, int j1, int j2, vector<vector<vector<int>>>& dp)
{
    if(j1<0 || j1>grid[i].size()-1 || j2<0 || j2>grid[i].size()-1) return INT_MIN;
    if(i==grid.size()-1)
    {
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2]; 
    int maxVal = 0;
    for(int aj1=-1; aj1<=1; aj1++)
    {
        for(int aj2=-1; aj2<=1; aj2++)
        {
            int call = helper(grid, i+1, j1+aj1, j2+aj2, dp);
            if(j1==j2) maxVal = max(maxVal, call+grid[i][j1]);
            else maxVal = max(maxVal, call+grid[i][j1]+grid[i][j2]);
        }
    }

    return dp[i][j1][j2] = maxVal;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, (vector<vector<int>>(c, vector<int>(c, -1))));
    return helper(grid, 0, 0, c-1, dp);
}*/


#include <bits/stdc++.h> 

// Tabulation - O(r*c*c)*9 tc, O(r*c*c) sc

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, (vector<vector<int>>(c, vector<int>(c, -1))));

    for(int j1=0; j1<c; j1++)
    {
        for(int j2=0; j2<c; j2++)
        {
            if(j1==j2) dp[r-1][j1][j2] = grid[r-1][j1];
            else dp[r-1][j1][j2] = grid[r-1][j1]+grid[r-1][j2]; 
        }
    }

    for(int i=r-2; i>=0; i--)
    {
        for(int j1=0; j1<c; j1++)
        {
            for(int j2=0; j2<c; j2++)
            {
                int maxVal = 0;
                for(int aj1=-1; aj1<=1; aj1++)
                {
                    for(int aj2=-1; aj2<=1; aj2++)
                    {
                        int call = INT_MAX;
                        if(j1+aj1>=0 && j1+aj1<c && j2+aj2>=0 && j2+aj2<c)
                        {
                            call = dp[i+1][j1+aj1][j2+aj2];
                        }
                        if(j1==j2) maxVal = max(maxVal, call+grid[i][j1]);
                        else maxVal = max(maxVal, call+grid[i][j1]+grid[i][j2]);
                    }
                }
                dp[i][j1][j2] = maxVal;       
            }
        }        
    }
    
    return dp[0][0][c-1];
}
