// 哈希表
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>um;
        int n = nums.size();

        for(int num:nums)
        {
            um[num]+=1;
        }

        for(auto it = um.begin();it!=um.end();++it)
        {
            if(it->second==1)
            {
                return it->first;
            }
        }

        return -1;
    }
};
