//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    #define ll long long
    //Function to find largest rectangular area possible in a given histogram.
    void NSR(ll arr[], int n, vector<int>& nsr){
        stack<int> s;
        s.push(n - 1);
        for(int i = n - 2; i >= 0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            nsr[i] = s.empty() ? n : s.top();
            s.push(i);
        }
    }
    void NSL(ll arr[], int n, vector<int>& nsl){
        stack<int> s;
        s.push(0);
        for(int i = 1; i < n; i++){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            nsl[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
    }
    ll getMaxArea(ll arr[], int n)
    {
        // Your code here
        vector<int> nsl(n, -1), nsr(n, n);
        NSL(arr, n, nsl);
        NSR(arr, n, nsr);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, arr[i] * (nsr[i] - nsl[i] - 1));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends