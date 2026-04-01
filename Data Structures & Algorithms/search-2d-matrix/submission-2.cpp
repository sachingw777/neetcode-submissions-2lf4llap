class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i < rows; i++){
            if(target >= matrix[i][0] && target <= matrix[i][cols-1]){
                int l = 0, r = cols-1;
                while(l <= r){
                    int mid = l + (r-l)/2;
                    if(target == matrix[i][mid]) return true;
                    else if(target > matrix[i][mid]) l = mid+1;
                    else r = mid-1;
                }
            }
        }

        return false;
    }
};
