/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

// bfs
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>um;
        int sum = 0;
        for(auto &employee:employees)
        {
            um[employee->id]=employee;
        }
        queue<int>q;
        q.push(id);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0;i<n;++i)
            {
                id = q.front();
                q.pop();
                Employee* e = um[id];
                sum+=e->importance;
                for(auto eid:e->subordinates)
                {
                    q.push(eid);
                }
            }
        }
        return sum;
    }
};

//dfs
class Solution {
private:
    unordered_map<int,Employee*> um;
public:
    int dfs(int id)
    {
        int sum = 0;
        Employee* employee = um[id];
        sum+=employee->importance;
        for(auto eid:employee->subordinates)
        {
            sum+=dfs(eid);
        }
        return sum;
    }

    int getImportance(vector<Employee*> employees, int id) {
        for(auto &employee :employees)
        {
            um[employee->id] = employee;
        }
        return dfs(id);
    }
};
