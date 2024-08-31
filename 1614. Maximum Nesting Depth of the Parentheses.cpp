class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        stack<char> st;
        for(char c: s)
        {
            if(c=='(')
            {
                st.push('(');
            }
            else if(c==')')
            {
                int stSize = st.size();
                count = max(count, stSize);
                st.pop();
            }
        }
        return count;
    }
};
