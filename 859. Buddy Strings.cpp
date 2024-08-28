class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
        {
            return false;
        }
        unordered_map<char, int> mp;
        for(char c: s)
        {
            mp[c]++;
        }
        int c = 0;
        for(auto it: mp)
        {
            c = max(c, it.second);
        }
        if(s==goal && c==1)
        {
            return false;
        }
        vector<int> res;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i]!=goal[i])
            {
                res.push_back(i);
            }
        }

        if(res.size()==2)
        {
            return (s[res[0]]==goal[res[1]] && s[res[1]]==goal[res[0]]);
        }
        else if(res.size()==0)
        {
            return true;
        }
        return false;
    }
};
