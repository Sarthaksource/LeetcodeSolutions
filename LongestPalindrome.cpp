class Solution {
public:
    int longestPalindrome(string s) {
        sort(s.begin(), s.end());
        unordered_map<char, int> m;
        int count = 0, flag = 0;
        for(char c: s)
        {
            m[c]++;
        }
        for(auto it: m)
        {
            if((it.second)%2==0)
            {
                count += it.second;
            }
            else
            {
                count += (it.second)-1;
                flag = 1;
            }
        }

        return (flag==1 ? ++count : count);
    }
};
