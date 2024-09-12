class Solution {
private:
    int maxArea = 0;
    void dfs(vector<vector<int>>& grid, int r, int c, int* maxVal)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c]=0;
        (*maxVal)++;
        if(r-1>=0 && grid[r-1][c]==1) dfs(grid, r-1, c, maxVal);
        if(r+1<nr && grid[r+1][c]==1) dfs(grid, r+1, c, maxVal);
        if(c-1>=0 && grid[r][c-1]==1) dfs(grid, r, c-1, maxVal);
        if(c+1<nc && grid[r][c+1]==1) dfs(grid, r, c+1, maxVal);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        for(int r=0; r<nr; r++)
        {
            for(int c=0; c<nc; c++)
            {
                int maxVal = 0;
                if(grid[r][c]==1)
                {
                    dfs(grid, r, c, &maxVal);
                    maxArea = max(maxArea, maxVal);
                }
            }
        }
        return maxArea;        
    }
};
