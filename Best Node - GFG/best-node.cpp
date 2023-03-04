//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int maxi=INT_MIN;
    void dfs(vector<int> &A, vector<int> &P,int node,int h,long long sum){
        if(h==0){
            maxi=max(maxi,A[node-1]);
            dfs(A,P,P[node-1],h+1,A[node-1]);
            return;
        }
        if(h%2){
            int temp=A[node-1]-sum;
            maxi= max(maxi,temp);
            if(node-1!=0){
                dfs(A,P,P[node-1],h+1,sum-A[node-1]);
            }
            return;
        }
        else{
            int temp=A[node-1]+sum;
            maxi=max(maxi,temp);
            if(node-1!=0){
                dfs(A,P,P[node-1],h+1,sum+A[node-1]);
            }
            return;
        }
    }
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        // code here
        int sum=0,h=0;
        vector<int> adj[N+1];
        if(N==1)return A[0];
        for(int i=1;i<N;i++){
            adj[P[i]].push_back(A[i]);
        }
        for(int i=1;i<=N;i++){
            if(adj[i].size()==0){
                dfs(A,P,i,0,0);
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends