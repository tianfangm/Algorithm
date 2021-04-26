class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);
        while(left<right)
        {
            int mid = (left+right)>>1;
            int need = 1,cur = 0;
            for(int weight:weights)
            {
                if(cur+weight>mid)
                {
                    need+=1;
                    cur = 0;
                }
                cur+=weight;
            }
            if(need<=D)
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};
