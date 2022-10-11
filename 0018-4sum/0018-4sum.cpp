class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        while(i<n-3){
            int a=nums[i];
            int j=i+1;
            while(j<n-2){
                int b=nums[j];
                int k=j+1,l=n-1;
                while(k<l){
                    int c=nums[k],d=nums[l];
                    ll sum=(ll)a+(ll)b+(ll)c+(ll)d;
                    if(sum>target){
                        l--;
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        v.push_back({a,b,c,d});
                        while(k<l&&c==nums[k]){
                            c++;
                        }
                        while(k<l&&d==nums[l]){
                            l--;
                        }
                    }
                }
                while(j<n-2&&b==nums[j]){
                    j++;
                }
            }
            while(i<n-3&&a==nums[i]){
                i++;
            }
        }
        return v;
    }
};