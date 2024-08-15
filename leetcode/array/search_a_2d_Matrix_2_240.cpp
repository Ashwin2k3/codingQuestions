
class Solution {
    public:

        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            
            int y = matrix.size();
            int x = matrix[0].size() - 1;
            for(int i = 0; i < y ; i++){
                int low = 0;
                int high = x ;
                while (low <= high) {
                    int mid = low + (high-low)/2 ;
                    if(matrix[i][mid] == target){
                        return true ;
                    }
                    else if(matrix[i][mid]< target){
                        low = mid +1 ;
                    }
                    else if (matrix[i][mid] > target){
                        high = mid -1 ;
                    }
                    else{
                        break;
                    }
                }
            }
            return false ;
        }
};


