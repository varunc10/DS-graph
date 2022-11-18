class Solution {
public:
    int dfs(vector<vector<int>>& stones,vector<bool> &vis,int i){
        vis[i]=true;
        int ans=0;
        for(int j=0;j<stones.size();j++){
            if(!vis[j]&&(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])){
                ans+=dfs(stones,vis,j)+1;
            }
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        int ans=0;
        vector<bool> vis(stones.size(),false);
        for(int i=0;i<stones.size();i++){
            if(!vis[i]){
                ans+=dfs(stones,vis,i);
            }
        }
        return ans;
    }
};