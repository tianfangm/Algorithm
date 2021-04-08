class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,high = nums.size() - 1;
        while(low<high)
        {
            int pivot = (low+high)>>1;
            if(nums[pivot]<nums[high])
            {
                high = pivot;
            }
            else
            {
                low = pivot + 1;
            }
        }
        return nums[low];
    }
};
