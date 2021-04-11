#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(int id,const int &L,const vector<vector<int>>&relation,const int &N)
{
    int count = 0;
    vector<int>hashMap(N+1,0);
    queue<int> q;
    q.push(id);
    int level = 0;
    while(!q.empty()&&level<L)
    {
        int n = q.size();
        for(int i = 0;i<n;++i)
        {
            id = q.front();
            q.pop();
            hashMap[id]=1;
            for(int j = 1;j<=N;++j)
            {
                if(!hashMap[j]&&relation[j][id]==1)
                {
                    hashMap[j]=1;
                    count+=1;
                    q.push(j);
                }
            }
        }
        level+=1;
    }
    
    return count;
}

void Read(int host,vector<vector<int>>&relation)
{
    int n = 0;
    scanf("%d",&n);
    for(int i = 0;i<n;++i)
    {
        // 关注的人
        int num = 0;
        scanf("%d",&num);
        relation[host][num]=1;
    }
}

int main()
{
    int N = 0,L = 0;
    scanf("%d %d",&N,&L);
    
    vector<vector<int>>relation(N+1,vector<int>(N+1,0));
    
    // 双向图
    for(int i = 1;i<=N;++i)
    {
        Read(i,relation);
    }
    
    int K = 0;
    scanf("%d",&K);
    
    for(int i = 0;i<K;++i)
    {
        int id = 0;
        scanf("%d",&id);
        printf("%d\n",solve(id,L,relation,N));
    }
    
    return 0;
}
