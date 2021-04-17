class Solution {
public:
    int getID(int x,long w)
    {
        return x<0?(x+1ll)/w-1:x/w;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int,int>um;
        for(int i = 0;i<nums.size();++i)
        {
            long x = nums[i];
            int id = getID(x,t+1ll);
            if(um.count(id))
            {
                return true;
            }
            if(um.count(id-1)&&abs(x-um[id-1])<=t)
            {
                return true;
            }
            if(um.count(id+1)&&abs(x-um[id+1])<=t)
            {
                return true;
            }
            um[id]=x;
            if(i>=k)
            {
                um.erase(getID(nums[i-k],t+1ll));
            }
        }
        return false;
    }
};
