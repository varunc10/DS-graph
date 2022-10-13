class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& v, int src, int dst, int k) {
        vector<int> dist(n,1e9);
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> temp(dist);
            for(auto i:v){
                temp[i[1]]=min(temp[i[1]],dist[i[0]]+i[2]);
            }
            dist=temp;
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};