class Solution {
public:
    #define ll long long
    void dfs(vector<vector<int>>& v, vector<pair<bool, int>> &vis, int i, int k, int &cnt){
        vis[i].first = true;
        cnt++;
        for(auto j: v[i]){
            if(!vis[j].first){
                vis[j].second = k;
                dfs(v, vis, j, k, cnt);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        for(auto i: edges){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        vector<pair<bool, int>> vis(n);
        int k = 1;
        vector<int> t;
        for(int i = 0; i < n; i++){
            if(!vis[i].first){
                vis[i].second = k;
                int cnt = 0;
                dfs(v, vis, i, k, cnt);
                t.push_back(cnt);
                k++;
            }
        }
        if(t.size() == 1){
            return 0;
        }
        ll sum = 0, ans = 0;
        for(auto i: t){
            sum += i;
        }
        for(int i = 0; i < t.size() - 1; i++){
            ll pr = (ll)t[i] * (sum - (ll)t[i]);
            ans += pr;
            sum -= (ll)t[i];
        }
        return ans;
    }
};