// 两次二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto row = upper_bound(matrix.begin(),matrix.end(),target,[](int b,const vector<int>&a){
            return b<a[0];
        });
        if(row==matrix.begin())
        {
            return false;
        }
        row--;
        return binary_search(row->begin(),row->end(),target);
    }
};

// 一次二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m*n - 1;

        while(left<=right)
        {
            int mid = (right - left)/2 + left;
            int x = matrix[mid/n][mid%n];
            if(x==target)
            {
                return true;
            }
            else if(x>target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
};
