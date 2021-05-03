#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    
    vector<pair<int,int>> m;
    
    for(int i =0;i<N;++i)
    {
        bool flag = true;
        int num = 0;
        scanf("%d",&num);
        for(auto it = m.begin();it!=m.end();++it)
        {
            if(it->first==num)
            {
                it->second+=1;
                flag = false;
                break;
            }
        }
        if(flag)
        {
            m.push_back({num,1});
        }
    }
    
    sort(m.begin(),m.end(),[](const pair<int,int> &x,const pair<int,int> &y){
        return x.first<y.first;
    });
    
    for(auto it = m.begin();it!=m.end();++it)
    {
        printf("%d:%d\n",it->first,it->second);
    }
    
    return 0;
}
