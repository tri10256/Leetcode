class Solution {
public:
    int titleToNumber(string s) {
        int no = 0;
        for(auto &ch:s){
            no=no*26+(ch-'A'+1);
        }
        return no;
    }
};