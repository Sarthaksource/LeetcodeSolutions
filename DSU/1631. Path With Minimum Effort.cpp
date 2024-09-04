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
        return parent[i] = find(parent[i]);
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

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
    
        parent.resize(m*n);
        size.resize(m*n, 1);

        for(int i=0; i<m*n; i++)
        {
            parent[i] = i;
        }

        vector<vector<int>> edges;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i+1<m)
                {
                    int w = abs(heights[i][j] - heights[i+1][j]);
                    edges.push_back({w, i*n+j, (i+1)*n+j});
                }
                if(j+1<n)
                {
                    int w = abs(heights[i][j] - heights[i][j+1]);
                    edges.push_back({w, i*n+j, i*n+(j+1)});
                }
            }
        }

        sort(edges.begin(), edges.end());

        for(auto it: edges)
        {
            int w = it[0];
            int u = it[1];
            int v = it[2];
            if(find(u)!=find(v))
            {
                unionBySize(u, v);
            }
            if(find(0)==find(m*n-1))
            {
                return w;
            }
        }
        return 0;
    }
};
