#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    scanf("%d",&n);
    
    int result = 0, cur = 0;
    
    for(int i =0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        if(num+cur>0)
        {
            cur+=num;
        }
        else
        {
            cur = 0;
        }
        if(cur>result)
        {
            result = cur;
        }
    }
    
    printf("%d\n",result);
    
    return 0;
}
