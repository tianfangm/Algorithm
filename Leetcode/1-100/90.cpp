//迭代
class Solution {
public:
    vector<int>t;
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int mask = 0;mask<(1<<n);++mask)
        {
            bool  flag = true;
            t.clear();
            for(int i =0;i<n;++i)
            {
                if(mask&(1<<i))
                {
                    if(i>0&&((mask>>(i-1)&1) == 0)&&nums[i] == nums[i-1])
                    {
                        flag = false;
                        break;
                    }
                    t.push_back(nums[i]);
                }
            }
            if(flag)
            {
                res.push_back(t);
            }
        }
        return res;
    }
};

//递归
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(bool choosePre, int cur, vector<int> &nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        dfs(false, cur + 1, nums);
        if (!choosePre && cur > 0 && nums[cur - 1] == nums[cur]) {
            return;
        }
        t.push_back(nums[cur]);
        dfs(true, cur + 1, nums);
        t.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        dfs(false, 0, nums);
        return ans;
    }
};
