class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int cur = 0;
        int tail = m+n-1;
        while(i>=0||j>=0)
        {
            if(i==-1)
            {
                cur = nums2[j--];
            }
            else if(j==-1)
            {
                cur = nums1[i--];
            }
            else if(nums1[i]>nums2[j])
            {
                cur = nums1[i--];
            }
            else
            {
                cur = nums2[j--];
            }
            nums1[tail--] = cur;
        }
    }
};
