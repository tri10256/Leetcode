class Solution {
public:
    int titleToNumber(string &s) {
        int no = 0;
        for(auto &ch:s){
            int d = (ch-'A'+1);
            no*=26; ///base 26 similar to base 10;
            no+=d;
        }
        return no;
    }
};