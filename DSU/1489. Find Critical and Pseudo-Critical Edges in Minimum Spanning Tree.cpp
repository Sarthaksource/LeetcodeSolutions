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
    
    int kruskalsFunc(vector<vector<int>>& edges, int skip, int incl, int n)
    {
        rank.resize(n, 1);
        parent.resize(n);
        
        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }

        int sum = 0;
        int comp = n;   //No. of edges not included in MST
        
        if(incl!=-1)
        {
            sum += edges[incl][0];
            unionByRank(edges[incl][1], edges[incl][2]);
            comp--;
        }
        for(int i=0; i<edges.size(); i++)
        {
            if(i==skip)
            {
                continue;
            }
            int w = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            
            int uParent = find(u);
            int vParent = find(v);
            
            if(uParent!=vParent)
            {
                unionByRank(u, v);
                sum += w;
                comp--;
            }
        }
        
        return (comp==1 ? sum : INT_MAX);
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(2, vector<int>());
        
        for(int i=0; i<edges.size(); i++)
        {
            swap(edges[i][0], edges[i][2]);
            swap(edges[i][1], edges[i][2]);
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end());

        int mstWeight = kruskalsFunc(edges, -1, -1, n);

        for(int i=0; i<edges.size(); i++)
        {
            int skipWeight = kruskalsFunc(edges, i, -1, n);
            int inclWeight = kruskalsFunc(edges, -1, i, n);
            if(skipWeight>mstWeight)
            {
                res[0].push_back(edges[i][3]);
            }
            else if(inclWeight==mstWeight)
            {
                res[1].push_back(edges[i][3]);
            }
        }

        return res;
    }
};
