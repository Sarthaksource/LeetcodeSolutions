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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        parent.resize(2*n +1);
        size.resize(2*n +1, 1);

        for(int i=0; i<2*n + 1; i++)
        {
            parent[i] = i;
        }
        
        for(int i=0; i<dislikes.size(); i++)
        {
            if(find(dislikes[i][0])==find(dislikes[i][1]))
            {
                return false;
            }
            unionBySize(dislikes[i][0], n+dislikes[i][1]);
            unionBySize(dislikes[i][1], n+dislikes[i][0]);
        }
        return true;
    }
};
