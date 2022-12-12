//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        vector<int> primes;
        bool IsPrime[1000001];
        memset(IsPrime,true,1000001);
        //finding primes using the method of sieve of eratothenes
        for(int i=2;i*i<=1e6;i++){
            if(IsPrime[i]){
                for(int j=2*i;j<=1e6;j+=i){
                    IsPrime[j]=false;
                }
            }
        }
        
        for(int i=2;i<=1e6;i++){
            if(IsPrime[i]) primes.push_back(i);
        }
        
        vector<int> ans;
        for(auto N:query){
            int ct = 0;
            
            for(int i=0;i<primes.size();i++){
                int x = primes[i];
                if(x*x>N) break;
                ct++;
            }
            
            ans.push_back(ct);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends