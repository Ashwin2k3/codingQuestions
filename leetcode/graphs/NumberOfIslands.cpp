class Solution {
public:
    void dfs(int row , int col , vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1 ;
        vector<int> dirx = {-1 , 1 , 0 ,0};
        vector<int> diry = {0,0,-1,1,};
        
        for(int i=0;i<4;i++){
            int newRow = row + dirx[i] ;
            int newcol = col + diry[i] ;
            if(newRow >= 0 and newRow < grid.size() and newcol >=0 and newcol < grid[0].size() and !vis[newRow][newcol] and grid[newRow][newcol] == '1' ){
                dfs(newRow, newcol, vis, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for (int row = 0;row < n;row ++){
            for (int col = 0 ; col < m; col++){
                if (!vis[row][col] and grid[row][col] == '1') {
                    cnt ++ ;
                    dfs(row, col, vis , grid);
                }
            }
        }
        return cnt ;
        
    }
};

