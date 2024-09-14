// https://leetcode.com/problems/flood-fill/
//

class Solution {
    public:

        void dfs(int row , int col , vector<vector<int>>& vis, vector<vector<int>>& image,int oldColor,  int c){
            vis[row][col] = 1 ;
            image[row][col] = c;
            vector<int> dirx = {-1 , 1 , 0 ,0};
            vector<int> diry = {0,0,-1,1,};

            for(int i=0;i<4;i++){
                int newRow = row + dirx[i] ;
                int newcol = col + diry[i] ;
                if(newRow >= 0 and newRow < image.size() and newcol >=0 and newcol < image[0].size() and !vis[newRow][newcol] and image[newRow][newcol] != c  and image[newRow][newcol] == oldColor ){
                    image[newRow][newcol] = c;
                    dfs(newRow, newcol, vis, image, oldColor, c);
                }
            }
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {


            int n = image.size();
            int m = image[0].size();
            int oldColor = image[][sc]
            vector<vector<int>> vis(n,vector<int>(m,0));
            dfs(sr, sc, vis, image, oldColor, color);
            return image ;


        }
};
