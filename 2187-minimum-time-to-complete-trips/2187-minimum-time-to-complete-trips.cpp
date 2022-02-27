// class Solution {
// public:
    
//     long long int calc(vector<int>&time,int given){
//         long long int trips = 0;
//         for(auto x:time){
            
//             long long int val = x;
            
//             trips+=(given/val);
//         }
        
//         return trips;
//     }
//     long long minimumTime(vector<int>&time, int totalTrips) {
//         long long int totaltime = 0;
//         for(auto time:time){
//             totaltime+=time;
//         }
        
//         long long int l = 1;
//         long long int h = 1e14;
        
//         while(l<h){
            
//             long long int mid = l+(h-l)/2;
            
//             if(calc(time,mid)>=totalTrips){
//                 h = mid;
//             }else{
//                 l = mid+1;
//             }
//         }
        
//         return l;
//     }
// };

class Solution {
public:
	// this function will count totalTrips for the given time
	// a = [1,2,3] , and at time 3 how many trips we can take? 
	// 3/1 + 3/2 + 3/3 => 3 + 1 + 1 = 5 Trips
    long long int numberOfTripsForGivenTime(vector<int>&a , long long int givenTime)
    {
        long long int totalTrips = 0;
        for(auto x : a)
        {
            // convert it to long long int 
            long long int val = x;
			
            totalTrips += (givenTime / val);
        }
        return totalTrips;
    }
    long long minimumTime(vector<int>& arr ,  int totalTrips) {
        long long int lowestTime = 1;
        long long int highestTime = 1e14;
        while(lowestTime<highestTime)
        {
            long long int mid = lowestTime + (highestTime-lowestTime)/2;
            
            if(numberOfTripsForGivenTime(arr , mid) >= totalTrips)
                highestTime = mid;
            else
                lowestTime = mid+1;
        }
        return lowestTime;
    }
};