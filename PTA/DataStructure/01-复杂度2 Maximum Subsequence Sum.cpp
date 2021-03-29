#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k = 0;
    int sum = -100000, right = 0, curLeft = 0, left = 0, cur = 0;
    vector<int> box;
    
    scanf("%d",&k);
    
    for(int i =0;i<k;++i)
    {
        int num = 0;
        scanf("%d",&num);
        
        box.emplace_back(num);
        
        cur+=num;
        
        if(cur<0)
        {
            cur = 0;
            curLeft = i+1;
        }
        else if(cur>sum)
        {
            sum = cur;
            right = i;
            left = curLeft;
        }
    }

    if(sum<0)
    {
        printf("0 %d %d",box[0],box[k-1]);
    }
    else
    {
        printf("%d %d %d",sum,box[left],box[right]);
    }
    
    return 0;
}
