class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==0||q.size()==grid.size()*grid[0].size()){
            return -1;
        }
        int res=-1;
        vector<pair<int,int>> v{{0,-1},{0,1},{1,0},{-1,0}};
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(auto k:v){
                int m=p.first+k.first,n=p.second+k.second;
                if(m>=grid.size()||m<0||n>=grid[0].size()||n<0||grid[m][n]!=0){
                    continue;
                }
                grid[m][n]=grid[p.first][p.second]+1;
                q.push({m,n});
                res=max(res,grid[m][n]);
            }
        }
        return res==-1?-1:res-1;
    }
};