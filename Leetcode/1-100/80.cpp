class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(auto first = nums.begin(),second = nums.begin();second!=nums.end();)
        {
            int temp = 0;
            while(second!=nums.end()&&*first==*second)
            {
                if(temp>1)
                {
                    second = nums.erase(second);
                }
                else
                {
                    ++second;
                }
                ++temp;
            }
            first = second;
        }
        return nums.size();
    }
};
