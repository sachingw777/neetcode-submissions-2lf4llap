class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        for(int i = 0; i < rows; i++){
            if(matrix[i][0] <= target && target <= matrix[i][cols-1]){
                int l = 0, r = cols-1;
                while(l <= r){
                    int mid = l + (r-l)/2;
                    if(matrix[i][mid] == target) return true;
                    else if(matrix[i][mid] < target) l = mid + 1;
                    else r = mid - 1;
                }
            }
        }

        return false;
    }
};
