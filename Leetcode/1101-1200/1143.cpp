class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(),m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i =1;i<=n;++i)
        {
            char c1 = text1.at(i-1);
            for(int j = 1;j<=m;++j)
            {
                char c2 = text2.at(j-1);
                if(c1==c2)
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
};
