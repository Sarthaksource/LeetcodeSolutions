class Solution {
private:
    int islandSize = 0, count = 0;
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c)
    {
        if(grid1[r][c]==grid2[r][c]) count++;
        int nr = grid2.size();
        int nc = grid2[0].size();
        grid2[r][c]=0;
        islandSize++;
        if(r-1>=0 && grid2[r-1][c]==1) dfs(grid1, grid2, r-1, c);
        if(r+1<nr && grid2[r+1][c]==1) dfs(grid1, grid2, r+1, c);
        if(c-1>=0 && grid2[r][c-1]==1) dfs(grid1, grid2, r, c-1);
        if(c+1<nc && grid2[r][c+1]==1) dfs(grid1, grid2, r, c+1);
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int nr = grid2.size();
        int nc = grid2[0].size();
        int islandNum = 0;
        for(int r=0; r<nr; r++)
        {
            for(int c=0; c<nc; c++)
            {
                islandSize = 0, count = 0;
                if(grid2[r][c]==1)
                {
                    dfs(grid1, grid2, r, c);
                    if(islandSize==count)
                    {
                        islandNum++;
                    }
                }
            }
        }
        return islandNum;
    }
};
