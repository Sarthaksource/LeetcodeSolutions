class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> temp(26, -1);
        int res = -1;
        for(int i=0; i<s.size(); i++)
        {
            if(temp[s[i]-'a']!=-1)
            {
                res = max(res, i - temp[s[i]-'a'] - 1);
            }
            else
            {
                temp[s[i]-'a'] = i;
            }
        }
        
        return res;
    }
};
