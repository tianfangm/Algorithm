class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0,right = (int)sqrt(c);
        while(left<=right)
        {
            long sum = left*left + right*right;
            if(sum==c)
            {
                return true;
            }
            else if(sum>c)
            {
                right-=1;
            }
            else
            {
                left+=1;
            }
        }
        return false;
    }
};
