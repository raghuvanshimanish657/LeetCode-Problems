//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int n=S.size();
        bool table[n][n];
        memset(table,0,sizeof(table));
        int mx=1;
        // unordered_map<int, int> m;
        map<int, int> m;
        for(int i=0;i<n;i++){
            table[i][i]= true;
        }
        
        int start = 0;
        for(int i=0; i<n-1; i++){
            if(S[i] == S[i+1]){
                table[i][i+1]=true;
                mx=2;
                start=i;
                m[start]=mx;
            }
        }
        
        for(int k=3; k<=n; k++){
            for(int i=0; i<n-k+1; i++){
                int j=i+k-1;
                if(table[i+1][j-1] && S[i]==S[j]){
                    table[i][j]=true;
                    if(k>mx){
                        start=i;
                        mx=k;
                        m[start]=mx;
                    }
                }
            }
        }
        
        // for(auto i: m){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        int ms=1002;
        for(auto i: m){
            if(i.second == mx){
                // start = i.first;
                if(i.first<ms){
                    ms=i.first;
                }
            }
        }
        // cout<<ms<<endl;
        
        string s="";
        if(mx>1){
            for(int i=ms; i<=ms+mx-1; i++){
                s+=S[i];
            }
            return s;
        }else if(mx==1){
            s="";
            s+=S[0];
            return s;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends