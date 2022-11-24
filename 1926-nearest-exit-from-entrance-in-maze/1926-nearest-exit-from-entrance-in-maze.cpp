class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        vector<pair<int,int>> v{{0,1},{0,-1},{1,0},{-1,0}};
        q.push({entrance[0],entrance[1]});
        vector<vector<int>> dist(maze.size(),vector<int>(maze[0].size(),INT_MAX));
        dist[entrance[0]][entrance[1]]=0;
        int ans=INT_MAX;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(auto k:v){
                int i=p.first+k.first;
                int j=p.second+k.second;
                if(i>=0&&j>=0&&i<maze.size()&&j<maze[0].size()&&dist[i][j]==INT_MAX&&maze[i][j]!='+'){
                    dist[i][j]=dist[p.first][p.second]+1;
                    // cout<<i<<" "<<j<<endl;
                    if(i==maze.size()-1||j==maze[0].size()-1||i==0||j==0){
                        ans=min(ans,dist[i][j]);
                    }
                    q.push({i,j});
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};