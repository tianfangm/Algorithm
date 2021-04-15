#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <string>

using namespace std;

const int INT_MAX = 99999999;

void Read(vector<vector<int>> &graph,const int &K,const int &N)
{
    for(int i = 0;i<K;++i)
    {
        string c1,c2;
        int num1,num2,l;
        cin>>c1>>c2>>l;
        if(c1[0]=='G')
        {
            num1=stoi(c1.substr(1))+N - 1;
        }
        else
        {
            num1 = stoi(c1)-1;
        }
        if(c2[0]=='G')
        {
            num2=stoi(c2.substr(1))+N-1;
        }
        else
        {
            num2 = stoi(c2)-1;
        }
        graph[num1][num2]=l;
        graph[num2][num1]=l;
    }
}

// the minimum distance between the station and any of
// the residential housing is as far away as possible.
// dijkstra
pair<int,int> solve(const int& index,const vector<vector<int>> &graph,const int &N,const int &M,const int &D) {
    vector<int>visited(N+M,0);
    vector<int> dist(N+M, INT_MAX);
    int sumLength = 0, minLength = INT_MAX;

    for(int i = 0;i<N+M;++i)
    {
        dist[i] = graph[index][i];
    }
    dist[index]=0;
    visited[index]=1;

    for(int k = 0;k<M+N;++k)
    {
        int MinDist = INT_MAX,V = -1;

        for(int i = 0;i<N+M;++i)
        {
            if(!visited[i]&&dist[i]<MinDist)
            {
                MinDist = dist[i];
                V = i;
            }
        }

        if(V==-1 || MinDist > D)
        {
            break;
        }
        visited[V]=1;
        // 遍历V的相邻结点
        for(int i = 0;i<N+M;++i)
        {
            if(graph[V][i]!=INT_MAX&&!visited[i]&&dist[i]>dist[V]+graph[V][i])
            {
                dist[i]=dist[V]+graph[V][i];
            }
        }
    }

    for(int i = 0;i<N;++i)
    {
        if(dist[i]<minLength)
        {
            minLength = dist[i];
        }
        sumLength += dist[i];
        if(dist[i]==INT_MAX||dist[i]>D)
        {
            return {-1,INT_MAX};
        }
    }

    return {minLength, sumLength};
}

int main()
{
    // N houses, M gas stations,K roads,D service range
    int N,M,K,D;
    scanf("%d %d %d %d\n",&N,&M,&K,&D);

    vector<vector<int>>graph(N+M,vector<int>(N+M,INT_MAX));

    // 处理读入数据
    Read(graph,K,N);

    // 分别对每个加油站计算
    int minLength = 0,sumLength = INT_MAX;
    int index = -1;
    for(int i = N;i<N+M;++i)
    {
        // 处理
        pair<int,int>result = solve(i,graph,N,M,D);
        // 最近居民最远，总居民最近
        if(result.first>minLength||(result.first==minLength&&result.second<sumLength))
        {
            sumLength = result.second;
            minLength = result.first;
            index = i;
        }
    }

    if(index==-1)
    {
        printf("No Solution\n");
    }
    else
    {
        printf("G%d\n",index-N+1);
        printf("%.1f %.1f",1.0*minLength,sumLength*1.0/N);
    }

    return 0;
}
