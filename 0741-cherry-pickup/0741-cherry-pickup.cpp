class Solution {
public:
    int memo[51][51][51][51];
    int dfs(vector<vector<int>>& grid, int x1, int y1, int x2, int y2){
        if(x1 < 0 || x2 < 0 || x1 == grid.size() || x2 == grid.size() || y1 == grid[0].size()|| y2 == grid[0].size() || grid[x1][y1] == -1 || grid[x2][y2] == -1){
            return INT_MIN;
        }
        if(x1 == grid.size() - 1 && y1 == grid[0].size() - 1){
            return grid[x1][y1];
        }
        if(x2 == grid.size() - 1 && y2 == grid[0].size() - 1){
            return grid[x2][y2];
        }
        if(memo[x1][y1][x2][y2] != -1){
            return memo[x1][y1][x2][y2];
        }
        int ans = 0;
        if(x1 == x2 && y1 == y2){
            ans += grid[x1][y1];
        }
        else{
            ans += grid[x1][y1] + grid[x2][y2];
        }
        int a = dfs(grid, x1 + 1, y1, x2, y2 + 1);
        int b = dfs(grid, x1, y1 + 1, x2 + 1, y2);
        int c = dfs(grid, x1 + 1, y1, x2 + 1, y2);
        int d = dfs(grid, x1, y1 + 1, x2, y2 + 1);
        return memo[x1][y1][x2][y2] = ans += max({a, b, c, d});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        if(grid[0][0] == -1 || grid[grid.size() - 1][grid[0].size() - 1] == -1){
            return -1;
        }
        memset(memo, -1, sizeof(memo));
        return max(0, dfs(grid, 0, 0, 0, 0));
    }
};