class Solution {
private:
    vector<int> parent;
    vector<int> sizex;
    
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
        
        int irank = sizex[irep];
        int jrank = sizex[jrep];
        
        if(irank>jrank)
        {
            parent[jrep] = irep;
            sizex[irep] += sizex[jrep];
        }
        else
        {
            parent[irep] = jrep;
            sizex[jrep] += sizex[irep];
        }
    }

    int getCount()
    {
        int count = 0;
        for(int i=0; i<parent.size(); i++)
        {
            if(parent[i]==i)
            {
                int r = sizex[i];
                count = max(count, r);
            }
        }
        return count;
    }

public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        parent.resize(n);
        sizex.resize(n, 1);

        for(int i=0; i<n; i++)
        {
            parent[i] = i;
        }

        map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                continue;
            }
            if(mp.find(nums[i]-1)!=mp.end())
            {
                unionBySize(i, mp[nums[i]-1]);
            }
            if(mp.find(nums[i]+1)!=mp.end())
            {
                unionBySize(i, mp[nums[i]+1]);
            }
            mp[nums[i]] = i;
        }

        return getCount();
    }
};
