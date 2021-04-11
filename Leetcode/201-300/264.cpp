// 最小堆
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>factors{2,3,5};
        unordered_set<long> hashMap;
        priority_queue<long,vector<long>,greater<long>> q;
        q.push(1L);
        hashMap.insert(1L);
        int ugly = 0;
        for(int i = 0;i<n;++i)
        {
            long curr = q.top();
            q.pop();
            ugly = static_cast<int>(curr);
            for(int factor:factors)
            {
                long next = curr*factor;
                if(!hashMap.count(next))
                {
                    q.push(next);
                    hashMap.insert(next);
                }
            }
        }
        return ugly;
    }
};

// 动态规划
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1);
        dp[1]=1;
        int p2=1,p3=1,p5=1;

        for(int i =2;i<=n;++i)
        {
            int num2=dp[p2]*2,num3=dp[p3]*3,num5=dp[p5]*5;
            dp[i]=min(min(num2,num3),num5);
            if(num2==dp[i])
            {
                p2+=1;
            }
            if(num3==dp[i])
            {
                p3+=1;
            }
            if(num5==dp[i])
            {
                p5+=1;
            }
        }

        return dp[n];
    }
};
