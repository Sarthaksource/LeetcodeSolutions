class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        for(char c: s)
        {
            mp[c]++;
        }
        for(auto it: mp)
        {
            pq.push({it.second, it.first});
        }

        s = "";

        while(!pq.empty())
        {
            s += string(pq.top().first, pq.top().second);
            pq.pop();
        }

        return s;
    }
};
