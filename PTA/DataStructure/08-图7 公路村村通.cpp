# Kruskal
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

using pEdge = struct Edge*;
struct Edge{
    int s,e,w;
    Edge(int start,int end,int weight):s(start),e(end),w(weight){}
};

int getParent(int node,const vector<int>&parent)
{
    while(parent[node]!=-1)
    {
        node = parent[node];
    }
    return node;
}

bool check(int n1,int n2,vector<int>&parent)
{
    int p1 = getParent(n1,parent),p2 = getParent(n2,parent);
    if(p1!=p2)
    {
        if(p1<=p2)
        {
            parent[p2]=p1;
        }
        else
        {
            parent[p1]=p2;
        }
        return false;
    }
    return true;
}

int Kruskal(const int&N,vector<pEdge>&edges)
{
    unordered_set<int>vertexs;
    vector<int>parent(N+1,-1);
    int result = 0;
    
    sort(edges.begin(),edges.end(),[=](const pEdge p1,const pEdge p2){
        return (p1->w)<(p2->w);
    });
    
    for(auto edge:edges)
    {
        if(vertexs.size()==N)
        {
            break;
        }
        // 并查集
        if(!check(edge->s,edge->e,parent))
        {
            result+=edge->w;
            vertexs.insert(edge->s);
            vertexs.insert(edge->e);
        }
    }
    
    for(int i = 1;i<=N;++i)
    {
        if(getParent(i,parent)!=1)
        {
            result = -1;
            break;
        }
    }
    
    return result;
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    vector<pEdge>edges;

    for(int i = 0;i<M;++i)
    {
        int s,e,w;
        scanf("%d %d %d",&s,&e,&w);
        edges.push_back(new Edge(s,e,w));
    }

    printf("%d\n",Kruskal(N,edges));

    return 0;
}
