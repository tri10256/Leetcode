class Solution {
public:
     static bool comp(vector<int>a,vector<int>b){
      
     int d1 = abs(a[0]*a[0] + a[1]*a[1]);
    int  d2 = abs(b[0]*b[0] + b[1]*b[1]);
      return d1<d2;
    }     
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
 
      // priority_queue<vector<int>,vector<vector<int>>,comp>pq(points.begin(),points.end());
        sort(points.begin(),points.end(),comp);
        vector<vector<int>>ans;
        
        for(int i = 0;i<k;i++){
            ans.push_back(points[i]);
        }
        
        return ans;
    }
};