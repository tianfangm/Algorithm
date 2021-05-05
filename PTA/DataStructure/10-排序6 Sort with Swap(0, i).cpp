#include <iostream>
#include <vector>

using namespace std;

// 表排序，求单元环，多元环个数，N-S+K-2
int main()
{
    int N,S = 0,K = 0;
    scanf("%d",&N);
    
    vector<int>nums;
    vector<int>table(N);
    
    for(int i = 0;i<N;++i)
    {
        int num = 0;
        scanf("%d",&num);
        nums.push_back(num);
        table[num]=i;
    }

    vector<int>visited(N,0);
    for(int i = 0;i<N;++i)
    {
        if(visited[i])
        {
            continue;
        }
        int j = i;
        int count = 1;
        while(table[j]!=j)
        {
            visited[j]=1;
            swap(table[j],j);
            count+=1;
        }
        if(count == 1)
        {
            S+=1;
        }
        else if(count>1)
        {
            K+=1;
        }
    }
    
    // 注意公式为3种环都存在时才成立，其余情况分类讨论
    // 全是单元环
    if(S==N)
    {
        printf("0\n");
    }
    // 无带0环
    else if(nums[0]==0)
    {
        printf("%d\n",N-S+K);
    }
    else
    {
        printf("%d\n",N-S+K-2);
    }
    
    return 0;
}
