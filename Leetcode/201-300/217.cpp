// 集合没有重复元素
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us(nums.begin(),nums.end());
        return us.size()!=nums.size();
    }
};

// 排序
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        {
            return false;
        }
        sort(nums.begin(),nums.end());
        for(int i = 1;i<n;++i)
        {
            if(nums[i-1]==nums[i])
            {
                return true;
            }
        }
        return false;
    }
};

// 哈希表
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int x: nums) {
            if (s.find(x) != s.end()) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};
