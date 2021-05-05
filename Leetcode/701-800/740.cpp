class Solution {
    int rob(vector<int>&nums)
    {
        int size = nums.size();
        int first = nums[0],second = max(nums[0],nums[1]);
        for(int i = 2;i<size;++i)
        {
            int temp = second;
            second = max(second,first+nums[i]);
            first = temp;
        }
        return second;
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 0;
        for(int &num : nums)
        {
            maxNum = max(maxNum,num);
        }
        vector<int>sum(maxNum+1,0);
        for(int &num : nums)
        {
            sum[num]+=num;
        }
        return rob(sum);
    }
};
