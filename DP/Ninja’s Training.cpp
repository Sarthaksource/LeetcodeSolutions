/*

// Memoization - O(n*4)*3 tc, O(n) + O(n*4) sc

int helper(vector<vector<int>> &points, int n, int last, vector<vector<int>> &dp)
{
    int maxVal = 0;
    if(n==0)
    {
        for(int i=0; i<3; i++)
        {
            if(i!=last)
            {
                maxVal = max(maxVal, points[0][i]);
            }
        }
    }
    else if(dp[n][last]!=-1) return dp[n][last];
    else
    {
        for(int i=0; i<3; i++)
        {
            if(i!=last)
            {
                int temp = points[n][i] + helper(points, n-1, i, dp);
                maxVal = max(maxVal, temp);
            }
        }
    }
    return dp[n][last] = maxVal;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return helper(points, n-1, 3, dp);
}*/

/*
// Tabulation - O(n*4*3) tc, O(n*4) sc

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(max(points[0][0], points[0][1]), points[0][2]);
    
    for(int day=1; day<n; day++)
    {
        for(int last=0; last<4; last++)
        {
            for(int task=0; task<3; task++)
            {
                if(task!=last)
                {
                    int temp = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], temp);
                }
            }
        }
    }

    return dp[n-1][3];
}
*/

// Space Optimized - O(n*4*3) tc, O(1) sc

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(4, -1);

    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(max(points[0][0], points[0][1]), points[0][2]);
    
    for(int day=1; day<n; day++)
    {
        vector<int> temp(4, -1);
        for(int last=0; last<4; last++)
        {
            for(int task=0; task<3; task++)
            {
                if(task!=last)
                {
                    temp[last] = max(temp[last], points[day][task] + dp[task]);
                }
            }
        }
        dp = temp;
    }

    return dp[3];
}
