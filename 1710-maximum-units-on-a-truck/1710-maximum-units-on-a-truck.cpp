class Solution {
public:
    
    static bool helper(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),helper);
        
        int units = 0;
        for(auto vec:boxTypes){
           
           if(vec[0] <= truckSize){
               units += vec[0]*vec[1];
               truckSize-=vec[0];  
             
           }else if(vec[0] > truckSize && truckSize >0){
               units += truckSize*vec[1];
               truckSize -= vec[0];
           }
        }
        
        return units;
    }
};