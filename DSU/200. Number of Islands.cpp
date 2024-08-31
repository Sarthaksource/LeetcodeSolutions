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
    
    void unionByRank(int i, int j)
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
            size[irep]++;
        }
        else
        {
            parent[irep] = jrep;
            size[jrep]++;
        }
    }

    int getCount()
    {
        int count = 0;
        for(int i=0; i<parent.size(); i++)
        {
            if(parent[i]==i && size[i]>1)
            {
                cout<<parent[i]<<" ";
                count++;
            }
        }
        return count;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
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
                if(grid[i][j]=='1')
                {
                    if(j+1<n && grid[i][j+1]=='1')
                    {
                        unionByRank((i*n)+j, (i*n)+j+1);
                    }
                    if(i+1<m && grid[i+1][j]=='1')
                    {
                        unionByRank((i*n)+j, ((i+1)*n)+j);
                    }
                    size[i*n+j]++;
                }
            }
        }

        return getCount();
    }
};
