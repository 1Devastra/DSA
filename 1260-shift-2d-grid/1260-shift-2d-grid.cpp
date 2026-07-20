class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row=grid.size();
        int col=grid[0].size();
        int size=row*col;
        int index=k%size;
        vector<vector<int>>ans(row,vector<int>(col));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int new_index=i*col+j+k;
                int new_row=(new_index/col)%row;
                int new_col=new_index%col;
                ans[new_row][new_col]=grid[i][j];
            }
        }
        return ans;
        
    }
};