class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0,right = nums.size() - 1;
        while(left<right)
        {
            int pivot = (left+right)>>1;
            if(nums[pivot]<nums[right])
            {
                right=pivot;
            }
            else if(nums[pivot]>nums[right])
            {
                left = pivot + 1;
            }
            else
            {
                right -= 1;
            }
        }
        return nums[left];
    }
};
