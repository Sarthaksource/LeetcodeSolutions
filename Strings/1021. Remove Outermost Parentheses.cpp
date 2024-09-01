class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int count = 0, n = s.size();
        string res = "";
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
            {
                if((s[i+1]=='(' && count==0) || count==0)
                {
                    count++;
                }
                else
                {
                    st.push(s[i]);
                    res += s[i];
                }
            }
            else
            {
                if(st.empty() && count==1)
                {
                    count--;
                }
                else
                {
                    res = res + s[i];
                    st.pop();
                }
            }
        }
        return res;
    }
};
