class Solution {
private:
    int toInteger(string s)
    {
        int res = 0, n = s.size();
        for(int i=0; i<n; i++)
        {
            res = res*10 + s[i]-'a';
        }
        return res;
    }
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return (toInteger(firstWord)+toInteger(secondWord))==toInteger(targetWord);
    }
};
