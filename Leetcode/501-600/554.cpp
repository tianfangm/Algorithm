class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int>um;
        for(auto &w:wall)
        {
            int sum = 0;
            int n = w.size();
            for(int i = 0;i<n-1;++i)
            {
                sum+=w[i];
                um[sum]+=1;
            }
        }
        int Max = 0;
        for(auto &[_,e]:um)
        {
            Max = max(Max,e);
        }
        return wall.size()-Max;
    }
};
