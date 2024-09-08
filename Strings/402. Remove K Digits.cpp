class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.size(), i;
        if(n==k)
        {
            return "0";
        }
        stack<char> st;

        for(i=0; i<n; i++)
        {
            while(k>0 && !st.empty() && st.top()>num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while(k>0)
        {
            st.pop();
            k--;
        }

        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        while(res.size()>1 && res[0]=='0')
        {
            res.erase(res.begin());
        }

        return res;
    }
};
