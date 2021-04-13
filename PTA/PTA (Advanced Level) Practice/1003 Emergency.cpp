#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int INT_MAX = 0x7fffffff;

void dijkstra(const int &C1,const int &C2,const int &N,const vector<int>&rescues,const vector<vector<int>>&roads)
{
    // 记录c1到j的最短路径数量
    vector<int>count(N,0);
    // 记录c1到j的最大救援数目
    vector<int>rescue(N,0);
    // 本题目不需要记录路径，故无path
    // 记录是否被访问过
    unordered_set<int> visited;
    // 记录c1到j的最短距离
    vector<int> dist(N,INT_MAX);
    
    // init
    for(int i = 0;i<N;++i)
    {
        dist[i]=roads[C1][i];
        if(dist[i]!=INT_MAX)
        {
            count[i]=1;
            rescue[i]=rescues[i]+rescues[C1];
        }
    }
    
    visited.insert(C1);
    count[C1]=1;
    rescue[C1]=rescues[C1];
    dist[C1]=0;
    
    while(1)
    {
        // 在未访问结点中找到dist最小的结点V
        int V = -1;
        int Min = INT_MAX;
        for(int i =0;i<N;++i)
        {
            if(!visited.count(i)&&dist[i]<Min)
            {
                V = i;
                Min = dist[i];
            }
        }
        if(V==-1)
        {
            break;
        }
        visited.insert(V);
        // 遍历V的未访问的相邻结点，更新值
        for(int i = 0;i<N;++i)
        {
            if(!visited.count(i)&&roads[V][i]!=INT_MAX)
            {
                if(dist[i]>dist[V]+roads[V][i])
                {
                    dist[i] = dist[V]+roads[V][i];
                    count[i] = count[V];
                    rescue[i] = rescue[V]+rescues[i];
                }
                else if(dist[i]==dist[V]+roads[V][i])
                {
                    count[i]+=count[V];
                    rescue[i]=max(rescue[i],rescue[V]+rescues[i]);
                }
            }
        }
    }
    printf("%d %d\n",count[C2],rescue[C2]);
}

int main()
{
    int N,M,C1,C2;
    // 读入数据
    scanf("%d %d %d %d",&N,&M,&C1,&C2);
    
    vector<int> rescues;
    vector<vector<int>> roads(N,vector<int>(N,INT_MAX));
    
    for(int i = 0;i<N;++i)
    {
        int num = 0;
        scanf("%d",&num);
        rescues.push_back(num);
    }
    
    for(int i = 0;i<M;++i)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        roads[x][y]=z;
        roads[y][x]=z;
    }
    
    // dijkstra
    dijkstra(C1,C2,N,rescues,roads);
    
    return 0;
}
