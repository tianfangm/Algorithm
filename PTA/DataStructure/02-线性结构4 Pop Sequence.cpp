#include <iostream>
#include <stack>

using namespace std;

void Judge(const int m,const int n)
{
    stack<int> stk;
    int count = 1;
    bool result = true;
    
    for(int i=0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        if(result)
        {
            while(stk.empty()||stk.top()!=num)
            {
                stk.push(count++);
                if(stk.size()>m)
                {
                    result = false;
                    break;
                }
            }
            if(stk.size()>=1&&stk.top()==num)
            {
                stk.pop();
            }
        }
    }
    
    printf("%s\n",result?"YES":"NO");
}

int main()
{
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    
    for(int i =0;i<k;++i)
    {
        Judge(m,n);
    }
    
    return 0;
}
