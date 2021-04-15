/* 两种状态
 * 第一个屋子偷了，最后一个屋子不能偷，范围为[0,n-2]
 * 第一个屋子没偷，最后一个屋子可以偷，范围为[1,n-1]
 * 状态转移为 dp[i] = max(dp[i-2]+nums[i],dp[i-1])
*/
class Solution {
private:
    int solve(int start,int end,const vector<int>&nums)
    {
        int first = nums[start],second = max(nums[start],nums[start+1]);
        for(int i = start + 2;i<=end;++i)
        {
            int temp = second;
            second = max(first+nums[i],second);
            first = temp;
        }
        return max(first,second);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        {
            return 0;
        }
        else if(n==1)
        {
            return nums[0];
        }
        else if(n==2)
        {
            return max(nums[0],nums[1]);
        }

        return max(solve(0,n-2,nums),solve(1,n-1,nums));
    }
};
