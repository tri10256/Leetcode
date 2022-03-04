class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double ans[102][102] = {};
        ans[0][0] = (double) poured;
        
        for(int r = 0;r<=query_row;++r){
            for(int c = 0;c<=r;++c){
                double val = (ans[r][c] - 1.0)/2.0;
                if(val>0){
                    ans[r+1][c] += val;
                    ans[r+1][c+1] += val;
                }
            }
        }
        
        return min((double)1,ans[query_row][query_glass]);
    }
};