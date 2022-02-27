class Solution {
public:
    
    long long int calc(vector<int>&time,long long int given){
        long long int trips = 0;
        for(auto x:time){
            
            long long int val = x;
            
            trips+=(given/val);
        }
        
        return trips;
    }
    long long minimumTime(vector<int>&time, int totalTrips) {
        long long int totaltime = 0;
        for(auto time:time){
            totaltime+=time;
        }
        
        long long int l = 1;
        long long int h = 1e14;
        
        while(l<h){
            
            long long int mid = l+(h-l)/2;
            
            if(calc(time,mid)>=totalTrips){
                h = mid;
            }else{
                l = mid+1;
            }
        }
        
        return l;
    }
};
