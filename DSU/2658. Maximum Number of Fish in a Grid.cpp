class Solution {
private:
    vector<int> parent;
    vector<int> fishes;
    vector<int> size;

    int find(int i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j)
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
            fishes[irep] += fishes[jrep];
        }
        else
        {
            parent[irep] = jrep;
            size[jrep] += size[irep];
            fishes[jrep] += fishes[irep];
        }
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
    
        parent.resize(m*n);
        size.resize(m*n, -1);
        fishes.resize(m*n);
        for(int i=0; i<m*n; i++)
        {
            parent[i] = i;
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                fishes[i*n+j] = grid[i][j];
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j])
                {
                    if(i+1<m && grid[i+1][j])
                    {
                        unite(i*n+j, (i+1)*n+j);
                    }
                    if(j+1<n && grid[i][j+1])
                    {
                        unite(i*n+j, i*n+(j+1));
                    }
                }
            }
        }

        return *max_element(fishes.begin(), fishes.end());
    }
};
