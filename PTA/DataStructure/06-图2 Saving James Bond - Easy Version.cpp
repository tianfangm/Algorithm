#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

const int N = 100;

int Read(vector<pair<int,int>>&cor)
{
    int n,d;
    scanf("%d %d",&n,&d);
    for(int i = 0;i<n;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        cor.push_back({x,y});
    }
    return d;
}

bool FisrtJump(int x,int y,int d)
{
    double r = sqrt(x*x+y*y);
    return r<=static_cast<double>(15+d);
}

bool CanJump(int x1,int y1,int x2,int y2,int d)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<=d;
}

bool IsSafe(int x,int y,int d)
{
    return abs(x)+d>=50||abs(y)+d>=50;
}

bool DFS(int num,vector<int>&visited,const int& d,const vector<pair<int,int>>cor,const int& n)
{
    visited[num] = 1;
    bool answer = false;
    int x = cor[num].first,y = cor[num].second;
    if(IsSafe(x,y,d))
    {
        answer = true;
    }
    else
    {
        for(int i = 0;i<n;++i)
        {
            if(!visited[i]&&CanJump(x,y,cor[i].first,cor[i].second,d))
            {
                answer = DFS(i,visited,d,cor,n);
                if(answer)
                {
                    break;
                }
            }
        }
    }
    return answer;
}

int main()
{
    vector<pair<int,int>> cor;
    
    int d = Read(cor);
    int n = cor.size();
    bool answer = false;
    vector<int> visited(n,0);
    
    for(int i = 0;i<n;++i)
    {
        if(!visited[i]&&FisrtJump(cor[i].first,cor[i].second,d))
        {
            answer = DFS(i,visited,d,cor,n);
        }
        if(answer)
        {
            break;
        }
    }
    
    if(answer)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    
    return 0;
}
