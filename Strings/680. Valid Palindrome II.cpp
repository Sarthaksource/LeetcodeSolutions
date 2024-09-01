class Solution {
private:
    bool checker(string s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++; j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n=s.size();
        if(n==1 || n==2)
        {
            return true;
        }
        int i=0, j=n-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++; j--;
            }
            else
            {
                bool res = checker(s, i+1, j);
                if(!res)
                {
                    res = checker(s, i, j-1);
                }
                return res;
            }
        }
        return true;
    }
};
