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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0; i<n+1; i++)
        {
            parent[i] = i;
        }

        vector<int> res;

        for(int i=0; i<n; i++)
        {
            if(find(edges[i][0])==find(edges[i][1]))
            {
                res = edges[i];
            }
            else
            {
                unionBySize(edges[i][0], edges[i][1]);
            }
        }

        return res;
    }
};
