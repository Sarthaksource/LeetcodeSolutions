class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        vector<int> res;
        for(int i=0; i<s1.size(); i++)
        {
            if(s1[i]!=s2[i])
            {
                res.push_back(i);
            }
        }
        if(res.size()==2)
        {
            return (s1[res[0]]==s2[res[1]] && s1[res[1]]==s2[res[0]]);
        }
        return (res.size()==0);
    }
};
