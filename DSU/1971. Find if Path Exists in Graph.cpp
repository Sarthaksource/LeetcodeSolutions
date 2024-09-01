class Solution {
private:
    vector<int> parent;
    vector<int> rank;
    
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
        
        int irank = rank[irep];
        int jrank = rank[jrep];
        
        if(irank<jrank)
        {
            parent[irep] = jrep;
        }
        else if(irank>jrank)
        {
            parent[jrep] = irep;
        }
        else
        {
            parent[irep] = jrep;
            rank[jrep]++;
        }
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        rank.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }

        for(int i=0; i<edges.size(); i++)
        {
            unionByRank(edges[i][0], edges[i][1]);
        }

        return (find(source)==find(destination));
    }
};
