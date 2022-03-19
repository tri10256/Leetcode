class SubrectangleQueries {
public:
    vector<vector<int>>rectanglecopy;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        int n = rectangle.size();
        int m = rectangle[0].size();
        rectanglecopy.resize(n,vector<int>(m,-1));
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                rectanglecopy[i][j] = rectangle[i][j];
            }
        }
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        
        for(int i = row1;i<=row2;i++){
            for(int j = col1;j<=col2;j++){
                rectanglecopy[i][j] = newValue;
            }
        }
        
    }
    
    int getValue(int row, int col) {
        return rectanglecopy[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */