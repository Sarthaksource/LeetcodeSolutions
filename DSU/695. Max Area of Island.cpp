class Solution {
private:
    vector<int> parent;
    vector<int> size;
    
    int find(int i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        else
        {
            return parent[i] = find(parent[i]);
        }
    }
    
    void unionBySize(int i, int j)
    {
        int irep = find(i);
        int jrep = find(j);
        
        if(irep==jrep)
        {
            return;
        }
        
        int irank = size[irep];
        int jrank = size[jrep];
        
        if(irank>jrank)
        {
            parent[jrep] = irep;
            size[irep] += size[jrep];
        }
        else
        {
            parent[irep] = jrep;
            size[jrep] += size[irep];
        }
    }

    int getCount()
    {
        int count = 0;
        for(int i=0; i<parent.size(); i++)
        {
            if(parent[i]==i)
            {
                int s = size[i];
                count = max(count, s);
            }
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        parent.resize(m*n);
        size.resize(m*n, 1);

        for(int i=0; i<m*n; i++)
        {
            parent[i] = i;
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    if(i+1<m && grid[i+1][j]==1)
                    {
                        unionBySize(i*n+j, (i+1)*n+j);
                    }
                    if(j+1<n && grid[i][j+1]==1)
                    {
                        unionBySize(i*n+j, i*n+(j+1));
                    }
                }
                else
                {
                    size[i*n+j]--;
                }
            }
        }

        return getCount();
    }
};
