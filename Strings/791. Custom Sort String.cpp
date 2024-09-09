class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp;
        for(auto it: s)
        {
            mp[it]++;
        }

        s = "";

        for(int i=0; i<order.size(); i++)
        {
            if(mp.find(order[i])!=mp.end())
            {
                s += string(mp[order[i]], order[i]);
                mp.erase(order[i]);
            }
        }

        for(auto it: mp)
        {
            s += string(it.second, it.first);
        }

        return s;
    }
};
