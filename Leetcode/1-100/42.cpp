class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0,rightMax = 0,left = 0,right = height.size()-1;
        int result = 0;
        while(left<right)
        {
            leftMax = max(leftMax,height[left]);
            rightMax = max(rightMax,height[right]);
            if(height[left]<height[right])
            {
                result+=leftMax-height[left];
                left+=1;
            }
            else
            {
                result+=rightMax-height[right];
                right-=1;
            }
        }
        return result;
    }
};
