// 迭代
class Solution {
public:
    vector<vector<int>> res;
    vector<int> t;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        
        for(int mask = 0;mask<(1<<n);++mask)
        {
            t.clear();
            for(int i =0;i<n;++i)
            {
                if(mask&(1<<i))
                {
                    t.push_back(nums[i]);
                }
            }
            res.push_back(t);
        }
        return res;
    }
};

// 递归
class Solution {
private:
    vector<int> t;
    vector<vector<int>> res;
public:
    void dfs(int cur,const vector<int>& nums)
    {
        if(cur == nums.size())
        {
            res.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur+1,nums);
        t.pop_back();
        dfs(cur+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return res;
    }
};
