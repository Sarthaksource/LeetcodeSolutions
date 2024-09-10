class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), count = 0;
        vector<int> bits(n);
        for(int i=0; i<n; i++)
        {
            int bit = 0;
            for(char c: words[i])
            {
                bit = bit | 1<<(c-'a');
            }
            bits[i] = bit;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if((bits[i] & bits[j]) == 0)
                {
                    int len = words[i].size() * words[j].size();
                    count = max(count, len);
                }
            }
        }
        return count;
    }
};
