class Solution {
public:
    bool dfs(vector<vector<int>>& v,vector<bool>& vis,int src,int parent){
        vis[src]=true;
        for(auto j:v[src]){
            if(!vis[j]){
                dfs(v,vis,j,src);
            }
            else if(j!=parent){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> v(edges.size()+1);
        for(auto i:edges){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
            vector<bool> vis(v.size(),false);
            if(dfs(v,vis,i[0],-1)){
                return i;
            }
        }
        return {};
    }
};