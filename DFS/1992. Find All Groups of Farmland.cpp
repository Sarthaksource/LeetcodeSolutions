class Solution {
private:
    int maxr = 0;
    int maxc = 0;
    void dfs(vector<vector<int>>& grid, int r, int c)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c]=0;
        maxr = max(maxr, r);
        maxc = max(maxc, c);
        if(r-1>=0 && grid[r-1][c]==1) dfs(grid, r-1, c);
        if(r+1<nr && grid[r+1][c]==1) dfs(grid, r+1, c);
        if(c-1>=0 && grid[r][c-1]==1) dfs(grid, r, c-1);
        if(c+1<nc && grid[r][c+1]==1) dfs(grid, r, c+1);
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int nr = land.size();
        int nc = land[0].size();
        vector<vector<int>> res;
        for(int r=0; r<nr; r++)
        {
            for(int c=0; c<nc; c++)
            {
                maxr = 0, maxc = 0;
                if(land[r][c]==1)
                {
                    dfs(land, r, c);
                    res.push_back({r, c, maxr, maxc});
                }
            }
        }
        return res;
    }
};
