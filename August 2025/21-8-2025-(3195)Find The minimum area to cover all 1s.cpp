class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        //0 1 0
        //1 0 1
        //0 0 1
        int row = grid.size(), col = grid[0].size();
        unordered_map<int> R, C;
        for (int r = 0; r<row; r++){
            for (int c = 0; c<col; c++){
                if (grid[r][c]){
                    R[r] = 1;
                    C[c] = 1;
                }
            }
        }
        int smallest_r = INT_MAX, largest_r = INT_MIN;
        for (auto&[key, val]: R){
            smallest_r = min(smallest_r, key);
            largest_r = max(largest_r, key);
        }

        


    }
};