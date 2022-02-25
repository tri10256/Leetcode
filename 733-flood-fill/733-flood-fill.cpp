class Solution {
public:
    void floodfill(vector<vector<int>>& image, int sr, int sc, int newColor,int n,int m, int color)
    {
        if( sr < 0 || sc < 0 || sr == n || sc == m || image[sr][sc]!=color)
            return;
        image[sr][sc]=newColor;
        floodfill(image,sr-1,sc,newColor,n,m,color);
        floodfill(image,sr+1,sc,newColor,n,m,color);
        floodfill(image,sr,sc-1,newColor,n,m,color);
        floodfill(image,sr,sc+1,newColor,n,m,color);   
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)    
    {     
        
     int n=image.size();
                                     
     int m= image[0].size();
    if(newColor==image[sr][sc])
        return image;
    floodfill(image,sr,sc,newColor,n,m,image[sr][sc]);
    return image;
                                                                                               }
};