class Solution {
    public:
        void dfs(int row , int col ,vector<vector<int> >& grid, vector<vector<int> > &vis) {
            vis[row][col] = 1 ;
            vector<int> dirx = {-1 , 1 , 0 ,0};
            vector<int> diry = {0,0,-1,1,};
            for(int i=0;i<4;i++){
                int newRow = row + dirx[i] ;
                int newcol = col + diry[i] ;
                if(newRow >= 0 and newRow < grid.size() and newcol >=0 and newcol < grid[0].size() and !vis[newRow][newcol]  and grid[newRow][newcol] == 1){
                    grid[newRow][newcol] = 2;
                    dfs(newRow, newcol, vis, grid);
                }
            }


        }
        int orangesRotting(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid.size();
            
            bool hasRotten = false;

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if (grid[i][j] == 1) {
                        hasRotten = true ;
                    }
                }
            }
            if (!hasRotten) {
                return 0;
            }

            vector<vector<int>> vis(n,vector<int>(m,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j] == 2 and !vis[i][j]){
                        dfs(i,j,grid,vis);
                    }
                }
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if (grid[i][j] == 1) {
                        return -1;
                    }
                }
            }

            return -1 ;

        }
};

