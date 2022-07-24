class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0;
        int h=n-1;
        while(l<m && h>=0)
        {
            if(matrix[l][h]==target)
                return true;
            matrix[l][h]>target? h--:l++;
        }
        return false;
        
    }
};