#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int e1,e2;
    int weight;
    Edge(){}
    Edge(int x1,int x2):e1(x1),e2(x2),weight(0){}
};

class Graph
{
private:
    
public:
    int nv,ne;
    vector<vector<int>> mGraph;
    Graph(int n):nv(n)
    {
        mGraph.resize(n);
        for(int i =0;i<n;++i)
        {
            mGraph[i].resize(n);
        }
    }
    
    void InsertEdge(Edge e)
    {
        mGraph[e.e1][e.e2] = e.weight;
        mGraph[e.e2][e.e1] = e.weight;
    }
    
    void DFS(vector<int>&result,vector<int>&visited,int node);
    void BFS(vector<int>&result,vector<int>&visited,int node);
    void ListElement(int flag);
    void Print(const vector<int>&vec);
    
};

void Graph::DFS(vector<int>&result,vector<int>&visited,int node)
{
    visited[node] = 1;
    result.push_back(node);
    
    for(int j = 0;j<nv;++j)
    {
        if(mGraph[node][j]&&!visited[j])
        {
            DFS(result,visited,j);
        }
    }
}

void Graph::BFS(vector<int>&result,vector<int>&visited,int node)
{
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0;i<n;++i)
        {
            node = q.front();
            if(!visited[node])
            {
                result.push_back(node);
            }
            visited[node] = 1;
            q.pop();
            for(int j = 0;j<nv;++j)
            {
                if(mGraph[node][j]&&!visited[j])
                {
                    q.push(j);
                }
            }
        }
    }
}

void Graph::ListElement(int flag)
{
    vector<int> visited(nv,0);
    vector<int> result;
    
    for(int i = 0;i<nv;++i)
    {
        result.clear();
        if(!visited[i])
        {
            if(flag)
            {
                DFS(result,visited,i);
            }
            else
            {
                BFS(result,visited,i);
            }
        }
        if(!result.empty())
            Print(result);
    }
}

void Graph::Print(const vector<int>&vec)
{
    int n = vec.size();
    printf("{ ");
    for(int i =0;i<n;++i)
    {
        printf("%d ",vec[i]);
    }
    printf("}\n");
}

Graph Read()
{
    int n = 0;
    scanf("%d",&n);
    
    Graph g(n);
    scanf("%d",&(g.ne));
    
    for(int i = 0;i<g.ne;++i)
    {
        Edge e = Edge();
        scanf("%d %d",&e.e1,&e.e2);
        e.weight = 1;
        g.InsertEdge(e);
    }
    
    return g;
}

int main()
{
    Graph g = Read();
    
    g.ListElement(1);
    
    g.ListElement(0);
    
    return 0;
}
