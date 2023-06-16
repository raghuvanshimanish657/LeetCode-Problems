//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution {
    vector<int>ty;
    unordered_map<ll,pair<ll,ll>>mp;
    ll dp[100001][3];
  public:
    ll f(int i,int j){
        ll pos=0;
        if(j==0){
            pos=mp[ty[i-1]].first;
        }else if(j==1){
            pos=mp[ty[i-1]].second;
        }
        
        if(i==ty.size()){
            return abs(pos);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        ll ans=1e18;
        ll dist=abs(mp[ty[i]].first-mp[ty[i]].second);//cost to pick up all the fruits of the ith type.
        //if you start picking from left you would end up at right and vice-versa, [jth represents-> here 0->left and 1->right] 
        ans=min(ans,dist+abs(mp[ty[i]].first-pos)+f(i+1,1));
        ans=min(ans,dist+abs(mp[ty[i]].second-pos)+f(i+1,0));
        
        return  dp[i][j]=ans;
    }
    long long minTime(int n, vector<int> &loc, vector<int> &types) {
        //storing the min and max distance of a particular type of fruit in map
         for(int i = 0; i < n; i++) {
            int lo = loc[i];
            int type = types[i];
            
            if(mp.find(type) == mp.end()) {
                mp[type] = {lo, lo};
                
            } else {
                int st = mp[type].first, end = mp[type].second;
                st = min(st, lo);
                end = max(end, lo);
                mp[type] = {st, end};
            }
        }
//storing the different types...
        for(auto x:mp){
            ty.push_back(x.first);
        }
        sort(ty.begin(),ty.end());
        memset(dp,-1,sizeof(dp));
//passing 2(can pass anything(except 0 and 1) ,easy for memo) for the jth value so , that the pos is 0 as we start from 0 
        return f(0,2);
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends