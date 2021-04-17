// 散列表
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>us;
        for(int i = 0;i<nums.size();++i)
        {
            if(us.find(nums[i])!=us.end())
            {
                return true;
            }
            us.insert(nums[i]);
            if(us.size()>k)
            {
                us.erase(nums[i-k]);
            }
        }
        return false;
    }
};
