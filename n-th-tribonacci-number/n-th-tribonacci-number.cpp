class Solution {
public:
    unordered_map<int,int>cache;
    
    int tribonacci(int n) {
        if(n <= 0)
            return 0;
        if(n==1 || n==2)
            return 1;
        
        if(cache.count(n))
            return cache[n];
        
        if(!cache.count(n))
            cache[n] = tribonacci(n-3) +  tribonacci(n-2) + tribonacci(n-1);
        
        return cache[n];
    }
};