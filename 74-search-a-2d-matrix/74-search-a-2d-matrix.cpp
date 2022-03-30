class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0;
        int h=m*n-1;
        while(l!=h)
        {
            int mid=(l+h-1)/2;
            if(matrix[mid/m][mid%m]<target)
                l=mid+1;
            else
                h=mid;
        }
        return matrix[h/m][h%m]==target;
    }
};