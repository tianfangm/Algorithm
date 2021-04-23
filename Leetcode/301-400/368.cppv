class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int>dp(n,1);
        int maxCount = 1,maxNum = 0;

        for(int i = 1;i<n;++i)
        {
            for(int j = 0;j<i;++j)
            {
                if(nums[i]%nums[j]==0)
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            if(dp[i]>maxCount)
            {
                maxCount = dp[i];
                maxNum = nums[i];
            }
        }

        vector<int>result;
        if(maxCount==1)
        {
            result.push_back(nums[0]);
        }
        else
        {
            for(int i = n-1;i>=0;--i)
            {
                if(maxCount==dp[i]&&maxNum%nums[i]==0)
                {
                    result.push_back(nums[i]);
                    maxCount-=1;
                    maxNum = nums[i];
                }
            }
        }
        return result;
    }
};
