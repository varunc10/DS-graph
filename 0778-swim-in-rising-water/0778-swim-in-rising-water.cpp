class Solution {
public:
    int memo[51][51][2501];
    int helper(vector<vector<int>>& grid, int i, int j, int mx, vector<vector<bool>>& vis){
        if(i < 0 || j < 0|| i == grid.size() || j == grid[0].size() || vis[i][j]){
            return INT_MAX;
        }
        mx = max(mx, grid[i][j]);
        if(i == grid.size() - 1 && j == grid[0].size() - 1){
            return mx;
        }
        if(memo[i][j][mx] != -1){
            return memo[i][j][mx];
        }
        vis[i][j] = true;
        int a = helper(grid, i - 1, j, mx, vis);
        int b = helper(grid, i, j - 1, mx, vis);
        int c = helper(grid, i + 1, j, mx, vis);
        int d = helper(grid, i, j + 1, mx, vis);
        vis[i][j] = false;
        return memo[i][j][mx] = min({a, b, c, d});
    }
    int swimInWater(vector<vector<int>>& grid) {
        int mx = grid[0][0];
        memset(memo, -1, sizeof(memo));
        vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(), false)); 
        return helper(grid, 0, 0, mx, vis);
    }
};