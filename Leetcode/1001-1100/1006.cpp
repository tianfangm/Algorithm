class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        stk.push(N);
        N-=1;
        int count = 0;

        while(N>0)
        {
            if(count%4==0)
            {
                int num = stk.top();
                stk.pop();
                stk.push(num*N);
            }
            else if(count%4==1)
            {
                int num = stk.top();
                stk.pop();
                stk.push(num/N);
            }
            else if(count%4==2)
            {
                stk.push(N);
            }
            else
            {
                stk.push(-N);
            }
            count+=1;
            N-=1;
        }
        int result = 0;
        while(!stk.empty())
        {
            int num = stk.top();
            stk.pop();
            result+=num;
        }
        return result;
    }
};

// 愚人节快乐
class Solution {
public:
    int clumsy(int N) {
        if (N == 1) {
            return 1;
        } else if (N == 2) {
            return 2;
        } else if (N == 3) {
            return 6;
        } else if (N == 4) {
            return 7;
        }

        if (N % 4 == 0) {
            return N + 1;
        } else if (N % 4 <= 2) {
            return N + 2;
        } else {
            return N - 1;
        }
    }
};
