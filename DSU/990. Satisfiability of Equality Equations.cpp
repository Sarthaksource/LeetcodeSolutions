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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(27);
        size.resize(27, 1);

        for(int i=0; i<27; i++)
        {
            parent[i] = i;
        }

        vector<vector<int>> notEqual(26);

        for(int i=0; i<equations.size(); i++)
        {
            if(equations[i][1]=='=')
            {
                for(auto it: notEqual[equations[i][0] - 'a'])
                {
                    if(find(equations[i][3] - 'a')==find(it))
                    {
                        return false;
                    }
                }
                for(auto it: notEqual[equations[i][3] - 'a'])
                {
                    if(find(equations[i][0] - 'a')==find(it))
                    {
                        return false;
                    }
                }
                unionBySize(equations[i][0] - 'a', equations[i][3] - 'a');
            }
            else
            {
                if(find(equations[i][0] - 'a') == find(equations[i][3] - 'a'))
                {
                    return false;
                }
                notEqual[equations[i][0] - 'a'].push_back(equations[i][3] - 'a');
                notEqual[equations[i][3] - 'a'].push_back(equations[i][0] - 'a');
            }
        }

        return true;
    }
};
