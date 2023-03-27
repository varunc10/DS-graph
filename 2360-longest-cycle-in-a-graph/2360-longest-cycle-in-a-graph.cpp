class Solution {
public:
    int ans = -1;
    void dfs(vector<int> &edges, vector<bool> &vis, int i, unordered_map<int, int>& m){
        vis[i] = true;
        if(edges[i] != -1 && !vis[edges[i]]){
            m[edges[i]] = m[i] + 1;
            dfs(edges, vis, edges[i], m);
        }
        else if(edges[i] != -1 && m.count(edges[i])){
            ans = max(ans, m[i] - m[edges[i]] + 1);
        }
    }
    int longestCycle(vector<int>& edges) {
        int mx = *max_element(begin(edges), end(edges));
        vector<bool> vis(mx + 1, false);
        for(int i = 0; i <= mx; i++){
            if(!vis[i]){
                unordered_map<int, int> m;
                m[i] = 1;
                dfs(edges, vis, i, m);
            }
        }
        return ans;
    }
};