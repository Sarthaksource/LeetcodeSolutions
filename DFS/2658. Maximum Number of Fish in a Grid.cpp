class Solution {
private:
    int maxFish = 0;
    void dfs(vector<vector<int>>& grid, int r, int c, int* maxVal)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        (*maxVal) += grid[r][c];
        grid[r][c]=0;
        if(r-1>=0 && grid[r-1][c]>0) dfs(grid, r-1, c, maxVal);
        if(r+1<nr && grid[r+1][c]>0) dfs(grid, r+1, c, maxVal);
        if(c-1>=0 && grid[r][c-1]>0) dfs(grid, r, c-1, maxVal);
        if(c+1<nc && grid[r][c+1]>0) dfs(grid, r, c+1, maxVal);
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        int maxVal = 0;
        for(int r=0; r<nr; r++)
        {
            for(int c=0; c<nc; c++)
            {
                maxVal = 0;
                if(grid[r][c]>0)
                {
                    dfs(grid, r, c, &maxVal);
                    maxFish = max(maxFish, maxVal);
                }
            }
        }
        return maxFish; 
    }
};
