#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using pEdge = struct Edge*;
struct Edge{
    int s,e,w;
    Edge(int start,int end,int weight):s(start),e(end),w(weight){}
};

int topology(const int& N,vector<int>&inDegree,vector<pEdge>edges)
{
    queue<int>q;
    vector<int>dist(N,0);
    int V = 0;
    int result = 0;
    
    for(int i = 0;i<N;++i)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
            dist[i]=0;
        }
    }
    
    int cnt = 0;
    int last = 0;
    
    while(!q.empty())
    {
        V = q.front();
        last = V;
        q.pop();
        cnt+=1;
        for(auto edge = edges.begin();edge!=edges.end();)
        {
            // V指向的点
            if((*edge)->s==V)
            {
                inDegree[(*edge)->e]-=1;
                if(inDegree[(*edge)->e]==0)
                {
                    q.push((*edge)->e);
                }
                dist[(*edge)->e] = max(dist[(*edge)->e],(*edge)->w+dist[(*edge)->s]);
                edge = edges.erase(edge);
            }
            else
            {
                edge+=1;
            }
        }
    }
    
    if(cnt!=N)
    {
        result=-1;
    }
    else
    {
        result = dist[last];
    }
    
    return result;
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    vector<pEdge>edges;
    vector<int>inDegree(N,0);
    
    for(int i = 0;i<M;++i)
    {
        int s,e,w;
        scanf("%d %d %d",&s,&e,&w);
        edges.push_back(new Edge(s,e,w));
        inDegree[e]+=1;
    }
    
    int result = topology(N,inDegree,edges);
    
    if(result!=-1)
    {
        printf("%d\n",result);
    }
    else
    {
        printf("Impossible\n");
    }
    
    return 0;
}
