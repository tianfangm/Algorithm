class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](const int &a,const int &b){
            long ax=10,bx=10;
            while(a>=ax)
            {
                ax*=10;
            }
            while(b>=bx)
            {
                bx*=10;
            }
            return a*bx+b>b*ax+a;
        });

        if(nums[0]==0)
        {
            return "0";
        }

        string result="";

        for(int &i:nums)
        {
            result+=to_string(i);
        }

        return result;
    }
};
