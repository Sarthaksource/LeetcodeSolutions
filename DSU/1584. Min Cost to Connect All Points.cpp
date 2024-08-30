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
    
    int kruskalsFunc(vector<vector<int>>& edges)
    {
        int sum = 0;

        for(auto edge: edges)
        {
            int w = edge[0];
            int u = edge[1];
            int v = edge[2];
            
            int uParent = find(u);
            int vParent = find(v);
            
            if(uParent!=vParent)
            {
                unionByRank(u, v);
                sum += w;
            }
        }
        
        return sum;
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int n = points.size();

        parent.resize(n);
        rank.resize(n, 1);

        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                edges.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]), i, j});
            }
        }

        sort(edges.begin(), edges.end());

        return kruskalsFunc(edges);
    }
};
