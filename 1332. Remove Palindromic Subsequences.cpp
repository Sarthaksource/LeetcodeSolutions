class Solution {
public:
    int removePalindromeSub(string s) {
        string r = s;
        reverse(r.begin(), r.end());

        return (r==s ? 1 : 2);
    }
};
