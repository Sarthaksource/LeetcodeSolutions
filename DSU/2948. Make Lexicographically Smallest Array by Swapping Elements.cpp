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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        parent.resize(n);
        size.resize(n, 1);
        unordered_map<int, vector<int>> temp;
        unordered_map<int, int> mp;
        vector<int> copy = nums;

        sort(copy.begin(), copy.end());

        for(int i=0; i<n; i++)
        {
            parent[i] = i;
            temp[i].push_back(i);
            mp[copy[i]] = i;
        }

        for(int i=1; i<n; i++)
        {
            if(abs(copy[i]-copy[i-1])<=limit)
            {
                unionBySize(i, i-1);
                int parent = find(i);
                temp[parent].push_back(i);
            }            
        }

        for(int i=0; i<n; i++)
        {
            int parent = find(mp[nums[i]]);
            int minVal = copy[temp[parent][0]];
            temp[parent].erase(temp[parent].begin());
            nums[i] = minVal;
        }

        return nums;
    }
};
