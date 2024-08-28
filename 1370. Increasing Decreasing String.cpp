class Solution {
private:
    string res = "";
    void forward(map<char, int>& mp, int val)
    {
        char target, i;
        target = val==1 ? 'z'+1 : 'a'-1;
        i = val==1 ? 'a' : 'z'; 
        while(i!=target)
        {
            if(mp.find(i)!=mp.end())
            {
                res += i;
                mp[i]--;
                if(mp[i]==0)
                {
                    mp.erase(i);
                }
            }
            val==1? i++ : i--;
        }
    }
public:
    string sortString(string s) {
        map<char, int> mp;
        for(char c: s)
        {
            mp[c]++;
        }
        while(mp.size()!=0)
        {
            forward(mp, 1);
            cout<<res<<endl;
            forward(mp, 2);
            cout<<res<<endl;
        }

        return res;
    }
};
