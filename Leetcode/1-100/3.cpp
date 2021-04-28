class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>se;
        int n = s.size();
        int rk = -1,ans = 0;
        for(int i = 0;i<n;++i)
        {
            if(i!=0)
            {
                se.erase(s[i-1]);
            }
            while(rk+1<n&&!se.count(s[rk+1]))
            {
                rk+=1;
                se.insert(s[rk]);
            }
            ans = max(rk-i+1,ans);
        }
        return ans;
    }
};
