//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void relax(vector<pair<int,int>> adj[], vector<int> &dist, int n){
        for(int i=0;i<n;i++){
            vector<pair<int,int>> edges = adj[i];
            for(pair<int,int> edge: edges){
                int u = i;
                int v = edge.first;
                int w = edge.second;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int> dist(N, 1e9);
        vector<pair<int,int>> adj[N];
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        dist[0] = 0;
        
        relax(adj, dist, N);
        relax(adj, dist, N);
        
        for(int i=0;i<N;i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends