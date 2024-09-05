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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        parent.resize(n+2);
        size.resize(n+2, 1);

        for(int i=0; i<n+2; i++)
        {
            parent[i] = i;
        }

        int u = n, v = n+1;
        
        for(int i=0; i<graph.size(); i++)
        {
            for(int it: graph[i])
            {
                if(find(i)==find(it))
                {
                    return false;
                }
                unionBySize(graph[i][0], it);
            }
        }
        return true;
    }
};
