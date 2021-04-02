// 动态规划
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0)
        {
            return 0;
        }

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        for(int i =1;i<n;++i)
        {
            leftMax[i] = max(height[i],leftMax[i-1]);
        }

        for(int i = n-2;i>=0;--i)
        {
            rightMax[i] = max(height[i],rightMax[i+1]);
        }

        int ans = 0;

        for(int i =0;i<n;++i)
        {
            ans+=min(leftMax[i],rightMax[i])-height[i];
        }

        return ans;
    }
};

// 双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n==0)
        {
            return 0;
        }

        int left = 0,right = n-1,leftMax = 0,rightMax = 0;
        int ans = 0;

        while(left<right)
        {
            leftMax = max(leftMax,height[left]);
            rightMax = max(rightMax,height[right]);
            if(leftMax<rightMax)
            {
                ans+=leftMax-height[left];
                left+=1;
            }
            else
            {
                ans+=rightMax-height[right];
                right-=1;
            }
        }

        return ans;
    }
};
