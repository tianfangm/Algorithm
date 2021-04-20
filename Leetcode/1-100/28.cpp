// 暴力法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(),m=needle.size();
        if(m==0)
        {
            return 0;
        }
        for(int i = 0;i+m<=n;++i)
        {
            int j = 0;
            while(i+j<n&&j<m&&haystack[i+j]==needle[j])
            {
                j+=1;
            }
            if(j==m)
            {
                return i;
            }
        }
        return -1;
    }
};

// kmp算法
