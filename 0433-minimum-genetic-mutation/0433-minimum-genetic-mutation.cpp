class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        string s="ACGT";
        queue<pair<string,int>> q;
        q.push({start,0});
        int ans=INT_MAX;
        while(!q.empty()){
            string curr=q.front().first;
            int count=q.front().second;
            //cout<<curr<<endl;
            q.pop();
            for(int i=0;i<curr.size();i++){
                char c=curr[i];
                for(auto j:s){
                    if(curr[i]==j){
                        continue;
                    }
                    curr[i]=j;
                    auto it=find(bank.begin(),bank.end(),curr);
                    if(it!=bank.end()){
                        bank.erase(it);
                        if(curr==end){
                            ans=min(ans,count+1);
                        }
                        else{
                            q.push({curr,count+1});
                        }
                    }
                }
                curr[i]=c;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};