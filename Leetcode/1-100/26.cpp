// 双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1,fast = 1;
        int n = nums.size();
        if(n==0)
        {
            return 0;
        }
        while(fast!=n)
        {
            if(nums[fast]!=nums[fast-1])
            {
                nums[slow]=nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

// 迭代器，较慢
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = 0x7fffffff;
        for(auto it = nums.begin();it!=nums.end();)
        {
            if(pre!=*it)
            {
                pre = *it;
                ++it;
            }
            else
            {
                it = nums.erase(it);
            }
        }
        return nums.size();
    }
};
