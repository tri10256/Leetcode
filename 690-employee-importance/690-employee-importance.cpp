/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        queue<int>q;
         unordered_map<int,Employee*>mp;
        unordered_set<int>visited;
        for(auto employee:employees){
            if(employee->id == id){
               q.push(id);
            }
            mp[employee->id] = employee;
        }
       
        
        
        int sum = 0;
        
        while(!q.empty()){
            
            auto id = q.front();
            q.pop();
            visited.insert(id);
            auto emp = mp[id];
            sum+=emp->importance;
            
            auto neigh = emp->subordinates;
            for(int i = 0;i<neigh.size();i++){
                if(!visited.count(neigh[i])){
                    q.push(neigh[i]);
                }
            }
        }
        
        return sum;
    }
};