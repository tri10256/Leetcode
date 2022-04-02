class Solution {
public:
    int minBitFlips(int start, int goal) {
         bitset<32> num1(start ^ goal);
    
        return num1.count();
    }
};