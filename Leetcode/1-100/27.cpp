// 迭代器
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto it=nums.begin();it!=nums.end();)
        {
            if(*it==val)
            {
                it=nums.erase(it);
            }
            else
            {
                ++it;
            }
        }
        return nums.size();
    }
};

// 双指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0,right = nums.size();
        while(left<right)
        {
            if(nums[left]==val)
            {
                nums[left] = nums[right-1];
                right-=1;
            }
            else
            {
                left+=1;
            }
        }
        return left;
    }
};
