class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i]==')')
            {
                if(st.empty() || st.top().first==')')
                {
                    st.push({s[i], i});
                }
                else
                {
                    st.pop();
                }
            }
            else if(s[i]=='(')
            {
                st.push({s[i], i});
            }
        }

        string res = "";
        for(int i=n-1; i>=0; i--)
        {
            if(!(st.empty()) && i==st.top().second)
            {
                st.pop();
                continue;
            }
            res += s[i];
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
