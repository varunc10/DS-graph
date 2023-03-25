class Solution {
public:
    void dfs(vector<vector<int>>& v, vector<bool>& vis, unordered_map<int, int>& m, int i){
        if(m.count(i) > 0){
            return;
        }
        vis[i] = true;
        for(auto j: v[i]){
            if(!vis[j]){
                dfs(v, vis, m, j);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> v(n);
        int ans = 0;
        unordered_map<int, int> m;
        for(auto i: restricted){
            m[i]++;
        }
        for(auto i: edges){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n);
        dfs(v, vis, m, 0);
        for(int i = 0; i < n ; i++){
            if(m.count(i) == 0 && vis[i]){
                ans++;
            }
        }
        return ans;
    }
};