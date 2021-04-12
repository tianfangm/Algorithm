#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int INT_MAX = 99999999;

using pNode = struct Node*;

struct weight{
    int cost;
    int length;
    weight():cost(0),length(0){}
    weight(int c,int l):cost(c),length(l){}
};

struct Node{
    int dst;
    weight w;
    pNode next;
    Node():dst(0),w(weight()),next(nullptr){}
    Node(int d,weight ww,pNode n):dst(d),w(ww),next(n){}
};

bool compare(weight w1,weight w2)
{
    return w1.length==w2.length?w1.cost<w2.cost:w1.length<w2.length;
}

void Dijkstra(const int& s,const int& d,const vector<pNode>&graph)
{
    unordered_set<int> collected;
    int n = graph.size();

    vector<weight>dist(n,weight(INT_MAX,INT_MAX));
    dist[s]=weight(0,0);
    collected.insert(s);

    pNode p = graph[s]->next;
    while(p)
    {
        dist[p->dst]=p->w;
        p=p->next;
    }

    while(1)
    {
        bool solve_all = true;
        weight temp = weight(INT_MAX,INT_MAX);
        int V = 0;
        for(int i = 0;i<n;++i) {
            if (!collected.count(i) && compare(dist[i], temp)) {
                temp = dist[i];
                V = i;
                solve_all = false;
            }
        }
        
        if(solve_all)
        {
            break;
        }
        collected.insert(V);
        p = graph[V]->next;
        while(p)
        {
            if(!collected.count(p->dst))
            {
                temp = weight(dist[V].cost+p->w.cost,dist[V].length+p->w.length);
                if(compare(temp,dist[p->dst]))
                {
                    dist[p->dst] = temp;
                }
            }
            p=p->next;
        }
    }

    printf("%d %d\n",dist[d].length,dist[d].cost);
}

int main()
{
    int N,M,S,D;
    scanf("%d %d %d %d",&N,&M,&S,&D);

    vector<pNode>graph;

    for(int i = 0;i<N;++i)
    {
        graph.push_back(new Node());

    }

    for(int i = 0;i<M;++i)
    {
        int s,d,c,l;
        scanf("%d %d %d %d",&s,&d,&l,&c);
        pNode temp = new Node(d,weight(c,l),(graph[s])->next);
        (graph[s])->next = temp;
        temp = new Node(s,weight(c,l),(graph[d])->next);
        (graph[d])->next = temp;
    }

    Dijkstra(S,D,graph);

    return 0;
}
