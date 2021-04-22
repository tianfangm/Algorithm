// Sr-Sl<=k -> Sl>=Sr-k 求最小Sl
// 动态规划
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(),n = matrix[0].size();
        int ans = INT_MIN;
        // 上界
        for(int i = 0;i<m;++i)
        {
            vector<int>sum(n);
            // 下界
            for(int j = i;j<m;++j)
            {
                // 列
                for(int c = 0;c<n;++c)
                {
                    sum[c]+=matrix[j][c];
                }
                set<int>sumSet{0};
                int sr = 0;
                for(int num : sum)
                {
                    sr+=num;
                    auto sl = sumSet.lower_bound(sr-k);
                    if(sl!=sumSet.end())
                    {
                        ans = max(ans,sr-*sl);
                    }
                    sumSet.insert(sr);
                }
            }
        }
        return ans;
    }
};
