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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        parent.resize(n);
        size.resize(n, 1);

        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j]==1)
                {
                    unionBySize(i, j);
                }
            }
        }

        int count = 0;

        for(int i=0; i<n; i++)
        {
            if(parent[i]==i)
            {
                count++;
            }
        }

        return count;
    }
};
