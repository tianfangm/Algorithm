class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>hashMap;
        for(int x : answers)
        {
            hashMap[x]+=1;
        }
        int result = 0;
        
        for(auto &[x,y]:hashMap)
        {
            result+=(x+y)/(x+1)*(x+1);
        }

        return result;
    }
};
